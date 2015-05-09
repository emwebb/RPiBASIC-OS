#include "gpio.h"

void gpio_setOutput(unsigned int gpioNum) {
  //Check if the value is valid
  if(gpioNum > 53) {
    return;
  }

  //The pointer to the section of memory that contains the function selector
  unsigned int* gpio_FunctionPointer = 0;

  //Figure out which 4 bytes of memory is the correct one for the gpioNum
  if(gpioNum < 10) {
    gpio_FunctionPointer = GPFSEL0;
  } else if(gpioNum < 20) {
    gpio_FunctionPointer = GPFSEL1;
  } else if(gpioNum < 30) {
    gpio_FunctionPointer = GPFSEL2;
  } else if(gpioNum < 40) {
    gpio_FunctionPointer = GPFSEL3;
  } else if(gpioNum < 50) {
    gpio_FunctionPointer = GPFSEL4;
  } else if(gpioNum < 60) {
    gpio_FunctionPointer = GPFSEL5;
  } else {
    return;
  }

  //Get the exact location of the 3 bits for the particular gpioNum
  unsigned int memPart = (gpioNum%10)*3;
  //Get the 4 bytes of memory at the function memory
  unsigned int bytes = *gpio_FunctionPointer;
  //Calaculate the 4 bytes to clear the current function setting of gpioNum
  unsigned int clearFlag = (0b111 << memPart);
  //calculate the 4 bytes in order to set the function to output for gpioNum
  unsigned int outputFlag = (0xFFFFFFF9 << memPart) | (0xFFFFFFF9 >> (32 - memPart));
  //Clear the function
  bytes = bytes | clearFlag;
  //Set the function
  bytes = bytes & outputFlag;
  //Put the 4 bytes back
  *gpio_FunctionPointer = bytes;

}
void gpio_outputSet(unsigned int gpioNum) {
  //Check if the value is valid
  if(gpioNum > 53) {
    return;
  }
  unsigned int* gpio_SetPointer = 0;
  unsigned int memPart = 0;

  //Figure out which part of the memory relates to gpioNum
  if(gpioNum < 32) {
    gpio_SetPointer = GPSET0;
    memPart = gpioNum;
  } else {
    gpio_SetPointer = GPSET1;
    memPart = gpioNum - 32;
  }
  //Get the relivant bytes
  unsigned int bytes = *gpio_SetPointer;
  //Calculate the flag for the specific gpioNum
  unsigned int setFlag = 0b1 << memPart;

  //Set the relevnat memory.
  *gpio_SetPointer = setFlag;



}
void gpio_outputClr(unsigned int gpioNum) {
  //Check if the value is valid
  if(gpioNum > 53) {
    return;
  }
  unsigned int* gpio_SetPointer = 0;
  unsigned int memPart = 0;

  //Figure out which part of the memory relates to gpioNum
  if(gpioNum < 32) {
    gpio_SetPointer = GPCLR0;
    memPart = gpioNum;
  } else {
    gpio_SetPointer = GPCLR1;
    memPart = gpioNum - 32;
  }
  //Get the relivant bytes
  unsigned int bytes = *gpio_SetPointer;
  //Calculate the flag for the specific gpioNum
  unsigned int setFlag = 0b1 << memPart;

  //Set the relevnat memory.
  *gpio_SetPointer = setFlag;

}


void gpio_setInput(unsigned int gpioNum, unsigned int pull) {

  if(gpioNum > 53) {
    return;
  }

  //The pointer to the section of memory that contains the function selector
  unsigned int* gpio_FunctionPointer = 0;

  //Figure out which 4 bytes of memory is the correct one for the gpioNum
  if(gpioNum < 10) {
    gpio_FunctionPointer = GPFSEL0;
  } else if(gpioNum < 20) {
    gpio_FunctionPointer = GPFSEL1;
  } else if(gpioNum < 30) {
    gpio_FunctionPointer = GPFSEL2;
  } else if(gpioNum < 40) {
    gpio_FunctionPointer = GPFSEL3;
  } else if(gpioNum < 50) {
    gpio_FunctionPointer = GPFSEL4;
  } else if(gpioNum < 60) {
    gpio_FunctionPointer = GPFSEL5;
  } else {
    return;
  }

  //Get the exact location of the 3 bits for the particular gpioNum
  unsigned int memPart = (gpioNum%10)*3;
  //Get the 4 bytes of memory at the function memory
  unsigned int bytes = *gpio_FunctionPointer;
  //Calaculate the 4 bytes to clear the current function setting of gpioNum
  unsigned int clearFlag = (0b111 << memPart);
  //calculate the 4 bytes in order to set the function to input for gpioNum
  unsigned int outputFlag = (0xFFFFFFF8 << memPart) | (0xFFFFFFF8 >> (32 - memPart));
  //Clear the function
  bytes = bytes | clearFlag;
  //Set the function
  bytes = bytes & outputFlag;
  //Put the 4 bytes back
  *gpio_FunctionPointer = bytes;

}

unsigned int gpio_inputGet(unsigned int gpioNum) {
  //Check if the value is valid
  if(gpioNum > 53) {
    return;
  }
  unsigned int* gpio_SetPointer = 0;
  unsigned int memPart = 0;

  //Figure out which part of the memory relates to gpioNum
  if(gpioNum < 32) {
    gpio_SetPointer = GPLEV0;
    memPart = gpioNum;
  } else {
    gpio_SetPointer = GPLEV1;
    memPart = gpioNum - 32;
  }
  //Get the relivant bytes
  unsigned int bytes = *gpio_SetPointer;
  //Calculate the flag for the specific gpioNum
  unsigned int setFlag = 0b1 << (memPart +0);

  //Remove the other values
  //bytes = bytes & setFlag;

  return bytes;

}
