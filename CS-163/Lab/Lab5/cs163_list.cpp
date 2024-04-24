#include "cs163_list.h"

/* These are the functions you will be implementing */
/* USE RECURSION! */
int insert_after(node * & head)
{
    if(!head)
        return 0;
    
    if(head->data == 2)
    {
        node* temp = new node;
        temp->data = 99;
        if(head->next)
        {
            temp->previous = head;
            temp->next = head->next;
            head->next->previous = temp;
            head->next = temp;
            return 1+insert_after(head->next);
        }

        temp->previous = head;
        head->next = temp;
        temp->next = NULL;

        return 1 + insert_after(head->next);
    }

    return insert_after(head->next);
}

int insert_before(node * & head)
{
    int ret = 0;

    if(!head)
        return 0;

    ret = insert_before(head->next);

    if(head->data == 2)
    {
        node* temp = new node;
        temp->data = 99;
        temp->previous  = head->previous;
        temp->next = head;
        temp->next->previous = temp;
        head = temp;
        ++ret;
    }

    return ret;
}

int display_last_two(node * head)
{
    if(!head)
        return 0;
    
   if(!head->next)
       return head->data;

   if(!head->next->next)
   {
       std::cout<<head->data<<" - "<<head->next->data<<"\n";
       return head->data+head->next->data;
   }

    return display_last_two(head->next);
}
int remove_last_two(node * & head)
{
    if(!head)
        return 0;

    if(!head->next)
    {
        delete head;
        head = NULL;
        return 1;
    }



}


//challenge:
bool same_length(node * head1, node * head2)
{

    return true;
}

