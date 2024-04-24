//stop.cpp
#include "stop.h"
#include <iostream>

/********************************************************************
 Author: Eduardo Robles
 Date: 10/20/2016
 Desc: Implementation for the stop class 
       Stop object holds all the information about a certain stop
********************************************************************/


/*******************************************************************
 Name: stop()
 Input: None
 Output: None
 Desc: Default constructor, initializes all variables to NULL state
*******************************************************************/
stop::stop()
{
  stop_name = NULL;
  location_of_stop = NULL;
  lodging_reserved = NULL;
  miles_to_previous_stop = 0;
  rating = NULL;
  gas_cost = NULL;
}


/*****************************************************************************
 Name: stop()
 Input: name,location,lodging,miles,rating, cost 
 Desc: Constructor, initializes all the member variables to arguments pased in 
******************************************************************************/
stop::stop(char* name,char* location,char* lodging,int miles,char* rating, char* cost)
{
   // set the information
   set_stop_name(name);
   set_location(location);
   set_lodging(lodging);
   set_miles(miles);
   set_rating(rating);
   set_gas_cost(cost);
}


/*******************************************************
 Name: ~stop()
 Desc: destructor, deallocates all the dynamic memory
*******************************************************/
stop::~stop()
{
  //deallocate all the memory
  delete [] stop_name;
  delete [] location_of_stop;
  delete [] lodging_reserved;
  delete [] rating;
  delete [] gas_cost;
}


/************************************************************
 Name: copy()
 Input: stop object
 Output: return 1 if copied 
 Desc: copies the stop information from the argument passed
************************************************************/
int stop::copy(const stop& data)
{
   //set the stop information
   set_stop_name(data.stop_name);
   set_location(data.location_of_stop);
   set_lodging(data.lodging_reserved);
   set_miles(data.miles_to_previous_stop);
   set_rating(data.rating);
   set_gas_cost(data.gas_cost);

   return 1;
}


		
/****************************************
 Name: set_stop_name()
 Input: stop name
 Desc: sets the name of the stop 
*****************************************/
void stop::set_stop_name(char* name)
{
   stop_name = new char[strlen(name)+1];
   strcpy(stop_name,name);
}



/**************************************
 Name: set_location()
 Input: location of stop 
 Desc: sets the location of the stop
***************************************/
void stop::set_location(char* location)
{
   location_of_stop = new char[strlen(location)+1];
   strcpy(location_of_stop,location);
}


/*************************************
 Name: set_lodging()
 Input: lodging information
 Desc: sets lodging information 
*************************************/
void stop::set_lodging(char* lodging)
{
   lodging_reserved = new char[strlen(lodging)+1];
   strcpy(lodging_reserved,lodging);
}



/***********************************
 Name: set_miles()
 Input: number of miles
 Desc: sets the number of miles
***********************************/
void stop::set_miles(int miles)
{
   miles_to_previous_stop = miles;
}


/**********************************
 Name: set_rating()
 Input: rating of the stop
 Desc: sets the rating of the stop
**********************************/
void stop::set_rating(char* rating)
{
  this->rating = new char[strlen(rating)+1];	
  strcpy(this->rating,rating);
}

		
/*************************************
 Name: set_gast_cost()
 Input: gas cost
 Desc: sets the cost of gas
*************************************/
void stop::set_gas_cost(char* cost)
{
   gas_cost = new char[strlen(cost)+1];
   strcpy(gas_cost,cost);	
}


/*************************************
 Name: add_feedback()
 Input: stop rating , gas cost
 Desc: sets the cost of gas and rating
*************************************/
void stop::add_feedback(char* rating, char* cost)
{
   set_rating(rating);
   set_gas_cost(cost);
}

/******************************************
 Name: display_all()
 Desc: displays all the stop information 
******************************************/
void stop::display_all(void)
{
     std::cout<<stop_name<<"\n";
     std::cout<<location_of_stop<<"\n";
     std::cout<<lodging_reserved<<"\n"; 
     std::cout<<miles_to_previous_stop<<"\n";
     std::cout<<rating<<"\n";
     std::cout<<gas_cost<<"\n";
}

