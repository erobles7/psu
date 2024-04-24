/*************************************************************
 Author: Eduardo Robles
 Date : 12/01/2016
 Desc: Test program for the adjacency list for graphs
**************************************************************/
#include <iostream>
#include "graph.h"

//function prototypes----->
void main_menu(table& my_table);
void insert_vertex(table& my_table);
void insert_edge(table& my_table);
void display_all_tasks_for_goal(table& my_table);
void display_all_connecting(table& my_table);
void display_all(table& my_table);

using namespace std;

int main()
{
    //create table object 
    table my_table;

    //run main menu
    main_menu(my_table);

    return 0;
}


/*******************************************************************
 Name: main_menu()
 Input: table object 
 Desc: main menu for testing functions
 *******************************************************************/
void main_menu(table& my_table)
{

	int input = 0; 

	do 
	{
		std::cout<<"\nPlease choose from the following options\n";
      		std::cout<<"1. Insert a vertex\n";
      		std::cout<<"2. Insert an edge (connect two verticies)\n"; 
      		std::cout<<"3. Display all tasks to achieve a certain goal\n";
      		std::cout<<"4. Display all connecting verticices from a specified goal\n";
      		std::cout<<"5. Display all vertexes\n";
      		std::cout<<"6. Quit\n";
      		std::cout<<" $: ";
      		std::cin>>input;
      		cin.ignore();
      		cout<<endl;
	}

	while(input != 1 && input !=2 && input !=3 && input != 4 && input !=5 && input!=6);

    	//call the correct function
    	switch(input)
    	{
      	case 1:
            	insert_vertex(my_table);
            	break;
      	case 2:
           	insert_edge(my_table); 
		break;
      	case 3:
            	display_all_tasks_for_goal(my_table);
            	break;
     	case 4:
            	display_all_connecting(my_table);
            	break;
     	case 5:
            	display_all(my_table);
            	break;
      	default:
           	break;
   }
}

/*******************************************************************
 Name: insert_vertex()
 Input: table object 
 Desc: inserts a vertex
 *******************************************************************/
void insert_vertex(table& my_table)
{
    char goal [100];
    char time [100];

    //get the goal
    std::cout<<"\nEnter a goal or task \n";
    cout<<": ";
    cin.get(goal,100,'\n');
    cin.ignore(100,'\n');

    //get the time
    std::cout<<"\nEnter a time for goal to be comepleted (ex Dec 16 2016) \n";
    cout<<": ";
    cin.get(time,100,'\n');
    cin.ignore(100,'\n');

    //create new activity
    Activity new_activity(goal,time);

   //insert activity
   my_table.insert_vertex(new_activity);

   //return to main menu
   main_menu(my_table);
}


/*******************************************************************
 Name: insert_edge()
 Input: table oject
 Desc: insert an edge between two verticies
 *******************************************************************/
void insert_edge(table& my_table)
{
	
    char goal [100];
    char goal2 [100];

    //get the goal
    std::cout<<"\nEnter first goal \n";
    cout<<": ";
    cin.get(goal,100,'\n');
    cin.ignore(100,'\n');

    //get the time
    std::cout<<"\nEnter second goal to connect to first goal\n";
    cout<<": ";
    cin.get(goal2,100,'\n');
    cin.ignore(100,'\n');

   //connect the goals
   if(my_table.insert_edge(goal,goal2) == 1)
    {
	std::cout<<"\nEdge connected successfully\n";
    }

   else
	std::cout<<"\nError inserting an edge, invalid goal\n";

    //return to main menu
    main_menu(my_table);
}


/*******************************************************************
 Name: display_all_tasks_for_goal()
 Input: table object 
 Desc: displays all task for a certain goal
 *******************************************************************/
void display_all_tasks_for_goal(table& my_table)
{

    char goal [100];

    //get the goal
    std::cout<<"\nEnter the goal to display all tasks that need to get gone\n";
    cout<<": ";
    cin.get(goal,100,'\n');
    cin.ignore(100,'\n');

    //display all the taks prior to goal
    my_table.display_tasks_for_goal(goal);

    //return to main menu
    main_menu(my_table);
}

/*******************************************************************
 Name:  display_all_connecting()
 Input: table object 
 Desc: displays all connecting verticies from a specified goal
 *******************************************************************/
void display_all_connecting(table& my_table)
{

    char goal [100];

    //get the goal
    std::cout<<"\nEnter the goal to display all connecting verticies\n";
    cout<<": ";
    cin.get(goal,100,'\n');
    cin.ignore(100,'\n');

    //display all connecting verticies
    //my_table.display_adjacent(goal);

    //return to main menu
    main_menu(my_table);

}


/*******************************************************************
 Name:  display_all_()
 Input: table object 
 Desc: displays all items in array
 *******************************************************************/
void display_all(table& my_table)
{
   //display array contents
   my_table.display_all();  


   //return to main menu
   main_menu(my_table);
}
