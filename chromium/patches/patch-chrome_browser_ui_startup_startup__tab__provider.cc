$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/startup_tab_provider.cc.orig	2024-07-24 02:44:29.652104900 +0000
+++ chrome/browser/ui/startup/startup_tab_provider.cc
@@ -61,7 +61,7 @@
 #include "extensions/browser/extension_registry.h"
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/headless/headless_mode_util.h"
 #endif
 
@@ -105,7 +105,7 @@ bool ValidateUrl(const GURL& url) {
 #if BUILDFLAG(IS_CHROMEOS_LACROS)
   // In ChromeOS, allow any URL pattern that matches chrome:// scheme.
   url_scheme_is_chrome = url.SchemeIs(content::kChromeUIScheme);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // In Headless mode, allow any URL pattern that matches chrome:// scheme if
   // the user explicitly allowed it.
   if (headless::IsHeadlessMode() && url.SchemeIs(content::kChromeUIScheme)) {
