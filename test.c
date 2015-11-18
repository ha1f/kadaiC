#include <stdio.h>

#define NUM 5

int sum(int *p, int num) {
    int total = p[0];
    for(int i=1; i<num; i++) {
        total += p[i];
    }
    return total;
}

double ave(int *p, int num) {
    return 1.0*sum(p, num)/num;
}

int min(int *p, int num) {
    int min = p[0];
    for(int i=1; i<num; i++) {
        if(min > p[i]) {
            min = p[i];
        }
    }
    return min;
}
int max(int *p, int num) {
    int max = p[0];
    for(int i=1; i<num; i++) {
        if(max < p[i]) {
            max = p[i];
        }
    }
    return max;
}

int main() {
    int a[NUM];
    printf("input five numbers:");
    for(int i=0; i<NUM; i++) {
        scanf("%d", &a[i]);
    }

    printf("sum is %d\n", sum(a, NUM));
    printf("average is %lf\n", ave(a, NUM));
    printf("min is %d\n", min(a, NUM));
    printf("max is %d\n", max(a, NUM));

    return 0;
}
