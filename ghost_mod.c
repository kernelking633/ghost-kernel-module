#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void) {
    printk(KERN_INFO "Ghost LKM Loaded\n");
    return 0;
}

void cleanup_module(void) {
    printk(KERN_INFO "Ghost LKM Unloaded\n");
}

MODULE_LICENSE("GPL");
