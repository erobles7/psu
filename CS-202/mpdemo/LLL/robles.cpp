#include "list.h"


//count the number of items in the list
int list::count()
{
     if(!head)
         return 0;
     
    return count(head);
}

int list::count(node* head)
{
    if(!head)
        return 0;

    return 1 + count(head->next);
}


//counts and displays unique data
int list::display_unique()
{
    if(!head)
        return 0;

    return display_unique(head);
}
      
int list::display_unique(node* head)
{
    int count = 0;

    if(!head)
        return 0;

    if(is_unique(head->next,head->data))
    {
        cout<<head->data<<" ";
        ++count;
    }

    return count + display_unique(head->next);
}

bool list::is_unique(node* head,int num)
{
    if(!head)
        return true;

    if(head->data == num)
        return false;

    return is_unique(head->next,num);
}

//display the last item if its not the same as the first
int list::display_last_not_first()
{
    if(!head)
        return 0;

    return display_last_not_first(head);
}
int list::display_last_not_first(node* head)
{
    if(head->data != tail->data)
    {
        cout<<tail->data;
        return tail->data;
    }
    else
        return 0;
}

int list::move_first_to_end()
{
    if(!head)
        return 0;

    if(!head->next)
        return 0;

    return move_first_to_end(head);
}

int list::move_first_to_end(node* head)
{
    if(head == tail)
    {
        tail->next = this->head;
        this->head = this->head->next;
        tail = tail->next;
        tail->next = NULL;
        return head->data;
    }

    return head->data + move_first_to_end(head->next);
}

int list::duplicate_first()
{
    if(!head)
        return 0;

    node* previous = NULL;

    return duplicate_first(head,previous);
}
int list::duplicate_first(node*& head,node* previous)
{
    if(!head)
    {
        head = new node;
        head->data = this->head->data;
        tail = head;
        return previous->data + head->data;
    }

    previous = head;
    
    return duplicate_first(head->next,previous);
}


//remove all duplicates
//from list 
int list::remove_duplicate()
{
    if(!head)
        return 0;

    return remove_duplicate(head);
}

int list::remove_duplicate(node*& head)
{
    int count = 0;

    if(!head)
        return 0;

    if(is_duplicate(head->next,head->data))
    {
        node* temp = head;
        head = head->next;
        delete temp;
        ++count;
        return count+ remove_duplicate(head);
    }

    return count + remove_duplicate(head->next);
}

bool list::is_duplicate(node* head,int data)
{
    if(!head)
        return false;

    if(head->data == data)
        return true;

    return is_duplicate(head->next,data);
}

//remove all except the last node
int list::remove_all_but_last()
{
    if(!head)
        return 0;

    if(!head->next)
        return 0;

    return remove_all_but_last(head);
}


int list::remove_all_but_last(node*& head)
{
    int sum = 0;
    
    if(head->next == tail)
    {
        node* temp = head;
        head = head->next;
        sum+= temp->data;
        delete temp;

        return sum;
    }

    node* temp = head;
    head = head->next;
    sum+= temp->data;
    delete temp;

    return sum+remove_all_but_last(head);
}


int list::copy_into_array(int* array)
{
    if(!head)
        return 0;

    return copy_into_array(array,head);
}

int list::copy_into_array(int* array,node* head,int& count)
{
    int size = 0;

    if(!head)
        return 0;

    int ret = copy_into_array(array,head->next,count,++count)

    if(ret == 0)
    {
       size = count;
       array = new int[size];
    }


    return 
}
