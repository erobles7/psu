//List.h
#include "AssistanceList.h"

/*
 Author: Eduardo Robles 
 Date: 10/11/2016
 Description: Definition for the List Class.
	      List is made up of subjects.Where each subject has its own list of Assistances 
*/

struct node
{
	char* subject;
	AssistanceList data;
	node* next;
}; 

class List
{
 	public:
		//default constructor
		List();

		//destructor
		~List();
		
		//add new subject to the list
		int add(char* subject);

		//add a new assistance for a particular subject
		int add_new_help(char* subject, const Assistance& to_add);
	
		//displays the entire list of assistances	
		int display_all(void);

		//displays only the top rated assistances with a rating of 3 or higher 
		int display_top_rated(void);

		//displays the lowest rated
		int display_lowest_rated(void);
		
		//edit the rating of a particular assistance 
		int edit_help_rating(char* description,int new_rating);

		//displays the list of subjects 
		void display_subjects(void);

	private:
		//private member functions  
		int display_top_rated(node* head);
		int display_lowest_rated(node* head);
		int display_all(node* head);
		int edit_help_rating(char* description,int new_rating,node* head);
		void remove_all(void);
		void remove_all(node* head);

		node* head;
		node* tail;
};
