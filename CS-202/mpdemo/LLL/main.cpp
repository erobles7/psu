#include "list.h"
using namespace std;

int main()
{
    list object;
    list new_list;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int x = object.remove_all_but_last();
  
     cout<<"\n"<<x<<"\n";

    //object.display_only_last();
    

    object.display();  //displays the LLL again!
    
   
    
    return 0;
}
