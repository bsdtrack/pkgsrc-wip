$NetBSD$

--- src/3rdparty/chromium/base/trace_event/process_memory_dump.h.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/trace_event/process_memory_dump.h
@@ -22,7 +22,7 @@
 
 // Define COUNT_RESIDENT_BYTES_SUPPORTED if platform supports counting of the
 // resident memory.
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
 #define COUNT_RESIDENT_BYTES_SUPPORTED
 #endif
 
