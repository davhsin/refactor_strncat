#include <linux/module.h>
#include <linux/init.h>
#include <linux/ktime.h>

#define REPEAT 100000

static int __init strncat_test_init(void)
{
	char dest[256];
	const char src[] = "abcdefghijklmnopqustuvwxyz0123456789";
	ktime_t start, end;
	int i;

	start = ktime_get();
	for (i = 0; i < REPEAT; ++i) {
		strcpy(dest, "begin");
		strncat(dest, src, 64);
	}
	end = ktime_get();
	printk(KERN_INFO "Old version took %lld ns\n", ktime_to_ns(ktime_sub(end, start)));
	return 0;
}

static void __exit strncat_test_exit(void) {}

module_init(strncat_test_init);
module_exit(strncat_test_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("David");
