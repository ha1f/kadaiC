#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double f(long double x) {
    //return (long double)pow(1.0, 2.0);
    return -2.0L*powl(x,4.0L)+3.0L*powl(x,3.0L)+4.0L*x-3.0L;
}

long double f_prime(long double x) {
    return -8.0L*powl(x,3.0L)+9.0L*powl(x,2.0L)+4.0L;
}

int main(){
    long double x = 0;
    for (int i = 0; i < 20; ++i)
    {
        x = x - (f(x)/f_prime(x));
        printf("%2d : %Le\n", i, x);
    }
    return 0;
}
