#include "CS299_dlist.h"
/*
 * Eduardo Robles
 * 09/01/2016
 */
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the functions
    int count = remove_every_other(head);
    cout << "Number of items removed"<< count<<endl;
    display_all(head);
    destroy(head);    
    return 0;
}
