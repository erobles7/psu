#include "CS299_list.h"

int display_all2(node* head)
{
    int count = 0;

    if(head == NULL)
    {
        return 0;
    }
    else
    {
        node* current = head->next;

        while(current != NULL)
        {
            if(current->data == head->data)
            {
                current = current->next;
            }
            else
            {
                std::cout<<current->data<<" ";
                count++;
                current = current->next;
            }
        }
    }

    return count;
}

node* buildNode(int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int sum_greater(node*& head)
{
    int sum = 0;    
    int lastNum= 0;
    node* current = head;

    if(head == NULL)
        return 0;
    
   //loop until last node  
    while(current->next != NULL)
            current = current->next;

    lastNum = current->data;
    current = head;
    
    //loop through list , do comparisons
     while(current->next  != NULL)
       {
           if(current->data > lastNum)
               sum = sum + current->data;
               
           current = current->next;
        }
    
     node* newNode = buildNode(sum);
     current->next = newNode;

    return sum;
}

/***********************************************************
 * Find out if the last two numbers appear more than once
 * *********************************************************/
bool find_last_two(node* head)
{
    int count = 0;

    if(head == NULL)
        return false;
    if(head->next == NULL)
        return false;
    
    node* current = head;
    while(current->next->next != NULL)
            current = current->next;
    
    int secondNum = current->data;
    int lastNum = current->next->data;

    current = head;

    while(current->next != NULL)
    {
        if(count >1)
            return true;
        if(current->data == lastNum || current->data == secondNum)
            count++;
        current = current->next;
    }

    return false;
}

float append(node*& head, int to_add)
{
    int sum = 0;
    int count = 0;

    if(head == NULL)
    {
        return 0;
    }
    
    node* current = head;

    while(current->next != NULL)
    {
        sum = sum+current->data;
        count++;
        current = current->next;
    }

    node* newNode = buildNode(to_add);
    current->next = newNode;
    sum = sum+newNode->data;
    count++;

    return (float) (sum/count);
}
//Look ahead method
/*
int remove_last(node*& head)
{
    if(head == NULL)
        return 0;
    
    node* current = head;
    
    while(current->next->next != NULL)
        current = current->next;

    node* deletePtr = current->next;
    current->next = NULL;
    int lastNum = deletePtr->data;
    delete deletePtr;

    return lastNum;
}
*/

int remove_last(node*& head)
{
    node* prev = NULL;
    int lastNum = 0;

    //empty list
    if(head == NULL)
        return 0;
    
    //one item in list (extra work , not really needed) 
    if(head->next == NULL)
    {
        lastNum = head->data;
        node* deletePtr = head;
        delete deletePtr;
        head = NULL;
        
        return lastNum;
    }

    //multiple items in list
    node* current = head;
    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    lastNum = current->data;
    prev->next = NULL;
    delete current;

    return lastNum;
}

/***************************
 * Remove Middle nodes    
 ****************************/
int remove_special(node*& head)
{   
    int count = 0;

    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return 0;
    
    while(head->next->next != NULL)
    {
        node* deletePtr = head->next;
        head->next = deletePtr->next;
        delete deletePtr;
        count++;
    }
    return count;
}
/*****************************************
 * Copy Last node , stick it in the front
 ****************************************/
int copy_last(node*& head)
{
    if(head == NULL)
        return 0;
    if(head->next == NULL)
        return 0;

    node* current = head;
    while(current->next->next!= NULL)
            current = current->next;
    //insert the node at the front 
    node* newNode = buildNode(current->next->data);
    newNode->next = head;
    head = newNode;

    return head->data;
}

