.globl main
.text
n: .word 10
result1:    .asciiz  "The sum of the first "
main:
li $s2 , 0
li $s1 ,10
    li $v0,1
    la $a0, n
    syscall 
li $v0,1
la $a0, $s1
syscall 
    li $v0,4
    la $a0,result1
syscall
li $v0, 5
syscall
move $s1, $v0
li $v0,1
la $a0, $s1
syscall 
li $s3 , 0
for:
    addi    $s2 , $s2 , 1
    bne $s2,$s1 for
    li      $v0, 10      
    syscall