#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "struct.h"
#include "tree.h"
#include "transform.h"


int main() {
    struct st *result = NULL;
    result = polish_back();
    if (result == NULL){
        printf("error")
        return 0;
    }
    tree *root = NULL;
    root = make_it(root, result);
    tree_print(root, 1);
    return 0;
}
