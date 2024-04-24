#include "table.h"

/*******************************
 * Insert Function
 * ****************************/
int insert(node*& root,int num)
{
    //empty tree
    if(!root)
    {
        root = new node;
        root->data = num;
        root->left = NULL;
        root->right = NULL;
        return 1;
    }

    if(num < root->data)
        insert(root->left,num);

    else
        insert(root->right,num);

    return 1;
}

/*******************************
 * remove all Function
 * ****************************/
void remove_all(node*& root)
{
    if(!root)
    {
        return;
    }

    remove_all(root->left);
    remove_all(root->right);

    //delete the node on the return
    delete root;
    root = NULL;
}


/*******************************
 * remove all Function
 * ****************************/
int count_leaves(node* root)
{
    int ret = 0;

    if(!root)
        return 0;

    //check for children
    if(!root->left && !root->right)
    {
        ++ret;

    }

    return ret + count_leaves(root->left) + count_leaves(root->right);
}


int count_even(node* root)
{
    int ret  = 0;

    if(!root)
        return 0;

    //check if even number
    if(root->data % 2 == 0)
    {
        ++ret;
    }

    return ret + count_even(root->left) + count_even(root->right);

}


void copy(node*& dest_root, node* source)
{
    if(!source)
    {
        dest_root = NULL;
        return;
    }

    dest_root = new node;
    dest_root->data = source->data;
 
    copy(dest_root->left,source->left);
    copy(dest_root->right,source->right);
}


int height(node* root)
{
    if(!root)
        return 0;

    return 1 + max(height(root->left),height(root->left));
}

void copy_even(node*& dest_root,node* source)
{
    if(!source)
        return;

    if(source->data % 2 == 1)
    {
        insert(dest_root,source->data);
    }

    copy_even(dest_root,source->left);
    copy_even(dest_root,source->right);
}

//count number of nodes with only 1 kid 
int count_single_child(node* root)
{
    int ret = 0;

    if(!root)
        return 0;

    //no left but has right
    if(!root->left && root->right)
        ++ret;

    //no right but has left
    if(!root->right && root->left)
        ++ret;

    return ret + count_single_child(root->left) + count_single_child(root->right);
}

//count twos 
int count_twos(node* root)
{
    int ret = 0;

    if(!root)
        return 0;

    if(root->data == 2)
    {
        ++ret;
    }

    return ret + count_twos(root->left) + count_twos(root->right);
}

//display leafs only
int display_leafs(node* root)
{
    if(!root)
        return 0;

    if(!root->left && !root->right)
    {
        std::cout<<root->data<<" ";
    }

    display_leafs(root->left);
    display_leafs(root->right);

    return 1;
}

//display smallest
int display_smallest(node* root)
{
    if(!root)
        return 0;

    if(!root->left)
    {
        std::cout<<root->data;
        return 1;
    }
    return display_smallest(root->left);
}

//display largest
int display_largest(node* root)
{
    if(!root)
        return 0;

    if(!root->right)
    {
        std::cout<<root->data;
        return 1;
    }

    return display_largest(root->right);
}

//remove smallest if its not a two
void remove_smallest_if_not_two(node*& root)
{
    if(!root)
        return;

    if(!root->left)
    {
        if(root->data != 2)
        {

            //no children
            if(!root->right)
            {
                delete root;
                root = NULL;
                return;
            }

            //right child
            if(root->right)
            {
                node* temp = root;
                root = root->right;
                delete temp;
                return;
            }
        }
    }
    return remove_smallest_if_not_two(root->left);
}


//display in order 
int display_in_order(node* root)
{
    if(!root || !root->right)
        return 0;

    return display_in_orderPrivate(root->right);
}

int display_in_orderPrivate(node* root)
{
    if(!root->left)
    {
        std::cout<<root->data<<std::endl;
        return 1;
    }

    return display_in_orderPrivate(root->left);
}


