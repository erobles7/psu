#include "CS299_arr.h"
using namespace std;
/*
 * Eduardo Robles
 * 09/07/2016
 */

//Find the longest linked list
int find_longest(node* head[], int size)
{
    if(!head)
        return 0;
    int largest = 0; 

    for(int i = 0; i<size; ++i)
    {
        int count = 0;
        node* current = *(head + i);
        while(current != NULL)
        {
            ++count;
            current = current->next;
        }
        if(count > largest)
            largest = count;
    }
    return largest;
}

//Remove last node in linked list
int remove_last(node* head[], int size)
{
    if(!head)
        return 0;
    int num_removed = 0;
    
    node* previous = NULL;
    node* current = NULL;
    for(int i = 0; i<size; ++i)
    {
        current = *(head+i);

        while(current->next)
        {
            previous = current;
            current = current->next;
        }
        if(previous == NULL)
        {
            delete current;
            *(head+i) = NULL;
            ++num_removed;
        }
        else
        {
            delete current;
            previous->next = NULL;
            ++num_removed;
        }
    }
    return num_removed;
}

//add a number to the end of the list 
int add_last(node* head[], int size)
{
  if(!head)
      return 0;
  int count = 1;

  node* current = *(head+size-1);
  
  if(!current)
  {
      current = new node;
      current->data = 9999;
      current->next = NULL;
      *(head+size-1) = current;
      return 1;
  }

  while(current->next)
  {
    current = current->next;
    ++count;
  }
  
  current->next = new node;
  current = current->next;
  current->data = 999;
  current->next = NULL;

  return count;
}

//deallocate the entire LLL of arrays
int remove_all(node* head[], int size)
{
    if(!head)
        return 0;

    int count = 0;
    node* current = NULL;

    for(int i = 0; i<size; ++i)
    {
        current = *(head+i);
        if(!current)
            return 0;
        while(current->next)
        {
           node* temp = current->next;
           delete current;
           ++count;
           current = temp;
        }
        delete current;
        ++count;
        *(head+i) = NULL;
    }
    delete [] head;
    head = NULL;

   return count; 
}
