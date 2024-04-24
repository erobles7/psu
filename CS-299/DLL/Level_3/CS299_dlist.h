//doubly linked list
//Notice that there is a head and a tail pointer!!!
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
        

     /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */
     
        int display_last_two();
        int remove_last_two();
        float add_average();
        int remove_except_last();
        float average();
        int remove_every_other();
        int sum_largest_two();
        
     private:
        int display_last_twoPrivate(node* head);
        int remove_last_two(node*& head);
        float add_average(node*& head, int& count);
        int remove_except_lastPrivate(node*& head);
        int averagePrivate(node*& head, int& count);
        int remove_every_otherPrivate(node*& head);
        int sum_largest_two_private(node* head, int& secondLargest);
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL
};
