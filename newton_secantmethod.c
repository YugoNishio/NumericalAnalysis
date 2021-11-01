#include <stdio.h>
#include <math.h>

double delta, x, a;
double h;
int n;

#define eps 0.000001 //最小値
#define n_max 150 //最大実行回数

double f(double x){
    //return 2/(x*x) +x -10;
    //return x + cos(x);
    return 5*x*x*x -1*x*x +9*x -10;
}

double df(double x){
    h = 0.000001;
	return (f(x+h)-f(x))/h;
}

double newton(double x_n){
    n = 0;
    x = x_n;//初期値
    printf("%f\n", x);
    do{
    delta = (-1 * f(x)) / df(x);
    x += delta;
    printf("%lf\n", x);
    n++;
    }
    while((fabs(delta) > eps) && (n < n_max));//収束条件
}

int main(){
    a = newton(10);//初期値設定
    return 0;
}