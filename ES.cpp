#include "normal.hpp"

int main(int argc,char *argv[]){
	double START,END;
	srand(time(NULL));
	int len = atoi(argv[1]);
	int time = atoi(argv[2]);
	
	ITER(onemax,temp,len,opt,time);	
}
