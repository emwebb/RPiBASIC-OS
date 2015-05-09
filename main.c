#include "timer.h"
#include "gpio.h"
#include "lcd.h"

extern void memPut32 ( unsigned int, unsigned int );
extern unsigned int memGet32 ( unsigned int );

extern void miniWait ( unsigned int );

struct lcdInfo lcd;

//-------------------------------------------------------------------------
int os_start ( void )
{

    timer_sleep(1000000);

    lcd.rs = 7;
    lcd.e = 8;
    lcd.db[0] = 25 ;
    lcd.db[1] = 24 ;
    lcd.db[2] = 23 ;
    lcd.db[3] = 18 ;

    //gpio_setOutput(lcd.db[0]);
    //gpio_outputSet(lcd.db[0]);


    gpio_setOutput(lcd.rs);
    gpio_setOutput(lcd.e);
    gpio_setOutput(lcd.db[0]);
    gpio_setOutput(lcd.db[1]);
    gpio_setOutput(lcd.db[2]);
    gpio_setOutput(lcd.db[3]);

  /*  gpio_outputSet(7);
    timer_sleep(1000000);
    gpio_outputSet(8);
    timer_sleep(1000000);
    gpio_outputSet(25);
    timer_sleep(1000000);
    gpio_outputSet(24);
    timer_sleep(1000000);
    gpio_outputSet(23);
    timer_sleep(1000000);
    gpio_outputSet(18);
    timer_sleep(1000000);*/

  //  gpio_outputSet(lcd.e);
    lcd_clear(&lcd);
    lcd_write(&lcd,&"Hello World!");





    while(1)
    {

    }
    return(0);
}
