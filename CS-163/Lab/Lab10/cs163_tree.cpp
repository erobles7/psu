#include "cs163_tree.h"
using namespace std;



//These are the functions that you will be writing for the BST


void table::display_largest()
{ 
    if(!root)
        return;

    display_largest(root);
}
void table::display_largest(node * root)
{
    if(!root->right)
    {
        std::cout<<root->data<<std::endl;
        return;
    }

    display_largest(root->right);
}

int table::count_root()
{
    if(!root)
        return 0;

    return count_root(root->right,root->data);
}
int table::count_root(node * root, int match)
{
    int ret = 0;

    if(!root)
        return 0;

    if(root->data == match)
    {
        ++ret;
    }

    return ret + count_root(root->left,match) + count_root(root->right,match);
}

void table::copy(table & source)
{
    if(!source.root)
        return;

    remove(source.root,source.root->data);

    copy(root,source.root);
}
void table::copy(node * & destination, node * source)
{
    if(!source)
    {
        destination = NULL;
        return;
    }

    destination = new node;
    destination->data = source->data;

    copy(destination->left,source->left);
    copy(destination->right,source->right);
}

int table::remove(node*& root,int match)
{
    //empty treee 
    if(!root)
        return 0;

    //less
    if(match < root->data)
        remove(root->left,match);

    //greater than 
    if(match > root->data)
        remove(root->right,match);
    
    if(root->data == match)
    {

        //leaf
        if(!root->left && !root->right)
        {
            delete root;
            root = NULL;
        }

        //1 child , no right
        else if(!root->right)
        {
            node* temp = root;
            root = root->left;
            delete temp;
        }

        //1 child no left
        else if(!root->left)
        {
            node* temp = root;
            root = root->left;
            delete temp;
        }

        else
        {
            node* temp = in_order(root->right);
            root->data = temp->data;
            remove(root->right,temp->data);
        }
    }

    return 1;
}

node* table::in_order(node* root)
{
    node* current = root;

    while(!current->left)
    {
        current = current->left;
    }

    return current;
}

//Now for the 2-3-4 Tree		//STEP 4
int table::count_3_data()   //sample wrapper function that return the count
{
      return count_3_data(root234);
}	     
     
int table::count_3_data(node234 * root){}	                    


//STEP 5
int table::height(){}                    //Return the height
int table::height(node234 * root){}                    

//STEP 6
//Copy from the argument into the data members...
int table::copy_234(table & copy_from) {}
int table::copy(node234 * & destination, node234 * source){}      
