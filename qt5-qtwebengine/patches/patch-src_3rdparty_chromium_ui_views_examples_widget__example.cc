$NetBSD$

--- src/3rdparty/chromium/ui/views/examples/widget_example.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/ui/views/examples/widget_example.cc
@@ -72,7 +72,7 @@ void WidgetExample::CreateExampleView(Vi
   BuildButton(container, "Popup widget", POPUP);
   BuildButton(container, "Dialog widget", DIALOG);
   BuildButton(container, "Modal Dialog", MODAL_DIALOG);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   BuildButton(container, "Child widget", CHILD);
 #endif
