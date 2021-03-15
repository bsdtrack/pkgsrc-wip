$OpenBSD: patch-src_3rdparty_chromium_services_service_manager_sandbox_sandbox_cc,v 1.2 2021/01/19 06:16:34 rsadowski Exp $

Index: src/3rdparty/chromium/services/service_manager/sandbox/sandbox.cc
--- src/3rdparty/chromium/services/service_manager/sandbox/sandbox.cc.orig
+++ src/3rdparty/chromium/services/service_manager/sandbox/sandbox.cc
@@ -10,6 +10,14 @@
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
 #endif  // defined(OS_LINUX)
 
+#if defined(OS_OPENBSD)
+#include "services/service_manager/sandbox/openbsd/sandbox_openbsd.h"
+#endif  // defined(OS_LINUX)
+
+#if defined(OS_NETBSD)
+#include "services/service_manager/sandbox/netbsd/sandbox_netbsd.h"
+#endif  // defined(OS_LINUX)
+
 #if defined(OS_MACOSX)
 #include "services/service_manager/sandbox/mac/sandbox_mac.h"
 #endif  // defined(OS_MACOSX)
@@ -21,7 +25,7 @@
 
 namespace service_manager {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool Sandbox::Initialize(SandboxType sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options) {
