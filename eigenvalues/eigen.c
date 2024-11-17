#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include "MatrixFunctions.h"
#include "GivensRotation.h"
#include "HouseholderReflection.h"
#include "Eigenvalue_calculator.h"
int main(){

    //int n = 4;
    /*double complex matrix[4][4] = {
        {CMPLX(1, -1), CMPLX(2, 3), CMPLX(-1, 4), CMPLX(5, -2)},
        {CMPLX(3, 2), CMPLX(4, -1), CMPLX(2, 1), CMPLX(-3, 3)},
        {CMPLX(-2, 1), CMPLX(1, -3), CMPLX(3, 0), CMPLX(4, 2)},
        {CMPLX(5, 0), CMPLX(-1, -2), CMPLX(4, -1), CMPLX(3, 1)}
    };*/
        /*matrix[0][0] = CMPLX(1, -1); matrix[0][1] = CMPLX(2, 3);  matrix[0][2] = CMPLX(-1, 4); matrix[0][3] = CMPLX(5, -2);
    matrix[1][0] = CMPLX(3, 2);  matrix[1][1] = CMPLX(4, -1); matrix[1][2] = CMPLX(2, 1);  matrix[1][3] = CMPLX(-3, 3);
    matrix[2][0] = CMPLX(-2, 1); matrix[2][1] = CMPLX(1, -3); matrix[2][2] = CMPLX(3, 0);  matrix[2][3] = CMPLX(4, 2);
    matrix[3][0] = CMPLX(5, 0);  matrix[3][1] = CMPLX(-1, -2);matrix[3][2] = CMPLX(4, -1); matrix[3][3] = CMPLX(3, 1);*/
    /*matrix={{CMPLX(1, -1), CMPLX(2, 3), CMPLX(-1, 4), CMPLX(5, -2)},
        {CMPLX(3, 2), CMPLX(4, -1), CMPLX(2, 1), CMPLX(-3, 3)},
        {CMPLX(-2, 1), CMPLX(1, -3), CMPLX(3, 0), CMPLX(4, 2)},
        {CMPLX(5, 0), CMPLX(-1, -2), CMPLX(4, -1), CMPLX(3, 1)}
    }*/
    FILE* fptr=fopen("input.txt", "r");
    int n;
    fscanf(fptr, "%d", &n);
    printf("%d\n", n);
    double complex** matrix = zeros(n, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            double real, imag;
            fscanf(fptr, "%lf %lf", &real, &imag);
            printf("matrix[%d][%d]=%lf %lf\n", i, j, real, imag);
            matrix[i][j]=CMPLX(real, imag);
        }
    }
    fclose(fptr);
/*int n = 10;
double complex** matrix = eye(10);
matrix[0][0] = CMPLX(1, 1), matrix[0][1] = CMPLX(2, -1), matrix[0][2] = CMPLX(-3, 2), matrix[0][3] = CMPLX(4, 0), matrix[0][4] = CMPLX(0, 3), matrix[0][5] = CMPLX(-1, 1), matrix[0][6] = CMPLX(5, -2), matrix[0][7] = CMPLX(0, 0), matrix[0][8] = CMPLX(2, 1), matrix[0][9] = CMPLX(1, -1),
matrix[1][0] = CMPLX(3, 2), matrix[1][1] = CMPLX(-2, -3), matrix[1][2] = CMPLX(1, 1), matrix[1][3] = CMPLX(-4, 0), matrix[1][4] = CMPLX(2, -1), matrix[1][5] = CMPLX(0, 4), matrix[1][6] = CMPLX(5, 0), matrix[1][7] = CMPLX(1, -2), matrix[1][8] = CMPLX(-1, 3), matrix[1][9] = CMPLX(2, 2),
matrix[2][0] = CMPLX(1, 1), matrix[2][1] = CMPLX(-3, -1), matrix[2][2] = CMPLX(4, 0), matrix[2][3] = CMPLX(1, 2), matrix[2][4] = CMPLX(-2, 1), matrix[2][5] = CMPLX(-1, 4), matrix[2][6] = CMPLX(0, 0), matrix[2][7] = CMPLX(-5, 1), matrix[2][8] = CMPLX(3, -3), matrix[2][9] = CMPLX(2, -2),
matrix[3][0] = CMPLX(1, 1), matrix[3][1] = CMPLX(-1, 2), matrix[3][2] = CMPLX(0, 1), matrix[3][3] = CMPLX(2, -3), matrix[3][4] = CMPLX(-2, 2), matrix[3][5] = CMPLX(1, 3), matrix[3][6] = CMPLX(-1, 2), matrix[3][7] = CMPLX(4, 1), matrix[3][8] = CMPLX(0, -4), matrix[3][9] = CMPLX(1, 1),
matrix[4][0] = CMPLX(3, 3), matrix[4][1] = CMPLX(2, 1), matrix[4][2] = CMPLX(-3, -2), matrix[4][3] = CMPLX(-1, -1), matrix[4][4] = CMPLX(5, 2), matrix[4][5] = CMPLX(2, -1), matrix[4][6] = CMPLX(-1, 3), matrix[4][7] = CMPLX(0, 0), matrix[4][8] = CMPLX(1, 2), matrix[4][9] = CMPLX(-4, 3),
matrix[5][0] = CMPLX(3, 0), matrix[5][1] = CMPLX(1, 3), matrix[5][2] = CMPLX(-1, -2), matrix[5][3] = CMPLX(2, -2), matrix[5][4] = CMPLX(1, 1), matrix[5][5] = CMPLX(-1, 2), matrix[5][6] = CMPLX(0, 0), matrix[5][7] = CMPLX(2, -3), matrix[5][8] = CMPLX(-2, 2), matrix[5][9] = CMPLX(1, 3),
matrix[6][0] = CMPLX(-1, 2), matrix[6][1] = CMPLX(4, 1), matrix[6][2] = CMPLX(0, -4), matrix[6][3] = CMPLX(1, 1), matrix[6][4] = CMPLX(3, 3), matrix[6][5] = CMPLX(2, 1), matrix[6][6] = CMPLX(-3, -2), matrix[6][7] = CMPLX(-1, -1), matrix[6][8] = CMPLX(5, 2), matrix[6][9] = CMPLX(2, -1),
matrix[7][0] = CMPLX(-1, 3), matrix[7][1] = CMPLX(0, 0), matrix[7][2] = CMPLX(1, 2), matrix[7][3] = CMPLX(-4, 3), matrix[7][4] = CMPLX(3, 0), matrix[7][5] = CMPLX(1, 3), matrix[7][6] = CMPLX(-1, -2), matrix[7][7] = CMPLX(2, -2), matrix[7][8] = CMPLX(1, 1), matrix[7][9] = CMPLX(-1, 2),
matrix[8][0] = CMPLX(0, 0), matrix[8][1] = CMPLX(2, 3), matrix[8][2] = CMPLX(1, -2), matrix[8][3] = CMPLX(3, 2), matrix[8][4] = CMPLX(0, 0), matrix[8][5] = CMPLX(1, 2), matrix[8][6] = CMPLX(0, -1), matrix[8][7] = CMPLX(-4, 3), matrix[8][8] = CMPLX(3, -1), matrix[8][9] = CMPLX(0, 0),
matrix[9][0] = CMPLX(1, 1), matrix[9][1] = CMPLX(-1, -1), matrix[9][2] = CMPLX(2, 3), matrix[9][3] = CMPLX(0, -1), matrix[9][4] = CMPLX(1, 2), matrix[9][5] = CMPLX(-2, 1), matrix[9][6] = CMPLX(3, 1), matrix[9][7] = CMPLX(0, 0), matrix[9][8] = CMPLX(2, 1), matrix[9][9] = CMPLX(1, -2);
*/

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


