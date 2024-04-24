#include "CS299_clist.h"
//Eduardo Robles
//08/28/2016
/*******************************
 * Display all except last node
 * ****************************/
int display_except(node* rear)
{ 
    int sum = 0;

    if(!rear || rear ==  rear->next)
        return 0;

    node* current = rear->next;
    while(current != rear)
    {
        sum = sum+current->data;
        std::cout<<current->data<<" ";
        current = current->next;
    }

    return sum;
}

/*****************************
 * Create a node 
 * **************************/
node* createNode(int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/******************************
 * Remove Last node
 *****************************/
bool remove_last(node*& rear)
{
    if(!rear)
        return false;
    if(rear == rear->next)
    {
        delete rear;
        rear = NULL;
        return true;
    }

    node* current = rear->next;
    while(current->next != rear)
    {
        current = current->next;
    }
    
    current->next = rear->next;
    delete rear;
    rear = current;

    return true;
}

/*****************************
 * Copy of Circular Linked List
 * ****************************/
int copy_all(node*& new_rear, node* source_rear)
{
    int count = 0;
    //empty list 
    if(!source_rear)
        return 0;
    
    //one item in list
    if(source_rear->next ==  source_rear)
    {
        new_rear = new node;
        new_rear->data = source_rear->data;
        new_rear->next = new_rear;
        return 1;
    }
    new_rear = new node;
    new_rear->data = source_rear->data;
    new_rear->next = new_rear;
    count++;

    node* oldCurrent = source_rear->next;
    node* newCurrent = new_rear;
    
    while(oldCurrent != source_rear)
    {
        newCurrent->next = new node;
        newCurrent = newCurrent->next;
        newCurrent->data = oldCurrent->data;
        newCurrent->next = new_rear;
        oldCurrent = oldCurrent->next;
        count++;
    }
    
    return count;
}
