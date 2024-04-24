#include "cs163_2-3.h"
using namespace std;

//These are the functions that you will be writing for Lab #8

// **** STEP 1
//First write the wrapper functions:
//Display all nodes with no children in 2-3 tree
int table::display_23()      
{
    //call the recursive function here
}

//Now implement the recursive function to display all leaves
int table::display_23(node23 * root){}     



// **** STEP 2
// Implement the recursive function to deallocate all items.
// The destructor already calls this function
int table::deallocate_23(node23 * & root){} 



// **** STEP 3
//First write the wrapper functions:
//Return true if the root's largest value appears more than once
bool table::find_largest()   
{

    //place your code here

}

//Return true if the root's largest value appears more than once
//Write this function recursively
bool table::find_largest(node23 * root, int match){}


// **** STEP 4
//First write the wrapper functions:
//Copies the argument's tree into the current object's tree
int table::copy(const table & source) 
{
   
    //call the recursive function here
}


//Now implement the recursive function to copy the tree
int table::copy(node23 * & dest_root, node23 * source_root){}      
