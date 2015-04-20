#include "lcd.h"
struct lcdInfo lcd_make(unsigned int rs,unsigned int e,unsigned int db[4]){
  struct lcdInfo lcdinfo;
  lcdinfo.rs = rs;
  lcdinfo.e = e;
  lcdinfo.db[0] = db[0];
  lcdinfo.db[1] = db[1];
  lcdinfo.db[2] = db[2];
  lcdinfo.db[3] = db[3];

  gpio_setOutput(lcdinfo.rs);
  gpio_setOutput(lcdinfo.e);
  gpio_setOutput(lcdinfo.db[0]);
  gpio_setOutput(lcdinfo.db[1]);
  gpio_setOutput(lcdinfo.db[2]);
  gpio_setOutput(lcdinfo.db[3]);

  lcd_clear(&lcdinfo);

  return lcdinfo;
}

void lcd_clear(struct lcdInfo* lcdinfo ) {
  lcd_cmd(lcdinfo,0x33,0);
  lcd_cmd(lcdinfo,0x32,0);
  lcd_cmd(lcdinfo,0x28,0);
  lcd_cmd(lcdinfo,0x0C,0);
  lcd_cmd(lcdinfo,0x06,0);
  lcd_cmd(lcdinfo,0x01,0);
}

void lcd_write(struct lcdInfo* lcdinfo , char* message) {

  unsigned int pos = 0;

  while(message[pos]) {
    if(message[pos] == '\n'){
      lcd_cmd(lcdinfo,0xC0,0);
    } else {
      lcd_cmd(lcdinfo,message[pos],1);
    }

    pos++;
  }

}

void lcd_cmd(struct lcdInfo* lcdinfo ,unsigned char data, unsigned int char_mode) {

  timer_sleep(100000);

  if(char_mode) {
    gpio_outputSet(lcdinfo->rs);
  } else {
    gpio_outputClr(lcdinfo->rs);
  }

  gpio_outputClr(lcdinfo->db[0]);
  gpio_outputClr(lcdinfo->db[1]);
  gpio_outputClr(lcdinfo->db[2]);
  gpio_outputClr(lcdinfo->db[3]);

  int n = 0;

  for(n = 0; n < 4; n++) {
    if(data & (0b1 << n)) {
      gpio_outputSet(lcdinfo->db[n]);
    }
  }
  timer_sleep(50000);
  gpio_outputSet(lcdinfo->e);
  timer_sleep(50000);
  gpio_outputClr(lcdinfo->e);
  timer_sleep(50000);

  gpio_outputClr(lcdinfo->db[0]);
  gpio_outputClr(lcdinfo->db[1]);
  gpio_outputClr(lcdinfo->db[2]);
  gpio_outputClr(lcdinfo->db[3]);

  for(n = 0; n < 4; n++) {
    if(data & (0b1 << (n + 4))) {
      gpio_outputSet(lcdinfo->db[n]);
    }
  }

  timer_sleep(50000);
  gpio_outputSet(lcdinfo->e);
  timer_sleep(50000);
  gpio_outputClr(lcdinfo->e);
  timer_sleep(50000);
}
