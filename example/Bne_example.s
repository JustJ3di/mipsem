.globl main
.text
li $s2 , 0
li $s1 ,10
li $s3 , 0
for:
    addi    $s2 , $s2 , 1
    bne $s2,$s1 for
mul $s3 , $s1 , $s2 