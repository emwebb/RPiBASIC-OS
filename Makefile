ARMGNU ?= arm-none-eabi

COPS = -Wall -O2 -nostdlib -nostartfiles -ffreestanding

all : kernel.img

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.hex

startA.o : startA.s
	$(ARMGNU)-as startA.s -o startA.o

main.o : main.c
	$(ARMGNU)-gcc $(COPS) -c main.c -o main.o

timer.o : timer.c
	$(ARMGNU)-gcc $(COPS) -c timer.c -o timer.o

gpio.o : gpio.c
	$(ARMGNU)-gcc $(COPS) -c gpio.c -o gpio.o

lcd.o : lcd.c
	$(ARMGNU)-gcc $(COPS) -c lcd.c -o lcd.o

memory.o : memory.c
	$(ARMGNU)-gcc $(COPS) -c memory.c -o memory.o

kernel.img : memmap startA.o main.o timer.o gpio.o lcd.o memory.o
	$(ARMGNU)-ld startA.o main.o timer.o gpio.o lcd.o memory.o -T memmap -o kernal.elf
	$(ARMGNU)-objdump -D kernal.elf > kernal.list
	$(ARMGNU)-objcopy kernal.elf -O binary kernel.img
