#include "CS299_dlist.h"

//Display the last two 
int list::display_last_two()
{
    if(!head)
        return 0;
    if(tail == head)
        return head->data;
    return display_last_twoPrivate(head);
}
int list::display_last_twoPrivate(node* head)
{
    cout<<tail->data<<"->"<<" "<<tail->previous->data<<" \n";
    return tail->data+tail->previous->data;
}

//remove the last two
int list::remove_last_two()
{
    if(!head)
        return 0;
    if(head == tail)
        return 0;
    if(head->next == tail)
    {
        delete head;
        delete tail;
        head = NULL;
        tail = NULL;
        return 0;
    }

    return remove_last_two(head);

}
int list::remove_last_two(node*& head)
{
    int count;

    if(head == tail)
    {
        tail = head->previous->previous;
        tail->next = NULL;
        node* temp = tail->next;
        delete head;
        delete temp;
        return -1;
    }
    count = remove_last_two(head->next)+1;
    return count;
}
float list::add_average()
{
    if(!head)
        return 0;
    if(head == tail)
        return (head->data);

    int count = 0;

    float sum = add_average(head,count);
    float average = 0.0;
    average = (sum/count);

    tail->next = new node;
    tail->next->data = average;
    tail->next->previous = tail;
    tail = tail->next;

    return average;
}
float list::add_average(node*& head, int& count)
{

    if(head == tail)
    {
        count++;
        return head->data;
    }
    return  head->data + add_average(head->next,++count);
}
/*********************************
 * Sum the largest two data items
 * ******************************/
int list::sum_largest_two()
{
    int largest; 
    if(!head)
        return 0;
    if(head->next == tail)
        return head->data + tail->data;

    int secondLargest;
    
    largest = sum_largest_two_private(head,secondLargest);

  return largest+secondLargest;
}
int list::sum_largest_two_private(node* head, int& secondLargest)
{
    int largest = 0;

    if(!head)
        return 0;

    largest = sum_largest_two_private(head->next,secondLargest);
    
    if(head->data > largest)
    {
        secondLargest = largest; 
        return head->data;
    }
    return largest;
}


