$NetBSD: patch-js_src_jit_arm_Architecture-arm.cpp,v 1.4 2015/02/28 04:30:55 ryoon Exp $

--- js/src/jit/arm/Architecture-arm.cpp.orig	2015-02-17 21:40:41.000000000 +0000
+++ js/src/jit/arm/Architecture-arm.cpp
@@ -16,7 +16,7 @@
 #include "jit/arm/Assembler-arm.h"
 #include "jit/RegisterSets.h"
 
-#if defined(ANDROID) || defined(JS_ARM_SIMULATOR)
+#if !defined(__linux__) || defined(ANDROID) || defined(JS_ARM_SIMULATOR) || defined(__NetBSD__)
 // The Android NDK and B2G do not include the hwcap.h kernel header, and it is not
 // defined when building the simulator, so inline the header defines we need.
 # define HWCAP_VFP        (1 << 6)
