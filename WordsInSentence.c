// program that prompts the user to enter a sentence and prints the number of words in the sentence
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int words = 0;  
    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ' || sentence[i] == '\n') {
            while (sentence[i+1] == ' ' || sentence[i+1] == '\n') {
                i++;
            }
        } else {
            if (i == 0 || sentence[i-1] == ' ' || sentence[i-1] == '\n') {
                words++;
            }
        }
    }
    printf("The sentence has %d words.\n", words);

    return 0;
}
