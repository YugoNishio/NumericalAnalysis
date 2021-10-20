#include <stdio.h>
#include <math.h>

double delta, x, next_x, a;
int n;

#define eps 0.001
#define n_max 100

double f(double x){
    return x + cos(x);
}

double df(double x){
    return 1 - sin(x);
}

double newton(double x_n){
    n = 0;
    x = x_n;
    printf("%f\n", x);
    do{
    delta = (-1 * f(x_n)) / df(x_n);
    next_x = x + delta;
    x = next_x;
    n++;
    }
    while((fabs(delta) > eps) && (n <= n_max));
    return next_x;
}

int main(){
    a = newton(-4);
    printf("%3d:[%f]\n", n, a);
    return 0;
}