#include <iostream>
using namespace std;

#include "queue.h"

/*************************************
Author: Eduardo Robles
Date: 10/21/2016
Desc: Testing program for stack and queues
**************************************/

//function prototypes
void main_menu(stack& my_stack, queue& my_queue);
void add_stop(stack& my_stack, queue& my_queue);
void display_all_stops(stack& my_stack, queue& my_queue);
void display_all_stops_reverse(stack& my_stack,queue& my_queue);
void display_most_recent_stop(stack& my_stack, queue& my_queue);

int main()
{
	//create a stack and queue
	stack my_stack(5);
	queue my_queue;

	//run main menu program	
	main_menu(my_stack,my_queue);
	return 0;
}


/************************************************************
 Name: main_menu()
 Input: stack object, queue object
 Desc: Main menu for testing stack and queue functions, 
************************************************************/
void main_menu(stack& my_stack, queue& my_queue)
{
  int input = 0;  

  do 
   {
	std::cout<<"\nPlease choose from the following options\n";
	std::cout<<"1. Add a new trip stop\n";
        std::cout<<"2. Display all stops in order\n"; 
	std::cout<<"3. Display all stops in reverse order\n";
        std::cout<<"4. Display most recent stop added\n";
        std::cout<<"5. Quit\n";
	std::cout<<" $: ";
 	std::cin>>input;
	cin.ignore();
	cout<<endl;
   }  

    while(input != 1 && input !=2 && input !=3 && input != 4 && input !=5);

    switch(input)
    {
	case 1:
		add_stop(my_stack,my_queue);
		break;
	case 2:
		display_all_stops(my_stack,my_queue);
		break;

	case 3:
	        display_all_stops_reverse(my_stack,my_queue);
		break;
	case 4:
		display_most_recent_stop(my_stack,my_queue);
		break;
	default:
		break;	
    }
}

/************************************************************
 Name: add_stop()
 Input: stack object, queue object
 Desc: adds a stop to stack and queue
************************************************************/
void add_stop(stack& my_stack, queue& my_queue)
{
   char stop_name[100];
   char location_of_stop[100];
   char lodging_reserved[100];
   int miles_to_previous_stop;
   char rating [100];
   char gas_cost[100];

    //get the name of the stop
    cout <<"\nEnter the name of the next stop \n";
    cout<<": ";
    cin.get(stop_name,100,'\n');
    cin.ignore(100,'\n');

    //get location of the stop
    cout <<"\nEnter the location (City and State) \n";
    cout<<": ";
    cin.get(location_of_stop,100,'\n');
    cin.ignore(100,'\n');

    //get lodging reserved
    cout <<"\nEnter the lodging information (Name, Address, Price) \n";
    cout<<": ";
    cin.get(lodging_reserved,100,'\n');
    cin.ignore(100,'\n');
	
    //get miles to previous stop
    cout <<"\nEnter the number of miles to travel from the previous stop to this one \n";
    cout<<": ";
    cin>>miles_to_previous_stop;
    cin.ignore(100,'\n');

    //get the rating for a stop
    cout <<"\nEnter rating for the lodging (excellent, good ,average, poor)\n";
    cout<<": ";
    cin.get(rating,100,'\n');
    cin.ignore(100,'\n');

    //get the cost of gas
    cout <<"\nEnter how much was spent on gas for this part of the trip\n";
    cout<<": ";
    cin.get(gas_cost,100,'\n');
    cin.ignore(100,'\n');

	
    
    //create stop object
    stop my_stop(stop_name,location_of_stop,lodging_reserved,miles_to_previous_stop,rating,gas_cost);

    //add to the queue
    my_queue.enqueue(my_stop);

   //push to the stack
   my_stack.push(my_stop);

   //return to main menu  	
   main_menu(my_stack,my_queue);
}

/************************************************************
 Name: display_all_stops()
 Input: stack object, queue object
 Desc: Displays all the list of stops
************************************************************/
void display_all_stops(stack& my_stack, queue& my_queue)
{
   //display the queue
   if(my_queue.display_all() == 0)
      std::cout<<"No trips have been planned :( \n";

   //return to main menu
   main_menu(my_stack,my_queue);
}

void display_all_stops_reverse(stack& my_stack,queue& my_queue)
{

   //display the queue
   if(my_stack.display_all() == 0)
      std::cout<<"No trips have been planned :( \n";

   //return to main menu
   main_menu(my_stack,my_queue);

}

/************************************************************
 Name: display_most_recent_stop()
 Input: stack object, queue object
 Desc: displays the most recent stop
************************************************************/
void display_most_recent_stop(stack& my_stack, queue& my_queue)
{
   stop my_stop;

   if(my_stack.peek(my_stop) == 0)
     std::cout<<"\nNo trips have been planned";
     std::cout<<"\n"; 

   //display info 
   my_stop.display_all();

   //return to main menu
   main_menu(my_stack,my_queue);
}


