$NetBSD$

--- src/3rdparty/chromium/components/autofill/core/browser/autofill_external_delegate.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/browser/autofill_external_delegate.cc
@@ -122,7 +122,7 @@ void AutofillExternalDelegate::OnSuggest
     // Append the "Hide Suggestions" menu item for only Autofill Address and
     // Autocomplete popups.
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kAutofillEnableHideSuggestionsUI)) {
     // If the user has selected a suggestion, it indicates the suggestions are
