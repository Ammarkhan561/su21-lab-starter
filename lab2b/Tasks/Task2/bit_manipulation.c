#include<stdio.h>
static inline int odd_occuring(int arr[],int len){
	int num = 0;
	for ( int i = 0; i < len; i++){
		num = num ^ arr[i];
	}
	return num;	
}
int main(){
        
	int len;
	printf("Enter the length of the array: ");
	scanf("%d",&len);
	int arr[len];
	printf("Enter the array elements:\n");
	for (int i = 0; i < len; i++){
		scanf("%d",&arr[i]);
	}
	
	printf("The array is: ");
	for (int j = 0; j < len; j++){
		printf("%d ",arr[j]);
	}	
	printf("\nThe odd occuring element is %d ",odd_occuring(arr,len));
	return 0;
}
