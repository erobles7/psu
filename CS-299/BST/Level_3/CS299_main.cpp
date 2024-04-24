#include "CS299_bst.h"
//Eduardo Robles
//

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    int num = object.display_smaller();
    
    std::cout<<"\n\nThe number of  smaller nodse is  "<<num<<endl;

    //object.display();	//displays again after!
   
    return 0;
}
