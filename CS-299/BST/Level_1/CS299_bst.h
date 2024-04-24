#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
/*
 * Eduardo Robles 
 */

struct node
{
    int data;
    node * left;
    node * right;
};

void build(node * & root);   //supplied
void display_all(node *  root);  //supplied
void destroy(node * & root); //supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
void insert(node*& root,int num);
int numGreaterThanRootPrivate(node* root,int num);
int numGreaterThanRoot(node* root);
int sumOfLeafs(node* root);
int treeHeight(node* root);
int inOrderSuccessor(node* root);
int inOrderSuccessorPrivate(node* root);
void  deallocate(node*& root);
int copy(node*& dest, node* root);
  

