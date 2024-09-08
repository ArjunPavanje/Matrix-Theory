struct points{
    int Q[2];
    int P[2];
	int Ra[2];
	int Rb[2];
	};

struct points get(){
    struct points temp;
    temp.Q[0] = 0;
    temp.Q[1] = 1;

    temp.P[0] = 5;
    temp.P[1] = -3;

	temp.Ra[0] = 4;
	temp.Ra[1]=6;

	temp.Rb[0]=-4;
	temp.Rb[1]=6;
    return temp;
}
