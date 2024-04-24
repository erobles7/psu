//Assistance.h
#include "Assistance.h"

/*
 Author: Eduardo Robles 
 Date: 10/11/2016
 Description: Definition for the AssitanceList Class
	      AssistList is a list of assistances
*/

struct node_AL
{
	Assistance data;
	node_AL* next;
};

class AssistanceList
{
	public:
		//Constructors
		AssistanceList();

		//destructor
		~AssistanceList();

		//add function
		int add(const Assistance& to_add);

		//remove everything in the list 
		void remove_All(void);

		//display all assistances in the list 
		int  display(void);

		//displays only top rated assistances
		int display_top_rated(void);

		//displays the lowest rated assistances
		int display_lowest_rated(void);

		//edits rating
		int edit_rating(char* description,int rating);
		
	private:
		//private member functions
		int display(node_AL* head);
		int display_top_rated(node_AL* head);
		int display_lowest_rated(node_AL* head);
		int edit_rating(char* description,node_AL* head,int rating);
		void  remove_All(node_AL*&  head);

		node_AL* head;
		node_AL* tail;
		
};
