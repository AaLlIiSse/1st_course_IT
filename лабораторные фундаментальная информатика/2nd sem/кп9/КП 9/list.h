//
// Created by boris on 13.05.2021.
//

#ifndef KP9_LIST_H
#define KP9_LIST_H
#include "stdio.h"
#include <stdlib.h>
#include "string.h"
#include <stdbool.h>

struct str_int{

    int value;
    char* string;

};

struct Node
{

    struct str_int key;
    char* data;
    struct Node* next;

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

typedef struct Node* ListIterator;

void set_element(struct Node* _node, struct str_int key, char* data){
    if (_node != NULL){

        _node->key = key;
        _node->data = data;

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

void pushBack(struct List* _list, struct str_int key, char* data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    set_element(newNode, key, data);

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

void printList(struct List* _list){
    printf("list: \n");
    struct Node* curNode = begin(_list);
    while (curNode != end(_list)){
        printf("%s%s\t%d\t", "key: ", curNode->key.string, curNode->key.value);
        printf("%s%s\n", "data: ", curNode->data);
        curNode = next(curNode);
    }
    printf("\n");
}

void destroyList(struct List* _list){

    struct Node* deletedNode = begin(_list);
    if (deletedNode == end(_list)){
        return;
    }
    struct Node* nextNode = next(deletedNode);
    while (nextNode != end(_list)){
        printf("%s %s\n", deletedNode->data, nextNode->data);
        free(deletedNode->key.string);
        free(deletedNode->data);
        free(deletedNode);
        deletedNode = nextNode;
        nextNode = next(nextNode);
    }
    free(deletedNode->key.string);
    free(deletedNode->data);
    free(deletedNode);

}
bool tableSorted = false;
void linear_sort(struct List* _list){
    struct Node* curNode = begin(_list);
    while(next(curNode) != end(_list)){
        if(strcmp(curNode->key.string, next(curNode)->key.string) > 0){
            struct Node tmp = { .key = curNode->key, .data = curNode->data };
            curNode->key = curNode->next->key;
            curNode->data = curNode->next->data;
            next(curNode)->key = tmp.key;
            next(curNode)->data = tmp.data;
            curNode = begin(_list);
        }
        else if (strcmp(curNode->key.string, next(curNode)->key.string) == 0){
            if(curNode->key.value > next(curNode)->key.value){
                struct Node tmp = { .key = curNode->key, .data = curNode->data };
                curNode->key = next(curNode)->key;
                curNode->data = next(curNode)->data;
                next(curNode)->key = tmp.key;
                next(curNode)->data = tmp.data;
                curNode = begin(_list);
            }
            else curNode = next(curNode);
        }
        else curNode = next(curNode);
    }
    tableSorted = true;
}
void simplesearch(ListIterator begin, ListIterator end, struct str_int key){
    ListIterator curNode;
    curNode = begin;
    int i = 0;
    bool element_found = false;
    while(curNode != end){
        if ((strcmp(curNode->key.string, key.string) == 0) && (curNode->key.value == key.value)) {
            printf("%s%d", "element found. it's position is ", i);
            element_found = true;
            curNode = next(curNode);
        }
        else curNode = next(curNode);
        i++;
    }
    if (element_found == false) printf("%s", "element not found");
}

struct Node* get_Item_by_index(ListIterator begin, int index){
    ListIterator curIterator = begin;
    for (int i = 0; i < index; i++){
        curIterator = next(curIterator);
    }
    return curIterator;
}

/*void ValuebyKey(struct List* _list, struct str_int _key){
    struct Node* curNode = begin(_list);
    while (curNode != end(_list)){
        if ((strcmp(curNode->key.string, _key.string) == 0) && (curNode->key.value == _key.value)){
            printf("%s%s", "Data by key: ", curNode->data);
        }
        else {
            printf("No data have been searched by that key ");
        }
        curNode = next(curNode);
    }
}*/

void ValuebyKey(struct List* _list, struct str_int _key){
    int count = 0;
    struct Node* curNode = begin(_list);
    while (curNode != end(_list)){
        if ((strcmp(curNode->key.string, _key.string) == 0) && (curNode->key.value == _key.value)){
            printf("%s%s", "Data by key: ", curNode->data);
            count += 1;
        }
        curNode = next(curNode);
    }
    if (count == 0){
        printf("No data by that key has founded");
    }
}

void binarysearch(struct List* _list, ListIterator begin, ListIterator end, struct str_int key){
    bool element_found = false;
    int left = 0;
    int right = distance(begin, end) - 1;
    int mid = (distance(begin, end) + 0) / 2;
    while(left <= right){
        mid = (left + right) / 2;
        if (strcmp(key.string, get_Item_by_index(begin, mid)->key.string) == 0 && key.value == get_Item_by_index(begin, mid)->key.value){
            element_found = true;
            printf("%s%d%s", "element found. it's position is ", mid);
            ValuebyKey(_list, key);
            break;
        }
        if (strcmp(key.string, get_Item_by_index(begin, mid)->key.string) < 0 ||
        (strcmp(key.string, get_Item_by_index(begin, mid)->key.string) == 0 && key.value < get_Item_by_index(begin, mid)->key.value)){
            right = mid - 1;
        }
        else left = mid + 1;
    }
    if (element_found == false) printf("%s", "element not found");

}


/*void binarysearch(ListIterator begin, ListIterator end, struct Node * _node){
    bool element_found = false;
    int left = 0;
    int right = distance(begin, end) - 1;
    int mid = (distance(begin, end) + 0) / 2;
    while(left <= right){
        mid = (left + right) / 2;
        if (strcmp(_node->key.string, get_Item_by_index(begin, mid)->_node->key.string) == 0 && _node->key.value == get_Item_by_index(begin, mid)->_node->key.value){
            element_found = true;
            printf("%s%d%s%c", "element found. it's position is ", mid, "data: ", _node->data);
            break;
        }
        if (strcmp(_node->key.string, get_Item_by_index(begin, mid)->_node->key.string) < 0 ||
        (strcmp(_node->key.string, get_Item_by_index(begin, mid)->_node->key.string) == 0 && _node->key.value < get_Item_by_index(begin, mid)->_node->key.value)){
            right = mid - 1;
        }
        else left = mid + 1;
    }
    if (element_found == false) printf("%s", "element not found");

}*/

#endif //KP9_LIST_H
