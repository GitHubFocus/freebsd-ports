--- cpp.orig/test/include/TestCommon.h	2011-06-15 21:43:59.000000000 +0200
+++ cpp/test/include/TestCommon.h	2012-03-04 20:14:53.000000000 +0100
@@ -17,6 +17,22 @@
 #include <stdlib.h>
 #endif
 
+#if defined(__FreeBSD__)
+#  include <sys/types.h>
+#  include <sys/sysctl.h>
+inline bool inFreeBSDJail()
+{
+    int jailed;
+    size_t size = sizeof(jailed);
+    return (sysctlbyname("security.jail.jailed", &jailed, &size, NULL, 0) != -1 || jailed);
+}
+#else
+inline bool inFreeBSDJail()
+{
+    return false;
+}
+#endif
+
 void
 inline testFailed(const char* expr, const char* file, unsigned int line)
 {
