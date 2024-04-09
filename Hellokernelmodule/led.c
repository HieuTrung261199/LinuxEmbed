#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/time.h>
#include <linux/io.h>
#include <linux/delay.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <linux/timer.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

#define GPIO_ADDR_BASE 0x44E07000
#define ADDR_SIZE (0x1000)
#define GPIO_SETDATAOUT_OFFSET 0x194
#define GPIO_CLEARDATAOUT_OFFSET 0x190
#define GPIO_OE_OFFSET 0x134
#define LED ~(1 << 31)
#define DATA_OUT (1 << 31)

void __iomem *base_addr; 
struct timer_list my_timer;

static void timer_function(struct timer_list *t)
{
    int i = 0;

    for (i = 10; i > 0; i--) {
        writel_relaxed(DATA_OUT, base_addr + GPIO_SETDATAOUT_OFFSET);
        msleep(1000);
        writel_relaxed(DATA_OUT, base_addr + GPIO_CLEARDATAOUT_OFFSET);
        msleep(1000);
    }
}

int init_module(void)
{
    uint32_t reg_data = 0;

    printk(KERN_INFO "Loading hello module...\n");
    printk(KERN_INFO "Hello world\n");

    base_addr = ioremap(GPIO_ADDR_BASE, ADDR_SIZE);// xin cấp phát 4 Kb để mapping từ vị trí bắt đầu đến kết thúc
    reg_data = readl_relaxed(base_addr + GPIO_OE_OFFSET);
    reg_data &= LED;
    writel_relaxed(reg_data, base_addr + GPIO_OE_OFFSET);

    timer_setup(&my_timer, timer_function, 0);
    add_timer(&my_timer);

    return 0;
}

void cleanup_module(void)
{
    del_timer_sync(&my_timer);
    printk(KERN_INFO "Goodbye Mr.\n");
}