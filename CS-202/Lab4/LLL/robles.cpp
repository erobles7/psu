#include "list.h"

int list::num_times(int match)
{
    if(!head)
        return 0;

    return num_times(head,match);
}
int list::num_times(node* head, int match)
{
    int count = 0;

    if(!head)
        return 0;

    if(head->data == match)
        ++count;

    return count+ num_times(head->next,match);


}

int list::display_first_last()
{
    if(!head)
        return 0;
    if(!head->next)
    {
        std::cout<<head->data;
        return head->data;
    }

    std::cout<<head->data;

    return display_first_last(head);
}

int list::display_first_last(node* head)
{
    if(!head->next)
    {
        std::cout<<"->"<<head->data<<"\n";
        return this->head->data + head->data;
    }
    return display_first_last(head->next);
}

bool list::remove_except()
{
    if(!head)
        return false;

    if(!head->next)
        return false;

    if(!head->next->next)
        return  false;

    return remove_except(head);
}

bool list::remove_except(node*& head)
{
    if(!head->next->next)
        return true;

    node* temp = head;
    head = head->next;
    delete temp;

    return remove_except(head);

}

int copy_special(list& new_list);
{
    if(!original)
        return 0;

    new_copy.rear = new node;
    new_copy.rear->data = rear->data;
    new_copy.rear->next = NULL;


}

int list::copy_special(node*& new_copy,node* original)
{


}

      int remove_all_twos(node*& head);
