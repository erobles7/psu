#include "CS299_dlist.h"
/*
 * Eduardo Robles
 * 09/01/2016
 */

//remove every item larger than the first
int remove_larger(node*& head)
{
    int count = 0;

    if(!head)
        return 0;
    if(head->previous == NULL && head->next == NULL)
        return 0;

     node* current = head->next;

     while(current!= NULL)
     {
         if(current->data > head->data)
         {
             node* temp = current;
             current->previous->next = current->next;
             if(current->next !=  NULL)
                current->next->previous = current->previous;
             current = current->next;
             delete temp;
             count++;
         }
         else
            current = current->next;
     }
    return count;
}

//remove every other item
int remove_every_other(node*& head)
{
    int count = 0;

    if(!head || head->next == NULL)
        return 0;

    node* current = head;

    while(current != NULL)
    {
        if(current->next != NULL)
        {
            node* temp = current->next;
            current->next = temp->next;
           if(temp->next != NULL)
                temp->next->previous = current;
          delete temp;
          count++;
          current = current->next;
        }
        else
            current = current->next;
    }
    return count;
}

//duplicate every item that is a 2 
int duplicate_2(node*& head)
{
    int count = 0;
    if(!head)
        return 0;
    
    node* current = head;
    while(current != NULL)
    {
       if(current->next != NULL)
       {
         if(current->data == 2)
         {
             node* temp = current;
             current = new node;
             current->data = temp->data;
             current->next = temp->next;
             current->previous = temp;
             current->next->previous = current;
             temp->next = current;
             count++;
         }
        current = current->next;
       }
     else
        current = current->next;
    }
    return count;
}
