.globl main
.data
prompt:     .asciiz  "Please enter a positive integer:  "
result1:    .asciiz  "The sum of the first "
result2:    .asciiz  " integers is "
newline:    .asciiz  "\n"
main:
    li      $s7,10
    move    $s0, $s7
    li      $s1, 0          ì
    li      $s2, 0          
for:
    blt     $s0, $s2, endf  
    add     $s1, $s1, $s2   
    add     $s2, $s2, 1     
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
    li      $v0, 4          
    la      $a0, newline
    syscall
    li      $v0, 4
    la      $a0, newline
    syscall
    li      $v0, 10         
    syscall
      