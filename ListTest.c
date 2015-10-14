#include <stdio.h>
#include "List.h"

void showListCelldata(void* data) {
    printf("%s", (char*)data);
}

int main() {
    List* list = newList(sizeof(char) * (4+1), showListCelldata);

    char testString[] = "hoge";

    List_append(list, testString);
    List_append(list, testString);
    List_append(list, testString);

    char testString2[] = "fuga";

    List_insert(list, 1, testString2);

    List_show(list);

    deleteList(list);
    return 0;
}
