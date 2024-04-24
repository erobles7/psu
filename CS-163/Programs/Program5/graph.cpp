//  graph.cpp

#include "graph.h"
#include <iostream>
using namespace std;

/*******************************************************************
 Name: table()
 Input: table size
 Desc: Default constructor, initializes all variables to NULL state
 *******************************************************************/
table::table(int size)
{
   //allocate the adjacency list
   list_size = size;
   adjacency_list = new vertex[list_size];
   vertex* current = adjacency_list;
   vertex* stop = adjacency_list + size;

   //loop through the array and initialize everything to NULL
   while(current < stop)
  {
	(*current).visited = false;
	(*current).activity = NULL;
	(*current).head = NULL;

	++current;
  } 
}

/*******************************************************************
 Name: ~table()
 Desc: destructor, deallocates all the memory
 *******************************************************************/
table::~table()
{
   //deallocate the array of vertexes
   for(int i = 0; i<list_size; ++i)
   {
	remove_chain((*(adjacency_list+i)).head); //remove linked list
	(*(adjacency_list+i)).visited = false; //set visited to false
	delete (*(adjacency_list+i)).activity; //delete the activity; 
   }

  delete adjacency_list;
}

/*******************************************************************
 Name: table()
 Input: table size
 Desc: Default constructor, initializes all variables to NULL state
 *******************************************************************/
void table::remove_chain(node*& head)
{
    if(!head)
	return;

   remove_chain(head->next);

   delete head;
   head = NULL;
}


/*******************************************************************
 Name: insert_vertex()
 Input: Activity
 Desc: inserts a new vertex
 *******************************************************************/
int table::insert_vertex(const Activity& to_add)
{
   int i = 0;
   
   bool isFound = false;
   
   while(i < list_size && !isFound)
   {
	if(!(*(adjacency_list+i)).activity)
	{
		(*(adjacency_list+i)).activity = new Activity;	
		(*(adjacency_list+i)).activity->copy(to_add);
		isFound = true;
	}
	++i;
   }

    if(isFound)
	return 1;
    else
	return 0;
}


/*******************************************************************
 Name: insert_edge()
 Input: current vertex, vertex to attach to
 Desc: connects to vertices
 *******************************************************************/
int table::insert_edge(char* current_vertex, char* to_attach)
{
    //find locations
    int from = find_location(current_vertex);
    int to  = find_location(to_attach);

    //invalid locations, not in list 
    if(from < 0 || to < 0)
	return 0;

    node* temp = (*(adjacency_list+from)).head;
    vertex* toAddTo = adjacency_list + from;
    (*(toAddTo)).head = new node;
    (*(toAddTo)).head->next = temp;
    (*(toAddTo)).head->adjacent = adjacency_list+to;
	
   return 1;
}


/*******************************************************************
 Name: find_location()
 Input: key value , (vertex goal)
 Desc: connects to vertices
 *******************************************************************/
int table::find_location(char* key_value)
{
	for(int i = 0; i<list_size; ++i)
	{
	   if((*(adjacency_list+i)).activity)
		if((*(adjacency_list+i)).activity->compare(key_value));
			return i;
	}

    return -1;
}


/*******************************************************************
 Name: display_tasks_for_goal()
 Input: key value
 Desc: displays tasks for a goal
 *******************************************************************/
int table::display_tasks_for_goal(char* key_value)
{
     int location = find_location(key_value);
	
    //invalid locations, not in list 
    if(location < 0)
	return 0;

   //recursively diplsay all the tasks
   return  display_tasks_for_goal((*(adjacency_list+location)).head);
}


/*******************************************************************
 Name: display_tasks_for_goal()
 Input: node pointer to linked list 
 Desc: displays all the tasks in the linked list
 *******************************************************************/
int table::display_tasks_for_goal(node* head)
{
	if(!head)
	    return 1;

       //display goal information
       head->adjacent->activity->display_all();
       std::cout<<endl;
      
      return display_tasks_for_goal(head->next);
}


/*******************************************************************
 Name: display_all()
 Input: displays all the verticies in the array
 Desc: displays all the tasks in the linked list
 *******************************************************************/
int table::display_all(void)
{
   if(!adjacency_list)
	return 0;

    //loop through the array 
   for(int i = 0; i< list_size; ++i)
    {
	//dont display if nothing is there 
	if((*(adjacency_list+i)).activity == NULL)
	{
	}

	else
	{
		//display vertex information
		(*(adjacency_list+i)).activity->display_all();
		std::cout<<"\n";
	}
    } 
   return 1;
}

/*******************************************************************
 Name: display_adjacent()
 Input: goal
 Desc: displays all the adjacent verticies of the goal
 *******************************************************************/
int table::display_adjacent(char* key_value)
{
	if(!adjacency_list)
		return 0;
  
	int index = find_location(key_value);

	return display_adjacent((*(adjacency_list+index)));	
}

/*******************************************************************
 Name: display_adjacent()
 Input: goal
 Desc: displays all the adjacent verticies of the goal
 *******************************************************************/
int table::display_adjacent(vertex my_vertex)
{
   if(my_vertex.visited == true)
	return 1;

   my_vertex.activity->display_all();
   my_vertex.visited = true;

   //display_adjacent(my_vertex.head->adjacent);

  return 1;

}

