#include "cs163_table.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
	hash_table_size = size;
    hash_table = new node* [hash_table_size];

    for(int i = 0; i<hash_table_size; ++i)
    {
        (*(hash_table+i)) = NULL;
    }
}

//Using a hash function, insert a new value into the 
//head of the chain
int table::insert(char * key_value, const journal_entry & to_add)
{   
    int index = hash_function(key_value);

    if(index == -1)
        return 0;

   node* temp = (*(hash_table+index));
   (*(hash_table+index)) = new node;
   (*(hash_table+index))->next = temp;
   (*(hash_table+index))->entry.copy_entry(to_add);

   return 1;
}

//Using a hash function determine which chain to search
//then return 0 if no match is found
int table::retrieve(char * title_to_find, journal_entry & found) const
{
    int index = hash_function(title_to_find);
    
    if(index == -1)
        return 0;

    return retrieve_list((*(hash_table+index)),title_to_find,found);
    
}

int table::retrieve_list(node* head,char* title,journal_entry& found)
{
    if(!head)
        return 0;

    if(head->entry.retrieve(title,found) == 1)   
        return 1;

    return (head->next,title,found);
}
int table::hash_function(char* key_value) const
{
    int sum = 0;

    if(!key_value)
        return -1;

    int length = strlen(key_value);

    for(int i = 0; i<length; ++i)
    {
        sum+=(*(key_value+i));

    }

    return sum % hash_table_size;
}
