$NetBSD$

--- src/3rdparty/chromium/third_party/blink/renderer/controller/memory_usage_monitor_posix.cc.orig	2020-07-15 18:56:02.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/controller/memory_usage_monitor_posix.cc
@@ -134,7 +134,7 @@ void MemoryUsageMonitorPosix::SetProcFil
   status_fd_.reset(status_file.TakePlatformFile());
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 void MemoryUsageMonitorPosix::Bind(
     mojo::PendingReceiver<mojom::blink::MemoryUsageMonitorLinux> receiver) {
