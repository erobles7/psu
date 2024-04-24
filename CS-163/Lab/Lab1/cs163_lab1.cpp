#include "cs163_list.h"
using namespace std;

int main()
{
    
    //First try this out as is. Then start adding in your function calls!
    list my_list;
    my_list.build();
    my_list.display_all();
    list new_list;

    //PLACE YOUR FUNCTION CALL HERE!
    //int total = my_list.sum_total();
    if(my_list.copy(new_list))
        std::cout<<"The list was copied "<<std::endl;
    else
        std::cout<<"The list was not copied "<<std::endl;

    //my_list.display_all();
    std::cout<<"\n\n";
    new_list.display_all();
    return 0;    
}
