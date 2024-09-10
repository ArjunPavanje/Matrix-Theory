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
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;

    double x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8;


	x5 = -1; y5 = 3; z5 = -4;
    x6 = 1; y6 = -3; z6 = 4;
    int m = 3, n = 1;
    double **E = createMat(m, n);
    double **F = createMat(m, n);
    
	E[0][0] = x5;
    E[1][0] = y5;
	E[2][0] = z5;
    
	F[0][0] = x6;
    F[1][0] = y6;
	F[2][0] = z6;
    
	FILE *fptr;
    fptr = fopen("line_points3.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
	point_gen(fptr, E,F ,20);
    fclose(fptr);
    return 0;
}
