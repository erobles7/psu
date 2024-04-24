#include "CS299_bst.h"

/*****************************
 * Display the largest
 * **************************/
int displayLargest(node* root)
{
    if(!root)
        return 0;
    if(!root->right)
        return root->data;

    return displayLargestPrivate(root->right);
}
int displayLargestPrivate(node* root)
{
    if(!root->right)
        return root->data;

    return displayLargest(root->right);
}

/*****************************************
* Number of nodes with same data as root
* *****************************************/
int sameAsRoot(node* root)
{
    if(!root || !root->right)
        return 0;

    return sameAsRootPrivate(root->right,root->data);
}
int sameAsRootPrivate(node* root,int num)
{
    if(!root)
        return 0;
    
    if(root->data == num)
        return 1 + sameAsRootPrivate(root->right,num);

    if(num < root->data)
        return sameAsRootPrivate(root->left,num);

    return sameAsRootPrivate(root->right,num);
}
/****************************************
 * Remove inOrder successor
 * *************************************/
int removeInorderSuccessor(node*& root)
{
    if(!root || !root->right)
        return 0;

    return removeInorderSuccessorPrivate(root->right); 
}
int removeInorderSuccessorPrivate(node*& root)
{
    if(!root->left)
    {
        node* temp = root;
        int num = temp->data;
        root = temp->right;
        delete temp;
        return num;
    }

    return removeInorderSuccessorPrivate(root->left);
}

/******************************************
* Complete copy of binary tree 
* ****************************************/
int copy(node*& new_copy,node* original)
{
    if(!original)
    {
        new_copy = NULL;
        return 0;
    }

    new_copy = new node;
    new_copy->data = original->data;

    return 1+ copy(new_copy->left,original->left) + copy(new_copy->right,original->right);
}

/*****************************************
 * Copy Tree without root
 *****************************************/
int copyWithoutRoot(node*& new_copy,node* original)
{
    if(!original)
        return 0;

   int count  =  copy(new_copy,original)-1;
    
    int new_root = removeInorderSuccessor(new_copy);
    new_copy->data = new_root;

    return count;
}
