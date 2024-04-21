.data
prompt: .asciiz "Please enter a number: "
even_msg: .asciiz "Sum of even numbers is: "
odd_msg: .asciiz "Sum of odd numbers is: "
newline: .asciiz "\n"
indent: .asciiz "    "  # Add an indent

.text
.globl main

main:
    # Initialize even_sum and odd_sum to 0
    li $t0, 0  # even_sum
    li $t1, 0  # odd_sum

input_loop:
    # Prompt user for input
    li $v0, 4
    la $a0, prompt
    syscall

    # Read user input
    li $v0, 5
    syscall
    move $t2, $v0  # Store input in $t2

    # Check if input is 0
    beq $t2, $zero, print_sums

    # Check if input is even or odd
    srl $t3, $t2, 1  # Shift right by 1 (divide by 2)
    sll $t3, $t3, 1  # Shift left by 1 (multiply by 2)
    sub $t3, $t2, $t3  # Calculate input % 2

    beq $t3, $zero, add_even
    j add_odd

add_even:
    add $t0, $t0, $t2  # even_sum += input
    j input_loop

add_odd:
    add $t1, $t1, $t2  # odd_sum += input
    j input_loop

print_sums:
    # Print a blank line
    li $v0, 4
    la $a0, newline
    syscall

    # Print even_sum
    li $v0, 4
    la $a0, even_msg
    syscall
    move $a0, $t0
    li $v0, 1
    syscall

    # Print newline
    li $v0, 4
    la $a0, newline
    syscall

    # Print odd_sum
    li $v0, 4
    la $a0, odd_msg
    syscall
    move $a0, $t1
    li $v0, 1
    syscall

    # Print newline
    li $v0, 4
    la $a0, newline
    syscall

    # Exit program
    li $v0, 10
    syscall


