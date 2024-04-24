#include "store.h"
using namespace collection;

//These are the functions you will be implementing for Lab #2
//REMEMBER to use initialization lists for your constructors
//where they are appropriate

//Step 6a - implement the default constructor
binary_tree::binary_tree():root(0)
{


}

//Step 6b - impelment the BST default constructor
//BST constructor
BST::BST():balance_factor(0)
{


}

//Step 6c - impelment the store default constructor
//Think about what this should do
store::store()
{
    std::cout<<"Enter in a store name: ";
    store_name.read();
    std::cout<<"Enter in a location: ";
    location.read();
}


//Step 7 - Now work on the copy constructor
/*
//Place your binary_tree copy constructor here. Make this a
//wrapper function, calling the recursive copy function below
//
//You should have already placed the prototype for this function
//in the .h file (that was NOT done for you already!)
//Use CARE when deciding the SYNTAX for the copy constructor!
//
//YOU WILL NEED TO "uncomment out" THIS CODE ONCE THIS 
//FUNCTION IS WRITTEN!
*/
binary_tree::binary_tree(const binary_tree& to_copy)
{
    copy_tree(root,to_copy.root);
}

//Step 8 - Now implement the recursion part of the copy operation
//
//Recursive copy function
void binary_tree::copy_tree(node * & result, node * source)
{
    if(!source)
    {
        result = NULL;
        return;
    }
       result = new node(*source);

       copy_tree(result->go_left(),source->go_left());
       copy_tree(result->go_right(),source->go_right());
}

//Step 9 - implement the destructor as a "wrapper"
//
//Implement the binary_tree destructor. Make this a
//wrapper function, calling the recursive delete_all function below
binary_tree::~binary_tree()
{
    delete_all(root);
}

//Recursive delete all function
void binary_tree::delete_all(node * & root)
{
    if(!root)
        return;

    delete_all(root->go_left());
    delete_all(root->go_right());

    delete root;
    root = NULL;
}


//Step 10 - implement the store constructor with arguments
//
//Store constructor with an argument
//Hint: Think about initialization lists
store::store(char * new_store_name, address & stores_location):store_name(new_store_name),location(stores_location)
{

}

//Step 11 - implement the store class' display_all
//
//Display all - think about what the job of this function should be:
void store::display_all() 
{
    std::cout<<"\nStore: ";
    store_name.display();
    std::cout<<"\nLocation: ";
    location.display();
    BST::display_all();

}
