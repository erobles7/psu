#include "table.h"

int table::count()
{
    if(!root)
        return 0;

    return count(root);
}

int table::count(node* root)
{

    if(!root)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

        
int table::count_more_than_30()
{
    if(!root)
        return 0;

    return count_more_than_30(root);
}

int table::count_more_than_30(node* root)
{
    int count = 0;

    //base case
    if(!root)
        return 0;

    if(root->data > 30)
        ++count;

    return count + count_more_than_30(root->left) + count_more_than_30(root->right);
}

        
int table::count_root()
{
    if(!root)
        return 0;

    return count_root(root->right,root->data);
}
int table::count_root(node* root,int match)
{
    int count = 0;

    //base case
    if(!root)
        return 0;

    if(root->data == match)
        ++count;

    return count + count_root(root->left,match)+ count_root(root->right,match);
}

int table::remove_all_children()
{
    if(!root)
        return 0;

    return remove_all_children(root);
}
int table::remove_all_children(node*& root)
{

    if(!root)
        return 0;

    //check for leaf
    if(!root->left && !root->right)
    {
        delete root;
        root = NULL;
        return 1;
    }

    return remove_all_children(root->left)+remove_all_children(root->right);
}

int table::remove_largest_num()
{
    if(!root)
        return 0;

    if(!root->right)
    {
        int ret = root->data;
        delete root;
        root = NULL;
        return ret;
    }

    return remove_largest_num(root->right);
}
int table::remove_largest_num(node*& root)
{
    if(!root->right)
    {
        int ret = root->data;
        delete root;
        root = NULL;
        return ret;
    }

    return remove_largest_num(root->right);
}

int table::remove_smallest()
{
    if(!root)
        return 0;

    if(!root->left)
    {
        int ret = root->data;
        delete root;
        root = NULL;
        return ret;
    }

    return remove_smallest(root->left);
}

int table::remove_smallest(node*& root)
{
    if(!root->left)
    {
        int ret = root->data;
        delete root;
        root = NULL;
        return ret;
    }

    return remove_smallest(root->left);
}
