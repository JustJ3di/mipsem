.globl main
.data
init: .asciiz "Benvenuto alla mia calcolatrice mips"
end: .asciiz "se vuoi uscire premi inserisci 0"
first: .asciiz "Primo operando."
second: .asciiz "Secondo operando. "
operator: .asciiz "operatore 1 = +, 2 = -, 3 = *, 4 = / "
resul: .asciiz "risultato = "
main:
    li      $s0 , 0
    li      $s1 , 1
    li      $t1 , 1 #valore temporaneo per +
    li      $t2 , 2 #valore temporaneo per -
    li      $t3 , 3 #valore temporaneo per *
    li      $t4 , 4 #valore temporaneo per /
    li      $v0 , 4         
    la      $a0 , init
    syscall 
while: #inizio ciclo delle istruzioni
    li      $v0, 4         
    la      $a0, first 
    syscall
    li      $v0, 5         
    syscall
    move    $s2, $v0
    li      $v0, 4         
    la      $a0, second
    syscall
    li      $v0, 5         
    syscall
    move    $s3, $v0
    li      $v0, 4         
    la      $a0, operator
    syscall
    li      $v0, 5         
    syscall
    move    $s4,$v0
    beq		$s4 , $t1 , sum	
    beq     $s4 , $t2 , sot
    beq     $s4 , $t3 , molt
    beq     $s4 , $t4 , divi
sum: #SOMMA
    add $s2 , $s3 , $s2
    b finish
sot: #DIFFERENZA
    sub $s2 , $s2 , $s3
    b finish
molt: #MOLTIPLICAZIONE
    mul $s2 , $s3 , $s2
    b finish
divi: #DIVISIONE
    div $s2 , $s2 , $s3
    b finish
finish: 
    li $v0,4
    la $a0,resul 
    syscall
    li $v0,1
    la $a0,$s2
    syscall
    li $v0 , 4
    la $a0 , end
    syscall
    li  $v0 , 5       
    syscall
    move $s1 , $v0
    bne $s0 , $s1 , while #JUMP ALL'INIZIO DELLE ISTRUZIONI
    li $v0 , 10
    syscall