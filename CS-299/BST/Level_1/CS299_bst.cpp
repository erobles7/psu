#include "CS299_bst.h"
/*
 * Eduardo Robles 
 */

/********************************
 * Insert node 
 * ***************************/
void insert(node*& root,int num)
{
    if(!root)
    {
        root = new node;
        root->data = num;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    else if(num < root->data)
        insert(root->left,num);

    else
        insert(root->right,num);
}

/**************************************
 * Number of nodes greater than root
 * ***********************************/
int numGreaterThanRoot(node* root)
{
    int count;
    
    if(!root)
        return 0;

    count = numGreaterThanRootPrivate(root->right,root->data);

    return count;
}

int numGreaterThanRootPrivate(node* root, int num)
{

    if(!root)
        return 0;
    if(root->data == num)
        return numGreaterThanRootPrivate(root->left,num)+numGreaterThanRootPrivate(root->right,num);

    return  numGreaterThanRootPrivate(root->left,num)+numGreaterThanRootPrivate(root->right,num)+1;
  
}
/***************************
 * Sum of Leafs
**************************/
int sumOfLeafs(node* root)
{
    if(!root)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return root->data;

   return sumOfLeafs(root->left)+sumOfLeafs(root->right);  
}

/**********************
 * Find Height 
 * *********************/
int treeHeight(node* root)
{
    if(!root)
        return 0;

    return max(treeHeight(root->left),treeHeight(root->right))+1;
}

/*********************************
 * InorderSuccessor
 * ******************************/
int inOrderSuccessor(node* root)
{
    if(!root || !root->right)
        return 0;
    
    return inOrderSuccessorPrivate(root->right);
}
int inOrderSuccessorPrivate(node* root)
{
    if(!root->left)
        return root->data;
    else
        return inOrderSuccessorPrivate(root->left);
}

/*******************************
 * deallocate Memory
 * ***************************/
void deallocate(node*& root)
{
    if(!root)
        return;

    deallocate(root->left);
    deallocate(root->right);

    delete root;
    root = NULL;
}

/*******************************
 * Copy
 * ****************************/
int copy(node*& dest, node* root)
{
    if(!root)
    {
        dest = NULL;
        return 0;
    }

    dest = new node;
    dest->data = root->data;

    return 1 + copy(dest->left,root->left) + copy(dest->right,root->right);
}
