#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    //int x = object.display_first_last();

    //std::cout<<"$: "<<x<<"\n";
    
    bool x = object.remove_except();

    if(x)
        std::cout<<"\nThe result was true\n";
    else
        std::cout<<"\nThe result was false\n";
    

    object.display();  //displays the LLL again!
   
    
    return 0;
}
