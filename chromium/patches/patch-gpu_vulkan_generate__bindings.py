$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/vulkan/generate_bindings.py.orig	2024-08-06 19:52:27.338142200 +0000
+++ gpu/vulkan/generate_bindings.py
@@ -271,7 +271,7 @@ VULKAN_DEVICE_FUNCTIONS = [
     ]
   },
   {
-    'ifdef': 'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)',
+    'ifdef': 'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)',
     'extension': 'VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME',
     'functions': [
       'vkGetImageDrmFormatModifierPropertiesEXT',
