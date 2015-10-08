/*
ListCellStructにメンバを追加
newListCellの.cと.hを共に編集
showを編集
*/

struct ListCellStruct {
    int id;
    char name[20];
    struct ListCellStruct* next;
};
typedef struct ListCellStruct ListCell;
ListCell* newListCell(int id, char name[]);
void deleteListCell(ListCell* this);
void ListCell_show(ListCell* this);
// thisが小さければ-1, 大きければ1、同じなら0
int ListCell_Compare(ListCell* this, ListCell* listCell2);


typedef struct {
    ListCell* first;
    ListCell* last;
    int length; //がんばって計算してるので代入禁止
} List;
// 末尾に追加
void List_append(List* this, ListCell* cell);
// 特定の位置を削除
void List_remove(List* this, int index);
// 特定の位置に挿入
void List_insert(List* this, int index, ListCell* insertCell);
// すべて表示
void List_show(List* this);
// 長さを取得
int List_getLength(List* this);
// 特定の要素をget
ListCell* List_get(List* this, int index);
// 特定のオブジェクトが含まれているか、なければ-1、あればindex
int List_find(List* this, ListCell* obj);
// リストをすべてクリア
void List_clear(List* this);
// リストを連結
void List_extend(List* this, List* list2);
// コンストラクタ、デストラクタ(要素も全て破棄)
List* newList();
void deleteList(List* this);
