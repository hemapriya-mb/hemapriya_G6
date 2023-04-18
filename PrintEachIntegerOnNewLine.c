// program that takes a string of integers separated by commas as input and enclosed by braces and then prints each integer on a new line.
#include <stdio.h>
int main() {
    char input[100];
    printf("Enter a string of integers enclosed by braces: ");
    scanf("%[^\n]", input);
    int i = 0;
    while (input[i] != '{') {
        i++;
    }
    i++; 
    while (input[i] != '}') {
        int num = 0;
        while (input[i] != ',' && input[i] != '}') {
            num = num * 10 + (input[i] - '0');
            i++;
        }
        printf("%d\n", num);
        i++;
    }
    return 0;
}
