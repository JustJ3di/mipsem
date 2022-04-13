.globl main
.text
main:
    li  $s0 , 0
    li  $s2 , 10
    li  $s1 , 2
for:
    beq		$s2, $s0, endfor
    addi		$s0, $s0, 1
    b for
endfor:
li $v0,10
syscall