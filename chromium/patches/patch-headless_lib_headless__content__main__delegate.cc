$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- headless/lib/headless_content_main_delegate.cc.orig	2024-07-24 02:44:39.285038000 +0000
+++ headless/lib/headless_content_main_delegate.cc
@@ -408,7 +408,7 @@ void HeadlessContentMainDelegate::InitCr
   if (process_type != ::switches::kZygoteProcess) {
     g_headless_crash_client.Pointer()->set_crash_dumps_dir(
         command_line.GetSwitchValuePath(switches::kCrashDumpsDir));
-#if !BUILDFLAG(IS_WIN)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
     crash_reporter::InitializeCrashpad(process_type.empty(), process_type);
 #endif  // !BUILDFLAG(IS_WIN)
     crash_keys::SetSwitchesFromCommandLine(command_line, nullptr);
