$NetBSD: patch-execinfo.c,v 1.2 2013/10/24 11:34:49 jperkin Exp $

Patch from FreeBSD ports devel/libexecinfo. Makes execinfo.c compilable

--- execinfo.c.orig	2004-07-19 05:21:09.000000000 +0000
+++ execinfo.c
@@ -36,6 +36,10 @@
 #include <string.h>
 #include <unistd.h>
 
+#ifdef __sun
+#include <alloca.h> 
+#endif
+
 #include "execinfo.h"
 #include "stacktraverse.h"
 
@@ -69,7 +73,8 @@ backtrace(void **buffer, int size)
 char **
 backtrace_symbols(void *const *buffer, int size)
 {
-    int i, clen, alen, offset;
+    size_t clen, alen;
+    int i, offset;
     char **rval;
     char *cp;
     Dl_info info;
@@ -78,7 +83,6 @@ backtrace_symbols(void *const *buffer, i
     rval = malloc(clen);
     if (rval == NULL)
         return NULL;
-    (char **)cp = &(rval[size]);
     for (i = 0; i < size; i++) {
         if (dladdr(buffer[i], &info) != 0) {
             if (info.dli_sname == NULL)
@@ -92,14 +96,14 @@ backtrace_symbols(void *const *buffer, i
                    2 +                      /* " <" */
                    strlen(info.dli_sname) + /* "function" */
                    1 +                      /* "+" */
-                   D10(offset) +            /* "offset */
+                   10 +                     /* "offset */
                    5 +                      /* "> at " */
                    strlen(info.dli_fname) + /* "filename" */
                    1;                       /* "\0" */
             rval = realloc_safe(rval, clen + alen);
             if (rval == NULL)
                 return NULL;
-            snprintf(cp, alen, "%p <%s+%d> at %s",
+            snprintf((char *) rval + clen, alen, "%p <%s+%d> at %s",
               buffer[i], info.dli_sname, offset, info.dli_fname);
         } else {
             alen = 2 +                      /* "0x" */
@@ -108,12 +112,15 @@ backtrace_symbols(void *const *buffer, i
             rval = realloc_safe(rval, clen + alen);
             if (rval == NULL)
                 return NULL;
-            snprintf(cp, alen, "%p", buffer[i]);
+            snprintf((char *) rval + clen, alen, "%p", buffer[i]);
         }
-        rval[i] = cp;
-        cp += alen;
+        rval[i] = (char *) clen;
+        clen += alen;
     }
 
+    for (i = 0; i < size; i++)
+        rval[i] += (long) rval;
+
     return rval;
 }
 
