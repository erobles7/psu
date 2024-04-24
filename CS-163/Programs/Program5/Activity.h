//Activity.h

/*************************************************************
 Author: Eduardo Robles
 Date : 12/01/2016
 Desc: Definition for the Activity Class
 An activity holds information about a task to do over winterbreak
 *************************************************************/

#include <cstring>

class Activity
{
    public:
        //constructor
        Activity();
        Activity(char* goal,char* time_to_complete);
    
        //destructor
        ~Activity();
    
        //copy function
        int copy(const Activity&  data);
    
        //set functions
        void set_goal(char* goal);
        void set_time(char* time_to_complete);
    
        //get functions
        char* get_goal(void);
        char* get_time(void);
    
        //compare
        bool compare(char* key_value);
    
        //print function
        void display_all(void);

    private:
        //private member variables
        char* goal;
        char* time_to_complete;
    
};
