#include "CS299_list.h"

int list::return_largest()
{ 
    return return_largest(head);
}
int list::return_largest(node* head)
{
    if(!head)
        return 0;
    if(head->next == NULL)
        return head->data;

    int largest = 0;
    return return_largestPrivate(head,largest);
}
int list::return_largestPrivate(node* head,int& largest)
{

    if(head == NULL)
        return 0;
    if(head->next != NULL)
    {
        if(head->data > largest)
        {
            largest = head->data;
        }
        return return_largestPrivate(head->next,largest);
    }
  return largest;
}
