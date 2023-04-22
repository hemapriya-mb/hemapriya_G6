/*program that asks the user to enter a list of names and ages separated by commas, and then prints out the names of all the people
who are older than a specified age.*/

#include <stdio.h>

int main() {
    char input[1000]; 
    char name[50], age_str[10];
    int age, min_age, i, j, name_len, age_len;
    printf("Enter names and ages separated by commas: ");
    fgets(input, 1000, stdin);
    printf("Enter the minimum age to filter by: ");
    scanf("%d", &min_age);
    i = 0;
    while (input[i] != '\0') {
        j = 0;
        while (input[i] != ',' && input[i] != '\n') {
            name[j] = input[i];
            i++;
            j++;
        }
        name[j] = '\0';
        i++;
        
        while (input[i] == ' ' || input[i] == '\t') {
            i++;
        }
        
        j = 0;
        while (input[i] >= '0' && input[i] <= '9') {
            age_str[j] = input[i];
            i++;
            j++;
        }
        age_str[j] = '\0';
        age = atoi(age_str);

        if (age >= min_age) {
            printf("%s\n", name);
        }
        
        while (input[i] != ',' && input[i] != '\n' && input[i] != '\0') {
            i++;
        }

        if (input[i] == ',') {
            i++;
                while (input[i] == ' ' || input[i] == '\t') {
                     i++;
                }
        }
    }

    return 0;
}
