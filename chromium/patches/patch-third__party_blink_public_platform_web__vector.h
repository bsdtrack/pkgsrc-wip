$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/public/platform/web_vector.h.orig	2024-07-24 02:44:45.117602800 +0000
+++ third_party/blink/public/platform/web_vector.h
@@ -86,7 +86,7 @@ class WebVector {
   // The vector can be populated using reserve() and emplace_back().
   WebVector() = default;
 
-#if defined(ARCH_CPU_64_BITS)
+#if defined(ARCH_CPU_64_BITS) || defined(__OpenBSD__)
   // Create a vector with |size| default-constructed elements. We define
   // a constructor with size_t otherwise we'd have a duplicate define.
   explicit WebVector(size_t size) : data_(size) {}
