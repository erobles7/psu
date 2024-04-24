#include "dlist.h"


int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int x =   object.reverse();
      
    std::cout<<"\nThe average of the odds is "<<x<<"\n\n";

    object.display();
    
    return 0;
}
