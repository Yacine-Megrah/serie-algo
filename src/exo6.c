#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void genererMat(int** M, int n, int m, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            M[i][j] = rand() % (k + 1);
        }
    }
}

double sqrt_bisection(double A, double epsilon) {
    double low = 0, high = A, mid;
    while (high - low > epsilon) {
        mid = (low + high) / 2;
        if (mid * mid > A) high = mid;
        else low = mid;
    }
    return (low + high) / 2;
}

double sqrt_newton(double A, double epsilon) {
    double x = A / 2.0;
    while (fabs(x * x - A) > epsilon) {
        x = 0.5 * (x + A / x);
    }
    return x;
}

int main() {
    srand(time(NULL));
    int n = 3, m = 3, k = 50;
    int** M = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) M[i] = malloc(m * sizeof(int));

    genererMat(M, n, m, k);

    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) free(M[i]);
    free(M);

    double A = 49.0, epsilon = 1e-6;
    printf("Square Root (Bisection): %.6f\n", sqrt_bisection(A, epsilon));
    printf("Square Root (Newton): %.6f\n", sqrt_newton(A, epsilon));
    printf("Square Root (Library): %.6f\n", sqrt(A));

    return 0;
}