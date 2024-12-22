#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isPrime1(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= n ; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int isPrime2(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int isPrime3(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

void test_times(FILE *fp, int tests) {
    srand(time(NULL));
    
    int test_numbers[tests];
    for(int i = 0; i < tests; i++) {
        test_numbers[i] = (rand() % 100000) + (100000 << i);
    }
    
    fprintf(fp, "n,method1,method2,method3\n");
    
    for (int i = 0; i < tests; i++) {
        int n = test_numbers[i];
        double times[3] = {0, 0, 0};
        
        for (int method = 0; method < 3; method++) {
            clock_t start = clock();
            
            switch(method) {
                case 0: isPrime1(n); break;
                case 1: isPrime2(n); break;
                case 2: isPrime3(n); break;
            }
            
            clock_t end = clock();
            times[method] = ((double)(end - start)) / CLOCKS_PER_SEC;
        }
        
        fprintf(fp, "%d,%f,%f,%f\n", n, times[0], times[1], times[2]);
        printf("n = %d completed\n", n);
    }
}

int main() {
    FILE *fp = fopen("./data/exo2.csv", "w");
    
    test_times(fp, 10);
    fclose(fp);
    
    return 0;
}
