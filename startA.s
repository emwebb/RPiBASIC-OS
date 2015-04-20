.globl _start
_start:
    mov sp,#0x8000
    bl os_start


.globl memPut32
memPut32:
    str r1,[r0]
    bx lr

.globl memGet32
memGet32:
    ldr r0,[r0]
    bx lr

.globl miniWait
miniWait:
  bx lr
