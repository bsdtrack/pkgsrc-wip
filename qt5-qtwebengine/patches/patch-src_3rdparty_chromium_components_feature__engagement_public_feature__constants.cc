$NetBSD$

--- src/3rdparty/chromium/components/feature_engagement/public/feature_constants.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_constants.cc
@@ -15,7 +15,7 @@ const base::Feature kIPHDummyFeature{"IP
                                      base::FEATURE_DISABLED_BY_DEFAULT};
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const base::Feature kIPHFocusModeFeature{"IPH_FocusMode",
                                          base::FEATURE_DISABLED_BY_DEFAULT};
 const base::Feature kIPHGlobalMediaControlsFeature{
