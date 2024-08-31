struct points{
    int A[3];
    int B[3];
	int C[3];
};

struct points get(){
    struct points temp;
    temp.A[0] = -2;
    temp.A[1] = 3;
	temp.A[2]= 5;
    temp.B[0] = 1;
    temp.B[1] = 2;
	temp.B[2]=3;
	temp.C[0] = 7;
	temp.C[1]=0;
	temp.C[2]=-1;
    return temp;
}
