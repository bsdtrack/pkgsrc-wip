$NetBSD$

--- src/3rdparty/chromium/content/browser/memory/swap_metrics_driver_impl_linux.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/browser/memory/swap_metrics_driver_impl_linux.cc
@@ -43,6 +43,7 @@ SwapMetricsDriverImplLinux::~SwapMetrics
 
 SwapMetricsDriver::SwapMetricsUpdateResult
 SwapMetricsDriverImplLinux::UpdateMetricsInternal(base::TimeDelta interval) {
+#if !defined(OS_BSD)
   base::VmStatInfo vmstat;
   if (!base::GetVmStatInfo(&vmstat)) {
     return SwapMetricsDriver::SwapMetricsUpdateResult::kSwapMetricsUpdateFailed;
@@ -61,6 +62,9 @@ SwapMetricsDriverImplLinux::UpdateMetric
   delegate_->OnSwapOutCount(out_counts, interval);
 
   return SwapMetricsDriver::SwapMetricsUpdateResult::kSwapMetricsUpdateSuccess;
+#else
+  return SwapMetricsDriver::SwapMetricsUpdateResult::kSwapMetricsUpdateFailed;
+#endif
 }
 
 }  // namespace content
