#include <stdio.h>

#define CSR_VAL 0x8000abcd00001234UL

#define ADDRESS 0x5300f000U

unsigned long int my_csr = CSR_VAL;

int main(void)

{

  printf("Before bit manipulation my_csr is : %lx\n",my_csr);

  //part (a) --> Make the first bit of my_csr equal to 1 (or high)
  unsigned long int updated_1st_bit = 0x0000000000000001UL;
  my_csr = my_csr | updated_1st_bit; //Bitwise or to make 1st bit to 1

  printf("\nPart a --> First bit to 1 \n");
  for ( int i = 63; i>=0; i--){
        unsigned long int bit = (my_csr >> i) & 1;
        printf("%lu", bit);
	}

  // (b) here --> Make the third bit (bit 2) equal to 0
  unsigned long int updated_3rd_bit = 0x0000000000000004UL;
  my_csr = my_csr ^ updated_3rd_bit; //xor to make 3rd bit to 0

  printf("\nPart b --> Third bit to zero\n");
  for ( int i = 63; i>=0; i--){
        unsigned long int bit = (my_csr >> i) & 1;
        printf("%lu", bit);
	}

  // (c) here --> make bits 8 to 15 equal to 0xee
  unsigned long int updated_8_15_bit = 0x000000000000fc00UL;
  my_csr = my_csr ^ updated_8_15_bit; //xor to make 8 to 15 bit to 0xee

  printf("\nPart c --> 8 to 15 bit equal to 0xee \n");
  for ( int i = 63; i>=0; i--){
        unsigned long int bit = (my_csr >> i) & 1;
        printf("%lu", bit);
	}

  // (d) here --> extract bits 12 to 27 of the given ADDRESS and store them in bits 16-31 of the my_csr
  unsigned int bits_extracted = (ADDRESS & 0x3fff000) >> 12;  
  
  printf("\nPart d --> Extracted bits are %x\n",bits_extracted);
  my_csr = ((bits_extracted << 16) | my_csr);

  printf("\nAfter bit manipulation my_csr is : %lx\n",my_csr);

	return 0;

}
