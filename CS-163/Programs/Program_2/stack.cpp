//stack.cpp
#include "stack.h"
#include <iostream>

/****************************************************
Author: Eduardo Robles
Date: 10/21/2016
Desc: Implemenation for the stack class 
      stack can store and manipulate stop objects
****************************************************/


/*********************************************************
 Name: stack()
 Input: size of the array to be created
 Desc: default constructor, initializes everything to NULL
*********************************************************/
stack::stack(int size)
{
   //initialize values 
   head = NULL;
   MAX_SIZE = size; 
   top_index = 0;
}



/*************************************************************
 Name: ~stack()
 Desc: deallocates all the dynamic memory and destorys stack
**************************************************************/
stack::~stack()
{
	remove_all();
}


/************************************
 Name: push()
 Input: stop object
 Output: returns 1 if item is pushed
 Desc: adds an item to the stack
*************************************/		
int stack::push(const stop& to_add)
{
    //empty stack
    if(!head)
    {
	head = new node;
	head->stops = new stop[MAX_SIZE];
	head->next = NULL;
    }

     //array is full
    if(top_index == MAX_SIZE)
   {
	top_index = 0;
	node* temp = new node;
	temp->stops = new stop[MAX_SIZE];
	temp->next = head;
	head = temp;
   }

   //push to the stack 
   (*(head->stops+top_index)).copy(to_add);
    ++top_index;

  return 1;

}


/*****************************************************
 Name: pop()
 Input: stop object
 Output: returns 0 if stack is empty, 1 other wise 
 Desc: removes the top item from the stack
*****************************************************/
int stack::pop(stop& data)
{
     //empty stack
     if(!head)
	 return 0;

     //only 1 item left in the array  
    if(top_index == 1)
     {
	node* temp = head;
	head = head->next;
	data.copy((*(temp->stops+top_index-1)));
	delete [] temp->stops;
	delete temp;
	top_index = MAX_SIZE;
	return 1;
     }
   
     //remove the top item from the stack 
     data.copy((*(head->stops+top_index-1)));
     --top_index;

  return 1;
}


/*****************************************************
 Name: pop()
 Output: returns 0 if stack is empty, 1 other wise 
 Desc: removes the top item from the stack
*****************************************************/
int stack::pop()
{

     //empty stack
     if(!head)
	 return 0;

     //only 1 item left in the array  
    if(top_index == 1)
     {
	node* temp = head;
	head = head->next;
	delete [] temp->stops;
	delete temp;
	top_index = MAX_SIZE;
	return 1;
     }
   
     //remove the top item from the stack 
     --top_index;

   return 1;
}



/************************************************
 Name: peek()
 Input: stop object
 Output: returns 0 if empty stack, 1 otherwise 
 Desc: returns the top item of the stack
*************************************************/
int stack::peek(stop& data)
{

 //empty list 
  if(!head) 
	return 0;

      data.copy((*(head->stops+top_index-1)));

   return 1;
}



/************************************************
 Name: display_all()
 Output: returns 0 if stack empty , 1 otherwise 
 Desc: displays the contents of the stack 
*************************************************/
int stack::display_all(void)
{
   //empty stack
   if(!head)
	return 0;

   //display the first array 
   for (int i = top_index-1; i > -1; i--)
     {
	std::cout<<"\n";
	(*(head->stops+i)).display_all();
     }

   //recursively display the rest of the stack 
   return display_all(head->next);
}


/************************************************
 Name: display_all()
 Input: head pointer of the stack 
 Output: returns 0 if stack empty , 1 otherwise 
 Desc: displays the contents of the stack 
*************************************************/
int stack::display_all(node* head)
{  
   //reached the end of stack
   if(!head)
	return 1;

   //display array of stops 	
   display_array_of_stops(head->stops);
  
   return display_all(head->next); 

}



/********************************************************
 Name: display_array_of_stops()
 Input: an array of stops
 Desc: displays all the stops stored in the array 
********************************************************/
void stack::display_array_of_stops(stop* array)
{
   //display the stop information 
   for (int i = MAX_SIZE-1; i > -1; i--)
     {
	(*(array+i)).display_all();
     }

}

/********************************************************
 Name: remove_all()
 Desc: removes all the items in the stack
********************************************************/
void stack::remove_all(void)
{
   //calls recursive function 
   remove_all(head);
}


/********************************************************
 Name: remove_all()
 Input: head pointer of stack
 Desc: removes all the items in the stack
********************************************************/
void stack::remove_all(node*& head)
{
   if(!head)
	return;

   remove_all(head->next);

   delete [] head->stops;
   delete head;
   head = NULL;
}
