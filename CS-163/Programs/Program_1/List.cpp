//List.cpp
#include "List.h"
using namespace std;

/*
 Author: Eduardo Robles 
 Date: 10/11/2016
 Description: Implementation for the AssitanceList Class
	      AssistanceList creates an list of Assistances
*/


/*
   Name: List(()
   Input: no arguments
   Output: no output
   Desc: Default constructor, sets all values to a null state
*/
List::List()
{
	head = NULL;
	tail = NULL;
}


/*
   Name: ~List()
   Input: no arguments
   Output: no output
   Desc: destructor, remove all the items in the list
*/
List::~List()
{
    if(!head)
	return;

    remove_all();
}



/*
   Name: add(char* subject)
   Input: subject to be added
   Output: returns 1
   Desc: adds subject to list, returns 1 if successful , 0 otherwise
*/
int List::add(char* subject)
{
	node* temp = new node;
	temp->next = NULL;
	temp->subject = new char[strlen(subject)+1];
	strcpy(temp->subject,subject);

	//check if list is empty
	if(!head)
	{
		head = temp;
		tail = temp;
		return 1;
	}	
	
	//check if its less than the head
	else if(strcmp(subject,head->subject) < 0)
	{
		temp->next = head;
		head = temp;
		return 1;
	}
	//check if its greater than the tail
	else if(strcmp(subject,tail->subject) > 0)
	{
		tail->next = temp;
		tail = temp; 
		return 1;
	}	
	
	//Its somewhere in the middle 
	else 
	{
		node* current = head;
		while(current->next)
		{
			//if same subject , dont add it
		  	if(strcmp(subject,current->subject) == 0)
			{
				delete temp->subject;
				delete temp;
		    		return 0;
			}
		  	else if(strcmp(subject,current->next->subject) < 0 )
		 	 {
				temp->next = current->next;
				current->next = temp;
				return 1;
		         }
			current = current->next;
		}
	}

	return 1;
}



/*
   Name: remove_all()
   Input: None
   Output: None
   Desc: removes all items subjects and assistances in the list
*/
void List::remove_all()
{
    if(!head)
	return;

     remove_all(head);
}


/*
   Name: remove_all(node* head)
   Input: head pointer
   Output: None
   Desc: removes all items subjects and assistances in the list
*/
void List::remove_all(node* head)
{
	if(!head)
	   return;

	remove_all(head->next);
	delete  [] head->subject;
	delete head;
	head = NULL;
	tail = NULL;
}



/*
   Name: display_all()
   Input: None
   Output: None
   Desc: displays all the assistances for each subject
*/
int List::display_all(void)
{
	if(!head)
	   return 0;

	std::cout<<"\nList of Subjects\n";
	std::cout<<"--------------------------\n";
	display_subjects();
	std::cout<<"\n";
	return display_all(head);
}


/*
   Name: display_all(node* head)
   Input: None
   Output: None
   Desc: displays all the assistances for each subject
*/
int List::display_all(node* head)
{
	if(!head)
	{
	   return 1;
	}
	head->data.display();

	return display_all(head->next);	
}


/*
   Name: add_new_help(char* subject, const Assistance& to_add)
   Input: subject to add assistance, assistance object
   Output: None
   Desc: adds  a new assistance for a particular subject
*/
int List::add_new_help(char* subject, const Assistance& to_add)
{
	node* current = head;

	while(current)
	{
		//if matching subject is found , add the assistance
		if(strcmp(subject,current->subject) == 0)
		{
			current->data.add(to_add);
			return 1;
		}
		current = current->next;
	}
	return 0;
}



/*
   Name: display_subjects(void)
   Input: None
   Output: None
   Desc: displays all the subjects
*/
void List::display_subjects(void)
{
	if(!head)
	    return ;

	node* current = head;
	while(current)
	{
	   //print out subject
	   std::cout<<"["<<current->subject<<"]"<<"  "; 
	   current = current->next;
	}
	std::cout<<"\n";
}



/*
   Name: display_top_rated(void)
   Input: None
   Output: None
   Desc: displays all the top rated assistances
*/
int List::display_top_rated(void)
{
	if(!head)
	    return 0;
	
	return display_top_rated(head);
}


/*
   Name: display_top_rated(node* head)
   Input: head pointer
   Output: return 1 if list was not empty 
   Desc: displays all the top rated assistances
*/

int List::display_top_rated(node* head)
{
	if(!head)
	    return 1;

	head->data.display_top_rated();

	return display_top_rated(head->next);
}

/*
   Name: display_lowest_rated(void)
   Input: None
   Output: None
   Desc: displays all the lowest rated assistances
*/
int List::display_lowest_rated(void)
{
	if(!head)
	    return 0;
	
	return display_lowest_rated(head);
}


/*
   Name: display_lowest_rated(node* head)
   Input: head pointer
   Output: return 1 if list was not empty 
   Desc: displays all the lowest rated assistances
*/
int List::display_lowest_rated(node* head)
{
	if(!head)
	    return 1;

	head->data.display_lowest_rated();

	return display_lowest_rated(head->next);
}

/*
   Name: edit_help_rating(char* description,int new_rating)
   Input: description of the assistance , new rating for the assistance
   Output: return 1 if list was not empty 
   Desc: displays all the top rated assistances
*/
int List::edit_help_rating(char* description,int new_rating)
{
	if(!head)
	   return 0;

	return edit_help_rating(description,new_rating,head);	

}


/*
   Name: edit_help_rating(char* description,int new_rating,node* head)
   Input: description of the assistance , new rating for the assistance, head pointer
   Output: return 1 if list was not empty 
   Desc: displays all the top rated assistances
*/
int List::edit_help_rating(char* description,int new_rating,node* head)
{

	if(!head)
	   return 1;

	head->data.edit_rating(description,new_rating);
	
	return edit_help_rating(description,new_rating,head->next);
}


