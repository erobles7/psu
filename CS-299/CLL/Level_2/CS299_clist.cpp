#include "CS299_clist.h"
//Eduardo Robles

//Remove all nodes from the list
int removal_entire(node*& rear)
{
    if(!rear)
        return 0;
    node* current = rear->next;
    return removal_entirePrivate(rear,current);
}
int removal_entirePrivate(node*& rear,node* current)
{
    if(current  == rear)
    {
        delete current;
        rear = NULL;
        return 1;
    }
    else
    {
        node* temp = current;
        rear->next = current->next;
        delete temp;
        current = rear->next;
        return 1+ removal_entirePrivate(rear,current);        
    }
}

//count all even data
int count_all(node* rear)
{
    if(!rear)
        return 0;
    //node* current = rear->next;
    return count_allPrivate(rear,rear->next);
}
int count_allPrivate(node* rear, node* current)
{
    if(current == rear)
    {
        if(current->data % 2 == 0)
                return current->data;
        else
            return 0;
    }
    else
    {
        if(current->data % 2 == 0)
            return current->data + count_allPrivate(rear,current->next);
        else
            return 0 + count_allPrivate(rear,current->next);
    }
}

//insert at end 
bool insertAtEnd(int num,node*& rear)
{
    if(!rear)
    {
        rear = createNode(num);
        rear->next = rear;
        return true;
    }

    if(rear->next == rear)
    {
        if(rear->data != num)
        {
            node* newNode = createNode(num);
            newNode->next = rear;
            rear->next = newNode;
            rear = newNode;
            
            return true;
        }
        else
            return false;
    }
    else
    {
        return insertAtEndPrivate(num,rear,rear->next);
    }
}

bool insertAtEndPrivate(int num, node*& rear , node* current)
{
    if(current->next == rear)
    {
        if(current->data == rear->data)
            return false;
        else
        {
            node* newNode = createNode(num);
            newNode->next = rear->next;
            current->next = newNode;
            rear = newNode;
            return true;
        }
    }
    else
    {
        if(num == current->data)
            return false;
        else
          return insertAtEndPrivate(num,rear,current->next);
    }
}
//duplicate list 
bool duplicate(node*& new_rear, node* source_rear)
{
    if(!source_rear)
        return false;

    new_rear = new node;
    new_rear->data = source_rear->data;
    new_rear->next = NULL;
    
    return duplicatePrivate(new_rear,new_rear->next,source_rear,source_rear->next);
}

bool duplicatePrivate(node*& new_rear_source,node*& new_rear ,node* source_rear, node* current)
{
    if(current == source_rear)
    {
        new_rear = new_rear_source;
        return true;
    }

    new_rear = new node;
    new_rear->data = current->data;
    new_rear->next = NULL;

    return duplicatePrivate(new_rear_source,new_rear->next,source_rear,current->next);
}
//Remove all except last two
int removeAllExceptLastTwo(node*& rear)
{
    if(!rear)
        return 0;
    if(rear->next == rear)
        return 0;
    node* current = rear->next; 
    return removeAllExceptLastTwoPrivate(current,rear);
}
int removeAllExceptLastTwoPrivate(node*& current,node*& rear)
{
    if(current->next == rear)
        return current->data + rear->data;
    else
    {
        node* temp = current;
        current = current->next;
        rear->next = current;
        delete temp;
        return removeAllExceptLastTwoPrivate(current,rear);
    }
}

node* createNode(int num)
{

    node* newNode = new node;
    newNode->data = num;
    newNode->next = NULL;
    return newNode;
}

