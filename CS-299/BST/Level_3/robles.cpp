#include "CS299_bst.h"

/************************
 * Duplicates
 * *********************/
bool table::hasDuplicate()
{
    if(!root)
        return false;
    
    node* prev = NULL;
    return hasDuplicate(prev,root);

}
bool table::hasDuplicate(node* prev, node* root)
{
    if(!root)
        return false;

    if(root->left)
        return hasDuplicate(root,root->left);

    if(root->right)
        return hasDuplicate(root,root->right);

    if(root->data == prev->data)
        return true;

    return false;
}
