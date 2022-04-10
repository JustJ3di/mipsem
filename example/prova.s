li $s2 , 0
li $s1 ,3
li $s3 ,0
for:
beq $s1,$s2 target
addi    $s2 , $s2 , 1
b    for
target:
mul $s3 , $s1 , $s2 