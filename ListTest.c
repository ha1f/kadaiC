#include <stdio.h>
#include <malloc/malloc.h>
#include "List.h"

void showAsString(void* data) {
    printf("%s", (char*)data);
}

void showAsDouble(void* data) {
    printf("%lf", *(double*)data);
}

int main() {
    // list1
    List* list = newList(sizeof(char) * (4+1), showAsString);
    char testString[] = "hoge";
    List_append(list, testString);
    List_append(list, testString);
    List_append(list, testString);
    char testString2[] = "fuga";
    List_insert(list, 1, testString2);
    List_show(list);
    deleteList(list);


    //list2
    List* list2 = newList(sizeof(double), showAsDouble);
    double tmp = 1.0;
    List_append(list2, &tmp);
    tmp = 2.0;
    List_append(list2, &tmp);// appendの時点での値がコピーされる
    tmp = 5.0;
    List_set(list2, 1, &tmp);
    List_show(list2);
    deleteList(list2);

    return 0;
}
