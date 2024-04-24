#include "CS299_bst.h"

/*************************
 * Remove the largest 
 * **********************/
int table::remove_largest()
{
    if(!root)
        return 0;
    if(!root->right)
    {
        int large = root->data;
        delete root;
        root = NULL;
        return large;
    }

    return remove_largest(root->right);
}
int table::remove_largest(node*& root)
{
    if(!root)
        return 0;
    
    if(!root->right)
    {
        int largest = root->data;
        node* temp = root;
        root = root->left;
        delete temp;
        return largest;
    }
    return remove_largest(root->right);
}

/*************************************************
* Display Every Item Smaller than the roots data
* ***********************************************/
int table::display_smaller()
{
    if(!root)
        return 0;

    return display_smaller(root->left);
}

int table::display_smaller(node* root)
{
    
     int count;

    if(!root)
        return 0;

    count = display_smaller(root->left)+display_smaller(root->right) + 1;
    std::cout<<root->data<<" ";

    return count;
}

/************************************************
*Count number of nodes larger than smallest item 
************************************************/
int table::count_larger()
{
    if(!root)
        return 0;

    return count_larger(root);
}

int table::count_larger(node* root)
{
    int smallest = 0;

    return count_larger(root,smallest);

}
int table::count_larger(node* root, int& smallest)
{
    int count = 0;

    if(!root)
        return 0;

    count+= count_larger(root->left,smallest);

    if(!smallest)
        smallest = root->data;

    count+=count_larger(root->right,smallest);

    if(root->data > smallest)
        ++count;
    
    return count;
}
/*******************************************
 * Remove every leaf unless same as root
 * *****************************************/
int table::remove_leaf()
{
    if(!root)
        return 0;

    return remove_leaf(root);
}

int table::remove_leaf(node*& root)
{
    if(!root)
        return 0;

    return remove_leaf(root,root->data);
}
int table::remove_leaf(node*& root, int num)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
    {
        if(root->data == num)
        {
            delete root;
            root = NULL;
            return 1;
        }
    }
    return remove_leaf(root->left,num)+remove_leaf(root->right,num);

}





