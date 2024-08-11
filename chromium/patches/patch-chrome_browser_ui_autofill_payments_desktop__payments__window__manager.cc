$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc.orig	2024-07-24 02:44:29.500090100 +0000
+++ chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc
@@ -49,7 +49,7 @@ gfx::Rect GetPopupSizeForVcn3ds() {
 DesktopPaymentsWindowManager::DesktopPaymentsWindowManager(
     ContentAutofillClient* client)
     : client_(CHECK_DEREF(client)) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   scoped_observation_.Observe(BrowserList::GetInstance());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
 }
@@ -109,7 +109,7 @@ void DesktopPaymentsWindowManager::WebCo
   }
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 void DesktopPaymentsWindowManager::OnBrowserSetLastActive(Browser* browser) {
   // If there is an ongoing payments window manager pop-up flow, and the
   // original tab's WebContents become active, activate the pop-up's
