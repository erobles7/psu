//list.cpp
#include "list.h"

//return the count in the list
int count(node* head)
{
    if(!head)
        return 0;

    return 1 + count(head->next);

}

//****************************
//Display last node
//****************************
int display_last(node* head)
{
    if(!head)
        return 0;
    if(head->next == NULL)
    {
        std::cout<<"The last item is "<<head->data;
        return 1;

    }
    display_last2(head);

    return 1;
}
void display_last2(node* head)
{
    if(!head->next)
    {
        std::cout<<"The last item is "<<head->data;
        return;
    }

    display_last2(head->next);
}

//****************************
//Display last two
//****************************
int display_last_two(node* head)
{
    //empty list 
    if(!head)
        return 0;

    //one item 
    if(!head->next)
    {
        std::cout<<head->data<<"\n";
        return 1;
    }
    node* prev = NULL;

    return display_last_two2(prev,head);

}
int display_last_two2(node* prev,node* head)
{
    //reach last node 
    if(!head->next)
    {
        std::cout<<prev->data<<" -> "<<head->data<<" ";
        return 1; 
    }

    prev = head;

    return display_last_two2(prev,head->next);
}

//****************************
//Display last if its not a 2
//****************************
int display_not_two(node* head)
{
    if(!head)
        return 0;

    if(!head->next)
    {
        if(head->data != 2)
        {
            std::cout<<head->data<<" ";
            return 1;
        }
        return 0;
    }

   return display_not_two2(head); 
}
int display_not_two2(node* head)
{
    if(!head->next)
    {
        if(head->data == 2)
            return 0;        
       std::cout<<head->data<<" ";
       return 1;
    }

    return display_not_two2(head->next);
}

//****************************
//insert at front 
//****************************
int insert_front(node*& head,int num)
{
    if(!head)
    {
        head = new node;
        head->data = num;
        head->next = NULL;
    }
    else
    {
        node* temp = new node;
        temp->data = num;
        temp->next = head;
        head = temp;
    }

    return 1; 
}

//****************************
//Insert at the end
//****************************
int insert_end(node*& head, int num)
{
    if(!head)
    {
        head = new node;
        head->data = num;
        head->next = NULL;
        return 1;
    }

    return insert_end2(head,num);
}
int insert_end2(node*& head, int num)
{
    if(!head)
    {
        head = new node;
        head->data = num;
        head->next = NULL;

        return 1;
    }

    return insert_end2(head->next,num);
}


//****************************
//move front to end 
//****************************
int move_front_to_end(node*& head)
{
    if(!head)
        return 0;
    if(!head->next)
        return 1;
    if(!head->next->next)
    {
        head->next->next = head;
        head = head->next;
        head->next->next = NULL;
        return 1;
    }

    node* current = head;

    return move_front_to_end2(head,current);
}
int move_front_to_end2(node*& head,node*& current)
{
    if(!current)
    {
        current = head;
        head = head->next;
        current->next = NULL;
        return 1;
    }
    
    return move_front_to_end2(head,current->next);
}
