#include <stdio.h>

int generateId() {
    static int id = 0;
    return id++;
}

int main() {
    int (*func)() = generateId;
    for(int i=0; i<10; i++) {
        printf("%d,", func());
    }
    return 0;
}
