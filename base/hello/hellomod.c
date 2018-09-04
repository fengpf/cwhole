
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

static int __init hellomod_init(void)
{
    printf("hhh");
    printk("Hello, World!\n");
    return 0;
}

static void __exit hellomod_exit(void)
{
    printk("Goodbye, World!\n");
}

module_init(hellomod_init);
module_exit(hellomod_exit);
