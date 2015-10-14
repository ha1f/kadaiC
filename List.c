#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "List.h"

/** ここからListCell */
ListCell* newListCell(int dataSize, void* data) {
    ListCell* listCell = malloc(sizeof(ListCell));
    listCell->data = malloc(dataSize);
    listCell->next = NULL;
    memcpy(listCell->data, data, dataSize);
    return listCell;
}

void deleteListCell(ListCell* this) {
    free(this->data);
    free(this);
}

void ListCell_show(ListCell* this) {
    printf("listCell");
}

/** ここからList */
// 末尾に追加
void List_append(List* this, void* data) {
    ListCell* cell = newListCell(this->dataSize, (void*)data);
    if (this->first == NULL) { // len=0
        this->first = cell;
    } else if (this->last == NULL) { // len=1
        this->last = cell;
        this->first->next = this->last;
    } else {
        this->last->next = cell;
        this->last = cell;
    }
    this->length += 1;
}

// 削除。空いたメモリはどんどん解放！
void List_remove(List* this, int index) {
    ListCell* cell = this->first;
    if (cell == NULL) {printf("Error: index is out of range!\n");return;}
    // 先頭が変わるとき
    if (index == 0) {
        ListCell* next = cell->next;
        deleteListCell(cell);
        this->first = next;
        this->length -= 1;
        return;
    }
    int i = 1;
    while(cell->next != NULL) {
        if (i == index) {
            ListCell* next = cell->next->next;
            deleteListCell(cell->next);
            cell->next = next;
            // 末尾が削除された時
            if (next == NULL) {
                this->last = cell->next;
            }
            this->length -= 1;
            return;
        }
        cell = cell->next;
        i += 1;
    }
    printf("Error: index is out of range!\n");
}

// 挿入、0なら先頭
void List_insert(List* this, int index, void* data) {
    ListCell* insertCell = newListCell(this->dataSize, data);
    if (index == 0) {
        insertCell->next = this->first;
        this->first = insertCell;
        this->length += 1;
        return;
    }
    ListCell* cell = this->first;
    int i = 1;
    while(cell != NULL) {
        if (i == index) {
            insertCell->next = cell->next;
            cell->next = insertCell;
            if (insertCell->next == NULL) {
                this->last = insertCell;
            }
            this->length += 1;
            return;
        }
        cell = cell->next;
        i += 1;
    }
    printf("Insert Error: index is out of range!\n");
}

// Listの中身を全て表示
void List_show(List* this) {
    ListCell* cell = this->first;
    printf("[ ");
    while(cell != NULL) {
        this->showCellData(cell->data);
        printf(", ");
        cell = cell->next;
    }
    printf("]\n");
}

// 特定のcellのdataを取得、なければNULL
void* List_get(List* this, int index) {
    int i = 0;
    ListCell* cell = this->first;
    while(cell != NULL) {
        if (i==index) {
            return cell->data;
        }
        cell = cell->next;
        i=i+1;
    }
    printf("Get Error: index is out of range!\n");
    return NULL;
}

void List_set(List* this, int index, void* data) {
    int i = 0;
    ListCell* cell = this->first;
    while(cell != NULL) {
        if (i==index) {
            memcpy(cell->data, data, this->dataSize);
            return;
        }
        cell = cell->next;
        i=i+1;
    }
    printf("Set Error: index is out of range!\n");
    return;
}

int List_getLength(List* this) {
    return this->length;
}

/*
//仕様変更のため使えない
// 特定のオブジェクトが含まれているか、なければ-1、あればindex
int List_find(List* this, ListCell* obj) {
    int i = 0;
    ListCell* cell = this->first;
    while(cell != NULL) {
        if (cell == obj) {
            return i;
        }
        cell = cell->next;
        i=i+1;
    }
    printf("Find Error: object not found\n");
    return -1;
}
*/

void List_extend(List* this, List* list2) {
    this->last->next = list2->first;
    this->length += list2->length;
    free(list2);
}

List* newList(int dataSize, void (*showCellData)(void*)) {
    List* list = malloc(sizeof(List));
    list->dataSize = dataSize;
    list->showCellData = showCellData;
    list->first = NULL;
    list->last = NULL;
    list->length = 0;
    return list;
}

void List_clear(List* this) {
    ListCell* cell = this->first;
    while(cell != NULL) {
        // 一旦保存
        ListCell* next = cell->next;
        deleteListCell(cell);
        cell = next;
    }
    this->first = NULL;
    this->last = NULL;
    this->length = 0;
}

void deleteList(List* this) {
    List_clear(this);
    free(this);
}
