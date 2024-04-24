#include "cs163_list.h"
using namespace std;

int main()
{
    node * head = NULL;
    //build(head);
    head = new node;
    head->data = 12;
    head->next = NULL;
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int x = display_last_two(head);

    std::cout<<"\n\nThe total of last two is "<<x<<std::endl;

    display(head);
    
    return 0;
}
