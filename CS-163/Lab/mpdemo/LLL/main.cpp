#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    
 /*   
    node* temp = new node;
    temp->data = 12;
    temp->next = NULL;
    head = temp;
   
    node* z = new node;
    z->data = 99;

    temp->next = z;
    */
/*
    node* a = new node;
    a->data =100;
    z->next = a;
    a->next = NULL;

    */

    display(head);
    std::cout<<"\n--------------\n";

    //PLEASE PUT YOUR CODE HERE to call the function assigned
//    int x  = count(head);
    int x = move_front_to_end(head);

    if(x == 0)
        std::cout<<"The last item is a two\n\n";

    display(head); //redisplay the list after your function
    destroy(head); 
    return 0;
}
