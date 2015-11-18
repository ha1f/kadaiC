#include <stdio.h>
#include <math.h>

#define DX 0.00000001

// 入力した関数
double f1(double x) {
    return - 2*pow(x,4) + 3*pow(x,3) + 4*x - 3;
}
double f2(double x) {
    return -2 * sin(x) + exp(x+1) + x - 10;
}

// 微分を求める
double fd(double (*func)(double), double x) {
    return (func(x+DX) - func(x)) / DX;
}

// x切片を返す、y=ax+bの形、ax+b=0のとき
double searchInterceptX(double a, double b) {
    return -b/a;
}

// ニュートン法で次のXを求める
double nextX(double (*func)(double), double currentX) {
    double dif = fd(func, currentX);
    return searchInterceptX(dif, func(currentX) - dif*currentX);
}

// 解いて結果を返す
double solve(double (*func)(double), double initialX) {
    double currentX = initialX;
    for(int i=0; i<10; i++) {
        printf("%lf\n", currentX);
        currentX = nextX(f1, currentX);
    }
    return currentX;
}

int main() {
    printf("f1\n");
    printf("result = %lf\n", solve(f1, 1));

    printf("\n");

    printf("f2\n");
    printf("result = %lf\n", solve(f2, M_PI));
}
