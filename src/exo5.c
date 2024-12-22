#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genererTab(int* T, int n, int k) {
    for (int i = 0; i < n; i++) {
        T[i] = rand() % (k + 1);
    }
}

int rechercheSeq(int* T, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (T[i] == x) return 1;
    }
    return 0;
}

void Trier(int* T, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (T[j] > T[j + 1]) {
                int temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
        }
    }
}

int rechercheDicho(int* T, int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (T[mid] == x) return 1;
        if (T[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int gcd_subtraction(int a, int b) {
    if (a == b) return a;
    if (a > b) return gcd_subtraction(a - b, b);
    return gcd_subtraction(a, b - a);
}

int gcd_modulo(int a, int b) {
    if (b == 0) return a;
    return gcd_modulo(b, a % b);
}

int main() {
    srand(time(NULL));
    int n = 10, k = 100;
    int T[n];
    genererTab(T, n, k);

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", T[i]);
    printf("\n");

    Trier(T, n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", T[i]);
    printf("\n");

    int x = 50;
    printf("Sequential Search for %d: %s\n", x, rechercheSeq(T, n, x) ? "Found" : "Not Found");
    printf("Binary Search for %d: %s\n", x, rechercheDicho(T, n, x) ? "Found" : "Not Found");

    int a = 48, b = 18;
    printf("GCD (Subtraction): %d\n", gcd_subtraction(a, b));
    printf("GCD (Modulo): %d\n", gcd_modulo(a, b));

    return 0;
}