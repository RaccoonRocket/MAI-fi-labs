#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

int length;

typedef struct tree
{
    char key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
}tree;

tree *create(tree *root, char key);
tree *add_node_right(tree *root);
tree *add_node_left(tree *root);
void tree_print(tree *root, int n);
int is_this_operator(char a);
tree *make_it(tree *root, st *result);

#endlf
