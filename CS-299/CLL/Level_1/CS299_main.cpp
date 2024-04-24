#include "CS299_clist.h"
//Eduardo Robles
//08/28/2016

using namespace std;

int main()
{
     node * rear = NULL;
      build(rear);
    // display_all(rear);
     node* newRear = NULL;
     int count = copy_all(newRear,rear);
    
    //PLEASE PUT YOUR CODE HERE to call the functions
    //display_all(rear); //resulting list after your function call!
    cout << "The number items of copied was " << count << endl;
    display_all(newRear);
    destroy(rear);
    destroy(newRear);    
    return 0;
}
