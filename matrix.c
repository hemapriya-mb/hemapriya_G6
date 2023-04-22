//program that reads in a matrix of integers and prints the sum of each row and column.
#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter the matrix values (separated by space):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int row_sum[n];
    for (int i = 0; i < n; i++) {
        row_sum[i] = 0;
        for (int j = 0; j < n; j++) {
            row_sum[i] += matrix[i][j];
        }
    }

    int col_sum[n];
    for (int j = 0; j < n; j++) {
        col_sum[j] = 0;
        for (int i = 0; i < n; i++) {
            col_sum[j] += matrix[i][j];
        }
    }

    printf("Sum of each row:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", row_sum[i]);
    }
    printf("\n");
    
    printf("Sum of each column:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", col_sum[j]);
    }
    printf("\n");

    return 0;
}
