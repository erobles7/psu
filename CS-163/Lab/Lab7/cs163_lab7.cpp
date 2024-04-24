#include "cs163_bst.h"
using namespace std;

int main()
{
    table BST;	
    BST.build();
//  BST.display();
     
    table taco;

    /*  PLACE YOUR FUNCTION CALL HERE */
    taco.copy(BST);

    taco.display();

    return 0;
}
