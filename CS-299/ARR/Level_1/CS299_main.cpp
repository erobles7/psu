#include "CS299_arr.h"
using namespace std;
/*
 * Eduardo Robles
 * 09/07/2016
 */

int main()
{
    node * head[SIZE] = {0,0,0,0,0};
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the functions
    int a = remove_all(head,SIZE);
    
    cout<<"\nThe number of nodes removed \n"<<a<<endl;

    display_all(head);
    destroy(head);
    
    return 0;
}
