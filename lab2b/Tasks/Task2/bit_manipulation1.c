#include<stdio.h>
static inline int odd_occuring(int arr[],int len){
	int num = 0;
	for ( int i = 0; i < len; i++){
		num = num ^ arr[i];
	}
	return num;	
}
int main(){

	int arr[7] = {12, 12, 14, 90, 14, 14, 14};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("Aray length: %d \n",len);	
	printf("The odd occuring element is %d ",odd_occuring(arr,len));
	return 0;
}
