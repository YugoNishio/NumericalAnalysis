#include <stdio.h>
#include <math.h>

double x1, x2, x3, error;
double before_x1, before_x2, before_x3;
double error1, error2, error3;
int roop;

double get_x1(double x2, double x3){
    return((10.0 - x2 -x3) / 5.0);
}

double get_x2(double x1, double x3){
    return((12.0 - x1 -x3) / 4.0);
}

double get_x3(double x1, double x2){
    return((13.0 - x1 -x2) / 3.0);
}

void get_roop(){
    x1 = x2 = x3 = 1.0; //initial values
    before_x1 = before_x2 = before_x3 = 0.0;
    error = 0.0001;
    roop = 0;

    while(1){
        error1 = fabs(x1 - before_x1);
        error2 = fabs(x2 - before_x2);
        error3 = fabs(x3 - before_x3);
        before_x1 = x1;
        before_x2 = x2;
        before_x3 = x3;
        x1 = get_x1(x2, x3);
        x2 = get_x2(x1, x3);
        x3 = get_x2(x1, x2);
        roop += 1;

        printf("[i = %3d] x1 = %.10f, x2 = %.10f, x3 = %.10f\n", roop, x1, x2, x3);
        if((error1 < error) && (error2 < error) && (error3 < error)){
            printf("収束\n終了します\n");
            break;
        }
    }
}

int main(){
    get_roop();
    return 0;
}