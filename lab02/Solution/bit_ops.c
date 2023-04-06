#include <stdio.h>
#include "bit_ops.h"

/* Returns the Nth bit of X. Assumes 0 <= N <= 31. */
unsigned get_bit(unsigned x, unsigned n) {
    /* YOUR CODE HERE */
    // return (x >> n) & 1;
    unsigned y = ( 1 << n );//<< of 1 by n bits where the nth bit is 1  
    return (x & y) != 0; //taking and with the x if that nth bit is 1 return (true == 1)else 0
}

/* Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1 */
void set_bit(unsigned *x, unsigned n, unsigned v) {
    /* YOUR CODE HERE */
    unsigned y = ( v << n );//bit to be replaced with 
    unsigned z = (*x & ~(1 << n));//bit to be replaced
    *x = ( y | z) ;
}

/* Flips the Nth bit in X. Assumes 0 <= N <= 31.*/
void flip_bit(unsigned *x, unsigned n) {
    /* YOUR CODE HERE */
    unsigned y = ( 1 << n );
    *x = ( *x ^ y); // using xor ^ here with the bit to be fliped
}

