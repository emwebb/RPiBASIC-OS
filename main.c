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

    lcd.rs = 4;
    lcd.e = 9;
    lcd.db[0] = 24 ;
    lcd.db[1] = 25 ;
    lcd.db[2] = 8 ;
    lcd.db[3] = 7 ;

    gpio_setOutput(lcd.db[0]);
    //gpio_outputSet(lcd.db[0]);

/*
    gpio_setOutput(lcd.rs);
    gpio_setOutput(lcd.e);
    gpio_setOutput(lcd.db[0]);
    gpio_setOutput(lcd.db[1]);
    gpio_setOutput(lcd.db[2]);
    gpio_setOutput(lcd.db[3]);

  //  gpio_outputSet(lcd.e);
    lcd_clear(&lcd);
    lcd_write(&lcd,&"Hello World!");*/





    while(1)
    {

    }
    return(0);
}
