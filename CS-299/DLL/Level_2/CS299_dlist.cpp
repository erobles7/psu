#include "CS299_dlist.h"
/*
 * Eduardo Robles
 */

/***************************
 * Sum the data of last two
 * *************************/
int sum_last_two(node* head)
{
   int sum = 0; 
    if(!head)
        return 0;

    if(head->next != NULL)
       sum = sum_last_two(head->next);

    else
        sum = head->data + head->previous->data;
    
    return sum;
}
/********************************
 * Display DLL in reverse 
 * *****************************/
int display_reverse(node* head)
{
    int last = 0;

    if(!head)
        return 0;
    
    last = display_reverse(head->next);
    cout<< head->data<<" ";

    if(last == 0)
        return head->data;

    return last;
}

/***********************************
 * Add unique node at the end 
 * ********************************/
int addUnique(node*& head,int num)
{
    if(!head)
    {
        head = new node;
        head->data = num;
        head->previous = NULL;
        head->next = NULL;
        return 1;
    }
    if(head->next == NULL)
    {
        if(head->data != num)
        {
            head->next = new node;
            head->next->data = num;
            head->next->previous = head;
            head->next->next = NULL;
            return 1;
        }
        else
            return 0;
    }

    return addUniquePrivate(head,num);
}
int  addUniquePrivate(node*& head, int num)
{
    int count; 

    if(head->next == NULL)
    {
        if(head->data == num)
            return 0;
        else
        {
            head->next = new node;
            head->next->data = num;
            head->next->next = NULL;
            head->next->previous = head;
            return 1;
        }
    }

    else
    {
        if(head->data == num)
            return 0;
        else
            count = addUniquePrivate(head->next,num);
    }
    return count;
}

/**********************************************
 * Duplicate copy of DLL
 **********************************************/
bool duplicate(node*& new_copy,node* original)
{
    if(!original)
        return false;
    if(original->next == NULL)
    {
        new_copy = new node;
        new_copy->data = original->data;
        new_copy->previous = NULL;
        new_copy->next = NULL;
        return true;
    }
    
    return duplicatePrivate(new_copy,original,original->previous);
}

bool duplicatePrivate(node*& dest, node* source, node*& prev)
{
    if(!source)
    {
        dest = NULL;
        return true;
    }

    dest = new node;
    dest->data = source->data;
    dest->previous = prev;
    node* previous = dest;

    return duplicatePrivate(dest->next,source->next,previous);
}


