#include <stdio.h>
#include <math.h>

#define VEC_NUM 5

double zeroVec[3] = {0,0,0};

double vectors[VEC_NUM][3] = {
{1.109, 4.202, 4.689},
{5.014, 1.508, 3.478},
{1.991, 3.846, 4.163},
{2.818, 6.848, 0.333},
{3.284, 2.13, 4.587}
};

double vecLen(double *vec3){
    return pow(vec3[0], 2) + pow(vec3[1], 2) + pow(vec3[2], 2);
}

double vecDist(double *vec31, double *vec32) {
    double tmpVec[3] = {vec31[0]-vec32[0],vec31[1]-vec32[1],vec31[2]-vec32[2]};
    return vecLen(tmpVec);
}

int main() {
    printf("Hello!\n");
    for(int i=0; i<VEC_NUM; i++) {
        for(int j=i+1; j<VEC_NUM; j++) {
            if (i != j) {
                printf("%d-%d, %lf\n", i, j, vecDist(vectors[i], vectors[j]));
            }
        }
    }
    return 0;
}