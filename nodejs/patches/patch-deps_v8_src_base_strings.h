$NetBSD$

stdarg.h is needed for va_list on at least NetBSD.

--- deps/v8/src/base/strings.h.orig	2022-02-08 12:37:48.000000000 +0000
+++ deps/v8/src/base/strings.h
@@ -8,6 +8,7 @@
 #include "src/base/base-export.h"
 #include "src/base/macros.h"
 #include "src/base/vector.h"
+#include <stdarg.h>
 
 namespace v8 {
 namespace base {
