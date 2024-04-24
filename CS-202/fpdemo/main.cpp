#include "table.h"

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */

    int x = object.remove_smallest();

    std::cout<<"\n\n---------  "<<x<<" ------------\n";

    object.display();	//displays again after!
   
    return 0;
}
