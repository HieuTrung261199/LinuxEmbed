#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0x6fbd61d8, "module_layout" },
	{ 0x702ae7b6, "misc_deregister" },
	{ 0xe8a65e6e, "misc_register" },
	{ 0xe97c4103, "ioremap" },
	{ 0x24d273d1, "add_timer" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0x75c1cf78, "gpiod_export" },
	{ 0x919e5361, "gpiod_direction_output_raw" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x5f754e5a, "memset" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x996d032a, "kmem_cache_alloc_trace" },
	{ 0x1f82d7eb, "kmalloc_caches" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x526c3a6c, "jiffies" },
	{ 0xe2621d8c, "gpiod_set_raw_value" },
	{ 0x1c2ddadb, "gpio_to_desc" },
	{ 0xc5850110, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");

