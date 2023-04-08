#include <stdio.h>
int mystrlen(char* str) {
    int count = 0;
    while (*str != '\0'){
        count = count + 1;
        str = str + 1;
    }
    return count;

}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    printf("Your string is of %d bytes",mystrlen(str));
    return 0;
}
