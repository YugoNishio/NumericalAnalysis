#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 計算する関数
double f(double x)
{
	return x+cos(x);//計算する式
}
// 二分法
void bisection(double a, double b, double *solution, int *N)
{
	int i = 0;
	double s;
	double eps = pow(2.0, -30.0);//収束条件
// 解が収束条件を満たせば終了
	while (fabs(b-a)>=eps){
		i++;
		s = (a+b)/2.0;
		if(f(s) * f(a)<0) b=s;
		else a = s;
		if(i==100) break; // 100回繰り返したら強制終了
	};
	*N = i;//繰り返し回数
	*solution = s;//解
}
int main()
{
	double solution;
	int N;
// 二分法
	bisection(-10000.0, 10000.0, &solution, &N);//初期区間:a,b
	printf("解:%f (繰り返し回数：%d )\n",solution,N);
	return 0;
}