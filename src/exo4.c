#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./h/strassen.h"

// 1. Function to generate an array of n integers between 0 and k
void genererTab(int T[], int n, int k) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        T[i] = rand() % (k + 1);
    }
}

// 2. Function to perform sequential search
int rechercheSeq(int T[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (T[i] == x) {
            return 1;
        }
    }
    return 0;
}

// 3. Function to sort the array
void Trier(int T[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (T[i] > T[j]) {
                int temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
}

// 4. Function to perform binary search
int rechercheDicho(int T[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (T[mid] == x) {
            return 1;
        }
        if (T[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

// 6. Function to generate a matrix of (n x m) integers between 0 and k
void genererMat(int M[][MAX_SIZE], int n, int m, int k) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            M[i][j] = rand() % (k + 1);
        }
    }
}

// 7. Function to multiply matrices using the usual method
void multiplicationUsuelle(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 7. Function to multiply matrices using Strassen's method
// Note: Strassen's method is complex and requires additional helper functions
// For simplicity, this is a placeholder function
void multiplicationStrassen(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int n) {
    
}

typedef struct time_mark_args{
    int A[MAX_SIZE][MAX_SIZE];
}

double time_mark(long long (*func)(int), int n) {
    double total_time = 0;

    for (int iter = 0; iter < 4; iter++) {
        clock_t start = clock();
        
        func(n);
        
        clock_t end = clock();
        total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    
    double avg_time = total_time / 4;
    return avg_time;
}

int main() {
    int n = 10, k = 50;
    int T[10];
    genererTab(T, n, k);

    printf("Generated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");

    int x = 25;
    printf("Sequential search for %d: %d\n", x, rechercheSeq(T, n, x));

    Trier(T, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");

    printf("Binary search for %d: %d\n", x, rechercheDicho(T, n, x));

    int M[MAX_SIZE][MAX_SIZE];
    int rows = 5, cols = 5;
    genererMat(M, rows, cols, k);

    printf("Generated matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    genererMat(A, rows, cols, k);
    genererMat(B, cols, rows, k);
    multiplicationUsuelle(A, B, C, rows, cols, rows);

    printf("Result of usual matrix multiplication:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}