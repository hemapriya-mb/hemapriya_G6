// program that prompts the user to enter a list of integers separated by commas and then finds the maximum value in the list.
#include <stdlib.h> 

int main() {
   int max = -2147483648; 
   char input[100];
   printf("Enter a list of integers separated by commas: ");
   scanf("%[^\n]", input);  
   for (int i = 0; input[i] != '\0'; i++) {
     int num = 0;
     int sign = 1; // 
     if (input[i] == '-') { 
        sign = -1; 
        i++; 
     }
     while (input[i] >= '0' && input[i] <= '9') {
        num = num * 10 + (input[i] - '0');
        i++;
     }
     num *= sign; 
     if (num > max) {
        max = num;
     }
  }
  printf("The maximum value in the list is: %d", max);
 
  return 0;
}
