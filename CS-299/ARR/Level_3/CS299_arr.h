//arr.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;  //some questions are char * data;
    node * next;
};

class table
{
    public:
    /* These functions are already written */
       table();		//supplied
       ~table();	//supplied
       void build();    //supplied
       void display();  //supplied
       node** getHead();


    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    int display_reverse();
    float average_all();
    int copy_arr(table& copy);
    private:
       int display_reverse(node** head,int index);
       int display_reversePrivate(node* head);
       float average_all(node** head, int index, int& count);
       int  average_all(node* head, int& count);
       int copy_arr(node** head,node**  copy,int index);
       int copy_arr(node*& new_copy, node* original);
       node ** head;     //dynamically allocated array
       int size;	 //the array size
};
