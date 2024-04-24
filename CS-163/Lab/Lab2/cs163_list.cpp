#include "cs163_list.h"
using namespace std;




//Implement these three functions
//Add to the end of the LLL as efficiently as possible
int list::add(journal_entry & to_add)
{
    if(!head)
    {
        head = new node;
        if(head->entry.copy_entry(to_add) == 1);
        {
          head->next = NULL;
          tail = head;
          return 1;
        }
        delete head;
        return 0;
    }
    else
    {
       tail->next = new node;
       if(head->next->entry.copy_entry(to_add) == 1);
       {
         head->next->next = NULL;
         tail = head->next;
         return 1;
       }
        return 0;
    }
}

//Determine if there is a match with the title passed in
//and if so provide the matching journal entry back to the
//client program through the second argument.
//Return a zero if no match is found
int list::find(char matching_title[], journal_entry & found)
{
    if(!head)
        return 0;
    node* current = head;

    while(current)
    {
        if(current->entry.retrieve(matching_title,found) == 1)
            return 1;
        current = current->next;
    }
   return 0;
}

//Display all journal entries
//Return false if there are no entries
int list::display(void)
{
    if(!head)
    {
        return 0;
    }
    node* current = head;
    while(current)
    {
        current->entry.display();
        current = current->next;
    }
    return 1;
}


//Copy the list passed in as an argument
//and add the nodes to the end of the current list
int list::append(list & source)
{
    

        //Your code goes here!

    return 1;
}
