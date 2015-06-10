#ifdef RPI2
#define MAILBOX_READ_ 0x3F00B880
#define MAILBOX_POLL 0x3F00B890
#define MAILBOX_SENDER 0x3F00B894
#define MAILBOX_STATUS 0x3F00B898
#define MAILBOX_CONFIG 0x3F00B89C
#define MAILBOX_WRITE 0x3F00B8A0
#else
#define MAILBOX_READ_ 0x2000B880
#define MAILBOX_POLL 0x2000B890
#define MAILBOX_SENDER 0x2000B894
#define MAILBOX_STATUS 0x2000B898
#define MAILBOX_CONFIG 0x2000B89C
#define MAILBOX_WRITE 0x2000B8A0
#endif

void mailbox_write(unsigned int data , unsigned int address);
unsigned int mailbox_read(unsigned int address);
