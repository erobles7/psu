#include "table.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function to display the tree in order. Return the number of nodes.
//The difficulty of this question is: 0
int displayAll(node* root)
{
    if(!root)
        return 0;
    
    displayAll(root->left);
    
    std::cout<<root->data<<" ";

    displayAll(root->right);

    return 1;
}

//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function to display the tree in reverse order. Return the number of nodes.
//The difficulty of this question is: 0

int displayReverse(node* root)
{
    if(!root)
        return 0;

    displayReverse(root->right);

    cout<<root->data<<" ";

    displayReverse(root->left);

    return 1;

}

//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function to display every node that is divisible by the argument passed in. Return number of nodes displayed.
//The difficulty of this question is: 0
/*
int displayDivisible(node* root, int toDisplay)
{


}
*/

//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function to add the data passed in to the function to the tree.
//The difficulty of this question is: 1
/*
int insertData(node*& root, int toAdd)
{

}
*/

//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function to remove every node that is divisible by 3 and 5 from the Tree. Return the number of nodes removed
//The difficulty of this question is: 3
/*
int removeDivisible(node*& root)
{

}
*/

//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function to display the data in the longest path of the tree.
//The difficulty of this question is: 3
int longestPath(node* root)
{
    if(!root)
        return 0;

    cout<<root->data<<" ";

    if(height(root->left) > height(root->right))
        longestPath(root->left);
    else
        longestPath(root->right);
   
   return 1;
}

int height(node* root)
{
    if(!root)
        return 0;

    return 1 + max(height(root->left),height(root->right));
}
//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function to return the average od the longest path in a tree.
//The difficulty of this question is: 4

int avgPath(node* root)
{
    int count = 0;


    int sum  = avgPath(root,count);
    
    return (sum/count);
}

int avgPath(node* root,int& count)
{
    if(!root)
        return 0;

    if(height(root->left) > height(root->right))
        return avgPath(root->left,++count)+ root->data;
    else
         return avgPath(root->right,++count) + root->data;
   
}

//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function that returns the average of the data contained in the tree
//The difficulty of this question is: 3
int avgData(node* root)
{
    if(!root)
        return 0;

    int sum;
    int count;

    count = avgData(root,sum);
    std::cout<<"sum is "<<sum;

    return (sum/count);
}

int avgData(node* root, int& sum)
{
    if(!root)
        return 0;
    sum+= root->data;

    return avgData(root->left,sum) + avgData(root->right,sum) + 1;
}

//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function to copy all the nodes that are greater than root into a new tree. Return the number of nodes copied
//The difficulty of this question is: 2
/*
int copyGreater(node* srcRoot, node*& destRoot)
{

}
*/

//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function to copy all even nodes from one tree into a new tree. return number of nodes divisible by 7
//The difficulty of this question is: 3
/*
int copyDivisible(node* srcRoot, node*& destRoot)
{

}
*/

//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function to remove all the leaves from a tree. return number of nodes removed.
//The difficulty of this question is: 2
/*
int prune(node*& root)
{

}
*/

//Place the prototype in the appropriate .h file
//Consider:
//Do you need helper functions?
//Is head or tail recursion better?
//Remove the block comments form the function below to get started
//The question is: Write a function to copy a tree, excluding its' root, into a new tree. return number of nodes copied.
//The difficulty of this question is: 3
/*
int copyNoRoot(node* srcRoot, node*& destRoot)
{

}
*/

