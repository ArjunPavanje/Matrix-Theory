#include <stdio.h>
#include <complex.h>
#include <math.h>

void householder(int n,double complex matrix[n][n]);
void matscale(int m, int n, double complex matrix[m][n], double k);
double complex multiply(double complex a, double complex b);
void matrix_multiply(int m, int p, int n, double complex A[m][p], double complex B[p][n], double complex C[m][n]);
void transpose(int m, int n, double complex matrix[m][n], double complex transpose[n][m]);
void upper_triangular(int m, int n, double complex matrix[m][n]);//via givens rotation
void givens_rotation(int i, int j, int m, int n, double complex matrix[m][n], double complex Q[m][n], double complex R[m][n]);
int main() {
    /*int n=3;
      double complex matrix[n][n];
      for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
      matrix[i][j]=CMPLX(i,j);
      }
      }*/
    int n = 4;
    double complex matrix[4][4] = {
        {CMPLX(1, -1), CMPLX(2, 3), CMPLX(-1, 4), CMPLX(5, -2)},
        {CMPLX(3, 2), CMPLX(4, -1), CMPLX(2, 1), CMPLX(-3, 3)},
        {CMPLX(-2, 1), CMPLX(1, -3), CMPLX(3, 0), CMPLX(4, 2)},
        {CMPLX(5, 0), CMPLX(-1, -2), CMPLX(4, -1), CMPLX(3, 1)}
    };


    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%lf + %lfi) ", creal(matrix[i][j]), cimag(matrix[i][j]));
        }
        printf("\n");
    }
    householder(n, matrix);
    /*printf("Matrix After householder:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%lf + %lfi) ", creal(matrix[i][j]), cimag(matrix[i][j]));
        }
        printf("\n");
    }*/
    for(int count=0; count<100; count++){
         upper_triangular(n, n, matrix);
    }
    printf("Eigen values:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i==j){
                printf("(%lf + %lfi) ", creal(matrix[i][j]), cimag(matrix[i][j]));
            }
        }
        printf("\n");
    }
    return 0;
}
void householder(int n, double complex matrix[n][n]){
    //'i' is mumn no. 'i' goes till n-2 because in upper hessenberg form last two ls remain unchanged.
    for(int i=0;i<n-1;i++){
        double complex x[n-i-1][1];
        //printf("size: %d\n", n-i-1);
        int count=0;
        for(int j=i+1;j<n;j++){
            //x[count]=CMPLX(creal(matrix[j][i]), cimag(matrix[j][i]));  
            x[count][0]=matrix[j][i];
            count++;

        }
        //printing vectors:
        /*printf("x%d:\n",i+1);
        for(int j=0;j<count;j++){
            printf("(%lf + %lfi)\n ", creal(x[j][0]), cimag(x[j][0]));
        }*/

        double norm_x=0;
        for(int j=0;j<count;j++){
            norm_x+=pow(cabs(x[j][0]),2);
        }
        norm_x=sqrt(norm_x);
        x[0][0]+=(CMPLX((norm_x*cos(carg(x[0][0]))) , (norm_x*sin(carg(x[0][0]))) ));

        //turning 'x' into a unit vector
        norm_x=0;
        for(int j=0;j<count;j++){
            norm_x+=pow(cabs(x[j][0]),2);
        }
        norm_x=sqrt(norm_x);
        matscale(count, 1, x, 1/norm_x);

        //printing householder reflectors:
       /* printf("u%d:\n",i+1);
        for(int j=0;j<count;j++){
            printf("(%lf + %lfi)\n ", creal(x[j][0]), cimag(x[j][0]));
        }*/

        complex double xT[1][n-i-1];
        transpose(n-i-1, 1, x, xT);

        double complex P[n-i-1][n-i-1];
        for (int l = 0; l < n-i-1; l++) {
            for (int m = 0; m < n-i-1; m++) {
                P[l][m] = (l == m) ? CMPLX(1, 0) : CMPLX(0, 0);
            }
        }
        double complex  u_outer_product[n-i-1][n-i-1];    
        matrix_multiply(n-i-1, 1, n-i-1, x, xT, u_outer_product);
        for (int l = 0; l < n-i-1; l++) {
            for (int m = 0; m < n-i-1; m++) {
                P[l][m] -= 2 * u_outer_product[l][m];
            }
        }

        double complex H[n][n];
        for(int j=0;j<n;j++){//'j'=row
            for(int k=0;k<n;k++){//'k'=columns
                
                if(k>(i) && j>(i)){
                    H[j][k]=P[j-i-1][k-i-1];
                }
                else{
                    H[j][k]= (j==k)?CMPLX(1,0):CMPLX(0,0);                
                }
            }
        }

        //printing H
        /*printf("P%d Matrix: \n",i+1);
        for(int l=0; l<(n); l++){
            for(int m=0; m<(n); m++){
                //printf("P[%d][%d]--> (%lf + %lfi) ",l, m, creal(P[l][m]), cimag(P[l][m]));
                printf("(%lf + %lfi) ", creal(H[l][m]), cimag(H[l][m]));

            }
            printf("\n");
        }*/

        //finding H*
        double complex HT[n][n];
        transpose(n, n, H, HT);
        double complex result[n][n];
        matrix_multiply(n, n, n, matrix, H, result);
        double complex final_result[n][n];
        matrix_multiply(n, n, n, H, result, matrix);
        //printing matrix
        /*printf("After doing shit:\n");
        for(int l=0; l<(n); l++){
            for(int m=0; m<(n); m++){
                //printf("P[%d][%d]--> (%lf + %lfi) ",l, m, creal(P[l][m]), cimag(P[l][m]));
                printf("(%lf + %lfi) ", creal(matrix[l][m]), cimag(matrix[l][m]));

            }
            printf("\n");
        }*/
        //making matrix=H
        /*for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                matrix[j][k]=result_final[j][k];
            }
        }*/
    }
}
void matscale(int m, int n, double complex matrix[m][n], double k){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]*=k;
        }
       // printf("\n");
    }
}

double complex multiply(double complex a, double complex b){
    double real=creal(a)*creal(b)-cimag(a)*cimag(b);
    double imag=creal(a)*cimag(b)+cimag(a)*creal(b);
    return CMPLX(real, imag);
}

void matrix_multiply(int m, int p, int n, double complex A[m][p], double complex B[p][n], double complex C[m][n]){
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            C[i][j] = 0;
            for (int k=0;k<p;k++) {
                C[i][j]+=multiply(A[i][k], B[k][j]);
            }
        }
    }
}

void transpose(int m, int n, double complex matrix[m][n], double complex transpose[n][m]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            transpose[j][i]=conj(matrix[i][j]);
        }
    }
}
void upper_triangular(int m, int n, double complex matrix[m][n]){
    //Q = identity matrix, R = copy of matrix

    double complex Q[m][n], R[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            Q[i][j]=(i==j)?CMPLX(1,0):CMPLX(0,0);//Q is 'identity' matrix initially
            R[i][j]=matrix[i][j];//
        }
    }
    for(int i=0;i<n-1;i++){
         givens_rotation(i, i+1, n, n, matrix, Q, R);
    }
    matrix_multiply(n, n, n, R, Q, matrix);
    /*printf("Q:\n");
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            printf("(%lf + %lfi) ", creal(Q[k][j]), cimag(Q[k][j]));
        }
        printf("\n");
    }
    printf("R:\n");
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            printf("(%lf + %lfi) ", creal(R[k][j]), cimag(R[k][j]));
        }
        printf("\n");
    }

    double complex verifier[m][n];
    matrix_multiply(n, n, n, Q, R, verifier);




    printf("For verification purposes:\n");
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            printf("(%lf + %lfi) ", creal(verifier[k][j]), cimag(verifier[k][j]));
        }
        printf("\n");
    }*/
    
}
void givens_rotation(int i, int j, int m, int n, double complex matrix[m][n], double complex Q[m][n], double complex R[m][n]){
    double complex G[m][n];//G is initially identity matrix
    for(int i=0; i<m; i++){
        for(int j=0;j<n;j++){
            G[i][j]=(i==j)?CMPLX(1,0):CMPLX(0,0);
        }
    }
    double r=sqrt(pow(cabs(matrix[i][i]),2) + pow(cabs(matrix[i+1][i]),2) );
    double complex c=conj(matrix[i][i])/r;
    double complex s=conj(matrix[i+1][i])/r;
    G[i][i]=c;
    G[i+1][i+1]=conj(c);
    G[i+1][i]=-conj(s);
    G[i][i+1]=s;
    /*printf("G value:\n");
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            printf("(%lf + %lfi) ", creal(G[k][j]), cimag(G[k][j]));
        }
        printf("\n");
    }*/
    double complex Gtranspose[m][n];
    transpose(m, n, G, Gtranspose);
    double complex temp[m][n];
    matrix_multiply(n, n, n, Q, Gtranspose, temp);
    matrix_multiply(n, n, n, G, matrix, R);
    for(int i=0; i<m; i++){
        for(int j=0;j<n;j++){
            Q[i][j]=temp[i][j];
            matrix[i][j]=R[i][j];
        }
    }
    /*printf("Q:\n");
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            printf("(%lf + %lfi) ", creal(Q[k][j]), cimag(Q[k][j]));
        }
        printf("\n");
    }
    printf("R:\n");
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            printf("(%lf + %lfi) ", creal(matrix[k][j]), cimag(matrix[k][j]));
        }
        printf("\n");
    }
    double complex verifier[m][n];
    matrix_multiply(n, n, n, Gtranspose, R, verifier);




    printf("For verification purposes:\n");
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            printf("(%lf + %lfi) ", creal(verifier[k][j]), cimag(verifier[k][j]));
        }
        printf("\n");
    }*/

}


