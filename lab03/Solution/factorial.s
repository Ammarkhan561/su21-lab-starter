.globl factorial

.data
n: .word 10

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1      #a0 = 1 syscall number for printing an integer
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11     #a0 = 11 syscall number for printing a character
    ecall # Print newline

    addi a0, x0, 10     #a0 = 10 syscall number for exiting the program.
    ecall # Exit

factorial:

    # Save registers
    addi sp, sp, -8
    sw ra, 4(sp)
    sw s0, 0(sp)

    # Initialize variables
    addi s0, x0, 1 # s0 = 1 (accumulator)
    addi t0, x0, 1 # t0 = 1 (loop counter)
    lw a0, n       # Load argument n into a0

    # Loop
    factorial_loop:
        beq t0, a0, factorial_end # If t0 == n, exit loop
        addi t0, t0, 1           # Increment loop counter
        mul s0, s0, t0           # Multiply accumulator by loop counter
        j factorial_loop

    # End of function
    factorial_end:
        
        #move the result to a0
        mv a0, s0 

        # Restore registers
        lw ra, 4(sp)
        lw s0, 0(sp)
        addi sp, sp, 8
        
        # Return result
        jr ra