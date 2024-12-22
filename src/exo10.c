#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main() {
    printf("Running comparative benchmarks:\n");

    printf("C Implementation:\n");
    clock_t start_c = clock();
    for (volatile int i = 0; i < 100000000; i++);  // Simulate work
    clock_t end_c = clock();
    printf("C Time: %.6f seconds\n", (double)(end_c - start_c) / CLOCKS_PER_SEC);

    printf("Python and Java equivalents should be run separately and logged for comparison.\n");

    int n = 3;
    hanoi(n, 'A', 'C', 'B');

    return 0;
}