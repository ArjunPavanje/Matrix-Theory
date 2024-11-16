#include <stdio.h>
#include <math.h>
#include <complex.h>
double complex** givens_rotation(int i, int j, int m, int n, double complex** matrix, double complex** Q, double complex** R);
double complex** givens_rotation(int i, int j, int m, int n, double complex** matrix, double complex** Q, double complex** R){
    double complex** G=eye(n);
    //printf("Matrix:\n");
    //print_matrix(n, n, matrix);
    double r=sqrt(pow(cabs(matrix[i][i]),2) + pow(cabs(matrix[j][i]),2) );
    /*double complex c=conj(matrix[i][i])/r;
    double complex s=conj(matrix[i+1][i])/r;
    G[i][i]=c;
    G[j][j]=conj(c);
    G[j][i]=-conj(s);
    G[i][j]=s;*/
    double complex c=conj(matrix[i][i])/r;
    double complex s=conj(matrix[i+1][i])/r;
    G[i][i]=c;
    G[j][j]=conj(c);
    G[j][i]=-conj(s);
    G[i][j]=s;
    //printf("1->%lf +%lfj", creal(conj(matrix[i][i])),creal(cimag(matrix[i][i])));
    //printf("2->%lf +%lfj", creal(conj(matrix[j][i])),creal(cimag(matrix[j][i])));

    //printf("r->%lf\n", r);

    //printf("G:\n");
    //print_matrix(n, n, G);
    double complex** Gtranspose=transpose(m, n, G);
    double complex** temp = matrix_multiply(n, n, n, Q, Gtranspose);
    R=matrix_multiply(n, n, n, G, matrix);
    for(int i=0; i<m; i++){
        for(int j=0;j<n;j++){
            Q[i][j]=temp[i][j];
            matrix[i][j]=R[i][j];
        }
    }
    //printf("R:\n");
    //print_matrix(n, n, R);
    //printf("QQT\n");
    //print_matrix(n, n, matrix_multiply(n, n, n, Q, transpose(n, n, Q)));
    return R;
        
}
