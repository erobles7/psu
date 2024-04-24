//stop.h
#include <cstring>

/*********************************************
 Author: Eduardo Robles
 Date: 10/20/2016
 Desc: Definition for the stop class 
       A stop holds all the information about a trip stop
*********************************************/

class stop
{
	public:
		//constructor
		stop();
		stop(char* name,char* location,char* lodging,int miles,char* rating, char* cost);

		//destructor
		~stop();

		//copy function
		int copy(const stop& data);
		
		//set function for each private member variable
		void set_stop_name(char* name);
		void set_location(char* location);
		void set_lodging(char* lodging);
		void set_miles(int miles);
		void set_rating(char* rating);
		void set_gas_cost(char* cost);
		void add_feedback(char* rating, char* cost);

		//print function
		void display_all(void);

	private:
		//private member variables
		char* stop_name;
		char* location_of_stop;
		char* lodging_reserved;
		int miles_to_previous_stop; 
		char* rating;
		char* gas_cost;
		

};
