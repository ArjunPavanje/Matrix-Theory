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


    x3 = -3; y3 = 7; z3 = 2;
	x4 = 2; y4 = 4; z4 = -1; 

    int m = 3, n = 1;
    double **C = createMat(m, n);
    double **D = createMat(m, n);

    
	C[0][0] = x3;
    C[1][0] = y3;
	C[2][0] = z3;
    
	D[0][0] = x4;
    D[1][0] = y4;
	D[2][0] = z4;
    

    
	FILE *fptr;
    fptr = fopen("line_points2.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
	point_gen(fptr, C,D,20);
    fclose(fptr);
    return 0;
}
