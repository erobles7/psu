#include "CS299_dlist.h"
//Eduardo Robles
//09/02/2016
using namespace std;

int main()
{
    node * head = NULL;
    node* new_copy = NULL;
     build(head);
     display_all(head);
    
    //PLEASE PUT YOUR CODE HERE to call the functions
    bool x  = duplicate(new_copy,head);
    display_all(head);
    cout << "The new copy is "<< endl;
    display_all(new_copy);
    destroy(head);    
    return 0;
}
