#include "CS299_list.h"

//Place your name here in comments:
//
//
//
int main()
{
    //The following code builds the linear linked list
    node * head = NULL;
     build(head);
   /* node* a = createNode(12);
    node* b = createNode(20);
    node* c = createNode(30);
    head = a;
    a->next = b;
    b->next = c;
   */ 
     display_all(head);
    
    //PLEASE PUT YOUR CODE HERE to call the functions
    remove_all(head);
    display_all(head);
    destroy(head);    

    return 0;
}
