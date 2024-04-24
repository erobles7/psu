#include "clist.h"

//add 99 before every even number
void list::add_before_even()
{
    if(!rear)
        return;

    add_before_even(rear->next);
}

void list::add_before_even(node*& current)
{
    if(current != rear)
        add_before_even(current->next);

    //check for even
    if(current->data % 2 == 0)
    {
        node* temp = new node;
        temp->data = 99;
        temp->next = current;
        current = temp;
    }
}

int list::remove_same_as_rear()
{
    if(!rear)
        return 0;

    if(rear->next == rear)
        return 0;

  return   remove_same_as_rear(rear->next,rear->data);
}
int list::remove_same_as_rear(node*& current,int match)
{

    int count = 0;

    if(current == rear)
        return 0;

    if(current->data == match)
    {
        node* temp = current;
        current = current->next;
        delete temp;
        ++count;
        return count+ remove_same_as_rear(current,match);
    }

    return count+remove_same_as_rear(current->next,match);
}
        
int list::remove_all()
{
    if(!rear)
        return 0;

    return remove_all(rear->next);
}
int list::remove_all(node*& current)
{
    if(current != rear)
        remove_all(current->next);

    delete current;
    current = NULL;
    rear = NULL;

    return 1;
}

int list::display_all_except_last()
{
    if(!rear)
        return 0;

    return display_all_except_last(rear->next);
}

int list::display_all_except_last(node* rear)
{
    if(rear == this->rear)
        return 0;

    std::cout<<rear->data<<" ";

    return rear->data+ display_all_except_last(rear->next);
}

        
int list::remove_last()
{
    if(!rear)
        return 0;
    if(rear->next == rear)
    {
        delete rear;
        rear = NULL;
        return 1;
    }

   node* prev = NULL;

   return remove_last(rear->next,prev);
}

int list::remove_last(node*& rear, node* prev)
{
    if(rear == this->rear)
    {
        rear = this->rear->next;
        delete this->rear;
        this->rear = prev;
        return 1;
    }

    prev = rear;

    return remove_last(rear->next,prev);
}

       
//count even
int list::count_even()
{
    if(!rear)
        return 0;

    return count_even(rear->next);
}

int list::count_even(node* rear)
{
    int count = 0;

    if(rear == this->rear)
    {
        if(rear->data % 2 == 0)
            return 1;
        else
            return 0;
    }

    if(rear->data % 2 == 0)
        ++count;

    return count + count_even(rear->next);
}


//remove same as rear
int list::remove_same_as_rear2()
{
    if(!rear)
        return 0;

    if(rear->next == rear)
        return 0;

    return remove_same_as_rear(rear->next,rear->data);
}

int list::remove_same_as_rear2(node*& rear,int num)
{
    if(rear == this->rear)
        return 1;

    if(rear->data == num)
    {
        node* temp = rear;
        rear = rear->next;
        delete temp;
        return remove_same_as_rear(rear,num);
    }

    return remove_same_as_rear(rear->next,num);
}

int list::largest_two()
{
    if(!rear)
        return 0;

    return largest_two(rear);
}

int list::largest_two(node* rear)
{
    int largest = 0;
    int second = 0;

    largest_two(rear->next,largest,second);

    std::cout<<largest<<" -> "<<second;

    return 1;
}

void list::largest_two(node* rear,int& largest , int& second)
{
    if(rear != this->rear)
        largest_two(rear->next,largest,second);

    if(rear->data > largest)
    {
        second = largest;
        largest = rear->data;
    }


    if(rear->data < largest)
    {
        if(rear->data > second)
            second = rear->data;
    }
}
