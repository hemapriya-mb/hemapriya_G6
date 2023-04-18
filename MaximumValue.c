// program that prompts the user to enter a list of integers separated by commas and then finds the maximum value in the list.
 #include <stdio.h>
 int main() {
   int max = 0;
   char input[100];
   printf("Enter a list of integers separated by commas: ");
   scanf("%[^\n]", input);  
   for (int i = 0; input[i] != '\0'; i++) {
     int num = 0;
     while (input[i] >= '0' && input[i] <= '9') {
        num = num * 10 + (input[i] - '0');
        i++;
     }
     if (num > max) {
        max = num;
     }
  }
  printf("The maximum value in the list is: %d", max);
  return 0;
}
