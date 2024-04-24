//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class list
{
   public:
   		//These functions are already written
   		list();			//supplied
   		~list();		//supplied
   		void build();	//supplied
   		void display();	//supplied

	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:
    int add_before(); 
    bool remove_same();
    void switchFirstAndLast();
    void insert(int num);
    float copy_two(list& new_list);

	private:
        int add_before(node*& rear);
        bool remove_same(node*& current);
        void switchFirstAndLastPrivate(node*& current);
        float copy_two(list& new_list, node* current);
		node * rear;
};
