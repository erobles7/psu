#include "CS299_bst.h"

int main()
{
    node * root = NULL;
    build(root);
    display_all(root);
    node* new_copy = NULL;

    int x = copy(new_copy,root);
    

    display_all(root);
    display_all(new_copy);

    destroy(root);
    destroy(new_copy);
    return 0;
}
