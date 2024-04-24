#include "CS299_list.h"

bool find(node* head, int match)
{
    if(head == NULL)
        return false;

   return  find2(head,match);
}

bool find2(node* head, int match)
{
    if(head == NULL)
        return false;

    if(head->data == match)
            return true;
        
   return find2(head->next,match);
}

int display_every_other(node* head)
{
    
    if(head == NULL)
        return 0;
    
    std::cout<<head->data<<" ";

    if(head->next != NULL)
        return 1+ display_every_other(head->next->next);
    else
        return 1;
}
int insert_before_last(node*& head, int to_add)
{
    if(head == NULL)
        return 0;
    if(head->next == NULL)
    {
        node* newNode = createNode(to_add);
        newNode->next = head;
        head = newNode;
        return newNode->next->data;
    }

    if(head->next->next != NULL)
        return insert_before_last(head->next,to_add);

    node* last = head->next;
    node* newNode = createNode(to_add);
    newNode->next = head->next;
    head->next = newNode;

    return last->data;
}
int remove_all(node*& head)
{
    if(head == NULL)
        return 0;
    else
    {
       return 1+ remove_all(head->next);
        delete head;
        head = NULL;
    }
}
int remove_special(node*&  head)
{
    if(head == NULL)
        return 0;
    if(head->next == NULL)
        return 0;
   return remove_special2(head);
}
int remove_special2(node*& head)
{
    int sum = 0;
    if(head->next->next != NULL)
    {
        node* deletePtr = head->next;
        sum = sum+ deletePtr->data;
        head->next = deletePtr->next;
        delete deletePtr;
        
       return sum + remove_special2(head);
    }
    else
        return sum;

}
/*************************************
 * Copy 
 * ***********************************/
int copy(node*& head_dest, node* head_source)
{
    if(head_source  == NULL)
    {
        head_dest = NULL;
        return 0;
    }

    //create new node
    node* newNode = createNode(head_source->data);
    head_dest = newNode;
    return 1+copy(head_dest->next, head_source->next);
}

/***************************
 * Remove First and Last  
 * *************************/

//wrapper
int removeFirstAndLast(node*& head)
{
    int sum = 0;

    if(!head)
        return 0;

    //one item in list  
    if(head->next == NULL)
    {
        sum = head->data;
        delete head;
        head = NULL;
        return sum;
    }
    //2 items in the list 
    if(head->next->next == NULL)
    {
        sum = head->data + head->next->data;
        delete head;
        head = NULL;
        return sum;
    }

    node* temp = head;
    node* temp2 = head->next;
    sum = sum+temp->data;
    delete head;
    head = NULL;

    return  removeFirstAndLast2(temp2);
}
//recursive part
int removeFirstAndLast2(node*& head)
{
    int sum = 0;
    if(head->next!= NULL)
      return  removeFirstAndLast2(head->next);
    else
    {
        sum = head->data;
        delete head;
    }

    return sum;
}

void removeLast(node*& head)
{
    if(!head)
        return;
    if(head->next == NULL)
    {
        node* temp = head;
        delete temp;
        head = NULL;
        return;
    }

    node* prev = NULL;
    removeLastPrivate(prev,head);
}
void removeLastPrivate(node*& prev, node*& head)
{
    if(head->next != NULL)
    {
        prev = head;
        removeLastPrivate(prev,head->next);
    }
    else
    {
        node* temp = head;
        prev->next = NULL;
        delete temp;
    }
}

node* createNode(int num)
{
    node* newNode = new node;
    newNode->data = num;
    newNode->next = NULL;
    
    return newNode;
}
