#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include "MatrixFunctions.h"
#include "GivensRotation.h"
#include "HouseholderReflection.h"
#include "Eigenvalue_calculator.h"
int main(){

    int n = 4;
    /*double complex matrix[4][4] = {
        {CMPLX(1, -1), CMPLX(2, 3), CMPLX(-1, 4), CMPLX(5, -2)},
        {CMPLX(3, 2), CMPLX(4, -1), CMPLX(2, 1), CMPLX(-3, 3)},
        {CMPLX(-2, 1), CMPLX(1, -3), CMPLX(3, 0), CMPLX(4, 2)},
        {CMPLX(5, 0), CMPLX(-1, -2), CMPLX(4, -1), CMPLX(3, 1)}
    };*/
    double complex** matrix = zeros(n, n);
    matrix[0][0] = CMPLX(1, -1); matrix[0][1] = CMPLX(2, 3);  matrix[0][2] = CMPLX(-1, 4); matrix[0][3] = CMPLX(5, -2);
    matrix[1][0] = CMPLX(3, 2);  matrix[1][1] = CMPLX(4, -1); matrix[1][2] = CMPLX(2, 1);  matrix[1][3] = CMPLX(-3, 3);
    matrix[2][0] = CMPLX(-2, 1); matrix[2][1] = CMPLX(1, -3); matrix[2][2] = CMPLX(3, 0);  matrix[2][3] = CMPLX(4, 2);
    matrix[3][0] = CMPLX(5, 0);  matrix[3][1] = CMPLX(-1, -2);matrix[3][2] = CMPLX(4, -1); matrix[3][3] = CMPLX(3, 1);
    /*matrix={{CMPLX(1, -1), CMPLX(2, 3), CMPLX(-1, 4), CMPLX(5, -2)},
        {CMPLX(3, 2), CMPLX(4, -1), CMPLX(2, 1), CMPLX(-3, 3)},
        {CMPLX(-2, 1), CMPLX(1, -3), CMPLX(3, 0), CMPLX(4, 2)},
        {CMPLX(5, 0), CMPLX(-1, -2), CMPLX(4, -1), CMPLX(3, 1)}
    }*/
    printf("Matrix:\n");
    print_matrix(n, n, matrix);
    double complex** eigenvalues=eigen(n, matrix);

    /*householder(n, matrix);

    for(int count=0; count<1000; count++){
        if(isUpperTriangular(n, matrix)==1){
            printf("number of iterations: %d\n", count);
            break;
        }
        upper_triangular(n, n, matrix);
    }
        double complex eigen_values[n][1];
    for(int i=0; i<n-1; i++){
        
        if(cabs(matrix[i+1][i]) < 1e-6 ){
            //printf("column %d normal\n", i+1);
            eigen_values[i][0]=matrix[i][i];
            continue;
        }
        double complex b,c;
        b=-(matrix[i][i]+matrix[i+1][i+1]);
        c=(matrix[i][i]*matrix[i+1][i+1])-(matrix[i][i+1]*matrix[i+1][i]);
        double complex D= csqrt((b*b)-(4*c));
        eigen_values[i][0]=(-b+D)/2;
        eigen_values[i+1][0]=(-b-D)/2;
        if(i==n-2){
            matrix[n-1][n-1]=(-b-D)/2;
        }
        i++;
    }
    eigen_values[n-1][0]=matrix[n-1][n-1];*/
    printf("Eigenvalues:\n");
    print_matrix(n, 1, eigenvalues);  
    /*for(int i=0; i<n; i++){
        printf("%lf + %lfj\n ", creal(eigenvalues[i][0]), cimag(eigenvalues[i][0]));
    }*/
    return 0;
}


