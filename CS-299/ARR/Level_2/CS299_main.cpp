#include "CS299_arr.h"
//Eduardo Robles
//09/08/2016
using namespace std;

int main()
{
    node * head[SIZE] = {0,0,0,0,0};
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the functions
   int count = add_last(head,SIZE);  
    display_all(head);
    cout<<" The number of nodes added  is "<<count <<endl;
    destroy(head);
    
    return 0;
}
