#ifdef RPI2
#define TIMER_CONTROL 0x3f003000
#define TIMER_COUNTER_LOWER 0x3f003004
#define TIMER_COUNTER_HIGHER 0x3f003008
#define TIMER_COMP_0 0x3f00300C
#define TIMER_COMP_1 0x3f003010
#define TIMER_COMP_2 0x3f003014
#define TIMER_COMP_3 0x3f003018
#else
#define TIMER_CONTROL 0X20003000
#define TIMER_COUNTER_LOWER 0X20003004
#define TIMER_COUNTER_HIGHER 0X20003008
#define TIMER_COMP_0 0X2000300C
#define TIMER_COMP_1 0X20003010
#define TIMER_COMP_2 0X20003014
#define TIMER_COMP_3 0X20003018
#endif


void timer_sleep(unsigned long time);
