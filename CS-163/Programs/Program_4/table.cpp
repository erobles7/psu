//table.cpp 
#include "table.h"
#include <iostream>
#include <fstream>
using namespace std;

/**********************************************
 * Author: Eduardo Robles
 * Date: 11/20/2016
 * Desc: Implementation for the table class 
 * *******************************************/

/*****************************************************************
 * Name: table()
 * Desc: Default constructor , initializes everything to NULL
 * ***************************************************************/
table::table()
{
    root = NULL;
}

/*****************************************************************
 * Name: ~table()
 * Desc: destructor, deallocates all dynamic memory
 * ***************************************************************/
table::~table()
{
    remove_all(root);
}


/***********************************************************
 * Name: remove_all()
 * Input: root pointer
 * Desc: deletes every node in the tree
 * ********************************************************/
void table::remove_all(node* root)
{
    if(!root)
        return;

    remove_all(root->left);
    remove_all(root->right);

    delete root;
    root = NULL;
}


/***********************************************************
 * Name: insert()
 * Input: game keyword, game object
 * Desc: inserts new video game into tree
 * ********************************************************/
int table::insert(char* key_word , Game& to_add)
{
    return insert(root,key_word,to_add);
}

/***********************************************************
 * Name: insert()
 * Input: root pointer,game keyword, game object
 * Desc: inserts new video game into tree
 * ********************************************************/
int table::insert(node*& root,char* key_word,Game& to_add)
{
    if(!root)
    {
        root = new node;
        root->data.copy(to_add);
	root->left = NULL;
	root->right = NULL;
        return 1;
    }

    if(strcmp(key_word,root->data.get_name()) < 0)
        insert(root->left,key_word,to_add);

    else if(strcmp(key_word,root->data.get_name()) >= 0)
            insert(root->right,key_word,to_add);

    return 1;
}


/***********************************************************
 * Name: remove()
 * Input: keyword
 * Desc: removes all video games with matchings title
 * ********************************************************/
int table::remove(char* key_word)
{
	return remove_all_occurences(root,key_word);
}


/***********************************************************
 * Name: remove()
 * Input: root pointer,keyword
 * Desc: removes all video games with matchings title
 * ********************************************************/
int table::remove_all_occurences(node*& root,char* key_word)
{
   //empty tree	
   if(!root)
       return 1;

   //keyword is less 
   if(strcmp(key_word,root->data.get_name()) < 0)
	remove_all_occurences(root->left,key_word);

   //keyword is greater
   if(strcmp(key_word,root->data.get_name()) > 0)
	remove_all_occurences(root->right,key_word);

   //found a match
   if(strcmp(key_word,root->data.get_name()) == 0)
   {
	//case 1: No children
	if(!root->left && !root->right)
	{
		delete root;
		root = NULL;
	}

	//case 2: One child on the left
	else if(!root->right)
	{
	   node* temp = root; 
	   root = root->left;
	   delete temp;
	}

	//case 2: One child on the right
	else if(!root->left)
	{
	   node* temp = root;
	   root = root->right;
	   delete temp;
	}

	//case 3: 2 children
	else
	{
		node* temp  = find_inOrder(root->right);
		root->data.reset_game();
		root->data.copy(temp->data);
		remove_all_occurences(root->right,temp->data.get_name());
	}
   }
	return 1;
}

/***********************************************************
 * Name: remove()
 * Input: keyword, platform
 * Desc: removes video game from tree
 * ********************************************************/
int table::remove(char* key_word, char* platform)
{
   return remove(root,key_word,platform);
}


/***********************************************************
 * Name: remove()
 * Input: root,keyword, platform
 * Desc: removes video game from tree 
 * ********************************************************/
int table::remove(node*& root,char* key_word, char* platform)
{
   //empty tree	
   if(!root)
       return 0;

   //keyword is less 
   if(strcmp(key_word,root->data.get_name()) < 0)
	remove(root->left,key_word,platform);

   //keyword is greater
   if(strcmp(key_word,root->data.get_name()) > 0)
	remove(root->right,key_word,platform);

   //found a match
   if(strcmp(key_word,root->data.get_name()) == 0 && strcmp(platform,root->data.get_platform()) == 0)
   {
	//case 1: No children
	if(!root->left && !root->right)
	{
		delete root;
		root = NULL;
	}

	//case 2: One child on the left
	else if(!root->right)
	{
	   node* temp = root; 
	   root = root->left;
	   delete temp;
	}

	//case 2: One child on the right
	else if(!root->left)
	{
	   node* temp = root;
	   root = root->right;
	   delete temp;
	}

	//case 3: 2 children
	else
	{
		node* temp  = find_inOrder(root->right);
		root->data.reset_game();
		root->data.copy(temp->data);
		remove(root->right,temp->data.get_name(),temp->data.get_platform());
	}
   }
   return 1;
}



/***********************************************************
 * Name: find_inOrder()
 * Input: root pointer
 * Desc: finds the in order successor of root passed in 
 * ********************************************************/
node* table::find_inOrder(node* root)
{
	node* current = root;

	//go all the way left as possible
	while(current->left != NULL)
	{
		current = current->left;
	}

	//return the data
	return current;
}


/***********************************************************
 * Name: load_from_file()
 * Input: file name
 * Desc: loads video games from a file
 * ********************************************************/
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

/***********************************************************
 * Name:  count()
 * Desc: counts the number of 5 star ratings 
 * ********************************************************/
int table::count()
{
   if(!root)
	return 0;

   return count(root);
}



/***********************************************************
 * Name:  count()a
 * Input: root pointer 
 * Desc: counts the number of 5 star ratings 
 * ********************************************************/
int table::count(node* root)
{
  int sum = 0;

    if(!root)
	return 0;

   if(strcmp(root->data.get_stars(),"5") == 0)
	sum++;

   return count(root->left) + count(root->right) + sum;
}



/***********************************************************
 * Name:  retrieve()
 * Input: keyword, game to copy 
 * Desc: retrieves matching game and copies information
 * ********************************************************/
int table::retrieve(char* key_word, Game& found)
{
   return retrieve(root,key_word,found);
}


/***********************************************************
 * Name:  retrieve()
 * Input: root pointer,keyword, game to copy 
 * Desc: retrieves the matching game and copies information
 * ********************************************************/
int table::retrieve(node* root,char* key_word, Game& found)
{
	if(!root)
	   return 0;

	if(strcmp(root->data.get_name(),key_word) == 0)
	{
	   found.copy(root->data);
	   return 1;
	}

	if(strcmp(key_word,root->data.get_name()) < 0 )
	   retrieve(root->left,key_word,found);

	return retrieve(root->right,key_word,found);
}


/********************************************************************************
 * Name:  compare()
 * Input: name of video game , first letter of range , second letter of range 
 * Desc: takes a string , and compares if its between the the two letters provided
 *******************************************************************************/
int table::compare(char* name,char first_letter,char second_letter)
{
	int x = (int)name[0];
	
	if(x >= (int)first_letter && x <= (int)second_letter)
		return 1;
	else
	  {
		return 0;
	  }
}

/***********************************************************
 * Name:  display_all()
 * Desc: displays all the games for every platform
 *********************************************************/
int table::display_all()
{
   if(!root)
      return 0;
	
     //call display function
     display_all(root);

    return 1;
}


/***********************************************************
 * Name:  display_all()
 * Input: root pointer
 * Desc: displays all the games for every platform
 * ********************************************************/
void table::display_all(node* root)
{
    if(!root)
	return;

    //traverse left 
    display_all(root->left); 

    //display data	
    root->data.display_all();
   
    //traverse right
    display_all(root->right);
}

/***********************************************************
 * Name:  display_range()
 * Input: first letter , second letter
 * Desc: displays all video games within given range
 * ********************************************************/
int table::display_range(char first_letter,char second_letter)
{
	//check for empty tree 
	if(!root)
	    return 0;

	//display all in range 
	display_range(root,first_letter,second_letter);

	//return successful
	return 1;
}


/***********************************************************
 * Name:  display_range()
 * Input: keyword , first letter , second letter
 * Desc: displays all video games within given range
 * ********************************************************/
void table::display_range(node* root,char first_letter, char second_letter)
{
	if(!root)
	    return;
	
	//traverse left
	display_range(root->left,first_letter,second_letter);
	
	//check and display data if in range
	if(compare(root->data.get_name(),first_letter , second_letter) == 1)
	{
		root->data.display_all();
	}

	//traverse left
	display_range(root->right,first_letter,second_letter);	
}
