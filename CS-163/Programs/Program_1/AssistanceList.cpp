//AssistanceList.cpp
#include "AssistanceList.h"

/*
 Author: Eduardo Robles 
 Date: 10/11/2016
 Description: Implementation for the AssitanceList Class
	      AssistanceList creates an list of Assistances
*/


/*
   Name: AssistanceList()
   Input: no arguments
   Output: no output
   Desc: Default constructor, sets all values to a null state
*/
AssistanceList::AssistanceList()
{
	head = NULL;
	tail = NULL;
}



/*
   Name: ~AssistanceList()
   Input: no arguments
   Output: no output
   Desc: deconstrcutor, deallocates all memory 
*/
AssistanceList::~AssistanceList()
{
	//call remove function to delete everything
	remove_All();
}



/*
   Name: add(const Assistance& to_add)
   Input: assistance being added to the list
   Output: return 0 if not added , 1 if assistance was added
   Desc: adds an assistance to the list  
*/
int AssistanceList::add(const Assistance& to_add)
{
	//if empty list 
	if(!head)
	{
	   head = new node_AL;
	   head->data.copy(to_add);
	   head->next = NULL;
	   tail = head;
	}
	//add to the end of the list
	else
	{
	  node_AL* temp = new node_AL;
	  temp->data.copy(to_add);
	  tail->next = temp;
	  tail = temp;
	  tail->next = NULL;
	}
	return 1;
}



/*
   Name: remove_all(void)
   Input: None
   Output: None
   Desc: removes all the items from the list   
*/
void AssistanceList::remove_All(void)
{
	if(!head)
	   return;

	remove_All(head);
}
void AssistanceList::remove_All(node_AL*&  head)
{
	if(!head)
	   return;

	remove_All(head->next);

	delete head;
	head = NULL;
	tail = NULL;
}



/*
   Name: display(void)
   Input: None
   Output: returns 1 if list not empty , 0 otherwise
   Desc: displays the list of assistances, return 1 if successful 
*/
int AssistanceList::display(void)
{
	if(!head)
	    return 0;

	return display(head);
}



/*
   Name: display(node_AL* head))
   Input: head pointer of the list
   Output: returns 1 
   Desc: displays the list of assistances, return 1 if successful 
*/
int AssistanceList::display(node_AL* head)
{
    
	if(!head)
	   return 1;

	head->data.display_all();
	std::cout<<"---------------"<<std::endl;

	return display(head->next);
}



/*
   Name: display_top_rated()
   Input: No input
   Output: returns 1 if list is not empty 
   Desc: displays the list of top rated  assistances, return 1 if successful 
*/
int AssistanceList::display_top_rated(void)
{
  if(!head)
	return 0;	

	return display_top_rated(head);
}



/*
   Name: display_top_rated()
   Input: No input
   Output: returns 1 if list is not empty 
   Desc: displays the list of top rated  assistances, return 1 if successful 
*/
int AssistanceList::display_top_rated(node_AL* head)
{
	if(!head)
	    return 1;
	if(head->data.get_rating() >= 8)
	{
		head->data.display_all();
		std::cout<<"---------------------"<<std::endl;
	}
	return display_top_rated(head->next);

}


/*
   Name: display_lowest_rated()
   Input: No input
   Output: returns 1 if list is not empty 
   Desc: displays the list of lowest rated  assistances, return 1 if successful 
*/
int AssistanceList::display_lowest_rated(void)
{
	if(!head)
	    return 0;

	return display_lowest_rated(head);

}


/*
   Name: display_lowest_rated()
   Input: No input
   Output: returns 1 if list is not empty 
   Desc: displays the list of lowest rated  assistances, return 1 if successful 
*/
int AssistanceList::display_lowest_rated(node_AL* head)
{

	if(!head)
	    return 1;
	if(head->data.get_rating() <4)
	{
		head->data.display_all();
		std::cout<<"---------------------"<<std::endl;
	}

	return display_top_rated(head->next);

}



/*
   Name: edit_rating(char* description, int rating)
   Input: description and assistance rating
   Output: returns 1 if  assistance was edited 
   Desc: edit the rating of a particular assistance
*/
int AssistanceList::edit_rating(char* description,int rating)
{
	if(!head)
	    return 0;
	return edit_rating(description,head,rating);
}



/*
   Name: edit_rating(char* description, node_AL* head,int rating)
   Input: description , head pointer, rating
   Output: returns 1 if  assistance was edited 
   Desc: edit the rating of a particular assistance
*/
int AssistanceList::edit_rating(char* description,node_AL* head,int rating)
{
	if(!head)
	   return 0;

	if(strcmp(head->data.get_description(),description) == 0)
	{
		head->data.set_rating(rating);
		return 1;
	}
	
	return edit_rating(description,head->next,rating);
}


