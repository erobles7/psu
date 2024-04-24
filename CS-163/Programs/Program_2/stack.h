//stack.h
#include "stop.h"

/*****************************************
 Author: Eduardo Robles
 Date: 10/20/2016
 Desc: Definition for the stack class 
       stack stores list of trip stops
******************************************/
struct node
{
	stop* stops;
	node* next;
};

class stack
{

	public:
		//constructors
		stack(int size);
		~stack();
		
		//pushes a stop object to the stack		
		int push(const stop& to_add);

		//removes top item from the stack and retrieves it 
		int pop(stop& data);
		
		//removes top item
		int pop();

		//retrieves the top item from the stack
		int peek(stop& data);

		//removes everthing in the stack 
		void remove_all(void);
		
		//displays all stops in the stack
		int display_all(void);	

	private:
		//private member variables
		node* head;
		int top_index;
		int MAX_SIZE;

		//private recursive functions 
		void remove_all(node*& head);
		int display_all(node* head);
		void display_array_of_stops(stop* array);
};
