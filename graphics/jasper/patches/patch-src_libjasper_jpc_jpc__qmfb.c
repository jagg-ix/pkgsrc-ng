$NetBSD: patch-src_libjasper_jpc_jpc__qmfb.c,v 1.1 2015/02/08 23:04:22 snj Exp $

Fix CVE-2014-8158.  Patch taken from
https://bugzilla.redhat.com/show_bug.cgi?id=1179298

--- src/libjasper/jpc/jpc_qmfb.c.orig	2007-01-19 13:43:07.000000000 -0800
+++ src/libjasper/jpc/jpc_qmfb.c	2015-02-08 14:49:33.000000000 -0800
@@ -306,11 +306,7 @@ void jpc_qmfb_split_row(jpc_fix_t *a, in
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numcols, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
@@ -318,7 +314,6 @@ void jpc_qmfb_split_row(jpc_fix_t *a, in
 	register int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
 		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
@@ -326,7 +321,6 @@ void jpc_qmfb_split_row(jpc_fix_t *a, in
 			abort();
 		}
 	}
-#endif
 
 	if (numcols >= 2) {
 		hstartcol = (numcols + 1 - parity) >> 1;
@@ -360,12 +354,10 @@ void jpc_qmfb_split_row(jpc_fix_t *a, in
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -374,11 +366,7 @@ void jpc_qmfb_split_col(jpc_fix_t *a, in
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
@@ -386,7 +374,6 @@ void jpc_qmfb_split_col(jpc_fix_t *a, in
 	register int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
 		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
@@ -394,7 +381,6 @@ void jpc_qmfb_split_col(jpc_fix_t *a, in
 			abort();
 		}
 	}
-#endif
 
 	if (numrows >= 2) {
 		hstartcol = (numrows + 1 - parity) >> 1;
@@ -428,12 +414,10 @@ void jpc_qmfb_split_col(jpc_fix_t *a, in
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -442,11 +426,7 @@ void jpc_qmfb_split_colgrp(jpc_fix_t *a,
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize * JPC_QMFB_COLGRPSIZE];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -457,7 +437,6 @@ void jpc_qmfb_split_colgrp(jpc_fix_t *a,
 	int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
 		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
@@ -465,7 +444,6 @@ void jpc_qmfb_split_colgrp(jpc_fix_t *a,
 			abort();
 		}
 	}
-#endif
 
 	if (numrows >= 2) {
 		hstartcol = (numrows + 1 - parity) >> 1;
@@ -517,12 +495,10 @@ void jpc_qmfb_split_colgrp(jpc_fix_t *a,
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -531,11 +507,7 @@ void jpc_qmfb_split_colres(jpc_fix_t *a,
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize * numcols];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -546,7 +518,6 @@ void jpc_qmfb_split_colres(jpc_fix_t *a,
 	int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
 		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
@@ -554,7 +525,6 @@ void jpc_qmfb_split_colres(jpc_fix_t *a,
 			abort();
 		}
 	}
-#endif
 
 	if (numrows >= 2) {
 		hstartcol = (numrows + 1 - parity) >> 1;
@@ -606,12 +576,10 @@ void jpc_qmfb_split_colres(jpc_fix_t *a,
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -619,18 +587,13 @@ void jpc_qmfb_join_row(jpc_fix_t *a, int
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numcols, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
 	register int n;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
 		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
@@ -638,7 +601,6 @@ void jpc_qmfb_join_row(jpc_fix_t *a, int
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numcols + 1 - parity) >> 1;
 
@@ -670,12 +632,10 @@ void jpc_qmfb_join_row(jpc_fix_t *a, int
 		++srcptr;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -684,18 +644,13 @@ void jpc_qmfb_join_col(jpc_fix_t *a, int
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
 	register int n;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
 		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
@@ -703,7 +658,6 @@ void jpc_qmfb_join_col(jpc_fix_t *a, int
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numrows + 1 - parity) >> 1;
 
@@ -735,12 +689,10 @@ void jpc_qmfb_join_col(jpc_fix_t *a, int
 		++srcptr;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -749,11 +701,7 @@ void jpc_qmfb_join_colgrp(jpc_fix_t *a, 
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize * JPC_QMFB_COLGRPSIZE];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -763,7 +711,6 @@ void jpc_qmfb_join_colgrp(jpc_fix_t *a, 
 	register int i;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
 		if (!(buf = jas_malloc(bufsize * JPC_QMFB_COLGRPSIZE * sizeof(jpc_fix_t)))) {
@@ -771,7 +718,6 @@ void jpc_qmfb_join_colgrp(jpc_fix_t *a, 
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numrows + 1 - parity) >> 1;
 
@@ -821,12 +767,10 @@ void jpc_qmfb_join_colgrp(jpc_fix_t *a, 
 		srcptr += JPC_QMFB_COLGRPSIZE;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -835,11 +779,7 @@ void jpc_qmfb_join_colres(jpc_fix_t *a, 
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize * numcols];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -849,7 +789,6 @@ void jpc_qmfb_join_colres(jpc_fix_t *a, 
 	register int i;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
 		if (!(buf = jas_malloc(bufsize * numcols * sizeof(jpc_fix_t)))) {
@@ -857,7 +796,6 @@ void jpc_qmfb_join_colres(jpc_fix_t *a, 
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numrows + 1 - parity) >> 1;
 
@@ -907,12 +845,10 @@ void jpc_qmfb_join_colres(jpc_fix_t *a, 
 		srcptr += numcols;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
