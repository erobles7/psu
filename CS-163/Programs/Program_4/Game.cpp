//Game.cpp
#include "Game.h"
#include <iostream>

/*************************************************************
 Author: Eduardo Robles
 Date : 11/21/2016
 Desc: Implementation for the Game class
       A game holds all the information about a video game 
**************************************************************/


/*******************************************************************
 Name: Game()
 Desc: Default constructor, initializes all variables to NULL state
*******************************************************************/
Game::Game()
{
   name = NULL;
   desc = NULL;
   type = NULL;
   platform = NULL;
   stars = NULL;
   recommendations = NULL;
}


/*******************************************************************
 Name: Game()
 Desc: Constructor, initializes all variables to arugments passed in 
*******************************************************************/
Game::Game(char* name, char* desc, char* type, char* platform, char* stars, char* recommendations)
{
   //set the information 
   set_name(name);
   set_desc(desc);
   set_type(type); 
   set_platform(platform);
   set_stars(stars);
   set_recommendations(recommendations);	
}



/******************************************************************
 Name: ~Game()
 Desc: Deconstructor , deallocates all dynamic memory
*******************************************************************/
Game::~Game()
{
   //deallocate all the memory
   delete [] name;
   delete [] desc;
   delete [] type;
   delete [] platform;
   delete [] stars;
   delete [] recommendations;
}



/******************************************************************
 Name: copy()
 Input: Game object
 Desc: Copies the game information from the Game passed
*******************************************************************/
int Game::copy(const Game& data)
{
  if(!data.name)
	return 0;

   set_name(data.name);
   set_desc(data.desc);
   set_type(data.type); 
   set_platform(data.platform);
   set_stars(data.stars);
   set_recommendations(data.recommendations);	

   return 1;
}



/******************************************************************
 Name: set_name()
 Input: name
 Desc: Sets the name of the game
*******************************************************************/
void Game::set_name(char* name)
{
  this->name = new char[strlen(name)+1];
  strcpy(this->name,name);
}



/******************************************************************
 Name: set_desc()
 Input: description
 Desc: Sets the description of the game
*******************************************************************/
void Game::set_desc(char* desc)
{
  this->desc = new char[strlen(desc)+1];
  strcpy(this->desc,desc);
}



/******************************************************************
 Name: set_type()
 Input: type of video game
 Desc: Sets the type of the game
*******************************************************************/
void Game::set_type(char* type)
{
  this->type = new char[strlen(type)+1];
  strcpy(this->type,type);
}



/******************************************************************
 Name: set_platform()
 Input: game platform
 Desc: Sets the platform of the game
*******************************************************************/
void Game::set_platform(char* platform)
{
  this->platform = new char[strlen(platform)+1];
  strcpy(this->platform,platform);
}



/******************************************************************
 Name: set_stars()
 Input: star rating
 Desc: Sets the star rating of the game
*******************************************************************/
void Game::set_stars(char* stars)
{
  this->stars = new char[strlen(stars)+1];
  strcpy(this->stars,stars);
}



/******************************************************************
 Name: set_recommendations()
 Input: recommendations
 Desc: Sets the recommendations of the game
*******************************************************************/
void Game::set_recommendations(char* recommendations)
{
   this->recommendations = new char[strlen(recommendations)+1];
   strcpy(this->recommendations,recommendations);
}
	

/******************************************************************
 Name: get_name()
 Desc: returns the name of the game
*******************************************************************/
char* Game::get_name(void)
{
	return name;
}
	

	
/******************************************************************
 Name: get_platform()
 Desc: returns the platform  of the game
*******************************************************************/
char* Game::get_platform(void)
{
 	return platform;
}



/******************************************************************
 Name: get_recommendations()
 Desc: returns the recommendations of the game
*******************************************************************/
char* Game::get_recommendations()
{
	return recommendations;
}


/******************************************************************
 Name: get_recommendations()
 Desc: returns the recommendations of the game
*******************************************************************/
char* Game::get_stars()
{
	return stars;
}



/******************************************************************
 Name: display_all()
 Desc: Displays all the Game information
*******************************************************************/
void Game::display_all(void)
{
   std::cout<<name<<std::endl;
   std::cout<<desc<<std::endl;
   std::cout<<type<<std::endl;
   std::cout<<platform<<std::endl;
   std::cout<<stars<<std::endl;
   std::cout<<recommendations<<std::endl;
   std::cout<<std::endl;
}


/******************************************************************
 Name: reset_recommendations()
 Desc: deletes current recommendations 
*******************************************************************/
void Game::reset_recommendations()
{
	delete [] recommendations;
}

/******************************************************************
 Name: reset_game()
 Desc: deletes current game information 
*******************************************************************/
void Game::reset_game()
{
   delete [] name;
   delete [] desc;
   delete [] type;
   delete [] platform;
   delete [] stars;
   delete [] recommendations;
}
