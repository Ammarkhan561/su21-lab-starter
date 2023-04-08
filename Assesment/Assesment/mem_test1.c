#include <stdio.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS<<3

typedef struct {
   unsigned long long double_word[NO_WORDS];
} arr_t __attribute__ ((aligned (SIZE_WORDS) ));

int test_check(arr_t *expected,arr_t *actual);

arr_t store_byte_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_byte_expected_data[8] =
       {    // double_word0         double_word1
          { 0x00000000000000EF, 0x0000000000000000 },
          { 0x000000000000BE00, 0x0000000000000000 },
          { 0x0000000000AD0000, 0x0000000000000000 },
          { 0x00000000DE000000, 0x0000000000000000 },
          { 0x000000EF00000000, 0x0000000000000000 },
          { 0x0000BE0000000000, 0x0000000000000000 },
          { 0x00AD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_expected_data[8] =
       {
          { 0x000000000000BEEF, 0x0000000000000000 },
          { 0x0000000000ADBE00, 0x0000000000000000 },
          { 0x00000000DEAD0000, 0x0000000000000000 },
          { 0x000000EFDE000000, 0x0000000000000000 },
          { 0x0000BEEF00000000, 0x0000000000000000 },
          { 0x00ADBE0000000000, 0x0000000000000000 },
          { 0xDEAD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x00000000000000EF }
       };


arr_t store_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_word_expected_data[8] =
       {
          { 0x00000000DEADBEEF, 0x0000000000000000 },
          { 0x000000DEADBEEF00, 0x0000000000000000 },
          { 0x0000DEADBEEF0000, 0x0000000000000000 },
          { 0x00DEADBEEF000000, 0x0000000000000000 },
          { 0xF00DC0DE00000000, 0x0000000000000000 },
          { 0x0DC0DE0000000000, 0x00000000000000F0 },
          { 0xC0DE000000000000, 0x000000000000F00D },
          { 0xDE00000000000000, 0x0000000000F00DC0 }
       };


arr_t store_double_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_double_word_expected_data[8] =
       {
          { 0xDEADBEEFF00DC0DE, 0x0000000000000000 },
          { 0xADBEEFF00DC0DE00, 0x00000000000000DE },
          { 0xBEEFF00DC0DE0000, 0x000000000000DEAD },
          { 0xEFF00DC0DE000000, 0x0000000000DEADBE },
          { 0xF00DC0DE00000000, 0x00000000DEADBEEF },
          { 0x0DC0DE0000000000, 0x000000DEADBEEFF0 },
          { 0xC0DE000000000000, 0x0000DEADBEEFF00D },
          { 0xDE00000000000000, 0x00DEADBEEFF00DC0 }
       };

int store_byte_test ( ) {

    // EF, BE, AD, DE, EF, BE, AD, DE
   unsigned long long array[] = { 0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE};

   //loop for storing the entries 
   int k = 0;
   for ( int i = 0; i < 8 ; i++){
      for (int j = 0; j < 2 ;j++){
         if ( j == 0 ){
            store_byte_data[i].double_word[j] = array[i] << (i*8);
         }
         if ( j == 1 & i != 0){
            store_byte_data[i].double_word[j] = (array[i] >> 64-(k*8));
            
         }
      }
      k++;
   }
   test_check (store_byte_expected_data,store_byte_data);
} // store_byte_test

int store_half_word_test ( ) {

   // BEEF, ADBE, DEAD, EFDE, BEEF, ADBE, DEAD, EFDE
   unsigned long long array[] = {0xBEEF, 0xADBE, 0xDEAD, 0xEFDE, 0xBEEF, 0xADBE, 0xDEAD, 0xEFDE};

   //loop for storing the entries 
   int k = 0;
   for ( int i = 0; i < 8 ; i++){
      for (int j = 0; j < 2 ;j++){
         if ( j == 0 ){
            store_half_word_data[i].double_word[j] = array[i] << (i*8);
         }
         if ( j == 1 & i != 0){
            store_half_word_data[i].double_word[j] = (array[i] >> 64-(k*8));
            
         }
      }
      k++;
   }
   test_check (store_half_word_expected_data,store_half_word_data);

} // store_half_word_test


int store_word_test ( ) {

   // DEADBEEF, F00DC0DE
   unsigned long long array[] = {0xDEADBEEF, 0xF00DC0DE};

   //loop for storing the entries 
   int k = 0;
   int x;

   for ( int i = 0; i < 8 ; i++){
         if ( i < 4 )
            x = 0;
         else
             x = 1;
      for (int j = 0; j < 2 ;j++){
         if ( j == 0 ){
            store_word_data[i].double_word[j] = array[x] << (i*8);
         }
         if ( j == 1 & i != 0){
            store_word_data[i].double_word[j] = (array[x] >> 64-(k*8));
            
         }
      }
      k++;
   }

   test_check (store_word_expected_data,store_word_data);

} // store_word_test

int store_double_word_test ( ) {

   unsigned long long int array[] = {0xDEADBEEFF00DC0DE};
   int k = 0;

   //loop for storing the entries 
   for ( int i = 0; i < 8 ; i++){
      for (int j = 0; j < 2 ;j++){
         if ( j == 0){
            store_double_word_data[i].double_word[j] = array[0] << (i*8);
         }
         if ( j == 1 & i != 0){
            store_double_word_data[i].double_word[j] = (array[0] >> 64-(k*8));
            
         }
      }
      k++;
   }
   test_check (store_double_word_expected_data,store_double_word_data);

} // store_double_word_test


int test_check(arr_t *expected,arr_t *actual){

 //Test condition
 int mismatches = 0;
 for (int i = 0; i < 8; i++) {
      for (int j = 0; j <= 1; j++){
         if (actual[i].double_word[j] == expected[i].double_word[j]){
            printf("Succesful: expected %016llx, got %016llx\n",expected[i].double_word[j], actual[i].double_word[j]);
         }
         if (actual[i].double_word[j] != expected[i].double_word[j]){
            printf("Mismatch at index %d Entry %d: expected %016llx, got %016llx\n", i,j, expected[i].double_word[j], actual[i].double_word[i]);
            mismatches++;}
      }
    }

    if (mismatches > 0) {
        printf("%d Mismatches found, Test Failed\n", mismatches);
        return 0;
    } else {
        printf("Test Passed\n");
        return 1;
    }
}


int main() {

   printf("\n\nTesting store_byte_test \n\n");
   store_byte_test ();
   printf("\n\nTesting store_half_word_test \n\n");
   store_half_word_test ();
   printf("\n\nTesting store_word_test \n\n");
   store_word_test();
   printf("\n\nTesting double_word_test \n\n");
   store_double_word_test ();
   return 0;
} // main
