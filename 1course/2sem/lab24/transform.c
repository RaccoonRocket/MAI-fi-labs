#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "tree.h"
#include "struct.h"



tree *num_num(tree *root) {
    if ((root->left->key) >= (root->right->key)) {
        if ((root->left->key - '0') % (root->right->key - '0') == 0) {
            int c = (root->left->key - '0') / (root->right->key - '0');
            root->left->key = NULL;
            root->right->key = NULL;
            root->key = c +'0';
            return root;
        }
    } else {
        if ((root->right->key - '0') % (root->left->key - '0') == 0) {
            int c = (root->right->key - '0') / (root->left->key - '0');
            root->left->key = '1';
            root->right->key = c + '0';
            return root;
        }
    }
    return 0;
}

tree *sigh_num(tree *root) {
    int num = (root->right->key) - '0';
    root = root->left;
    if ((47 < (root->left->key) && (root->left->key) < 58)) {
        int c = root->left->key - '0';
        if (c >= num) {
            if (c % num == 0) {
                c = c / num;
                root->left->key = c + '0';
                root->parent>right->key = NULL;
                root->parent->key = NULL;
                return root;
                }
        } else {
            if (num % c == 0) {
                c = num / c;
                root->left->key = c + '0';
                root->parent->right->key = NULL;
                root->parent->key = NULL;
                return root;
                }
        }
    }
    else if ((47 < (root->right->key) && (root->right->key) < 58)) {
        int c = root->right->key - '0';
        if (c >= num) {
            if (c % num == 0) {
                c = c / num;
                root->right->key = c + '0';
                root->parent->right->key = NULL;
                root->parent->key = NULL;
                return root;
                }
        } else {
            if (num % c == 0) {
                c = num / c;
                root->left->key = c + '0';
                root->parent->right->key = NULL;
                root->parent->key = NULL;
                return root;
            }
        }
    }
}

tree *num_sigh(tree *root) {
    int num = (root->left->key) - '0';
    root = root->right;
    if ((47 < (root->left->key) && (root->left->key) < 58)) {
        int c = root->left->key - '0';
        if (c >= num) {
            if (c % num == 0) {
                c = c / num;
                root->left->key = c + '0';
                root->parent->left->key = NULL;
                root->parent->key = NULL;
                return root;
                }
        } else {
            if (num % c == 0) {
                c = num / c;
                root->left->key = c + '0';
                root->parent->right->key = NULL;
                root->parent->key = NULL;
                return root;
                }
        }
    }
    else if ((47 < (root->right->key) && (root->right->key) < 58)) {
        int c = root->right->key - '0';
        if (c >= num) {
            if (c % num == 0) {
                c = c / num;
                root->right->key = c + '0';
                root->parent->left->key = NULL;
                root->parent->key = NULL;
                return root;
                }
        } else {
            if (num % c == 0) {
                c = num / c;
                root->left->key = c + '0';
                root->parent->right->key = NULL;
                root->parent->key = NULL;
                return root;
            }
        }
    }
}

tree *sigh_sigh(tree *root) {
    int a = -1, b = -1, c = -1, d = -1;
    if ((47 < (root->left->left->key) && (root->left->left->key) < 58)) a = (root->left->left->key) - '0';
    if ((47 < (root->left->right->key) && (root->left->right->key) < 58)) b = (root->left->right->key) - '0';
    if ((47 < (root->right->left->key) && (root->right->left->key) < 58)) c = (root->right->left->key) - '0';
    if ((47 < (root->right->right->key) && (root->right->right->key) < 58)) d = (root->right->right->key) - '0';
    if (a >= c && a % c == 0 && a != -1 && c != -1) {
        root->left->left->key = a/c + '0';
        root->right->left->key = NULL;
        root->right->key = root->right->right->key;
        root->right->right->key = NULL;
        return root;
    } if (a >= d && a & d == 0 && a != -1 && d != -1) {
        root->left->right->key = a/d + '0';
        root->right->right->key = NULL;
        root->right->key = root->right->left->key;
        root->right->left->key = NULL;
        return root;
    } if (b >= c && b % c == 0 && b != -1 && c != -1) {
        root->right->left->key = b/c + '0';
        root->left->right->key = NULL;
        root->left->key = root->left->left->key;
        root->left->left->key = NULL;
        return root;
    } if (b >= d && b % d == 0 && b != -1 && d != -1) {
        root->right->right->key = b/d + '0';
        root->left->right->key = NULL;
        root->left->key = root->left->left->key;
        root->left->left->key = NULL;
        return root;
    }
    if (c > a && c % a == 0 && a != -1 && c != -1) {
        root->left->left->key = '1';
        root->right->left->key = c/a + '0';
        return root;
    } if (d > a && d & a == 0 && a != -1 && d != -1) {
        root->left->right->key = '1';
        root->right->right->key = d/a + '0';
        return root;
    } if (c > b && c % b == 0 && c != -1 && b != -1) {
        root->right->left->key = '1';
        root->left->right->key = c/b + '0';
        return root;
    } if (d > b && d % b == 0 && d != -1 && b != -1) {
        root->right->right->key = '1';
        root->left->right->key = d/b + '0';
        return root;
    }
}

void *divided(tree *root) {
    if (root->key =='/') {
        if ((47 < (root->left->key) && (root->left->key) < 58) && (47 < (root->right->key) && (root->right->key) < 58)) {
            root = num_num(root);
        }
        if ((root->left->key) == 42 && 47 < (root->right->key) && (root->right->key) < 58) {
            root = sigh_num(root);
        }
        if (47 < (root->left->key) && (root->left>key) < 58 && (root->right->key) == 42) {
            root = num_sigh(root);
        }
        if ((root->left->key) == 42 && (root->right->key) == 42) {
            root = sigh_sigh(root);
        }
    }
    if (root->left != NULL) divided(root->left);
    if (root->right != NULL) divided(root->right);
}
