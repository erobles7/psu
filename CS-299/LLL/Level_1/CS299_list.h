//list.h
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;


//The data structure is a linear linked list of integers
struct node
{
    int data;
    node * next;
};

//These functions are already written and used by main
void build(node * & head);      //supplied
void display_all(node * head);  //supplied
void destroy(node * &head);     //supplied


/* *****************YOUR TURN! ******************************** */
/* PLACE YOUR PROTOTYPE HERE */
int display_all2(node* head);
int sum_greater(node*& head);
bool find_last_two(node* head);
float append(node*& head, int to_add);
int remove_last(node*& head);
int remove_special(node*& head);
int copy_last(node*& head);
node* buildNode(int data);




