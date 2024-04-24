//Game.h
#include <cstring>

/*************************************************************
 Author: Eduardo Robles
 Date : 11/10/2016
 Desc: Definition for the Game class
       A game holds all the information about a video game 
*************************************************************/

class Game
{
	public:
		//constructor 
		Game();
		Game(char* name, char* desc, char* type, char* platform, char* stars, char* recommendations);
	
		//destructor
		~Game();

		//copy function
		int copy(const Game& data);

		//set functions
		void set_name(char* name);
		void set_desc(char* desc);
		void set_type(char* type);
		void set_platform(char* platform);
		void set_stars(char* stars);
		void set_recommendations(char* recommendations);	
                
    		//get functions
		char* get_name(void);	
		char* get_platform(void);
	        char* get_recommendations();	

		//reset recommendations
		void reset_recommendations();

		//print function
		void display_all(void);
		

	private:
		//private member variables
		char* name;
		char* desc;
		char* type;
		char* platform;
		char* stars;
		char* recommendations;

};
