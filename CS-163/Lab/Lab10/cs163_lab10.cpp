#include "cs163_tree.h"
using namespace std;

int main()
{
    table trees;
    trees.build();
    trees.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    std::cout<<"\n\n";
    table taco;
    taco.copy(trees);

    taco.display();
    return 0;

}
