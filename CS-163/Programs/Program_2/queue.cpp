//queue.cpp
#include "queue.h"
#include <iostream>

/*************************************
Author: Eduardo Robles
Date: 10/21/2016
Desc: implementation for the queue class
**************************************/


/********************************************************
 Name: queue()
 Desc: initializes rear pointer to NULL
********************************************************/
queue::queue(void)
{
   rear = NULL;
}

		
/*********************************************************
 Name: ~queue()
 Desc: deallocates all dynamic memory and destroys queue
*********************************************************/
queue::~queue(void)
{
  remove_all();
}

/***********************************************
 Name: enqueue
 Input: stop object
 Output: returns 1 if stop successfully added 
***********************************************/
int queue::enqueue(const stop& to_add)
{
   //create temp node
   q_node* temp;
   temp = new q_node; 
   temp->data.copy(to_add);
  
   //empty list 
   if(!rear)
   {
	rear = temp;
	rear->next = rear;
	return 1;	
   }

   //add it to the queue 
   temp->next = rear->next;
   rear->next = temp;
   rear = temp;

   return 1;
}


/*********************************************
 Name: dequeue()
 Output: returns if empty queue, 1 otherwise 
 Desc: removes the top item from the queue
**********************************************/
int queue::dequeue()
{
   //empty list 
   if(!rear)
	return 0;

    //single item in list 
   if(rear->next == rear)
    {
	delete rear;
	rear = NULL;
    }

   //delete top item
   q_node* temp = rear->next;
   rear->next = temp->next;
   delete temp;

  return 1;
}

/**************************************************************************
 Name: dequeue()
 Input: stop object
 Ouput: returns 0 if empty queue, 1 otherwise 
 Desc: retries the top item from the queue, copies it and then removes it 
**************************************************************************/
int queue::dequeue(stop& top_item)
{
   //empty queue
   if(!rear)
	return 0;

   //one item 
   if(rear->next == rear)
    {
	delete rear;
	rear = NULL;
    }

   //delete top item
   q_node* temp = rear->next;
   top_item.copy(temp->data);
   rear->next = temp->next;
   delete temp;

  return 1;
}

/************************************************
 Name: peek()
 Input: stop object
 Output: returns 0 if empty queue, 1 otherwise 
 Desc: returns the top item of the queue
*************************************************/
int queue::peek(stop& top_item)
{
  //empty queue
  if(!rear)
     return 0;

  //copy top item in queue
  top_item.copy(rear->next->data);

 return 1;

}

/************************************************
 Name: peek()
 Output: returns 0 if empty queue, 1 otherwise 
 Desc: displays the top item of the queue
*************************************************/
int queue::peek()
{
  //empty queue 
  if(!rear)
	return 0;

  //display top item in queue 
  rear->next->data.display_all();

 return 1;
}

/************************************************
 Name: display_all()
 Output: returns 0 of empty queue , 1 otherwise 
************************************************/
int queue::display_all()
{
  //empty queue
  if(!rear)
	return 0;

  //recursively displays items in queue 
  return display_all(rear->next);
}

/************************************************
 Name: display_all()
 Input: rear pointer 
 Output: returns 0 of empty queue , 1 otherwise 
 Desc: dislays the contents of the queue 
*************************************************/
int queue::display_all(q_node* rear)
{
   //last item in queue 
   if(rear == this->rear)
    {
	rear->data.display_all();
	return 1;
    }

     //display info 
     rear->data.display_all();
     std::cout<<"\n";

    //recursively traverse 
    return display_all(rear->next);
}


/*****************************************
 Name: remove_all()
 Desc:: recursively deletes the queue 
*****************************************/
void queue::remove_all()
{
  if(!rear)
      return;
  
  remove_all(rear->next);
}


/************************************************
 Name: remove_all()
 Input: rear pointer
 Desc: recursively deletes the queue contents 
************************************************/
void queue::remove_all(q_node*& rear)
{
   if(rear == this->rear)
   {
	delete rear;
	this->rear = NULL;
	return;
   }
    
   //create temp pointer and delete node 
   q_node* temp = rear;
   rear = temp->next;
   delete temp;
  
   //recursively traverse  
   remove_all(rear);
}

