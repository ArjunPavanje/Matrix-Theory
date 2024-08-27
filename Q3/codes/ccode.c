struct points{
    int A[2];
    int B[2];
	int C[2];
};

struct points get(){
    struct points temp;
    temp.A[0] = 2;
    temp.A[1] = 3;
    temp.B[0] = 4;
    temp.B[1] = 0;
	temp.C[0] = 6;
	temp.C[1]=-3;
    return temp;
}
