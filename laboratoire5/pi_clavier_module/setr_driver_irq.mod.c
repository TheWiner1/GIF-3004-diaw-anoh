#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
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
__used
__attribute__((section("__versions"))) = {
	{ 0xcb0a126b, "module_layout" },
	{ 0x750f20c1, "class_unregister" },
	{ 0x9a1ce951, "device_destroy" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xfe990052, "gpio_free" },
	{ 0xda053c82, "__mutex_do_init" },
	{ 0x41bf7845, "__rt_mutex_init" },
	{ 0xd6b8e852, "request_threaded_irq" },
	{ 0x54c3ab6, "gpiod_to_irq" },
	{ 0x9647310, "gpiod_set_debounce" },
	{ 0x8205807c, "gpiod_direction_output_raw" },
	{ 0x50e453ab, "gpiod_direction_input" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xe83bf01d, "class_destroy" },
	{ 0x652b0cd9, "device_create" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xea6dd11b, "__class_create" },
	{ 0x90ecee87, "__register_chrdev" },
	{ 0xfaef0ed, "__tasklet_schedule" },
	{ 0xf4fa543b, "arm_copy_to_user" },
	{ 0x37a0cba, "kfree" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x7c32d0f0, "printk" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x140a52b, "_mutex_unlock" },
	{ 0x112a1d12, "_mutex_lock" },
	{ 0x573a7d4f, "gpiod_get_raw_value" },
	{ 0x22d04384, "gpiod_set_raw_value" },
	{ 0x16ee9571, "gpio_to_desc" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "39503D884140E209D791BA6");
