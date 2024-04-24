#include "CS299_arr.h"

/******************************************
 * Display entire array of LLL in reverse 
 * ****************************************/
int table::display_reverse()
{
    if(!head)
        return 0;

    return display_reverse(head,size-1);

}
int table::display_reverse(node** head,int index)
{
    int count;

    if(!head || index <  0)
        return 0;

    count = display_reversePrivate(*(head+index)); 
    cout<<endl; 
    return count + display_reverse(head,--index);
}

int table::display_reversePrivate(node* head)
{
    int count = 0;
    
    if(!head)
        return 0;
    count = display_reversePrivate(head->next)+1;
    cout<< head->data<<"  ";
    return count;
}

/*****************************************
 * Average of all data in Array of LLL
 * **************************************/
float table::average_all()
{
    int count = 0;

    if(!head)
        return 0;
    float sum  = average_all(head,size-1,count);
    cout<<sum<<endl; 
    return (sum/count);
}

float table::average_all(node** head, int index, int& count)
{
    int sum = 0;
        
    if(!head || index < 0)
        return 0;

     sum = average_all(*(head+index),count);

    return sum + average_all(head,--index,count);
}

int  table::average_all(node* head, int& count)
{
    int sum = 0;

    if(!head)
        return 0;
    sum = head->data+ average_all(head->next,++count);

    return sum;
}

/*********************************************
 * Make a complete copy of an Array of LLL
 * ******************************************/
int table::copy_arr(table& copy)
{
    if(!head)
        return 0;
    copy.head = new node* [size];
    copy.size = size;

    return copy_arr(head,copy.head,size-1);
}
int table::copy_arr(node** head,node** copy,int index)
{
    int count;

    if(!head || index < 0)
        return 0;
    
    count = copy_arr(*(copy+index),*(head+index));
    
    return count+copy_arr(head,copy,--index);
}
int table::copy_arr(node*& new_copy, node* original)
{

    if(original == NULL)
    {
        new_copy = NULL;
        return 0;

    }
    new_copy = new node;
    new_copy->data = original->data;

    return 1+copy_arr(new_copy->next, original->next);
    
}
node** table::getHead()
{
    return head;
}
