// program that takes a string of integers separated by commas as input and enclosed by braces and then prints each integer on a new line.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter a string of integers enclosed by braces: ");
    scanf("%[^\n]", input);
    
    if (input[0] != '{') {
        printf("Error: Input string must start with '{'\n");
        exit(1);
    }
    
    int i = 1;
    while (input[i] != '}') {
        if (!isdigit(input[i]) && input[i] != ',' && input[i] != '-') {
            printf("Error: Invalid character '%c'\n", input[i]);
            exit(1);
        }
        
        int sign = 1;
        if (input[i] == '-') {
            sign = -1;
            i++;
        }
        
        int num = 0;
        while (isdigit(input[i])) {
            num = num * 10 + (input[i] - '0');
            i++;
        }
        printf("%d\n", sign * num);
        
        if (input[i] != ',' && input[i] != '}') {
            printf("Error: Expected ',' or '}' after integer\n");
            exit(1);
        }
        
        if (input[i] == ',') {
            i++;
        }
    }
    
    if (input[i] != '}') {
        printf("Error: Input string must end with '}'\n");
        exit(1);
    }

    return 0;
}
