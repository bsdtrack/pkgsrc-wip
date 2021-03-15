$NetBSD$

--- src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.cc
@@ -124,7 +124,7 @@ const base::Feature kAutofillUpstreamAll
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
