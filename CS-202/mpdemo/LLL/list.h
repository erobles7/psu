//list.h
#include <iostream>
#include <cstring>
#include <cctype>
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
     list();			//supplied
     ~list();			//supplied
     void build();     		//supplied
     void display();  		//supplied

    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    int count();
    int display_unique();
    int display_last_not_first();
    int move_first_to_end();
    int duplicate_first();
    int remove_duplicate();
    int remove_all_but_last();
    int copy_into_array(int* array);
    

   private:		//notice there is both a head and a tail!
      int count(node* head);
      int display_unique(node* head);
      bool is_unique(node* head,int num);
      int display_last_not_first(node* head);
      int move_first_to_end(node* head);
      int duplicate_first(node*& head,node* previous);
      int remove_duplicate(node*& head);
      bool is_duplicate(node* head,int data);
      int remove_all_but_last(node*& head);
      int copy_into_array(int* array,node* head,int& count);
      node * head;
      node * tail;
};
