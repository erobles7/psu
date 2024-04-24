//table.cpp
#include "table.h"
#include <iostream>
#include <fstream>
using namespace std;

/*************************************************************
 Author: Eduardo Robles
 Date : 11/10/2016
 Desc: Implementation for the table class
**************************************************************/


/*************************************************************
 Name: table()
 Input: size of the array to be created
 Desc: default constructor, initializes everything to NULL
**************************************************************/
table::table(int size)
{
  //set the size of the array
  hash_table_size = size;

  //create teh array 
  hash_table = new node* [hash_table_size];

  //initialize elements to NULL
  for(int i = 0; i<hash_table_size; ++i)
    {
	(*(hash_table+i)) = NULL;
    }
}


/*************************************************************
 Name: ~table()
 Desc: deconstructor , deallocates all dynamic memory 
**************************************************************/
table::~table()
{
  for(int  i = 0; i<hash_table_size; ++i)
  {
	delete_chain((*(hash_table+i)));
  }

  delete [] hash_table;
}



/*************************************************************
 Name: ~table()
 Input: head pointer to chain
 Desc: deletes the chain
**************************************************************/
void table::delete_chain(node*& head)
{
   if(!head)
	return;

  delete_chain(head->next);

  delete head;
  head = NULL;
}



/*************************************************************
 Name: table()
 Input: size of the array to be created
 Desc: default constructor, initializes everything to NULL
**************************************************************/
int table::hash_function(char* key_value) const
{
   int sum = 0;

   if(!key_value)
	return -1;

  int length = strlen(key_value);

   for(int i = 0; i<length; ++i)
          sum+=(*(key_value+i));
  
  return sum % hash_table_size;	
}



/*************************************************************
 Name:  insert()
 Input: key value , Game being added
 Desc: inserts game into hash table based on key value
**************************************************************/
int table::insert(char* key_value, const Game& to_add)
{
   //get index 
   int index = hash_function(key_value);
   
    //invalid index
    if(index == -1)
   	return 0;

   node* temp = (*(hash_table+index));
   (*(hash_table+index)) = new node;
   (*(hash_table+index))->next = temp;
   (*(hash_table+index))->myGame.copy(to_add);

   return 1;
}


/*************************************************************
 Name:  remove()
 Input: Game to be removed 
 Desc: removes game from the hash table
**************************************************************/
int table::remove(char* key_value,char* platform)
{
   int index = hash_function(key_value);

   if(index == -1)
	return 0;

   return remove_from_chain((*(hash_table+index)),key_value,platform);      

}


/*************************************************************
 Name:  remove_from_chain()
 Input: head pointer 
 Desc: removes games from chain
**************************************************************/
int table::remove_from_chain(node*& head,char* key_value,char* platform)
{
   if(!head)
       return 0;
  
  if(strcmp(head->myGame.get_name(),key_value) == 0 && strcmp(head->myGame.get_platform(),platform) == 0)
   {
	node* temp = head;
	head = head->next;
        delete temp;
	return 1;
   }

   return remove_from_chain(head->next,key_value,platform);   
}



/*************************************************************
 Name:  retrieve()
 Input: key_value and video game
 Desc: retrieves video game information and copies it
**************************************************************/
int table::retrieve(char* key_value, Game& found)
{
   int index = hash_function(key_value);
   
   if(index == -1)
	return 0;

   return retrieve_from_chain((*(hash_table+index)),key_value,found);
}


          
/*************************************************************
 Name:  retrieve_from_chain()
 Input: head pointer,key_value,video game
 Desc: retrieves video game information and copies it
**************************************************************/
int table::retrieve_from_chain(node* head,char* key_value, Game& found)
{
   if(!head)
	return 0;

  if(strcmp(head->myGame.get_name(),key_value) == 0)
  {
	found.copy(head->myGame);
	return 1;
  }

  return retrieve_from_chain(head->next,key_value,found);
}



/*************************************************************
 Name:  display_all()
 Desc:  displays all the items in the hash table
**************************************************************/
int table::display_all(void)
{
   if(!hash_table)
	return 0;

  for(int i = 0; i<hash_table_size; ++i)
   {
 	if((*(hash_table+i)) == NULL)
	{

	}
	else
	display_all((*(hash_table+i)));
   }
   return 1;
}




/*************************************************************
 Name:  display_all()
 Input: head pointer
 Desc: displays all the items in the chain
**************************************************************/
void table::display_all(node* head)
{
	if(!head)
	   return;

	head->myGame.display_all();
    
        display_all(head->next);
}



/*************************************************************
 Name:  display_all()
 Input: head pointer
 Desc: displays all the items in the chain
**************************************************************/
int table::display_all_platform(char* platform)
{
   if(!hash_table)
	return 0;

   for(int i = 0; i < hash_table_size; ++i)
   {
	if( (*(hash_table+i)) == NULL)
        {}
 	
        else 
	   display_all_platform(platform,(*(hash_table+i)));	
   }

    return 1;	
}



/*************************************************************
 Name:  load_from_file()
 Input: file_name
 Desc:  loads game information
**************************************************************/
int table::load_from_file(char* file_name)
{ 
 
  //store information 
  char name[100];
  char desc[100];
  char type[100];
  char platform[100];
  char stars[100];
  char recommendations[100];

    if(!file_name)
	return 0;

    ifstream file_in;

   //connect to variable to file
   file_in.open(file_name);

   //prime the pump
   file_in.get(name,100,':');
   file_in.ignore(100,':');  

   if(file_in)
   {
	//was the read in successful
	while(file_in && !file_in.eof())
 	{
		//get description	
		file_in.get(desc,100,':');
		file_in.ignore(100,':');
		
		//get the game type 
		file_in.get(type,100,':');
		file_in.ignore(100,':');

		//get the platform		
		file_in.get(platform,100,':');
		file_in.ignore(100,':');
	
		//get the stars
		file_in.get(stars,100,':');
		file_in.ignore(100,':');

		//get the recommendations
		file_in.get(recommendations,100,':');
		file_in.ignore(100,'\n');

		//create a game object and insert it into the hash table
		Game myGame(name,desc,type,platform,stars,recommendations);
		insert(name,myGame);

		//prime the pump 
   		file_in.get(name,100,':');
   		file_in.ignore(100,':'); 
	}
	//close the file 
	file_in.close();
   } 
  return 1;
}



/*************************************************************
 Name:  add_recommendations()
 Input: key value, platform , new recommendation
 Desc: adds new recommendation to a game
**************************************************************/
int table::add_recommendations(char* key_value,char* platform, char* to_add)
{
   int index = hash_function(key_value);

   if(index == -1)
	return 0;

   return add_recommendations((*(hash_table+index)),key_value,platform,to_add);
}



/*************************************************************
 Name:  add_recommendations()
 Input: head pointer,key value, platform , new recommendation
 Desc: adds new recommendation to a game
**************************************************************/
int table::add_recommendations(node*& head,char* key_value,char* platform, char* to_add)
{
   if(!head)
	return 0;

   if(strcmp(head->myGame.get_name(),key_value) == 0 && strcmp(head->myGame.get_platform(),platform) == 0)
   {	
	char new_rec[strlen(head->myGame.get_recommendations()) + strlen(to_add) + 1];
	strcpy(new_rec,head->myGame.get_recommendations());
	char x [] = ",";
	strcat(new_rec,x);
	strcat(new_rec,to_add);
	head->myGame.reset_recommendations();
	head->myGame.set_recommendations(new_rec);
	return 1;
   }

   return add_recommendations(head->next,key_value,platform,to_add);
}

/*************************************************************
 Name:  display_all_platform()
 Input: platform ,head pointer
 Desc: displays all the items to a specific platform
**************************************************************/
void table::display_all_platform(char* platform,node* head)
{
   if(!head)
	return;

  if(strcmp(head->myGame.get_platform(),platform) == 0)
	head->myGame.display_all();

  display_all_platform(platform,head->next);

}
