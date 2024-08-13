$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc.orig	2024-08-06 19:52:14.885089600 +0000
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc
@@ -23,7 +23,7 @@
 #include "components/policy/core/common/management/management_service.h"
 #include "content/public/browser/browser_context.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/connectors/device_trust/attestation/browser/browser_attestation_service.h"
 #include "chrome/browser/enterprise/connectors/device_trust/attestation/browser/device_attester.h"
@@ -54,7 +54,7 @@ bool IsProfileManaged(Profile* profile) 
   return management_service && management_service->IsManaged();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 policy::CloudPolicyStore* GetUserCloudPolicyStore(Profile* profile) {
   policy::CloudPolicyManager* user_policy_manager =
       profile->GetCloudPolicyManager();
@@ -101,7 +101,7 @@ DeviceTrustServiceFactory::DeviceTrustSe
   DependsOn(DeviceTrustConnectorServiceFactory::GetInstance());
   DependsOn(policy::ManagementServiceFactory::GetInstance());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Depends on this service via the SignalsService having a dependency on it.
   DependsOn(enterprise_signals::SignalsAggregatorFactory::GetInstance());
   // Depends on this service via the ProfileAttester having a dependency on it
