//table.h
#include "Game.h"

/*************************************************************
 Author: Eduardo Robles
 Date : 11/10/2016
 Desc: Definition for the table class
       Hash table , array of linked list
**************************************************************/


struct node
{
   Game myGame;
   node* next;
};

class table
{
   public:
	  //constructor
	  table(int size=5);

	  //destructor
	  ~table();

	  //insert function
          int insert(char* key_value, const Game& to_add);
	
	  //hash function
	  int hash_function(char* key_value) const;

	  //remove function
	  int remove(char* key_value,char* platform);

	  //retrieve function
	  int retrieve(char* key_value, Game& found);

	  //load game information from a file
	  int load_from_file(char* file_name);

	  //add recommendations to a game
	  int add_recommendations(char* key_value,char* platform, char* to_add);

	  //display all	
	  int display_all(void);

	  //display only a specific platform
          int display_all_platform(char* platform);
	
	
	

   private:
	   node** hash_table; //a dynamically allocated array of head pointers
	   int hash_table_size;

	  //recursive functions
 	  void display_all(node* head);
	  void delete_chain(node*& head);
	  int remove_from_chain(node*& head,char* key_value,char* platform);
          int retrieve_from_chain(node* head,char* key_value, Game& found);
	  int add_recommendations(node*& head,char* key_value,char* platform, char* to_add);
	  void display_all_platform(char* platform,node* head);
};
