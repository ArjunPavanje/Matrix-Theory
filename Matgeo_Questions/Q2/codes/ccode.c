struct points{
    int O[2];
    int A[2];
	int B[2];
};

struct points get(){
    struct points temp;
    temp.O[0] = 0;
    temp.O[1] = 0;
    temp.A[0] = 1;
    temp.A[1] = 2;
	temp.B[0] = 2;
	temp.B[1]=4;
    return temp;
}
