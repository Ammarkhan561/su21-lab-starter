#include<stdio.h>
void swap(int* x, int* y) {
   *x = *x + *y;
   *y = *x - *y;
   *x = *x - *y;
}

int main (){

   int a = 10;
   int b = 20;

   int *num1 = &a;
   int *num2 =&b;

   printf("Before swap a is %d and b is %d\n",a,b);
   swap(num1,num2);

   printf("After swap a is %d and b is %d\n",a,b);
   return 0;


}

