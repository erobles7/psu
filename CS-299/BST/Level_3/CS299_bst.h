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
        bool hasDuplicate();
/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
        bool hasDuplicate(node* prev,node* root);
        int remove_largest();
        int display_smaller();
        int count_larger();
        int remove_leaf();

 	private:
        int remove_largest(node*& root);
        int display_smaller(node* root);
        int count_larger(node* root);
        int count_larger(node* root, int& smallest);
        int remove_leaf(node*& root);
        int remove_leaf(node*& root, int num);
 		node * root;
};
  

