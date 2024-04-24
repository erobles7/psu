#include "CS299_clist.h"
//Eduardo Robles
//08/29/2016

using namespace std;

int main()
{
    node * rear = NULL;
    node* new_copy = NULL;
    build(rear);
    bool a = duplicate(new_copy,rear);
    if(a)
        cout<<"\nIt copied\n";
    else
        cout<<"\nIt didnt copy";
    display_all(new_copy);
    
    //PLEASE PUT YOUR CODE HERE to call the functions
   // display_all(rear); //resulting list after your function call!
    destroy(rear);
    
    return 0;
}
