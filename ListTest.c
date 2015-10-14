#include <stdio.h>
#include "List.h"

void showListCelldata(void* data) {
    printf("%s", (char*)data);
}

void showListCelldata2(void* data) {
    printf("%lf", *(double*)data);
}

int main() {
    // list1
    List* list = newList(sizeof(char) * (4+1), showListCelldata);
    char testString[] = "hoge";
    List_append(list, testString);
    List_append(list, testString);
    List_append(list, testString);
    char testString2[] = "fuga";
    List_insert(list, 1, testString2);
    List_show(list);
    deleteList(list);


    //list2
    List* list2 = newList(sizeof(double), showListCelldata2);
    double tmp = 1.0;
    List_append(list2, &tmp);
    tmp = 2.0;
    List_append(list2, &tmp);// appendの時点での値がコピーされる
    List_show(list2);
    deleteList(list2);

    return 0;
}
