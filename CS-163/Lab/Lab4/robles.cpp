#include "cs163_queue.h"


void queue::remove_entire()
{
    if(!rear)
        return;

  remove_entire(rear->next);

}
void queue::remove_entire(q_node*& rear)
{
    if(rear == this->rear)
    {
        delete rear;
        this->rear = NULL;
        return;
    }

    q_node* temp = rear;
    rear = temp->next;
    delete temp;
    
    remove_entire(rear);
}


int queue::count_all()
{
    if(!rear)
        return 0;

    return count_all(rear->next);
}
int queue::count_all(q_node* rear)
{
    if(rear == this->rear)
        return 1;

    return 1 + count_all(rear->next);
}

