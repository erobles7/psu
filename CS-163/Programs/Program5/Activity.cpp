//Activity.cpp
#include "Activity.h"
#include <iostream>
using namespace std;

/*************************************************************
 Author: Eduardo Robles
 Date : 12/01/2016
 Desc: Implementation for the Activity class
 An activity holds information about a task to do over winterbreak
 **************************************************************/

/*******************************************************************
 Name: Activity()
 Desc: Default constructor, initializes all variables to NULL state
 *******************************************************************/
Activity::Activity()
{
    goal = NULL;
    time_to_complete = NULL;
}


/*******************************************************************
 Name: Activity()
 Desc: Constructor, initializes all variables to arguments passed
 *******************************************************************/
Activity::Activity(char* goal, char* time)
{
    //set the information
    set_goal(goal);
    set_time(time);
}


/******************************************************************
 Name: ~Activity()
 Desc: Deconstructor , deallocates all dynamic memory
 *******************************************************************/
Activity::~Activity()
{
    //deallocate all memory
    delete [] goal;
    delete [] time_to_complete;
}


/******************************************************************
 Name: copy()
 Input: Activity object
 Desc: Copies the Activity information from the Activity passed
 *******************************************************************/
int Activity::copy(const Activity&  data)
{
    if(!data.goal)
        return 0;
    
    //copy information over
    set_goal(data.goal);
    set_time(data.time_to_complete);
    
    return 1;
}


/******************************************************************
 Name: set_goal()
 Input: goal
 Desc: Sets the goal
 *******************************************************************/
void Activity::set_goal(char* goal)
{
    this->goal = new char[strlen(goal)+1];
    strcpy(this->goal,goal);
    
}


/******************************************************************
 Name: set_time()
 Input: time to comeplete
 Desc: Sets when the activity needs to be completed
 *******************************************************************/
void Activity::set_time(char* time_to_complete)
{
    this->time_to_complete = new char[strlen(time_to_complete)+1];
    strcpy(this->time_to_complete, time_to_complete);
}


/******************************************************************
 Name: get_goal()
 Desc: returns the goal of the activity
 ******************************************************************/
char* Activity::get_goal(void)
{
    return goal;
}


/******************************************************************
 Name: get_time()
 Desc: returns the time when the task needs to get completed
 *****************************************************************/
char* Activity::get_time(void)
{
    return time_to_complete;
}


/******************************************************************
 Name: compare()
 Input: key value to compare
 Desc: returns true if the key value is a match , false otherwise
 *****************************************************************/
bool Activity::compare(char* key_value)
{
    if(strcmp(goal, key_value) == 0)
        return true;
    else
        return false;
}


/******************************************************************
 Name: display_all()
 Desc: displays all the information for an activity
 *****************************************************************/
void Activity::display_all(void)
{
    //display the information
    cout<<goal<<endl;
    cout<<time_to_complete<<endl;
}
