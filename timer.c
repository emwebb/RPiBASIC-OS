#include "timer.h"
extern void miniWait ( unsigned int );
void timer_sleep(unsigned long time) {
  unsigned long* timeLower = TIMER_COUNTER_LOWER;
  unsigned long waitUntil = *timeLower + time;
  while(*timeLower < waitUntil) miniWait(0);
}
