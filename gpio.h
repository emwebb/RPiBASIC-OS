#ifdef RPI2

#define GPFSEL0 0x3f200000
#define GPFSEL1 0x3f200004
#define GPFSEL2 0x3f200008
#define GPFSEL3 0x3f20000C
#define GPFSEL4 0x3f200010
#define GPFSEL5 0x3f200014

#define GPSET0 0x3f20001C
#define GPSET1 0x3f200020

#define GPCLR0 0x3f200028
#define GPCLR1 0x3f20002C

#define GPLEV0 0x3f200034
#define GPLEV1 0x3f200028

#define GPEDS0 0x3f200040
#define GPEDS1 0x3f200044

#define GPREN0 0x3f20004C
#define GPREN1 0x3f200050

#define GPFEN0 0x3f200058
#define GPFEN1 0x3f20005C

#define GPHEN0 0x3f200064
#define GPHEN1 0x3f200068

#define GPLEN0 0x3f200070
#define GPLEN1 0x3f200074

#define GPAREN0 0x3f20007C
#define GPAREN1 0x3f200080

#define GPAFEN0 0x3f200088
#define GPAFEN1 0x3f20008C

#define GPPUD 0x3f200094
#define GPPUDCLK0 0x3f200098
#define GPPUDCLK1 0x3f20009C

#else

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

#endif

#define GPIO_PULL_OFF 0X0
#define GPIO_PULL_UP 0X1
#define GPIO_PULL_DOWN 0X2


void gpio_setOutput(unsigned int gpioNum);
void gpio_setInput(unsigned int gpioNum);
void gpio_setPUD(unsigned int gpioNum,unsigned int pud);
unsigned int gpio_inputGet(unsigned int gpioNum);
void gpio_outputSet(unsigned int gpioNum);
void gpio_outputClr(unsigned int gpioNum);
