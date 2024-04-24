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
        void add_before_even();
        int remove_same_as_rear();
        int remove_all(); 
        int display_all_except_last();
        int remove_last();
        int count_even();
        int remove_same_as_rear2();
        int largest_two();

	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:


	private:
        void add_before_even(node*& current);
        int remove_same_as_rear(node*& current,int match);
        int remove_all(node*& current);
        int display_all_except_last(node* rear);
        int remove_last(node*& rear, node* prev);
        int count_even(node* rear);
        int remove_same_as_rear2(node*& rear,int num);
        int largest_two(node* rear);
        void largest_two(node* rear,int& largest , int& second);
		node * rear;
};
