/* https://github.com/cirosantilli/linux-kernel-module-cheat#kernel-module-dependencies */

#include <linux/debugfs.h>
#include <linux/kernel.h>
#include <linux/module.h>

u32 buildroot_lkmc_dep = 0;
EXPORT_SYMBOL(buildroot_lkmc_dep);
static struct dentry *debugfs_file;

static int myinit(void)
{
	debugfs_file = debugfs_create_u32("buildroot_lkmc_dep", S_IRUSR | S_IWUSR, NULL, &buildroot_lkmc_dep);
	return 0;
}

static void myexit(void)
{
	debugfs_remove(debugfs_file);
}

module_init(myinit)
module_exit(myexit)
MODULE_LICENSE("GPL");
