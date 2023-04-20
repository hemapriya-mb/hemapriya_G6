// program that prompts the user to enter a sentence and prints the number of words in the sentence
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int words = 1;  
    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ' || sentence[i] == '\n') {
            words++;
        }
    }
    printf("The sentence has %d words.\n", words);

    return 0;
}
