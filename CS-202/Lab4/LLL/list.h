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
     int num_times(int match);
     int display_first_last();
     bool remove_except();
     int copy_special(list& new_list);
     int remove_all_twos();
    
    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    

   private:		//notice there is both a head and a tail!
      int num_times(node* head, int match);
      int display_first_last(node* head);
      bool remove_except(node*& head);
      int copy_special(node*& new_copy,node* original, node* origi
      int remove_all_twos(node*& head);

      node * head;
      node * tail;
};

