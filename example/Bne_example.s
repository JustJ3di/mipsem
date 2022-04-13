.globl main
.text
n: .word 10
li $s2 , 0
li $s1 ,10
li $v0,1
la $a0, $s1
syscall 
li $v0,1
la $a0, n
syscall 
li $s3 , 0
for:
    addi    $s2 , $s2 , 1
    bne $s2,$s1 for
    li      $v0, 10      
    syscall