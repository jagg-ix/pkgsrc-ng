$NetBSD: patch-src_liolib.c,v 1.1 2015/01/02 15:50:44 alnsn Exp $
Fix build on Darwin powerpc: pkg/49526.

--- src/liolib.c.orig	2013-04-12 18:48:47.000000000 +0000
+++ src/liolib.c
@@ -15,6 +15,7 @@
 #endif
 
 
+#include <sys/types.h>
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
