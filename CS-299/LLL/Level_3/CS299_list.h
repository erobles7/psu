//list.h
#include <iostream>
#include <cstring>
#include <cctype>
//Eduardo Robles
using namespace std;
                                                             

struct node
{
    int data;   //some questions are a char * data;
    node * next;
};

class list
{
   public:
   //These functions are already written for you
     list();		    	//supplied
     ~list();		    	//supplied
     void build();     		//supplied
     void display();  		//supplied

    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    bool remove_last_two();
    float average(); 
    int add_99();
    node* createNode(int num);
    int copy_even(list& new_list);
    void insert(int data);
    int return_largest();
    int return_largest(node* head);

   private:		                                //notice there is both a head and a tail!    
      int return_largestPrivate(node* head,int& largest);
      bool remove_last_twoPrivate(node*& head);
      int average(node* head, int& total);
      int add_99Private(node*& head);
      int copy_evenPrivate(list& new_list, node* oldHead);
      node * head;
      node * tail;
};
