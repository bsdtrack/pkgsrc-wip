$NetBSD$

--- libraries/source/fcollada/src/FCollada/FCDocument/FCDocument.h.orig	2012-06-04 21:33:15.000000000 +0000
+++ libraries/source/fcollada/src/FCollada/FCDocument/FCDocument.h
@@ -30,7 +30,7 @@
 #if defined(WIN32)
 template <class T> class FCOLLADA_EXPORT FCDLibrary; /**< Trick Doxygen. */
 template <class T> class FCOLLADA_EXPORT FUUniqueStringMapT; /**< Trick Doxygen. */
-#elif defined(LINUX) || defined(__APPLE__) || defined (__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#elif defined(LINUX) || defined(__APPLE__) || defined (__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
 template <class T> class FCDLibrary; /**< Trick Doxygen. */
 template <class T> class FUUniqueStringMapT; /**< Trick Doxygen. */
 #endif // LINUX
