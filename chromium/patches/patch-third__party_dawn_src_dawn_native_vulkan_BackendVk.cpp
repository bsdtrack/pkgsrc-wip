$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp.orig	2024-08-06 19:53:14.102094400 +0000
+++ third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp
@@ -56,7 +56,7 @@ constexpr char kSwiftshaderLibName[] = "
 #endif
 
 #if DAWN_PLATFORM_IS(LINUX)
-#if DAWN_PLATFORM_IS(ANDROID)
+#if DAWN_PLATFORM_IS(ANDROID) || DAWN_PLATFORM_IS(BSD)
 constexpr char kVulkanLibName[] = "libvulkan.so";
 #else
 constexpr char kVulkanLibName[] = "libvulkan.so.1";
