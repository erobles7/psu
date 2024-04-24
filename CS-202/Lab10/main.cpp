#include "table.h"
using namespace std;

int main()
{
    table BST;	
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    int x = BST.sum();

   cout<<"----"<<x<<"---------"<<endl;



    BST.display(0);

    return 0;
}
