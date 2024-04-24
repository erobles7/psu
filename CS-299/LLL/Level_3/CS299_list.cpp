#include "CS299_list.h"
//Eduardo Robles    

/****************************
 *  Remove Last Two 
 ***************************/
bool list::remove_last_two()
{
    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return 0;

    //three items
    return remove_last_twoPrivate(head);

}
bool list::remove_last_twoPrivate(node*& head)
{
    if(head->next->next != tail)
        remove_last_twoPrivate(head->next);
    else
    {
        if(this->head->data < (head->next->data + tail->data))
        {

            delete head->next;
            delete tail;
            tail = head;
            tail->next = NULL;

            return true;
        }
    }
    return false;
}

/*****************************
 * Average all items in list
 * **************************/
float list::average()
{
    int total = 0;

    if(head == NULL)
        return 0;
    if(head->next == NULL)
        return head->data;

   int count = average(head,total);

   return (static_cast<float>(total)/static_cast<float>(count));
} 

int list::average(node* head, int& total)
{
    if(head != NULL)
    {
        total = total + head->data;
        return 1 + average(head->next,total);
    }

    return 0;
}

/****************************************
 * Add a node with 99 after each node
 * *************************************/
int list::add_99()
{
    //empty list or single node 
    if(head  == NULL || head->next == NULL)
        return 0;
    return add_99Private(head);
}

int list::add_99Private(node*& head)
{
    int count = 0;

    if(head == NULL)
        return 0;
    
    if(head->next != tail)
        count = add_99Private(head->next);
    
    if(head->data > tail->data)
    {
        node* newNode = createNode(99);
        newNode->next = head->next;
        head->next = newNode;
        return count+1;
    }
    return count;
}
/************************************
 * Create a new node
 * *********************************/
node* list:: createNode(int num)
{
    node* newNode = new node;
    newNode->data = num;
    newNode->next = NULL;

    return newNode;
}

/***********************************
 * Copy only even nodes
 * ********************************/
int list::copy_even(list&  new_list)
{
    return copy_evenPrivate(new_list,head);
}

int list::copy_evenPrivate(list& new_list, node* oldHead)
{
    if(oldHead == NULL)
    {
        return 0;
    }
    if(oldHead->data % 2 == 0)
    {
        new_list.insert(oldHead->data);
        return 1+copy_evenPrivate(new_list,oldHead->next);
    }
    else
    {
        return 0+copy_evenPrivate(new_list,oldHead->next);
    }
}

/******************************
 * Insert Function
*******************************/
void list::insert(int data)
{
    node* newNode = createNode(data);

    if(!head)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
