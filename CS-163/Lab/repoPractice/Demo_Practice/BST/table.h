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
 int longestPath(node* root);
 int height(node* root);
 int avgPath(node* root);
 int avgPath(node* root,int& count);
 int avgData(node* root);
 int avgData(node* root, int& sum);
 int displayAll(node* root);
 int displayReverse(node* root);

