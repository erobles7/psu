#include "table.h"

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    std::cout<<"----------------------\n";
    //longestPath(root);
    //int x = avgData(root);
    displayReverse(root);

    //display(root);
    //std::cout<<"The average is "<<x<<std::endl;

    return 0;
}
