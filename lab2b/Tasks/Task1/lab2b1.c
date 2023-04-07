#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    int age;
    char name[20];
    int id;
} student;

int main() {
	student *s1;
	s1 = malloc( sizeof(student));
	
	strcpy(s1->name,"Ammar");
	s1->age = 23;
	s1->id  = 34;

    printf("Student Name: %s\n", s1->name);
    printf("Student Age: %d\n", s1->age);
    printf("Student ID: %d\n", s1->id);

	free(s1);
    return 0; 
}
