#include <stdio.h>
#include "elog.h"
 
int main()
{
	elog_panic(E_TAG(test_tag)"<hello %s", "world");
	elog_error(E_TAG(tag1) E_KV(key, %d) "hello %s", 123, "world");
	elog_warn(E_KV(str, "%s") "hello %s", "elog", "world");
	elog_notice("hello %s"E_KV(test, 123456), "world");
	elog_info(E_TAG(tag1) "hello %s" E_KV(key, "--"),  "world");
	elog_debug("hello %s", "world");
	elog_trace("hello %s", "world");
	return 0;
}
