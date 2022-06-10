#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "tree.h"
#include "struct.h"

int conder = 0;
int studer = 2;
tree *guard = NULL;

tree *create(tree *root, char key)
{
    tree *tmp = malloc(sizeof(tree));
    tmp -> key = key;
    tmp -> parent = NULL;
    tmp -> left = tmp -> right = NULL;
    root = tmp;
    return root;
}

tree *add_node_right(tree *root)
{
    tree *root_new = root;
    tree *root_parent = root;
    tree *tmp = malloc(sizeof(tree));
    root_new = root -> right;
    tmp -> key; //=NULL - warning
    tmp -> parent = root_parent;
    tmp -> right = NULL;
    tmp -> left = NULL;
    root -> right = tmp;
    return root;
}

tree *add_node_left(tree *root)
{
    tree *root_new = root;
    tree *root_parent = root;
    tree *tmp = malloc(sizeof(tree));
    root_new = root -> left;
    tmp -> key; //=NULL - warning
    tmp -> parent = root_parent;
    tmp -> right = NULL;
    tmp -> left = NULL;
    root -> left = tmp;
    return root;
}

void tree_print(tree *root, int n)
{
    if (root != NULL) {
        tree_print(root->right, n + 1);
        for (int i = 0; i < n; i++) printf("\t");
        printf("%c\n", root->key);
        tree_print(root->left, n + 1);
    }
}
/*---------------------------------*/

int is_this_operator(char a)
{
    if (isdigit(a) || isalpha(a) || isspace(a)) return 0;
    else return 1;
}

tree *go_up(tree *root) {
    if ((is_this_operator(root->key) == 1 && root -> left == NULL) || (root == guard))
        return root;
    else
        root = go_up(root -> parent);
}
/*---------------------------------*/

tree *make_it(tree *root, st *result) {
    char s;
    int i = 0;
    while (i < length) {
        s = pop(&result);
        if (conder == 0) {
            root = create(root, s);
            guard = root;
            conder++;
        } else {
            if (conder == 1) {
                root = add_node_right(root);
                root = root -> right;
                root -> key = s;
                    if (is_this_operator(s) == 0) {
                        root = go_up(root);
                        conder++;
                    }
            }
            else if (conder == 2) {
                root = add_node_left(root);
                root = root -> left;
                root -> key = s;
                if (is_this_operator(s) == 0)
                    root = go_up(root);
                else
                    conder = 1;
                if (root == guard)
                    conder = 2;
            }
        }
        i++;
    }
    return guard;
}
