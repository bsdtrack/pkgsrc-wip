$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/enterprise_companion/lock.cc.orig	2024-08-06 19:52:18.305378700 +0000
+++ chrome/enterprise_companion/lock.cc
@@ -16,7 +16,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kLockName[] = "/ChromeEnterpriseCompanion.lock";
 #elif BUILDFLAG(IS_MAC)
 constexpr char kLockName[] = "org.chromium.ChromeEnterpriseCompanion.lock";
@@ -41,7 +41,7 @@ CSecurityDesc GetAdminDaclSecurityDescri
 namespace enterprise_companion {
 
 std::unique_ptr<ScopedLock> CreateScopedLock() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return named_system_lock::ScopedLock::Create(kLockName, base::Seconds(0));
 #elif BUILDFLAG(IS_WIN)
   CSecurityAttributes sa =
