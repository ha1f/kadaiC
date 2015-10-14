#include <stdio.h>
#include "List.h"

int main() {
    List* list = newList(sizeof(char) * (3+1));

    char testString[] = "abc";

    List_append(list, testString);
    List_append(list, testString);
    List_append(list, testString);

    char testString2[] = "def";

    List_insert(list, 1, testString2);

    List_show(list);

    deleteList(list);
    return 0;
}
