.data
x:  .word 2
y:  .word 4
z:  .word 6
fooStr: .asciiz "p + q: "
newline:  .asciiz "\n"

.text
MAIN:  # Begin: Initialize x, y, and z integers
    la $t0, x
    lw $s0, 0($t0)        # Load x into $s0 (2)
    la $t0, y
    lw $s1, 0($t0)        # Load y into $s1 (4)
    la $t0, z
    lw $s2, 0($t0)        # Load z into $s2 (6)
    
    # Prepare to call foo(x, y, z)
    addu $a0, $zero, $s0    # Set $a0 as m for FOO  
    addu $a1, $zero, $s1    # Set $a1 as n for FOO  
    addu $a2, $zero, $s2    # Set $a2 as o for FOO
    jal FOO
    
    # Calculate final z value
    addu $t0, $s1, $s0
    addu $t0, $s2, $t0
    addu $t0, $t0, $v0
    
    # Print resulting integer z
    addu $a0, $zero, $t0
    li $v0, 1         
    syscall    
    j END
    
    
FOO:    # FOO: Prologue
    addi $sp, $sp, 24
    sw $ra, 20($sp)        # Save return address
    sw $a0, 16($sp)        # Save argument m
    sw $a1, 12($sp)        # Save argument n
    sw $a2, 8($sp)        # Save argument o
    sw $s1, 4($sp)        # Save y variable
    sw $s0, 0($sp)        # Save x variable
    
    # Prepare to call bar(m + o, n + o, m + n)
    addu $t0, $a0, $a2
    addu $t1, $a1, $a2
    addu $t2, $a0, $a1
    addu $a0, $zero, $t0
    addu $a1, $zero, $t1
    addu $a2, $zero, $t2
    jal BAR
    addu $s0, $zero, $v0    # Save result as p
    
    # Intermediate epilogue
    lw $a0, 16($sp)        # Restore m
    lw $a1, 12($sp)        # Restore n
    lw $a2, 8($sp)        # Restore o
    
    # Prepare to call bar(m - o, n - m, n + n)
    subu $t0, $a0, $a2
    subu $t1, $a1, $a0
    addu $t2, $a1, $a1
    addu $a0, $zero, $t0
    addu $a1, $zero, $t1
    addu $a2, $zero, $t2
    jal BAR
    addu $s1, $zero, $v0    # Save result as q

    # Print "p + q: {p + q}"
    la $a0, fooStr
    li $v0, 4
    syscall
    addu $v1, $s0, $s1
    addu $a0, $zero, $v1
    li $v0, 1         
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    # FOO: Epilogue
    lw $s1, 0($sp)        # Restore y variable
    lw $s0, 4($sp)        # Restore x variable
    lw $ra, 20($sp)        # Restore return address
    addi $sp, $sp, 24
    addu $v0, $zero, $v1    # Set return value
    jr $ra

BAR:    # BAR function
    subu $t0, $a1, $a0
    sllv $t0, $t0, $a2
    addu $v0, $zero, $t0
    jr $ra
    
END:  # End of program
