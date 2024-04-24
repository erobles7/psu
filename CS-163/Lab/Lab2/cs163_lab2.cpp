#include "cs163_list.h"
using namespace std;

const int SIZE=100;

int main()
{
    
    char title[SIZE], notes[SIZE];      //temporary for journals
    char response;
    journal_entry entry;                //Start creating entries!
    list my_journal;

    char a [] = "PABLO";
    char b [] = "Life";
    entry.create_entry(a,b);
    //entry.display();

    char c [] = "Tacos";
    char d [] = "Burritos";
    journal_entry new_entry;
    new_entry.create_entry(c,d);

    journal_entry am;
    am.copy_entry(entry);

   // am.display();
   journal_entry z;
   my_journal.add(am);
   my_journal.add(new_entry);

   // int test = am.retrieve(a,z);
    //std::cout<<"\n\n"<<test<<std::endl;
    my_journal.display();
    char pie [] = "ZZZZZZ";

    int pizza = my_journal.find(pie,am);
    std::cout<<"\n\n"<<pizza<<std::endl;
    //Main has already been written for you to test out
    //the add and find functions
    //
    //Notice how we use the returned value of the functions!
    //Also notice that all communication with the user is
    //done through main (not the ADT)
   
////////
/*///
    //Let's create some journal entries
    do
    {
       cout <<"Please enter the title of your journal entry\n";
       cin.get(title, SIZE, '\n'); cin.ignore(SIZE,'\n');
       cout <<"Please enter your notes\n";
       cin.get(notes, SIZE, '\n'); cin.ignore(SIZE,'\n');
       
       //Now create the journal entry
       if (entry.create_entry(title, notes)) 
           //if this was successful, let's add it to the list!
          if (! my_journal.add(entry))
              cerr << "We were unable to add it to the list...\n";
     } while (again());
     
     //Now display all that we have
     cout <<"\n\nThe entire list contains the following:\n";
     if (!my_journal.display())
            cerr << "The list is empty...try again\n";
            */
////////////////////////////////

     //The following code demonstrates how to call the find function.
     //You may use this code or modify it to fully test your lab code!
/*

     //Is there an entry we would like to find (by title)?
     cout <<"Enter a title which you would like to find in your journal: ";
     cin.get(title, SIZE, '\n'); cin.ignore(SIZE,'\n');
     if (my_journal.find(title, entry))
     {
        cout <<"\n\nWe found:\n"; 
        if (!entry.display())
            cerr << "Sorry, can't display it at this time\n";
     }
     else  cout <<"\n\nNo match found.\n";
*/
     return 0;
     
}
