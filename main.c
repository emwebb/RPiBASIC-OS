#include "timer.h"
#include "gpio.h"
#include "lcd.h"
#include "framebuffer.h"

extern void memPut32 ( unsigned int, unsigned int );
extern unsigned int memGet32 ( unsigned int );

extern void miniWait ( unsigned int );

struct lcdInfo lcd;

//-------------------------------------------------------------------------
int os_start ( void )
{
  create_framebuffer(640,480,32);
  register unsigned int x = 0;
  register unsigned int y = 0;
  register unsigned int** framebuffer = get_framebuffer();
  for(x = 0; x < 640; x++) {
    for(y = 0; y < 480; y++) {
      framebuffer[x * 480 + y] = 0xffffffff;
      timer_sleep(1000000);
    }
  }

  while(1)
  {

  }
  return(0);
}
