#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void measureSorting(int* T, int n) {
    clock_t start, end;
    start = clock();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (T[j] > T[j + 1]) {
                int temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
        }
    }
    end = clock();
    printf("Sorting time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void measureSearch(int* T, int n, int x) {
    clock_t start, end;
    start = clock();
    for (int i = 0; i < n; i++) {
        if (T[i] == x) break;
    }
    end = clock();
    printf("Search time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

#define N 8

bool is_safe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]) return false;
    return true;
}

bool solve_nqueens(int board[N][N], int col) {
    if (col >= N) return true;
    for (int i = 0; i < N; i++) {
        if (is_safe(board, i, col)) {
            board[i][col] = 1;
            if (solve_nqueens(board, col + 1)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int n = 1000, k = 100;
    int* T = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) T[i] = rand() % (k + 1);

    measureSorting(T, n);
    measureSearch(T, n, 50);

    free(T);

    int board[N][N] = {0};
    if (solve_nqueens(board, 0)) print_board(board);
    else printf("Solution does not exist\n");

    return 0;
}