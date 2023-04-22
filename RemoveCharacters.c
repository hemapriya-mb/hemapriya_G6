//program that removes all characters from a given string that are also in a second string
#include <stdio.h>
#include <string.h>

int main() {
  char string1[100];
  char string2[100];
  int i, j, k;

  printf("Enter first string: ");
  scanf("%s", string1);

  printf("Enter second string: ");
  scanf("%s", string2);

  for (i = 0; i < strlen(string2); i++) {
    for (j = 0; j < strlen(string1); j++) {
      if (string2[i] == string1[j]) {
        for (k = j; k < strlen(string1); k++) {
          string1[k] = string1[k + 1];
        }
        j--;
      }
    }
  }

  printf("Result: %s\n", string1);

  return 0;
}
