$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.h.orig	2024-07-24 02:45:10.960106100 +0000
+++ ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.h
@@ -65,7 +65,7 @@ class VIEWS_EXPORT DesktopDragDropClient
     // The offset of |drag_widget_| relative to the mouse position.
     gfx::Vector2d offset;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The last received drag location.  The drag widget is moved asynchronously
     // so its position is updated when the UI thread has time for that.  When
     // the first change to the location happens, a call to UpdateDragWidget()
@@ -86,7 +86,7 @@ class VIEWS_EXPORT DesktopDragDropClient
       const gfx::Point& root_location,
       int allowed_operations,
       ui::mojom::DragEventSource source) override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void UpdateDragImage(const gfx::ImageSkia& image,
                        const gfx::Vector2d& offset) override;
 #endif
