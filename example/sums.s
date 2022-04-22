    .globl main
    .data
prompt:     .asciiz  "Please enter a positive integer:  "
result1:    .asciiz  "The sum of the first "
result2:    .asciiz  " integers is "
    .text
main:
    li      $v0, 4         
    la      $a0, prompt
    syscall
    li      $v0, 5         
    syscall
    move    $s0, $v0
    li      $s1, 0         
    li      $s2, 0          
for:
    blt     $s0, $s2, endf  
    add     $s1, $s1, $s2   
    addi     $s2, $s2, 1    
    b       for            
endf:
    li      $v0, 4         
    la      $a0, result1
    syscall
    li      $v0, 1          
    move    $a0, $s0
    syscall
    li      $v0, 4        
    la      $a0, result2
    syscall
    li      $v0, 1         
    move    $a0, $s1
    syscall
    li      $v0, 10       
    syscall
        