#include "framebuffer.h"

unsigned int framebuffer_info[10] __attribute__((aligned(16)));

void create_framebuffer(unsigned int width, unsigned int height , unsigned int colour_depth){
  if(width > 4096) return;
  if(height > 4096) return;
  if(colour_depth > 32) return;
  framebuffer_info[0] = width;
  framebuffer_info[1] = height;
  framebuffer_info[2] = width;
  framebuffer_info[3] = height;
  framebuffer_info[4] = 0;
  framebuffer_info[5] = colour_depth;
  framebuffer_info[6] = 0;
  framebuffer_info[7] = 0;
  framebuffer_info[8] = 0;
  framebuffer_info[9] = 0;

  mailbox_write((unsigned int)&framebuffer_info,1);

}
int** get_framebuffer() {
  return &framebuffer_info;
}
