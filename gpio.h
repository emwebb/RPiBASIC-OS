#define GPFSEL0 0x20200000
#define GPFSEL1 0x20200004
#define GPFSEL2 0x20200008
#define GPFSEL3 0x2020000C
#define GPFSEL4 0x20200010
#define GPFSEL5 0x20200014

#define GPSET0 0x2020001C
#define GPSET1 0x20200020

#define GPCLR0 0x20200028
#define GPCLR1 0x2020002C

#define GPLEV0 0x20200034
#define GPLEV1 0x20200028

#define GPEDS0 0x20200040
#define GPEDS1 0x20200044

#define GPREN0 0x2020004C
#define GPREN1 0x20200050

#define GPFEN0 0x20200058
#define GPFEN1 0x2020005C

#define GPHEN0 0x20200064
#define GPHEN1 0x20200068

#define GPLEN0 0x20200070
#define GPLEN1 0x20200074

#define GPAREN0 0x2020007C
#define GPAREN1 0x20200080

#define GPAFEN0 0x20200088
#define GPAFEN1 0x2020008C

#define GPPUD 0x20200094
#define GPPUDCLK0 0x20200098
#define GPPUDCLK1 0x2020009C

#define GPIO_PULL_UP 0X1
#define GPIO_PULL_DOWN 0X2

void gpio_setOutput(unsigned int gpioNum);
void gpio_setInput(unsigned int gpioNum, unsigned int pull);
unsigned int gpio_inputGet(unsigned int gpioNum);
void gpio_outputSet(unsigned int gpioNum);
void gpio_outputClr(unsigned int gpioNum);