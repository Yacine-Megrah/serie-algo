#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

long long sumN_iter(int n) {
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

long long sumN_direct(int n) {
    return (long long)n * (n + 1) / 2;
}

long long sumN2_iter(int n) {
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += (long long)i * i;
    }
    return sum;
}

long long sumN2_direct(int n) {
    return (long long)n * (n + 1) * (2 * n + 1) / 6;
}

long long sumN3_iter(int n) {
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += (long long)i * i * i;
    }
    return sum;
}

long long sumN3_direct(int n) {
    long long temp = (long long)n * (n + 1) / 2;
    return temp * temp;
}

void measureSums(FILE *fp, int tests) {
    srand(time(NULL));

    int test_numbers[tests];
    for(int i = 0; i < tests; i++) {
        test_numbers[i] = 1200 * i * 17 + (rand() % 100);
    }
    fprintf(fp, "n,sum_iter,sum_direct,sum2_iter,sum2_direct,sum3_iter,sum3_direct\n");
    
    for (int i = 0; i < tests; i++) {

        int n = test_numbers[i];
        double times[6];

        for(int i=0 ; i < 6; i++) {
            switch(i) {
                case 0:times[i] = time_mark(sumN_iter, n); break;
                case 1:times[i] = time_mark(sumN_direct, n); break;
                case 2:times[i] = time_mark(sumN2_iter, n); break;
                case 3:times[i] = time_mark(sumN2_direct, n); break;
                case 4:times[i] = time_mark(sumN3_iter, n); break;
                case 5:times[i] = time_mark(sumN3_direct, n); break;
            }
        }
        
        fprintf(fp, "%d,%f,%f,%f,%f,%f,%f\n", 
                n, times[0], times[1], times[2], times[3], times[4], times[5]);
        printf("n = %d completed\n", n);
    }
}

int main() {
    FILE *fp = fopen("./data/exo3.csv", "w");

    measureSums(fp, 10);
    fclose(fp);
    
    return 0;
}
