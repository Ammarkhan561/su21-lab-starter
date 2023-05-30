#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src) {
    // YOUR CODE HERE
    int i, j, x, y;
    int block_row, block_col;

    for (block_row = 0; block_row < n; block_row += blocksize) {
        for (block_col = 0; block_col < n; block_col += blocksize) {
            // Iterate over the current block
            for (i = block_row; i < block_row + blocksize && i < n; i++) {
                for (j = block_col; j < block_col + blocksize && j < n; j++) {
                    // Compute the transpose indices
                    x = j;
                    y = i;
                    // Update the destination matrix
                    dst[y + x * n] = src[x + y * n];
                }
            }
        }
    }
}
