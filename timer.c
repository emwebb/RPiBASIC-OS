#include "timer.h"
extern void miniWait ( unsigned int );
void timer_sleep(unsigned int time) {
  unsigned int* timeLower = TIMER_COUNTER_LOWER;
  unsigned int waitUntil = *timeLower + time;
  while(*timeLower < waitUntil) miniWait(0);
}
