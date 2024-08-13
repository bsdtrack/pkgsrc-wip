$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/files/file_path_watcher_kqueue.h.orig	2024-08-06 19:52:09.896668000 +0000
+++ base/files/file_path_watcher_kqueue.h
@@ -5,6 +5,7 @@
 #ifndef BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 #define BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 
+#include <sys/time.h>
 #include <sys/event.h>
 
 #include <memory>
