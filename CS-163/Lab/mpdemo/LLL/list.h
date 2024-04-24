//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:
int count(node* head);
int display_last(node* head);
void display_last2(node* head);

//display only last two
int display_last_two(node* head);
int display_last_two2(node* prev,node* head);

//display last item if its not a 2
int display_not_two(node* head);
int display_not_two2(node* head);


//add at node to the beginning of a non empty list 
int insert_front(node*& head, int num);
int insert_front2(node*& head);

//insert at the end 
int insert_end(node*& head, int num);
int insert_end2(node*& head, int num);

//move front node to the end of the list
int move_front_to_end(node*& head);
int move_front_to_end2(node*& head,node*&  current);
