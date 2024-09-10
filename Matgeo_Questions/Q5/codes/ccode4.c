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

    x7 = 2; y7 = -1; z7 = 3;
	x8 = -2; y8 = 1; z8 = 3; 
    int m = 3, n = 1;

    double **G = createMat(m, n);
    double **H = createMat(m, n);

    
	G[0][0] = x7;
    G[1][0] = y7;
	G[2][0] = z7;
    
	H[0][0] = x8;
    H[1][0] = y8;
	H[2][0] = z8;
    
	FILE *fptr;
    fptr = fopen("line_points4.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

	point_gen(fptr, G,H,20);
    fclose(fptr);
    return 0;
}
