#include "table.h"
using namespace std;

//These are the functions that you will be writing for Lab #10


//STEP 1
int table::count()	//SAMPLE wrapper function
{
    if(!root)
        return 0;

	return count(root);
}

int table::count(node * root)
{
    if(!root)
        return 0;

    return 1 + count(root->left)+ count(root->right);
}

//STEP 2
int table::count_leaf()
{
    if(!root)
        return 0;

    return count_leaf(root);
}
int table::count_leaf(node * root)
{
    int count = 0;

    if(!root)
        return 0;

    if(!root->left && !root->right)
        ++count;

    return count + count_leaf(root->left)+count_leaf(root->right);
}


//STEP 3
int table::remove_largest()
{
    if(!root)
        return 0;

    if(!root->right && root->left)
    {
        node* temp = root;
        root = root->left;
        int x = temp->data;
        delete temp;
        return x;
    }

    return remove_largest(root->right);
}

int table::remove_largest(node * & root)
{
    if(!root->right)
    {
        int x = root->data;
        node* temp = root;
        root = root->left;
        delete temp;
        return x;
    }
    return remove_largest(root->right);
}


//STEP 4
int table::sum()
{
    if(!root)
        return 0;

    return sum(root);
}

int table::sum(node * root)
{
    int ret = 0;

    if(!root)
        return 0;

    if((root->data % 3 == 0) || (root->data % 5 == 0))
        ++ret;

    return ret + sum(root->left) + sum(root->right);
}

//STEP 5
int table::copy(table & to_copy)
{
    if(!to_copy.root)
        return 0;

    return copy(root,to_copy.root);
}

int table::copy(node * & destination, node * source)
{
    if(!source)
    {
        destination = NULL;
        return 1;
    }

    destination 


}

//STEP 6a Challenge
int table::create_full(){}
int table::create_full(node * & new_tree){}


//STEP 6b
bool table::is_full(){}
bool table::is_full(node * root){}


//STEP 6c
int table::display_largest(){}
int table::display_largest(node * root){}


//STEP 6d
int table::display_largest2(){}
int table::display_largest2(node * root){}



