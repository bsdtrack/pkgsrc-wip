$NetBSD$

--- common/rfb/util.h.orig	2020-09-08 12:16:08.000000000 +0000
+++ common/rfb/util.h
@@ -31,7 +31,7 @@
 #include <limits.h>
 #include <string.h>
 
-struct timeval;
+#include <sys/time.h>
 
 #ifdef __GNUC__
 #  define __printf_attr(a, b) __attribute__((__format__ (__printf__, a, b)))
