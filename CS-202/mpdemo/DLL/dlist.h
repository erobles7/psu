//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class list
{
    public:
        //These functions are already written
        list();         //supplied
        ~list();        //supplied
        void build();   //supplied
        void display(); //supplied
        int display_reverse(); 
        int reverse();
        

     /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */
       int display_reverse(node* head);
       int reverse(node*& head, node*& tail);
       void reverse_list(node*& head, node*& tail);
       int reverse(node*& head,node*& tail, int& count);
     
     private:
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL
};
