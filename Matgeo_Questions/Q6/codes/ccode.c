struct points{
    int A[3];
    int B[3];
	int C[3];
	int D[3];
    int E[3];
    int F[3];
	};

struct points get(){
    struct points temp;
    temp.A[0] = 0;
    temp.A[1] = 0;
	temp.A[2]= 6;

    temp.B[0] = 0;
    temp.B[1] = 4;
	temp.B[2]=0;

	temp.C[0] = 6;
	temp.C[1]=0;
	temp.C[2]=0;

	temp.D[0] = 3;
	temp.D[1]=2;
	temp.D[2]=0;


    temp.E[0] =3;
    temp.E[1] = 0;
	temp.E[2]= 3;

    temp.F[0] = 0;
    temp.F[1] = 2;
	temp.F[2]=3;
    return temp;
}
