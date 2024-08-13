$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/spinning_mutex.cc.orig	2024-08-06 19:52:09.816661100 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/spinning_mutex.cc
@@ -17,7 +17,16 @@
 #endif
 
 #if PA_CONFIG(HAS_LINUX_KERNEL)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
+#include <sys/time.h>
+#include <sys/futex.h>
+#elif defined(OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/thr.h>
+#include <sys/umtx.h>
+#else
 #include <linux/futex.h>
+#endif
 #include <sys/syscall.h>
 #include <unistd.h>
 
@@ -109,8 +118,19 @@ void SpinningMutex::FutexWait() {
   // |kLockedContended| anymore. Note that even without spurious wakeups, the
   // value of |state_| is not guaranteed when this returns, as another thread
   // may get the lock before we get to run.
+#if defined(OS_FREEBSD)
+  int err = _umtx_op(&state_, UMTX_OP_WAIT_UINT_PRIVATE,
+                    kLockedContended, nullptr, nullptr);
+#elif defined(OS_OPENBSD)
+  int err = futex(reinterpret_cast<volatile unsigned int *>(&state_), FUTEX_WAIT | FUTEX_PRIVATE_FLAG,
+                    kLockedContended, nullptr, nullptr);
+#elif defined(OS_NETBSD)
+  int err = syscall(SYS___futex, reinterpret_cast<int *>(&state_), FUTEX_WAIT | FUTEX_PRIVATE_FLAG,
+                     kLockedContended, nullptr, nullptr, 0, 0);
+#else
   int err = syscall(SYS_futex, &state_, FUTEX_WAIT | FUTEX_PRIVATE_FLAG,
                     kLockedContended, nullptr, nullptr, 0);
+#endif
 
   if (err) {
     // These are programming error, check them.
@@ -122,8 +142,19 @@ void SpinningMutex::FutexWait() {
 
 void SpinningMutex::FutexWake() {
   int saved_errno = errno;
+#if defined(OS_FREEBSD)
+  long retval = _umtx_op(&state_, UMTX_OP_WAKE_PRIVATE,
+                         1 /* wake up a single waiter */, nullptr, nullptr);
+#elif defined(OS_OPENBSD)
+  long retval = futex(reinterpret_cast<volatile unsigned int *>(&state_), FUTEX_WAKE | FUTEX_PRIVATE_FLAG,
+                        1 /* wake up a single waiter */, nullptr, nullptr);
+#elif defined(OS_NETBSD)
+  long retval = syscall(SYS___futex, reinterpret_cast<int *>(&state_), FUTEX_WAKE | FUTEX_PRIVATE_FLAG,
+                         1 /* wake up a single waiter */, nullptr, nullptr, 0, 0);
+#else
   long retval = syscall(SYS_futex, &state_, FUTEX_WAKE | FUTEX_PRIVATE_FLAG,
                         1 /* wake up a single waiter */, nullptr, nullptr, 0);
+#endif
   PA_CHECK(retval != -1);
   errno = saved_errno;
 }
