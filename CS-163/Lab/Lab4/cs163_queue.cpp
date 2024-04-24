#include "cs163_queue.h"


//Implement these functions using a Circular Linked List
//Add at the rear
int queue::enqueue(const journal_entry & to_add)
{
    q_node* temp;
    temp = new q_node;

    if(!temp->entry.copy_entry(to_add))
    {
        delete temp;
        return 0;
    }

    if(!rear)
    {
        rear = temp;
        rear->next = rear;
        return 1;
    }

    temp->entry.copy_entry(to_add);
    temp->next = rear->next;
    rear->next = temp;
    rear = temp;

    return 1;
}

//Remove the node at the front
int queue::dequeue ()
{
    if(!rear)
        return 0;

    if(rear->next == rear)
    {
        delete rear;
        rear = NULL;
        return 1;
    }

    q_node* temp = rear->next;
    rear->next = temp->next;
    delete temp;

    return 1;
}

