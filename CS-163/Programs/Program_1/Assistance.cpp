//Assitance.cpp
#include "Assistance.h"

/*
 Author: Eduardo Robles 
 Date: 10/11/2016
 Description: Implementation for the Assitance Class
	      Assistance object holds all information to get help
*/


/*
   Name: Assistance()
   Input: no arguments
   Output: no output
   Desc: Default constructor, sets all values to a null state
*/
Assistance::Assistance()
{
	//set everything to NULL
	description = NULL;
	available_hours = NULL;
	rating = 0;
	location = NULL;
        phone_number = NULL;
}


/*
   Name: Assistance(char* desc, char* hours, int rating, char* location, char* number)
   Input: description, hours, rating , location of help , phone number
   Output: no output
   Desc: constructor, intializes all the member variables to arguments passed in
*/
Assistance::Assistance(char* desc, char* hours, int rating, char* location, char* number)
{
	set_description(desc);
	set_hours(hours);
	set_rating(rating);
        set_location(location);
        set_number(number);
}



/*
   Name: ~Assistance()
   Input: No input
   Output: no output
   Desc: deconstructor , deallocates all the dynamic memory 
*/
Assistance::~Assistance()
{
	//Deallocate Memory	
	delete [] description;
	delete [] available_hours;
	delete [] location;
	delete [] phone_number;
}



/*
   Name: copy(const Assitance& A))
   Input: Assistance object
   Output: returns 1 , if object was copied 
   Desc: copies the assistance object information
*/
int Assistance::copy(const Assistance& A)
{
	//set the information 
	set_description(A.description);
	set_hours(A.available_hours);
	set_rating(A.rating);
	set_location(A.location);
	set_number(A.phone_number);

	return 1;
}



/*
   Name: set_rating(int num)
   Input: num - the rating 
   Output: No output 
   Desc: set the rating of the assistance
*/
void  Assistance::set_rating(int num)
{
	//if higher than the max
	if(num > 10)
	    rating = 10;

	//if lower than the max 
	else if(num < 0)
	    rating = 0;	

	else 
	rating = num;
}



/*
   Name: set_description(char* name)
   Input: the description of the Assistance
   Output: No output 
   Desc: set the description of the assistance
*/
void Assistance::set_description(char* name)
{
	description = new char[strlen(name)+1];
	strcpy(description,name);
}



/*
   Name: set_hours(char* hours)
   Input: the hours for the assistance
   Output: No output 
   Desc: set the hours  of the assistance
*/
void Assistance::set_hours(char* hours)
{
	available_hours = new char[strlen(hours)+1];
	strcpy(available_hours,hours);
}



/*
   Name: set_location(char* location)
   Input: the hours for the assistance
   Output: No output 
   Desc: set the hours  of the assistance
*/
void Assistance::set_location(char* location)
{
	this->location = new char[strlen(location)+1];
	strcpy(this->location,location);
}



/*
   Name: set_number(char* number)
   Input: the number for the assistance
   Output: No output 
   Desc: set the phone number for  the assistance
*/
void Assistance::set_number(char* number)
{
	phone_number = new char[strlen(number)+1];
	strcpy(phone_number,number);	
}



/*
   Name: get_rating(void)
   Input: No input
   Output: rating
   Desc: returns the rating 
*/
int Assistance::get_rating(void)
{
	return rating;
}



/*
   Name: get_description(void)
   Input: No input
   Output: description
   Desc: returns the description 
*/
char* Assistance::get_description(void) const
{
	return description;
}



/*
   Name: display_all(void)
   Input: No input
   Output: No output
   Desc: displays all the assistance information
*/
void Assistance::display_all(void)
{
	std::cout<<description<<std::endl;	
	std::cout<<available_hours<<std::endl;	
	std::cout<<"Rating: "<<rating<<std::endl;	
	std::cout<<location<<std::endl;
	std::cout<<phone_number<<std::endl;	
}
	
