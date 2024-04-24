#include "cs163_list.h"
using namespace std;

//Sum  all of the data together in a LLL
int list::sum_total()
{
    if(!head)
        return 0;

    return sum_total(head);
}

//Now implement the function recursively!
int list::sum_total(node * head)
{
    if(!head)
        return 0;

    return head->data + sum_total(head->next);
}

// *************************************************
//Remove the last node in a LLL. Return false if the
//list is empty and nothing is removed
bool list::remove_last()
{
    if(!head)
        return false;
    if(!head->next)
    {
        delete head;
        head = NULL;
        return true;
    }

    return remove_last(head,tail);

}

//Now implement the function recursively!
bool list::remove_last(node * & head, node * & tail)
{
   if(head->next == tail)
   {
       delete tail;
       head->next = NULL;
       tail = head;
       return true;
   }
    return remove_last(head->next,tail);
}

// ************************************************
//Remove all nodes in a LLL. Remove false if there is
//nothing to remove
bool list::remove_all()
{
    if(!head)
        return false;
    
    return remove_all(head);
}

//Now implement the function recursively!
bool list::remove_all(node * & head)
{
    bool wasRemoved;

    if(!head)
        return true;

    wasRemoved = remove_all(head->next);
    
    delete head;
    head = NULL;

    return wasRemoved;
}

// ************************************************
//Return true if the requested item (sent in as an argument)
//is in the list, otherwise return false
bool list::find_item(int item_to_find)
{
        if(!head)
            return false;
        
        return find_item(head,item_to_find);
}

//Now implement the function recursively!
bool list::find_item(node * head, int item_to_find)
{
    if(!head)
        return false;

    if(head->data == item_to_find)
        return true;

    return find_item(head->next,item_to_find);
}


// ************************************************
//Make a complete copy of a LLL
bool list::copy(list& from)
{
        //Write your code here
        if(!head)
            return false;

        return copy(from.head,tail,head);
}

//Now implement the function recursively
bool list::copy(node * & dest_head, node * & dest_tail, node * source)
{
    if(!source)
        return true;

    dest_head = new node;
    dest_head->data = source->data;
    dest_head->next = NULL;
    dest_tail = dest_head;

    return copy(dest_head->next,dest_tail,source->next);
}

void list::insert(int data)
{
    if(!head)
    {
        head = new node;
        head->data = data;
        head->next = NULL;
        tail = head;
    }
    else
    {
        tail->next = new node;
        tail->next->data = data;
        tail->next->next = NULL;
        tail = tail->next;
    }
}
