#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int compare_suffixes(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void build_suffix_array(const char* text) {
    int n = strlen(text);
    char* suffixes[n];
    for (int i = 0; i < n; i++) {
        suffixes[i] = strdup(text + i);
    }

    qsort(suffixes, n, sizeof(char*), compare_suffixes);

    printf("Suffix Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", suffixes[i]);
        free(suffixes[i]);
    }
}

int main() {
    FILE* file = fopen("data.csv", "w");
    fprintf(file, "n,time\n");

    for (int n = 10; n <= 100; n += 10) {
        clock_t start = clock();
        // Code logic to measure time
        for (int i = 0; i < n; i++) {
            // Simulate some work
        }
        clock_t end = clock();
        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(file, "%d,%lf\n", n, elapsed);
    }

    fclose(file);

    const char* text = "banana";
    build_suffix_array(text);

    return 0;
}