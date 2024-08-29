struct points{
    int A[2];
    int B[2];
	int C[2];
};

struct points get(){
    struct points temp;
    temp.A[0] = 1;
    temp.A[1] = 3;
    temp.B[0] = 3;
    temp.B[1] = 5;
	temp.C[0] = 4;
	temp.C[1] = 6;
    return temp;
}
