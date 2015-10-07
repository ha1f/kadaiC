#include <stdio.h>
#include "List.h"

int main() {
    List* list = newList();
    List_append(list, newListCell(3));
    List_append(list, newListCell(6));
    List_append(list, newListCell(7));
    List_append(list, newListCell(8));
    List_remove(list, 0);
    List_append(list, newListCell(5));

    List_insert(list, 0, newListCell(0));
    List_insert(list, 1, newListCell(1));

    List_show(list);
    printf("len=%d\n", List_getLength(list));

    List_remove(list, 1);

    List_show(list);
    printf("len=%d\n", List_getLength(list));

    ListCell_show(List_get(list, 1));

    deleteList(list);
    return 0;
}
