.text
.arm
.global operacion

operacion:
cmp R0,#0
addeq R12,R1,R2
cmp R0, #1
subeq R12,R1,R2
cmp R0, #2
andeq R12,R1,R2
cmp R0, #3
orreq R12,R1,R2

mov R0,R12
mov pc,lr
