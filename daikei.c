#include <stdio.h>
#include <math.h>
#define EPS (0.1)

double f(double x){
	return(x*x*x*x -2*x*x*x +x*x -3*x +1);
}

double daikei(double x){
	double a = 0, b = 4, sum_daikei = 0;
	for(double x = a; x < b; x += EPS){
        sum_daikei += (f(x) + f(x+EPS));
    }
    sum_daikei *= (EPS / 2);
	printf("daikei : %f\n", sum_daikei);
}

double simpson(double x){
	double a = 0, b = 4, sum_simpson = 0;
	for(double x = a; x < b; x += EPS * 2){
		sum_simpson += (f(x) + 4 * f(x + EPS) + f(x + EPS * 2));
    }
	sum_simpson *= (EPS / 3);
	printf("simpson : %f\n", sum_simpson);
}

int main(){
	double x;
	daikei(x);
	simpson(x);
	return 0;
}