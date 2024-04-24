//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;;
};

void build(node * & root);  //supplied
void display(node *  root); //supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
int insert(node*& root, int num);

//count stuff 
int count_leaves(node* root);
int count_even(node* root);
int count_single_child(node* root);
int count_twos(node* root);

//height
int height(node* root);

//remove
void remove_all(node*& root);
void remove_smallest_if_not_two(node*& root);

//copies
void copy(node*& dest_root, node* source);
void copy_even(node*& dest_root,node* source);

 
//displays
int display_leafs(node* root);
int display_smallest(node* root);
int display_largest(node* root);
int display_in_order(node* root);
int display_in_orderPrivate(node* root);



