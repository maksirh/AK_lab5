#include <linux/module.h>
#include <linux/printk.h>
#include <linux/ktime.h>
#include <linux/slab.h>
#include "hello1.h"

void print_hello(int count)
{
    int i;
    ktime_t start, end;

    for (i = 0; i < count; i++) {
        start = ktime_get();
        pr_info("Hello, world!\n");
        end = ktime_get();
        pr_info("Print duration: %lld ns\n", ktime_to_ns(ktime_sub(end, start)));
    }
}

EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
    pr_info("hello1 module loaded\n");
    return 0;
}

static void __exit hello1_exit(void)
{
    pr_info("hello1 module unloaded\n");
}

module_init(hello1_init);
module_exit(hello1_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yorzh Maksym");
MODULE_DESCRIPTION("Hello2 module for calling hello1");
