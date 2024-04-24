//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node * previous;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display_all(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
/* place your prototype here */
int sum_last_two(node* head);
int display_reverse(node* head);
int addUnique(node*& head,int num);
int addUniquePrivate(node*& head, int num);
bool duplicate(node*& new_copy,node* original);
bool duplicatePrivate(node*& dest, node* source, node*& prev);

