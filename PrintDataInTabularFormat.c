//Write a program that prompts the user to enter a string (e.g."1|Alice|25;2|Bob|30;3|Charlie|35") and then prints out the contents of the table in tabular format.
#include <stdio.h>
int main() {
 char input[100];
 printf("Enter a string \n");
 scanf("%[^\n]", input);
 printf("%s %s %s\n", "ID", "Name", "Age");
 int i = 0;
 while (input[i] != '\0') {
    int id = 0;
    while (input[i] != '|') {
       id = id * 10 + (input[i] - '0');
       i++;
    }
    i++; 
    char name[100];
    int j = 0;
    while (input[i] != '|') {
      name[j] = input[i];
      i++;
      j++;
    }
    i++; 
    int age = 0;
    while (input[i] != ';' && input[i] != '\0') {
       age = age * 10 + (input[i] - '0');
       i++;
     }
    printf("%d %s %d\n", id, name, age);
    if (input[i] == ';') {
       i++;
    }
 }
 return 0;
}
