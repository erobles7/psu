//queue.h
#include "stack.h"

/*************************************
Author: Eduardo Robles
Date: 10/21/2016
Desc: Definition for the queue class
*************************************/
struct q_node
{
	stop data;
	q_node* next;
};

class queue
{
	public:
		//default constructor
		queue(void);
		
		//destructor
		~queue(void);

		//adds an item to the queue
		int enqueue(const stop& to_add);

		//removes an item from the queue
		int dequeue(stop& top_item);

		//removes an item from the queue, nothing is returned
		int dequeue();

		//returns the first item in the queue
		int peek(stop& top_item);

		//displays the top item in the queue
		int peek();

		//displays the queue
		int display_all(); 

		//deallocates all dynamic memory 
		void remove_all();

	private:
		//private recursive functions 	
		int display_all(q_node* rear);
		void remove_all(q_node*& rear);

		//rear pointer 
		q_node* rear;
};
