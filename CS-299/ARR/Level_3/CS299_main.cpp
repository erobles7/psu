#include "CS299_arr.h"
//Eduardo Robles
//09//09/2016


int main()
{
    table object; 
    table object2;
    object.build(); //creates an array of LLL
    object.display(); //displays the array

    //PLEASE PUT YOUR CODE HERE to call the functions
    int  num = object.copy_arr(object2);
    cout<<"\nThe number of nodes copied was  "<<num<<endl;
    cout<<"Here is the copied list fam\n\n"<<endl;

    object2.display();
   // object.display();  //display again afterward!
    
    
    return 0;
}
