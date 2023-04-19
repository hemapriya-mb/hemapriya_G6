//program that reads in a string from the user and determines whether or not it is a valid IPv4 address
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_IP_LEN 15

int main() {
    char ip[MAX_IP_LEN + 1];  
    int a, b, c, d;
    int num_fields;
    int is_valid = 1;
    printf("Enter an IPv4 address: ");
    scanf("%s", ip);
    num_fields = sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
    if (num_fields != 4) {
        is_valid = 0;
    }
    if (is_valid && (a < 0 || a > 255 || b < 0 || b > 255 ||
                     c < 0 || c > 255 || d < 0 || d > 255)) {
        is_valid = 0;
    }
    if (is_valid) {
        printf("%s is a valid IPv4 address.\n", ip);
    } else {
        printf("%s is not a valid IPv4 address.\n", ip);
    }
  
    return 0;
}
