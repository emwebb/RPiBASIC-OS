#include "gpio.h"
#include "timer.h"

struct lcdInfo {
  unsigned int rs;
  unsigned int e;
  unsigned int db[4];
};

struct lcdInfo lcd_make(unsigned int rs,unsigned int e,unsigned int db[]);
void lcd_clear(struct lcdInfo* lcdinfo );
void lcd_write(struct lcdInfo* lcdinfo , char* message);
void lcd_cmd(struct lcdInfo* lcdinfo ,unsigned char data, unsigned int char_mode);
