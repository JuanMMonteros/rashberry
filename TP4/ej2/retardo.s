.text
.arm
.global retardo

retardo:
while:
subs r0,r0,#1
cmp r0,#0
bne while
mov   pc, lr
