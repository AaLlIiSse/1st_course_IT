
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
struct Node
{
 
    int data;
    struct Node* next;
 
};

enum colors {
	WHITE = 1,
	BLUE,
	RED,
	YELLOW,
	GREEN,
	BARRIER,
};

struct List
{
 
    struct Node* head;
    int size;
    struct Node* end;
 
};
 
struct List createList(){
 
    struct List list;
    list.head = NULL;
    list.size = 0;
    return list;
 
}
 void enum_out(int x) {
    switch (x) {
        case 1:
            printf("WHITE");
            break;
        case 2:
            printf("BLUE");
            break;
        case 3:
            printf("RED");
            break;
        case 4:
            printf("YELLOW");
            break;
        case 5:
            printf("GREEN");
            break;
    }
    printf(" ");
}
typedef struct Node* ListIterator;
 
void set_element(struct Node* _node, int element){
 
    if (_node != NULL){
 
        _node->data = element;
 
    }
 
}
 
void set_next_element(struct Node* _node, struct Node* _next){
 
    if (_node != NULL){
 
        _node->next = _next;
 
    }
 
}
 
bool is_list_empty(struct List* _list){
 
    return _list->size == 0;
 
}
 
ListIterator end(struct List* _list){
 
    return _list->end;
 
}
 
ListIterator begin(struct List* _list){
 
    if (_list != NULL && _list->head != NULL){
 
        return _list->head;
 
    }
    else
        return end(_list);
 
}
 
ListIterator next(ListIterator It){
 
    return It->next;
 
}
 
ListIterator plus(struct List* _list, ListIterator It, int _n){
 
    if (is_list_empty(_list)){
 
        return begin(_list);
 
    }
 
    ListIterator ansIterator = It;
    int i = 0;
    while (i < _n && next(ansIterator) != end(_list)){
 
        ansIterator = next(ansIterator);
        ++i;
 
    }
    return ansIterator;
 
}
 
int distance(ListIterator _begin, ListIterator _end){
 
    int ans = 0;
    ListIterator curIt = _begin;
    while (curIt != _end){
 
        ++ans;
        curIt = next(curIt);
 
    }
    return ans;
 
}
 
void increase(struct List* _list, ListIterator _lIt, int _n){
 
    int i = 0;
    while (i < _n && _lIt != end(_list)){
 
        _lIt = next(_lIt);
 
    }
 
}
 
int getListLength(struct List* _list){
 
    return distance(begin(_list), end(_list));
 
}
 
void pushBack(struct List* _list, int _newData){
 
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    set_element(newNode, _newData);
 
    if (is_list_empty(_list)){
 
        set_next_element(newNode, end(_list));
        _list->head = newNode;
        ++_list->size;
        return;
 
    }
    struct Node* lastNode = begin(_list);
 
    while (next(lastNode) != end(_list)){
 
        lastNode = next(lastNode);
 
    }
    set_next_element(lastNode, newNode);
    set_next_element(newNode, end(_list));
    ++_list->size;
 
}
 
void popBack(struct List* _list){
 
    ListIterator prevNode = plus(_list, begin(_list), _list->size - 2);
    if (getListLength(_list) > 1){
 
        ListIterator deletedNode = next(prevNode);
        free(deletedNode);
        set_next_element(prevNode, end(_list));
        --_list->size;
 
    }
    else if (getListLength(_list) == 1){
 
        free(_list->head);
        _list->head = end(_list);
        --_list->size;
 
    }
 
}
 
void insert(struct List* _list, int _newData, int _pos){
    if (_pos > 0){
        if (is_list_empty(_list) || _pos > getListLength(_list)){
            pushBack(_list, _newData);
            return;
        }
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        set_element(newNode, _newData);
        if (_pos == 1){
            set_next_element(newNode, _list->head);
            _list->head = newNode;
            ++_list->size;
            return;
        }
 
 
        struct Node* prevNode = plus(_list, begin(_list), _pos - 2);
 
        set_next_element(newNode, next(prevNode));
        set_next_element(prevNode, newNode);
        ++_list->size;
    }
}
 
void printList(struct List* _list){
    printf("list: ");
    struct Node* curNode = begin(_list);
    while (curNode != end(_list)){
        printf("%d \n", curNode->data);
        enum_out(curNode->data);
        curNode = next(curNode);
    }
    printf("\n");
}
 
ListIterator findPrevNode(struct List* _list, int _data){
    ListIterator ans = begin(_list);
    if (ans->data == _data){
        return ans;
    }
    while (ans != end(_list)){
        if (next(ans)->data == _data){
            return ans;
        }
        else {
            ans = next(ans);
        }
    }
    return ans;
}
 
bool deleteByValue(struct List* _list, int _data){
    ListIterator prevNode = findPrevNode(_list, _data);
    if (prevNode == begin(_list)){
        if (prevNode == end(_list)){
            return false;
        }
        if (prevNode->data == _data){
            struct Node* deletedNode = prevNode;
            _list->head = next(deletedNode);
            free(deletedNode);
 
            --_list->size;
            return true;
        }
        else {
            struct Node* deletedNode = next(prevNode);
            set_next_element(prevNode, next(deletedNode));
            free(deletedNode);
            --_list->size;
            return true;
        }
 
    }
    else if (prevNode != end(_list)){
        struct Node* deletedNode = next(prevNode);
        set_next_element(prevNode, next(deletedNode));
        free(deletedNode);
        --_list->size;
        return true;
    }
    return false;
}
 
void deletePrevAndNext(struct List* _list, int _data){
 
    while (deleteByValue(_list, _data - 1));
    while (deleteByValue(_list, _data + 1));
 
}
 
 
void destroyList(struct List* _list){
 
    struct Node* deletedNode = begin(_list);
    if (deletedNode == end(_list)){
        return;
    }
    struct Node* nextNode = next(deletedNode);
    while (nextNode != end(_list)){
        printf("%d %d\n", deletedNode->data, nextNode->data);
        free(deletedNode);
        deletedNode = nextNode;
        nextNode = next(nextNode);
    }
    free(deletedNode);
 
}
int deleteByPosition(struct List* _list, int position){
    ListIterator Data = begin(_list);
    for(int i = 1; i < position; i++){
        Data = next(Data);
    }
    return Data->data;
}

void menu(){
    printf("+ add el., '-' pop el. from the end of list, t - task, d - delete from list, i - put el. in entered position, p - print, l - lenght\n");
}

int main(){
    menu();
    printf("\n");
    printf("Add and delete: 1 - for WHITE, 2 - for BLUE, 3 - for RED, 4 - for YELLOW, 5 - for GREEN\n");
    char *strings_colors[] = {"WHITE", "BLUE", "RED", "YELLOW", "GREEN"};
    struct List list = createList();
    int symb;
    while ((symb = getchar()) != EOF) {
        switch (symb) {
            case '+': {
                getchar();
                int newElem;
                scanf("%d", &newElem);
                getchar();
                pushBack(&list, newElem);
                break;

            }

            case 'p': {

                printList(&list);
                break;

            }
            case '-': {

                popBack(&list);
                break;

            }
            case 't': {

                getchar();
                int elem;
                scanf("%d", &elem);
                deletePrevAndNext(&list, elem);
                break;

            }
            case 'i': {

                getchar();
                int newElem;
                scanf("%d", &newElem);
                getchar();
                int position;
                scanf("%d", &position);
                insert(&list, newElem, position);
                break;

            }
            case 'd':{

                getchar();
                int position;
                scanf("%d", &position);
                deleteByValue(&list, deleteByPosition(&list, position));
                break;

            }
            case 'l':{
                int len = getListLength(&list);
                printf("Length: %d\n", len);
            }
        }
    }

    destroyList(&list);
 return 0;
}
