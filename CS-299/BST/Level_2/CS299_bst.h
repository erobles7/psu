#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

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
int displayLargest(node* root);
int displayLargestPrivate(node* root);
int sameAsRoot(node* root);
int sameAsRootPrivate(node* root,int num);
int removeInorderSuccessor(node*& root);
int removeInorderSuccessorPrivate(node*& root);
int copy(node*& new_copy,node* original);
int copyWithoutRoot(node*& new_copy,node* original);
