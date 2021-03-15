$NetBSD$

--- src/3rdparty/chromium/chrome/common/channel_info_posix.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/channel_info_posix.cc
@@ -67,7 +67,7 @@ std::string GetChannelSuffixForDataDir()
   }
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 std::string GetDesktopName(base::Environment* env) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   version_info::Channel product_channel(GetChannel());
