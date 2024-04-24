#include "CS299_clist.h"
//Eduardo Robles

//add before
int list::add_before()
{
    if(!rear)
        return 0;
    
    return add_before(rear->next);
}

int list::add_before(node*& rear)
{
    int count = 0;
    
    if(rear != this->rear)
        count =  add_before(rear->next);
    
    if(rear->data % 2 == 0)
    {
        node* temp = new node;
        temp->data = 99;
        temp->next = rear;
        rear = temp;
        count++;
    }
    return count;
}
/**********************
 * Remove Same as rear 
 * *********************/
bool list::remove_same()
{
    if(!rear)
        return false;
    
    if(rear->next == rear)
        return false;
    
    return remove_same(rear->next);

}

bool list::remove_same(node*& current)
{
    bool removed;

    if(current == this->rear)
    {
        if(current->next->data == this->rear->data)
        {
            node* temp = current->next;
            this->rear->next = temp->next;
            delete temp;
            return true;
        }
        else
            return false;
    }
    if(current != this->rear)
    {
        if(current->next->data == this->rear->data)
        {
            node* temp = current->next;
            current->next = temp->next;
            current = temp->next; 
            delete temp;
            return true;
        }
            removed = remove_same(current->next);
    }
    return removed;
}

/***************************
 * Switch First and Last 
 * ************************/
void list::switchFirstAndLast()
{
    if(!rear)
        return;
    if(rear->next == rear)
        return;
    switchFirstAndLastPrivate(rear->next);
}
void list::switchFirstAndLastPrivate(node*& current)
{ 
    if(current == rear)
    {
        node* temp = rear->next;
        current = temp;
        rear->next = temp->next;
        temp->next = rear;
        this->rear = temp;
    }
    else
        switchFirstAndLastPrivate(current->next); 
}

/******************************
 * Copy Last two into new List 
 * ****************************/
float list::copy_two(list& new_list)
{
    float sum = 0.0;

    if(!rear)
        return 0;

    if(rear->next == rear)
        return 0;

    if(rear->next->next == rear)
    {
        new_list.insert(rear->data);
        new_list.insert(rear->next->data);
        return ((rear->next->data + rear->data) / 2);
    }
    
    sum = copy_two(new_list,rear->next);
    
    float average = (sum/2);

    return average;
}

float list::copy_two(list& new_list, node* current)
{
    float sum = 0;

    if(current->next == rear)
    {
        new_list.insert(current->next->data);
        new_list.insert(current->data);
        return current->next->data + current->data;
    }

    sum = copy_two(new_list,current->next);

    return sum;
}
void list::insert(int num)
{
    if(!rear)
    {
        rear = new node;
        rear->data = num;
        rear->next = rear;
    }
    else
    {
        node* temp = new node;
        temp->data = num;
        temp->next = rear->next;
        rear->next = temp;
    }
}
