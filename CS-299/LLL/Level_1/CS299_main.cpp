#include "CS299_list.h"

//Place your name here in comments:
//Eduardo Robles
//
//
int main()
{
    //This code sets up the list
    node * head = NULL;
     build(head);
    display_all(head);
    
    //PLEASE PUT YOUR CODE HERE to call the functions for lab
    int lastNum = copy_last(head); 
    display_all(head);
    std::cout<<"\n\nThe value of the new last node is  "<<lastNum<<std::endl;
    destroy(head);    

    return 0;
}

