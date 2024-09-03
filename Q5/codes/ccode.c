struct points{
    int A[3];
    int B[3];
	int C[3];
	int D[3];
    int E[3];
    int F[3];
	int G[3];
	int H[3];};

struct points get(){
    struct points temp;
    temp.A[0] = 2;
    temp.A[1] = 3;
	temp.A[2]= 5;

    temp.B[0] = 4;
    temp.B[1] = 3;
	temp.B[2]=1;

	temp.C[0] = -3;
	temp.C[1]=7;
	temp.C[2]=2;

	temp.D[0] = 2;
	temp.D[1]=4;
	temp.D[2]=-1;


    temp.E[0] = -1;
    temp.E[1] = 3;
	temp.E[2]= -4;

    temp.F[0] = 1;
    temp.F[1] = -3;
	temp.F[2]=4;

	temp.G[0] = 2;
	temp.G[1]=-1;
	temp.G[2]=3;

	temp.H[0] = -2;
	temp.H[1]=1;
	temp.H[2]=3;
    return temp;
}
