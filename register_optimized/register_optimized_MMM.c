#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1500
#define K 1500
#define M 1500
#define block_size 500
#define num_iterations 5

void fill_matrix(int num_rows, int num_columns, double matrix[num_rows][num_columns]) {
    srand(time(NULL));
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            matrix[i][j] = (double)(rand() % 9);
        }
    }
}

void multiply_matrix(int A_rows, int A_columns, int B_rows, int B_columns, double A[A_rows][A_columns], double B[B_rows][B_columns], double C[A_rows][B_columns]) {
    for (int i = 0; i < N; i+=block_size) {
        for (int j = 0; j < M; j+=block_size) {
            for (int k = 0; k < K; k+=block_size) {
                for (int i0 = i; i0 < (i + block_size); i0++) {
                    for (int j0 = j; j0 < (j + block_size); j0++) {
                        for (int k0 = k; k0 < (k + block_size); k0++) {
                            //Due to high manual labor I am not going to test manual loop unrolling.
                            for (int k00 = k0; k00 <= (k0 + KU); k00++) {
                                for (int j00 = j0; j00 <= (j0 + NU); j00++) {
                                    for (int i00 = i0; i00 <= (i0 + MU); i00++) {
                                        C[i00][j00] += A[i00][k00]*B[k00][j00];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    static double A[N][K];
    static double B[K][M];
    static double C[N][M];

    for (int i = 0; i < num_iterations; i++) {
        printf("filling matrix A\n");
        fill_matrix(N, K, A);

        printf("filling matrix B\n");
        fill_matrix(K, M, B);

        printf("filling matrix C\n");
        fill_matrix(N, M, C);

        printf("calculating AxB\n");
        multiply_matrix(N, K, K, M, A, B, C);
    }

    return 0;
}
