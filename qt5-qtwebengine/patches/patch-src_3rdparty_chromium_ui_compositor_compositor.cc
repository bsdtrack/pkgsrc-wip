$NetBSD$

--- src/3rdparty/chromium/ui/compositor/compositor.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/ui/compositor/compositor.cc
@@ -705,7 +705,7 @@ void Compositor::OnFrameTokenChanged(uin
   NOTREACHED();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 void Compositor::OnCompleteSwapWithNewSize(const gfx::Size& size) {
   for (auto& observer : observer_list_)
     observer.OnCompositingCompleteSwapWithNewSize(this, size);
