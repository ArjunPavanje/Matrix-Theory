#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
double complex** upper_triangular(int m, int n, double complex** matrix);
double complex** eigen(int n, double complex** matrix);

double complex** upper_triangular(int m, int n, double complex** matrix){
    //Q = identity matrix, R = copy of matrix

    double complex** Q=eye(n);
    double complex** R=eye(n);
    for(int i=0;i<n-1;i++){
        matrix=givens_rotation(i, i+1, n, n, matrix);
    }
    //matrix=matrix_multiply(n, n, n, matrix, Q);
    return matrix;
}
double complex** eigen(int n, double complex** matrix){

    double complex** eigenvalues=(double complex**)malloc(sizeof(double complex)*n);
    for(int i=0; i<n; i++){
        eigenvalues[i]=(double complex*)malloc(sizeof(double complex)*1);
        for(int j=0; j<1; j++){
            eigenvalues[i][j]=0;
        }
    }
    matrix=householder(n, matrix);
    printf("Matrix after householder:\n");
    print_matrix(n, n, matrix);
    int COUNT=0;

    for(int m=n; m>1; m--){
        while(COUNT<1000){
            if(isUpperTriangular(n, matrix)) break;
            double complex sigma=matrix[m-1][m-1];
            for(int i=0; i<n; i++){
                matrix[i][i]-=sigma;
            }
            
            matrix=upper_triangular(n, n, matrix);
            for(int i=0; i<n; i++){
                matrix[i][i]+=sigma;
            }
            COUNT++;
            if(COUNT==1){
                printf("Matrix:\n");
                print_matrix(n, n, matrix);
            }
            if(cabs(matrix[m-1][m-2]) < 1e-10) break;
        }

    }
    printf("number of iterations: %d\n", COUNT);

    printf("Final Matrix:\n");
    print_matrix(n, n, matrix);
    double complex eigen_values[n][1];
    for(int i=0; i<n-1; i++){

        if(cabs(matrix[i+1][i]) < 1e-6 ){
            eigenvalues[i][0]=matrix[i][i];
            continue;
        }
        double complex b,c;
        b=-(matrix[i][i]+matrix[i+1][i+1]);
        c=(matrix[i][i]*matrix[i+1][i+1])-(matrix[i][i+1]*matrix[i+1][i]);
        double complex D= csqrt((b*b)-(4*c));
        eigenvalues[i][0]=(-b+D)/2;
        eigenvalues[i+1][0]=(-b-D)/2;
        if(i==n-2){
            return eigenvalues;
        }
        i++;
    }
    eigenvalues[n-1][0]=matrix[n-1][n-1];
    return eigenvalues;

}


