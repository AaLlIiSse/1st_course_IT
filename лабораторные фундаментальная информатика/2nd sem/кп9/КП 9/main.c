#include "list.h"

int main(){
    printf("+ - add el into end of table, s - sort table, ? - search by key\n");
    struct List list = createList();
    int symb;
    
    while ((symb = getchar()) != EOF) {
        switch (symb) {

            case '+': {

                struct str_int key;
                char text[100];
                char* data = (char*) malloc(sizeof(data));
                char* string = (char*) malloc(sizeof(string));
                int value;
                fgets(text, 100, stdin);
                sscanf(text," %s%d%s", string, &value, data);
                key.string = string;
                key.value = value;
                pushBack(&list, key, data);
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
            case 's':{
                linear_sort(&list);
                break;

            }
            case '?':{
                struct str_int key;
                char text[100];
                char* string = (char*) malloc(sizeof(string));
                int value;
                struct Node* curNode = begin(&list);
                fgets(text, 100, stdin);
                sscanf(text," %s%d", string, &value); //ввожу ключ (строка + целое)
                key.string = string;
                key.value = value;
                struct str_int memory;
                memory.string = key.string;
                memory.value = key.value;
                if(tableSorted) binarysearch((&list), begin(&list), end(&list), memory);
                //if(!tableSorted) simplesearch(begin(&list), end(&list), key);
                free(string);
                break;
            }

        }

    }

    destroyList(&list);
    return 0;
}