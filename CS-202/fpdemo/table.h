//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class table
{
    public:
    	//These functions are supplied already
    	table();			//supplied
    	~table();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied
/* ************** PLACE YOUR PUBLIC PROTOTYPE HERE ***************** */
        int count();
        int count_more_than_30();
        int count_root();
        int remove_all_children();
        int remove_largest_num();
        int remove_smallest();
            
 	private:
 		node * root;

/* ************** PLACE YOUR PRIVATE PROTOTYPE HERE ***************** */
        int count(node* root);
        int count_more_than_30(node* root);
        int count_root(node* root,int match);
        int remove_all_children(node*& root);
        int remove_largest_num(node*& root);
        int remove_smallest(node*& root);
};
  

