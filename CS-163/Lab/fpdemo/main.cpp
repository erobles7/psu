#include "table.h"

int main()
{
    node * root = NULL;
    node * new_root = NULL;
    

    build(root);
    display(root);

   // copy_even(new_root,root);

    //int x = count_twos(root);

    //std::cout<<"\n"<<x<<"\n";

    display_in_order(root);
 
    std::cout<<"\n-----------------\n";

  //  display(root);



    remove_all(root);
    remove_all(new_root);

    return 0;
}

