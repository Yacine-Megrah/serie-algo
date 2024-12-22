#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void standardMultiplication(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Strassen's multiplication implementation is skipped for simplicity

void naive_pattern_matching(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == m) printf("Pattern found at index %d\n", i);
    }
}

int main() {
    srand(time(NULL));
    int n = 2;
    int** A = malloc(n * sizeof(int*));
    int** B = malloc(n * sizeof(int*));
    int** C = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(int));
        B[i] = malloc(n * sizeof(int));
        C[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    standardMultiplication(A, B, C, n);

    printf("Resultant Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    const char* text = "abracadabra";
    const char* pattern = "cad";
    naive_pattern_matching(text, pattern);

    return 0;
}