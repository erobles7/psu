//table.h
#include "Game.h"
#include <iostream>

/************************************************************
 * Author: Eduardo Robles
 * Date: 11/20/2016
 * Desc: Definition for tables class , Binary Search Tree
 * ********************************************************/

struct node
{
    Game data;
    node* left;
    node* right;
};

class table
{
    public:
            //constructor
            table();
            
            //insert
            int insert(char* key_word , Game& to_add);

            //remove (all that match keyword)
            int remove(char* key_word);

            //remove (all that match platform)
            int remove(char* key_word, char* platform);

	    //load from file 
	    int load_from_file(char* file_name);

            //count number of 5 star ratings 
            int count();

            //retrieve 
            int retrieve(char* key_word, Game& found);

            //display all games
            int display_all();

            //display all within given range
            int display_range(char first_letter,char second_letter);

            //destructor
            ~table();

    private:
        node* root; //root pointer
	
	//private functions
        void remove_all(node* root);
        int insert(node*& root,char* key_word,Game& to_add);
	int remove(node*& root,char* key_word, char* platform);
	int remove_all_occurences(node*& root,char* key_word);
	void display_all(node* root);
	void display_range(node* root,char first_letter, char second_letter);
	int count(node* root);
	int retrieve(node* root,char* key_word, Game& found);
	int compare(char* name,char first_letter,char second_letter);
	node*  find_inOrder(node* root);
	

};
