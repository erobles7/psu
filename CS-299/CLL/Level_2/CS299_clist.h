//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
//Eduardo Robles
using namespace std;

struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & rear);  //supplied
void display_all(node * rear);  //supplied
void destroy(node * & rear); //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:
int removeAllExceptLastTwo(node*& rear);
int removeAllExceptLastTwoPrivate(node*& current,node*& rear);
int removal_entire(node*& rear);
int removal_entirePrivate(node*& rear,node* current);
int count_all(node* rear);
int count_allPrivate(node* rear, node* current);
bool insertAtEnd(int num,node*& rear);
bool insertAtEndPrivate(int num, node*& rear , node* current);
bool duplicate(node*& new_rear, node* source_rear);
bool duplicatePrivate(node*& new_rear_source,node*& new_rear,node* source_rear, node* current);
node* createNode(int num);

