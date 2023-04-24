// program that takes a sentence as input and prints each word in the sentence on a new line. 
#include <stdio.h>

int main() {
 char sentence[1000];
 int i;
 printf("Enter a sentence: ");
 scanf("%[^\n]",sentence);
 for (i = 0; sentence[i] != '\0'; i++) {
       if (sentence[i] == ' ') {
          printf("\n");
       }
       else {
          printf("%c", sentence[i]);
       }
  }
 
 return 0;
}
