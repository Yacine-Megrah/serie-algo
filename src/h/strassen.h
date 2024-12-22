#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 64

void add(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void strassen( ) {
    if (n == 1) {
        c[0][0] = a[0][0] * b[0][0];
        return;
    }

    int k = n / 2;
    
    // Split matrices into sub-matrices
    int a11[MAX_SIZE][MAX_SIZE], a12[MAX_SIZE][MAX_SIZE], a21[MAX_SIZE][MAX_SIZE], a22[MAX_SIZE][MAX_SIZE];
    int b11[MAX_SIZE][MAX_SIZE], b12[MAX_SIZE][MAX_SIZE], b21[MAX_SIZE][MAX_SIZE], b22[MAX_SIZE][MAX_SIZE];
    int m1[MAX_SIZE][MAX_SIZE], m2[MAX_SIZE][MAX_SIZE], m3[MAX_SIZE][MAX_SIZE], m4[MAX_SIZE][MAX_SIZE], m5[MAX_SIZE][MAX_SIZE], m6[MAX_SIZE][MAX_SIZE], m7[MAX_SIZE][MAX_SIZE];
    
    // Splitting matrices into 4 sub-matrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + k];
            a21[i][j] = a[i + k][j];
            a22[i][j] = a[i + k][j + k];
            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + k];
            b21[i][j] = b[i + k][j];
            b22[i][j] = b[i + k][j + k];
        }
    }
    
    // Computing P1 to P7
    int temp1[MAX_SIZE][MAX_SIZE], temp2[MAX_SIZE][MAX_SIZE];
    add(a11, a22, temp1, k);
    add(b11, b22, temp2, k);
    strassen(temp1, temp2, m1, k);
    
    add(a21, a22, temp1, k);
    strassen(temp1, b11, m2, k);
    
    subtract(b12, b22, temp2, k);
    strassen(a11, temp2, m3, k);
    
    subtract(b21, b11, temp2, k);
    strassen(a22, temp2, m4, k);
    
    add(a11, a12, temp1, k);
    strassen(temp1, b22, m5, k);
    
    subtract(a21, a11, temp1, k);
    add(b11, b12, temp2, k);
    strassen(temp1, temp2, m6, k);
    
    subtract(a12, a22, temp1, k);
    add(b21, b22, temp2, k);
    strassen(temp1, temp2, m7, k);
    
    // Combining the results to form the final matrix
    int c11[MAX_SIZE][MAX_SIZE], c12[MAX_SIZE][MAX_SIZE], c21[MAX_SIZE][MAX_SIZE], c22[MAX_SIZE][MAX_SIZE];
    
    add(m1, m4, c11, k);
    subtract(c11, m5, c11, k);
    add(c11, m7, c11, k);
    
    add(m3, m5, c12, k);
    
    add(m2, m4, c21, k);
    
    add(m1, m3, c22, k);
    subtract(c22, m2, c22, k);
    subtract(c22, m6, c22, k);
    
    // Combine sub-matrices into final matrix
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            c[i][j] = c11[i][j];
            c[i][j + k] = c12[i][j];
            c[i + k][j] = c21[i][j];
            c[i + k][j + k] = c22[i][j];
        }
    }
}
