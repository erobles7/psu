#include "CS299_dlist.h"
//Eduardo Robles
//
using namespace std;


int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the functions
    int sum  = object.sum_largest_two();
    object.display();
    cout<<"\n\nThe sum of the largest two data items is  "<<sum<<endl;
    
    
    return 0;
}
