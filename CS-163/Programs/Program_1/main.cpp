//main.cpp
#include "List.h"
using namespace std;

/*
 Author: Eduardo Robles 
 Date: 10/11/2016
 Description: Client test program, tests all the functions of the list class
*/


//function prototypes
void main_menu(List& myList);
void add_subject(List& myList);
void add_assistance(List& myList);
void display_all(List& myList);
void display_top_rated(List& myList);
void display_low_rated(List& myList);
void edit_rating(List& myList);


int main()
{
	//create new list object
	List myList;
	
	//run test menu
	main_menu(myList);

	return 0;
}


/*
   Name: main_menu(List& myList)
   Input: List object
   Output: no output
   Desc: Main menu for testing list functions, takes List object as an argument
*/
void main_menu(List& myList)
{
    int input;

	do
	{	
		
		cout <<"\nPlease choose from the following options\n";
		cout <<"1. Add a new subject\n";
		cout <<"2. Add a new assistance for a particular subject\n";
		cout <<"3. Display all information\n";
		cout <<"4. Display top rated assistances\n";
		cout <<"5. Display low rated assistances\n";
		cout <<"6. Edit  a assistance rating\n";
		cout <<"7. Quit \n";
		cout<<"  $: ";
		cin>>input;
		cin.ignore();
		cout<<endl;
	}

	while(input != 1 &&  input != 2 && input !=3  && input !=4  &&  input !=5 && input !=6 && input !=7);

	//call the corresponding function 	
	switch(input)
	{
	   case 1 :
		   add_subject(myList);
		   break;
	  case 2 :
		  add_assistance(myList);
		  break;
	  case 3: 
		  display_all(myList);
		  break;
	  case 4:
		  display_top_rated(myList);
		  break;
	  case 5:
		  display_low_rated(myList);
		  break;

	  case 6: 
		  edit_rating(myList);
		  break;
	   
	  default:
	          break;
	}
}

/*
   Name: add_subject(List& myList)
   Input: List object
   Output: no output
   Desc: gets new subject from the user,add's it to the list being passed
*/
void add_subject(List& myList)
{
	
	char userInput[100];
   	cout <<"\nEnter a new subject to add\n";
   	cout<<": ";
   	cin.get(userInput,100,'\n');
   	cin.ignore(100,'\n');
	myList.add(userInput);	
	main_menu(myList);
}



/*
   Name: add_assistance(List& myList)
   Input: List object
   Output: no output
   Desc: gets new subject from the user,add's it to the list being passed
*/
void add_assistance(List& myList)
{
	char subject[100];	
	char desc [100];
	char hours [100];
	int rating;
	char location [100];
	char number [100];

	//get the subject the assistance is for 	
	cout <<"\nEnter a subject to add an assistance for \n";
   	cout<<": ";
   	cin.get(subject,100,'\n');
   	cin.ignore(100,'\n');
	
	//get description of the assistance
	cout <<"\nEnter a description of the assistance\n";
   	cout<<": ";
   	cin.get(desc,100,'\n');
   	cin.ignore(100,'\n');
	
	//get available hours
	cout <<"\nEnter available hours ex. 5:00 pm - 10:00 pm \n";
   	cout<<": ";
   	cin.get(hours,100,'\n');
   	cin.ignore(100,'\n');
	
	//get assistance rating 
	cout <<"\nEnter a rating  0 - 10 (10 being best)\n";
   	cout<<": ";
   	cin>>rating;
   	cin.ignore(100,'\n');
	
	//get location
	cout <<"\nEnter a location\n";
   	cout<<": ";
   	cin.get(location,100,'\n');
   	cin.ignore(100,'\n');

	//get phone number
	cout <<"\nEnter a phone number ex. 503-454-232\n";
   	cout<<": ";
   	cin.get(number,100,'\n');
   	cin.ignore(100,'\n');

	//create assistance object	
	Assistance new_assistance(desc,hours,rating,location,number);
	
	//add it to the list
	myList.add_new_help(subject,new_assistance);
	
	//bring up the main menu	
	main_menu(myList);
}



/*
   Name: display_all(List& myList)
   Input: List object
   Output: no output
   Desc: displays all the assistances for each subject 
*/
void display_all(List& myList)
{
	std::cout<<"\n";
	
	//display list information unless its empty 
	if(myList.display_all() == 0)
	{
	   std::cout<<"\nThe list is empty\n";

	}
	
	//bring up the main menu
	main_menu(myList);
}



/*
   Name: display_top_rated(List& myList)
   Input: List object
   Output: no output
   Desc: displays the top rated assistances
*/
void display_top_rated(List& myList)
{
	std::cout<<"\n";

	//display the top rated assistances in the list unless its empty
	if(myList.display_top_rated() == 0)
	{
	   std::cout<<"\nThe list is empty\n";

	}	
	
	//bring up the main menu
	main_menu(myList);
}



/*
   Name: display_low_rated(List& myList)
   Input: List object
   Output: no output
   Desc: displays the lowest rated assistances
*/
void display_low_rated(List& myList)
{
	std::cout<<"\n";

	//display the lowest rated assistances in the list unless its empty 
	if(myList.display_lowest_rated() == 0)
	{
	  std::cout<<"\nThe list is empty\n";

	}
	
	//bring up the main menu
	main_menu(myList);

}



/*
   Name: edit_rating(List& myList)
   Input: List object
   Output: no output
   Desc: edits the rating for an assistance
*/
void edit_rating(List& myList)
{

	char desc[100];	
	int rating;	

	//get description
	cout <<"\nEnter the name of the description to be edited\n";
   	cout<<": ";
   	cin.get(desc,100,'\n');
   	cin.ignore(100,'\n');
	
	//get the new rating 
	cout <<"\nEnter a new rating for the assistance \n";
   	cout<<": ";
   	cin>>rating;
   	cin.ignore(100,'\n');

	//change the rating 
	if(myList.edit_help_rating(desc,rating) == 0)
	{
	   std::cout<<"\nAssistance not found \n";
	}

	//bring up the main menu	
	main_menu(myList);
}
