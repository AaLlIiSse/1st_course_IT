#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int TreeItem;
typedef struct _tree Tree;
/*typedef struct {
  TreeItem data;
  Tree *child;
  Tree *sibling;
} Tree;*/

Tree *tree_create(TreeItem value);
Tree *tree_add_node(Tree *parent, TreeItem value);
void tree_node_print(TreeItem value, int indent);
//void tree_show(Tree *t, int indent);
void tree_print(Tree *t);

#endif
