#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "libs/matfun.h"
#include "libs/geofun.h"

void point_gen(FILE *fptr, double **A, double **B, int num_points) {
    for (int i = 0; i <= num_points; i++) {
		double temp = (double)i/(double)num_points;
		double temp1 = 1-temp;
        double **output = Matadd(Matscale(A,3,1,temp1),Matscale(B,3,1,temp),3,1);
		printf("%lf,%lf,%lf\n",output[0][0],output[1][0],output[2][0]);
		fprintf(fptr, "%lf,%lf,%lf\n", output[0][0], output[1][0],output[2][0]);
        freeMat(output,2);
	}}


int main() {
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5;
	//    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    x1 = 1; y1 = -7; z1 = 7;
	x2 = 3; y2 = -2; z2 = 2;
    x3 = 0; y3 = 0; z3 = 0;
	x4 = 0; y4 = 1/sqrt(2); z4 = 1/sqrt(2);
	x5 = 0; y5 = -1/sqrt(2); z5 = -1/sqrt(2);

    int m = 3, n = 1;
    double **A = createMat(m, n);
    double **B = createMat(m, n);
    double **C = createMat(m, n);
	double **D = createMat(m, n);
    double **E = createMat(m, n);
	A[0][0] = x1;
    A[1][0] = y1;
	A[2][0] = z1;
	B[0][0] = x2;
    B[1][0] = y2;
	B[2][0] = z2;
    C[0][0] = x3;
    C[1][0] = y3;
	C[2][0] = z3;
	D[0][0] = x4;
    D[1][0] = y4;
	D[2][0] = z4;
    E[0][0] = x5;
    E[1][0] = y5;
	E[2][0] = z5;
    FILE *fptr;
    fptr = fopen("line_points.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
	point_gen(fptr, C,A,20);
	point_gen(fptr, C,B,20);
	point_gen(fptr, C,D,20);
	point_gen(fptr, C,E,20);
	fclose(fptr);
    return 0;
}
