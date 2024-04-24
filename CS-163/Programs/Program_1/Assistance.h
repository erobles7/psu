//Assistance.h
#include <cstring>
#include <iostream>

/*
 Author: Eduardo Robles 
 Date: 10/11/2016
 Description: Definition for the Assitance Class
	      An Assitance holds information on how to get help for a subject
*/

class Assistance
{
	public:
		//constructor(s)
		Assistance();
		Assistance(char* desc, char* hours, int rating, char* location, char* number);

		//destructor
		~Assistance();

		//Copy function 
		int copy(const Assistance& A);

		//Set functions for each private member variable
		void set_rating(int num);
		void set_description(char* name);
		void set_hours(char* hours);
		void set_location(char* location);
		void set_number(char* number);
		int get_rating(void);
		char* get_description(void) const;
	        
		//print funtions 	
		void display_all(void);
	private:
		//private member variables
		char* description;
		char* available_hours;
		int rating;
		char* location;
		char* phone_number;
};
