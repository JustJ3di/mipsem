.globl main
.data
init: .asciiz "Benvenuto alla mia calcolatrice mips\n"
end: .asciiz "se vuoi uscire premi inserisci 1"
li $s0,0

while: 

    

    bne		$s0, $s1, while	
    