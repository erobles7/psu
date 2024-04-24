#include "dlist.h"



int list::display_reverse()
{
    if(!head)
        return 0;

    return display_reverse(tail);
}

int list::display_reverse(node* head)
{
    if(!head)
        return 0;

    std::cout<<head->data<<" ";

    return display_reverse(head->previous);
}

int list::reverse()
{
    if(!head)
        return 0;

    reverse_list(head,tail);

    //return reverse(head,tail);
    return 1;
}

void list::reverse_list(node*& head, node*& tail)
{
    if(head == tail)
    {
        tail->data = head->data;
        return;
    }

     head->data = tail->data;

    reverse(head->next,tail->previous);
}

int list::reverse(node*& head, node*& tail)
{
    int count = 0;
    int sum = 0;

    sum = reverse(head,tail,count);

   return (sum/count);
}

int list::reverse(node*& head,node*& tail, int& count)
{
    int sum = 0;

    if(!head)
        return 0;

    if(head->data % 2 != 0)
    {
        sum+= head->data;
        ++count;
    }

   return sum+reverse(head->next,tail,count);
}
