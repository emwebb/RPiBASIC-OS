#include "mailbox.h"

void mailbox_write(unsigned int data , unsigned int address){
  if((data & 0b1111) != 0) return;
  if(address > 15) return;
  while(1) {
    if((*((unsigned int*)MAILBOX_STATUS) & 0x80000000) == 0) break;
  }
  *((unsigned int*)MAILBOX_WRITE) = data + address;

}
unsigned int mailbox_read(unsigned int address){
  if(address > 15) return 0;
  while(1) {
    while(1) {
      if((*((unsigned int*)MAILBOX_STATUS) & 0x40000000) == 0) break;
    }

    if((*((unsigned int*)MAILBOX_READ_) & 0b1111) == address) break;

  }

  return *((unsigned int*)MAILBOX_READ_);

}
