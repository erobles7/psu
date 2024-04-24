#include "CS299_clist.h"
//Eduardo Robles
//08/31/2016

int main()
{
    list object;
    object.build();	//builds a circular LL
    object.display();	//displays the list
    int num = object.add_before();
 //   list new_copy;
//    float average = object.copy_two(new_copy);
    //PLEASE PUT YOUR CODE HERE to call the functions
    //object.display(); //resulting list after your function call!  return 0;
    //std::cout<<"The average of the last two items is "<<average<<endl;
    //new_copy.display();
    object.display();
    std::cout<<"\n\n\nThe number of new items is "<<num<<endl;

    return 0;
}
