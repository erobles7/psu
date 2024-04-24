#include "CS299_bst.h"
//Eduardo Robles

int main()
{
    node * root = NULL;
    node* duplicate = NULL;
    build(root);
    display_all(root);
    int num = copyWithoutRoot(duplicate,root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    std::cout<<"The number of nodes is  "<<num<<endl;
    //display_all(root);
    display_all(duplicate);
    destroy(root);
    destroy(duplicate);

    return 0;
}
