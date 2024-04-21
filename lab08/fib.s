.data
prompt: .asciiz "Please enter a number: "
n: .word 0

.text
main:
    # Print the prompt message
    li $v0, 4
    la $a0, prompt
    syscall
    
    # Read an integer from the user
    li $v0, 5
    syscall
    move $t3, $v0  # Store user input in $t3

    # Initialize $t0 and $t1 for the Fibonacci sequence
    add $t0, $0, $zero
    addi $t1, $zero, 1

    # Calculate the nth Fibonacci number
fib:
    beq $t3, $0, finish
    add $t2, $t1, $t0
    move $t0, $t1
    move $t1, $t2
    subi $t3, $t3, 1
    j fib

finish:
    # Print the result
    add $a0, $t0, $zero
    li $v0, 1
    syscall

    # Exit the program
    li $v0, 10
    syscall		

