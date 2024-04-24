#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int x = object.largest_two();

    std::cout<<"\n------  "<<x<<"\n";


    object.display(); //resulting list after your function call!
    
    return 0;
}
