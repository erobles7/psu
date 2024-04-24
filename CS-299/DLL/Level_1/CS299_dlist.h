//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
/*
 * Eduardo Robles
 * 09/01/2016
 */
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
int remove_larger(node*& head);
int remove_every_other(node*& head);
int duplicate_2(node*& head);