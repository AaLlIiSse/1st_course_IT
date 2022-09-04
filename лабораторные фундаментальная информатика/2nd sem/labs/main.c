#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
//#define max(a, b) ((a) > (b) ? (a) : (b))

typedef int TreeItem;

struct _tree {
  TreeItem data;
  Tree *child;
  Tree *sibling;
};

int max(int a, int b){
  if (a > b){
    return a;
  } else {
    return b;
  }
}

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

void tree_show(Tree *t, int x){
  if (t == NULL){
    return;
  }
  for (int i = 0; i < x; i++) {
          printf("\t");
      }
      printf("%d\n", t->data);
      tree_show(t->child, x+1 );
      tree_show(t->sibling, x);

}

void tree_print(Tree *t){
  tree_show(t, 0);
}

void print_siblings(Tree *t){
  if (t == NULL){
    return;
  }
  while (t != NULL){
    printf("%d ", t->sibling->data);
    print_siblings(t->sibling);
  }
}

void *search(Tree *t) {
   if (t->child == NULL){
       if (t->sibling == NULL){
        printf("%d ", t->data);
    } else {
     search(t->sibling);
    }
  }
    else (t->child != NULL) {
        search(t->child);
    }
}
}
int main(/*int argc, char *argv[]*/){
  Tree *t = tree_create(1);
  Tree *f = tree_add_node(t, 3);
  tree_add_node(t, 2);

  tree_add_node(t, 4);
  Tree *g = tree_add_node(f, 5);
  tree_add_node(g, 8);

  Tree *h = tree_add_node(g, 10);
  Tree *j = tree_add_node(h, 13);
  Tree *k = tree_add_node(j, 230);
  Tree *s = tree_add_node(k, 66);
  tree_print(g);
  search(g);

}
