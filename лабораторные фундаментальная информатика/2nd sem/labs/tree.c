/*#include <stdio.h>
#include "tree.h"
#include <stdlib.h>

#include "tree.h"

typedef int TreeItem;

struct _tree {
  TreeItem data;
  Tree *child;
  Tree *sibling;
};

Tree *tree_create(TreeItem value){
  Tree *tree = (Tree *) malloc(sizeof(Tree));

  tree->data = value;
  tree->child = NULL;
  tree->sibling = NULL;

  return tree;
}

Tree *tree_add_node(Tree *parent, TreeItem value){
  Tree *res = tree_create(value);
  if (parent->child == NULL){
    parent->child = res;
  } else {
       Tree *last = parent->child;
       while (last->sibling != NULL){
         last = last->sibling;
       }
       last->sibling = res;
  }
  return res;
}

void tree_print_node(TreeItem value, int indent){
  for(int i = 0; i < indent; ++i){
    printf(" ");
  }
  printf("%d\n", value);
}

void tree_show(Tree *t, int indent){
  if (t == NULL){
    exit(2);
  }
  tree_show(t->sibling, indent + 2);
  tree_print_node(t->data, indent);
  tree_show(t->child, indent + 2);
}

void tree_print(Tree *t){
  tree_show(t, 0);
}*/
#include <stdio.h>
#include <stdlib.h>

#define DEEP 0

#define max(x,y) ((x) > (y) ? (x) : (y))

struct tnode {
        float value;
        struct tnode *son;
        struct tnode *brother;
        struct tnode *parent;
};
typedef struct tnode node;
typedef struct {
        node *root;
} Tree;
node *create_node(float f, node *par) {
        node *t;
        t = (node *) malloc(sizeof(node));
        t->value = f;
        t->son = NULL;
        t->brother = NULL;
        t->parent = par;
        return t;
}
Tree *create_tree(float f) {
        Tree *t;
        t = (Tree *) malloc(sizeof(Tree));
        t->root = create_node(f, NULL);
        return t;
}
node *search_tree(node *t, float f) {
        if (t == NULL){
                return t;
        }
        node *tree = NULL;
        if (t->value == f) {
                return t;
        }
        if (t->son != NULL) {
                tree = search_tree(t->son, f);
        }
        if (tree == NULL) {
                tree = search_tree(t->brother, f);
        }
        return tree;
}
void add_node_in_tree(Tree *tree, float par_f, float f) {
        node *t = tree->root;
        t = search_tree(t, par_f);
        if (t == NULL) {
                printf("%-.2f Родитель не содержится в дереве\n", par_f);
                return;
        }
        if (t->son == NULL) {
                t->son = create_node(f, t);
        } else {
                t = t->son;
                while (t->brother != NULL) {
                        t = t->brother;
                }
                t->brother = create_node(f, t->parent);
        }
}
void delete_node(Tree *tree, float f) {
        node *t = tree->root;
        t = search_tree(t, f);
        if (t == NULL) {
                printf("%-.2f Вершина не содержится в дереве\n", f);
                return;
        }
        if (t->parent->son == t){
                t->parent->son = t->brother;
        }
        else{
                node *tr = t->parent->son;
                while (tr->brother != t){
                        tr = tr->brother;
                }
                tr->brother = t->brother;
        }
        free(t);
}
void print_tree(node *t, int x) {
        if (t == NULL) {
                return;
        }
        for (int i = 0; i < x; i++) {
                printf("\t");
        }
        printf("%-.2f\n", t->value);
        print_tree(t->son, x + 1);
        print_tree(t->brother, x);
}

int max_level(node *t, int deep){
    if(!t) return deep - 1;
    return max(max_level(t->son, deep + 1), max_level(t->brother, deep));
}

void noad_search(node *t, int start, int n){
   if (start == n){
     printf("%-3.f", t->value);
   }
   else{
     if(t->son){
       noad_search(t->son, start + 1, n);
   }
     if(t->brother){
       noad_search(t->brother, start, n);
     }
 }
}

  int main() {
        Tree *t = NULL;
        int a, g = 1;
        while (g) {
                printf("1. Create tree\t 2. Add node to tree\t 3. Delete node from tree\t 4. Zadacha\t 5. Print tree\t 6. Exit \n");
                scanf("%d", &a);
                switch (a) {
                        case 1: {
                                printf("Напишите корень дерева\n");
                                float f;
                                scanf("%f", &f);
                                t = create_tree(f);
                                break;
                        }
                        case 2: {
                                printf("Напишите значение дерева\n");
                                float f, par_f;
                                scanf("%f", &f);
                                printf("Напишите значение родителя\n");
                                scanf("%f", &par_f);
                                add_node_in_tree(t, par_f, f);
                                break;
                        }
                        case 3: {
                                printf("Напишите значение дерева\n");
                                float f;
                                scanf("%f", &f);
                                delete_node(t, f);
                                break;
                        }
                        case 4: {
                          int tree_deep = max_level(t->root, 0);
                                noad_search(t->root, 1, tree_deep);
                                break;
                        }
                        case 5: {
                                print_tree(t->root, 0);
                                break;
                        }
                        case 6: {
                                g = 0;
                                break;
                        }
                        default: {
                                printf("Введите нужную цифру\n");
                        }
                }
        }
        return 0;
}
