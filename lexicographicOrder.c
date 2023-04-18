//program that takes a list of strings and sorts them in lexicographic order, ignoring case.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int character_compare(char a, char b) {
    if (a >= 'a' && a <= 'z') {
        a = 'A' + (a - 'a');
    }
    if (b >= 'a' && b <= 'z') {
        b = 'A' + (b - 'a');
    }
  
    return a - b;
}

int string_compare(char* s1, char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        int result = character_compare(s1[i], s2[i]);
        if (result != 0) {
          
            return result;
        }
        i++;
    }
  
    return character_compare(s1[i], s2[i]);
}

void swap_strings(char** list, int i, int j) {
    char* temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

int main() {
    printf("Enter the number of strings: ");
    int n;
    scanf("%d", &n);
    char** string_list = (char**) malloc(n * sizeof(char*));
    printf("Enter %d strings, one per line:\n", n);
    for (int i = 0; i < n; i++) {
        char buffer[100];
        scanf("%s", buffer);
        string_list[i] = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(string_list[i], buffer);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (string_compare(string_list[j], string_list[j+1]) > 0) {
                swap_strings(string_list, j, j+1);
            }
        }
    }
    printf("\nThe sorted list is:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", string_list[i]);
    }
    for (int i = 0; i < n; i++) {
        free(string_list[i]);
    }
    free(string_list);

    return 0;
}
