//ogawaのコードを参考に作成
#include <stdio.h>
#include <math.h>

double delta, x, next_x, a;
int n;

#define eps 0.000001 //
#define n_max 100 //最大実行回数

double f(double x){
    return x*x*x -3*x*x +9*x -8;
}

double df(double x){
    double h = 0.000001;
	return (f(x+h)-f(x))/h;
}

double newton(double x_n){
    n = 0;
    x = x_n;
    printf("%f\n", x);
    do{
    delta = (-1 * f(x)) / df(x);
    x += delta;
    printf("%3d x=%lf\n", n, x);
    n++;
    }
    while((fabs(delta) > eps) && (n <= n_max));
    return next_x;
}

int main(){
    a = newton(10);
    return 0;
}