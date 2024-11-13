#include <stdio.h>
#include <math.h>

#define N 4  // Size of the matrix (adjust as needed)

// Function to apply Givens rotation to zero out the a_ij element
void apply_givens_rotation(double a, double b, double *c, double *s) {
    if (b == 0) {
        *c = 1;
        *s = 0;
    } else {
        double r = hypot(a, b);
        *c = a / r;
        *s = -b / r;
    }
}

// Function to perform QR decomposition of an upper Hessenberg matrix
void qr_decomposition(double H[N][N], double Q[N][N], double R[N][N]) {
    // Initialize Q as the identity matrix and R as a copy of H
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Q[i][j] = (i == j) ? 1.0 : 0.0;
            R[i][j] = H[i][j];
        }
    }

    // Apply Givens rotations to zero out the subdiagonal elements
    for (int j = 0; j < N - 1; j++) {
        double c, s;
        apply_givens_rotation(R[j][j], R[j + 1][j], &c, &s);

        // Apply rotation to R
        for (int k = j; k < N; k++) {
            double temp = c * R[j][k] - s * R[j + 1][k];
            R[j + 1][k] = s * R[j][k] + c * R[j + 1][k];
            R[j][k] = temp;
        }

        // Apply rotation to Q
        for (int k = 0; k < N; k++) {
            double temp = c * Q[k][j] - s * Q[k][j + 1];
            Q[k][j + 1] = s * Q[k][j] + c * Q[k][j + 1];
            Q[k][j] = temp;
        }
    }
}

// Function to print a matrix
void print_matrix(double mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%10.5f ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double H[N][N] = {
        {4, 1, 2, 0},
        {3, 4, 1, 1},
        {0, 2, 3, 4},
        {0, 0, 1, 3}
    };

    double Q[N][N], R[N][N];
    qr_decomposition(H, Q, R);

    printf("Q matrix:\n");
    print_matrix(Q);
    printf("\nR matrix:\n");
    print_matrix(R);

    return 0;
}

