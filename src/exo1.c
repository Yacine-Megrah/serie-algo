#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITERATIONS 4
int START_N = 1000;
int MAX_N = 1000 << 10;
int STEP_SHIFT = 1;
int STEP_INC = 0;

typedef struct args {
    int n;
} args_t;

void empty_loop(int n, args_t args) {
    for (int i = 0; i < n; i++) {
        continue;
    }
}

void time_mark(FILE *fp, void (*func)(int,args_t), args_t args) {
    fprintf(fp, "n,time\n");
    for (int n = START_N; n <= MAX_N; n = n << STEP_SHIFT + STEP_INC) {
        double total_time = 0;

        for (int iter = 0; iter < ITERATIONS; iter++) {
            clock_t start = clock();
            
            func(n, (args_t){n});
            
            clock_t end = clock();
            total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
        }
        
        double avg_time = total_time / ITERATIONS;
        
        printf("n = %d, Average time: %f seconds\n", n, avg_time);
        fprintf(fp, "%d,%f\n", n, avg_time);
    }
}

int main() {

    // 1. executer le programme
    empty_loop(10, (args_t){0});
    
    // 2. Create CSV file for timing analysis
    FILE *fp = fopen("./data/exo1.csv", "w");
    
    time_mark(fp, empty_loop, (args_t){0});
    
    fclose(fp);
    
    return 0;
}
