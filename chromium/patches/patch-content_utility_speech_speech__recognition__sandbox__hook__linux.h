$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/utility/speech/speech_recognition_sandbox_hook_linux.h.orig	2024-07-24 02:44:38.328945400 +0000
+++ content/utility/speech/speech_recognition_sandbox_hook_linux.h
@@ -5,7 +5,13 @@
 #ifndef CONTENT_UTILITY_SPEECH_SPEECH_RECOGNITION_SANDBOX_HOOK_LINUX_H_
 #define CONTENT_UTILITY_SPEECH_SPEECH_RECOGNITION_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace speech {
 
