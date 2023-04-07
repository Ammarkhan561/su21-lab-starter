#include <stdio.h>
static inline int cube ( int num ) {
	return ( num * num *num );
}

int main (){

	int num;
	printf("Enter the num: ");
	scanf("%d",&num);
	int i = cube (num);
	printf("The Cube of the %d is %d",num,i);

return 0;

}
