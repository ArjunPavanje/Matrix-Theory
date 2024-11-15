#include <linux/limits.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>

void householder(int n,double complex matrix[n][n]);
void matscale(int m, int n, double complex matrix[m][n], double k);
double complex multiply(double complex a, double complex b);
void matrix_multiply(int m, int p, int n, double complex A[m][p], double complex B[p][n], double complex C[m][n]);
void transpose(int m, int n, double complex matrix[m][n], double complex transpose[n][m]);
void print_matrix(int m, int n, double complex matrix[m][n]);
void QR(int n, double complex matrix[n][n]);
void getcol(int j, int n, double complex matrix[n][n], double complex col[n][1]);
void eye(int n, double complex identity[n][n]);//generating an nxn identity matrix
double complex dot_product(int n, double complex a[n][1], double complex b[n][1]);
int main(){
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
   /* double complex matrix[6][6] = {
        {CMPLX(2, 1), CMPLX(3, 0), CMPLX(5, 0), CMPLX(7, 0), CMPLX(11, 0), CMPLX(13, 0)},
        {CMPLX(17, 1), CMPLX(19, 0), CMPLX(23, 0), CMPLX(29, 0), CMPLX(31, 0), CMPLX(37, 0)},
        {CMPLX(41, 1), CMPLX(43, 0), CMPLX(47, 0), CMPLX(53, 0), CMPLX(59, 0), CMPLX(61, 0)},
        {CMPLX(67, 1), CMPLX(71, 0), CMPLX(73, 0), CMPLX(79, 0), CMPLX(83, 0), CMPLX(89, 0)},
        {CMPLX(97, 1), CMPLX(101, 0), CMPLX(103, 0), CMPLX(107, 0), CMPLX(109, 0), CMPLX(113, 0)},
        {CMPLX(127, 1), CMPLX(131, 0), CMPLX(137, 0), CMPLX(139, 0), CMPLX(149, 0), CMPLX(151, 0)}
    };*/
    printf("Matrix:\n");
    print_matrix(n, n, matrix);
    householder(n, matrix);
    printf("Matrix After householder:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%lf + %lfi) ", creal(matrix[i][j]), cimag(matrix[i][j]));
        }
        printf("\n");
    }
    for(int count=0; count<1000; count++){
         QR(n, matrix);
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
    for(int i=0;i<n-2;i++){
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


void print_matrix(int m, int n, double complex matrix[m][n]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("(%lf + %lfi) ", creal(matrix[i][j]), cimag(matrix[i][j]));
        }
        printf("\n");
    }
}
void eye(int n, double complex identity[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            identity[i][j]=(i==j)?CMPLX(1,0):CMPLX(0,0);
        }
    }
}
void QR(int n, double complex matrix[n][n]){
    double complex Q[n][n];
    double complex R[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Q[i][j]=CMPLX(0,0);
        }

    }
    for(int i=0; i<n; i++){
        double complex col[n][1];
        getcol(i, n, matrix, col);
        if(i==0){
            double norm=dot_product(n, col, col);
            /*for(int j=0; j<n; j++){
                norm+=pow(cabs(col[i][0]),2);
            }*/
            norm=sqrt(norm);
            matscale(n, 1, col, 1/norm);
        }
        for(int j=0; j<i; j++){
            double complex e[n][1];           
            getcol(j, n, Q, e);
            //printf("e=\n");
            //print_matrix(n, 1, e); 
            //printf("scaling factor is: %lf + %lfj\n", creal(dot_product(n, col, e)), cimag(dot_product(n, col, e)));
            //matscale(n, 1, e, dot_product(n, e, col));
            double complex scale=dot_product(n, col, e);
            for(int k=0; k<n; k++){
                e[k][0]*=scale;
            }
            //printf("scaled e:\n");
            //print_matrix(n, 1, e);
            //printf("col:\n");
            //print_matrix(n, 1, col);
            
            for(int k=0; k<n; k++){
                col[k][0]-=e[k][0];
            }
        }
        double norm=dot_product(n, col, col);
        norm=sqrt(norm);
        matscale(n, 1, col, 1/norm);  
        for(int j=0; j<n; j++){
            Q[j][i]=col[j][0];
        }
        printf("Q': \n");
        print_matrix(n, n, Q);
    }
        /*printf("Q: \n");
    print_matrix(n, n, Q);*/
    double complex Qtranspose[n][n];
    transpose(n, n, Q, Qtranspose);
    double complex temp[n][n];
    /*matrix_multiply(n, n, n, Q, Qtranspose, temp);
    printf("QQT:\n");
    print_matrix(n, n, temp);*/
    matrix_multiply(n, n, n, Qtranspose, matrix, temp);
    matrix_multiply(n, n, n, temp, Q, matrix);

    
}
void getcol(int j, int n, double complex matrix[n][n], double complex col[n][1]){
    for(int i=0; i<n; i++){
        col[i][0]=matrix[i][j];
    }
}
double complex dot_product(int n, double complex a[n][1], double complex b[n][1]){
    double complex dot=0;
    for(int i=0; i<n; i++){
        dot+= a[i][0]*conj(b[i][0]);
    }
    return (dot);
}
