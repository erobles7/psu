#include "cs163_graph.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the adjacency list and set each
      //head pointer to NULL
    list_size = size;
    adjacency_list = new vertex[list_size];
    vertex* current = adjacency_list;
    vertex* stop = adjacency_list+size;

    while(current < stop)
    {
        (*current).entry = NULL;
        (*current).head = NULL;
        ++current;
    }
}

//Store the vertex at this location.
int table::insert_vertex(const journal_entry & to_add)
{
    int i = 0;

    bool isFound = false;

    while( i < list_size && !isFound)
    {
        if(!(*(adjacency_list+i)).entry)
        {
            (*(adjacency_list+i)).entry = new journal_entry;
            (*(adjacency_list+i)).entry->copy_entry(to_add);
            isFound = true;
        }
        ++i;
    }

    if(isFound)
        return 1;
    else
        return 0;
}

//Attach an edge to a vertex
int table::insert_edge(char * current_vertex, char * to_attach)
{
    int index_a = find_location(current_vertex);
    int index_b = find_location(to_attach);



}

//Display all vertices adjacent to the one specified
int table::display_adjacent(char * key_value)
{

}

//Find a location in the graph
//Consider this a helper function foro all of the other member functions!
int table::find_location(char * key_value)
{

    if(!adjacency_list)
        return -1;

    int i  = 0; 
    bool found = false;

    while( i < list_size && !found)
    {
        if((*(adjacency_list+i)).entry)
            if((*(adjacency_list+i)).entry->compare(key_value))
                found = true;
        ++i;
    }

    if(found)
        return i;

    return -1;
}


