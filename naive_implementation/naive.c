#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define K 1500
#define M 2000

void fill_matrix(int num_rows, int num_columns, double matrix[num_rows][num_columns]) {
    srand(time(NULL));
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            matrix[i][j] = (double)(rand() % 9);
        }
    }
}

int main() {
    static double A[N][K];
    static double B[K][M];
    static double C[N][M];

    printf("filling matrix A\n");
    fill_matrix(N, K, A);
    printf("%f\n", A[22][22]);

    printf("filling matrix B\n");
    fill_matrix(K, M, B);

    printf("filling matrix C\n");
    fill_matrix(N, M, C);

    printf("calculating AxB\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < K; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return 0;
}
