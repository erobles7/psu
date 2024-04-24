//  graph.h

/*************************************************************
 Author: Eduardo Robles
 Date : 12/01/2016
 Desc: Definition for the graph class
  Adjacency list of Activities for winter break
 *************************************************************/

#include "Activity.h"

struct vertex
{
    bool visited;
    Activity* activity;
    struct node* head;
    
};

struct node
{
    vertex* adjacent;
    node* next;
};

class table
{
    public:
    
        //constructor
        table(int size = 5);
    
        //destructor
        ~table(void);
    
        //insert vertex
        int insert_vertex(const Activity& to_add);
    
        //find location
        int find_location(char* key_value);
    
        //insert edge
        int insert_edge(char* current_vertex, char* to_attach);
    
        //display adjacent
        int display_adjacent(char* key_value);

	//display all tasks for a goal
	int display_tasks_for_goal(char* key_value);
    
        //display all
        int display_all(void);

    private:
	    vertex* adjacency_list;
	    int list_size;

	   //remove chain
	   void remove_chain(node*& head);
	   int display_tasks_for_goal(node* head);
	   int display_adjacent(vertex my_vertex);
};

