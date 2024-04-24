#include "CS299_list.h"
//Eduardo Robles

int main()
{
    list object;
    list newObject;
    object.build();       //builds a LLL
    object.display();     //displays the LLL
    int largest = object.return_largest();
    //PLEASE PUT YOUR CODE HERE to call the functions
    cout<< "The largest object was "<<largest<<endl;
    object.display();  //displays the LLL again!
    
    return 0;
}
