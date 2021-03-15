$NetBSD$

--- src/3rdparty/chromium/third_party/swiftshader/src/Common/Configurator.cpp.orig	2020-07-15 19:01:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/src/Common/Configurator.cpp
@@ -42,6 +42,9 @@ namespace sw
 
 	bool Configurator::readFile()
 	{
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+		return false;
+#endif
 		#if defined(__unix__)
 			if(access(path.c_str(), R_OK) != 0)
 			{
