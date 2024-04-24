#include "CS299_arr.h"
using namespace std;

/****************************************
 * Display All data except last item
 * *************************************/
int display_except(node* head[], int size, int index)
{
    if(!head || index == size)
        return 0;
    int count = display_except(*(head+index));
    cout<<endl;
    return count + display_except(head,size,++index);
}

int display_except(node* head)
{
    if(!head || !(head->next))
        return 0;

    cout<<head->data<<" ";

    return 1+ display_except(head->next);
}
/************************************************
 * Remove the enitre last list from the array
 * *********************************************/
int remove_lastLLL(node* head[],int size)
{
    if(!head)
        return 0;
    if(*(head+(size-1))== NULL)
        return 0;
   int count = remove_lastLLL(head[size-1]); 

   return count;
}

int remove_lastLLL(node*& head)
{
    if(!head)
        return 0;
    
    node* temp = head->next;
    delete head;
    head = temp;

    return 1+ remove_lastLLL(head);
}
/*******************************************
 * Add a new node to the end of each list 
 * ***************************************/
int add_last(node* head[], int size)
{
    if(!head || size < 0)
        return 0;
    int num = (*(head+(size-1)))->data;
    int count = add_last(*(head+(size-1)),num);

    return count+ add_last(head,--size);
}
int add_last(node*& head,int num)
{
    if(!head)
        return 0;

    if(head->next == NULL)
    {
        head->next = new node;
        head->next->data = num;
        head->next->next = NULL;
        return 1;
    }
    int count = add_last(head->next,num);

    return count;
}

