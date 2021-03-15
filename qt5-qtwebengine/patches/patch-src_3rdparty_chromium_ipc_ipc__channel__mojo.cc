$NetBSD$

--- src/3rdparty/chromium/ipc/ipc_channel_mojo.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_channel_mojo.cc
@@ -74,7 +74,7 @@ class MojoChannelFactory : public Channe
 };
 
 base::ProcessId GetSelfPID() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
 #endif  // OS_LINUX
