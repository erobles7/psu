#include <iostream>
#include "table.h"
using namespace std;

/********************************************************
 Author: Eduardo Robles
 Date: 11/23/2016
 Desc: Testing program for the binary search tree 
*********************************************************/

//function prototypes
void main_menu(table& my_table);
void add_game(table& my_table);
void load_game(table& my_table);
void remove_game(table& my_table);
void remove_all_games(table& my_table);
void display_all_games_range(table& my_table);
void disply_all_games(table& my_table);
void display_count(table& my_table);

int main()
{

  //create a table     
  table my_table;

  //run main menu
  main_menu(my_table);
   
  return 0;
}


/*************************************************************
 Name: main_menu()
 Input: the hash table
 Desc: main menu for testing functions 
**************************************************************/
void main_menu(table& my_table)
{
   
 int input = 0;  

  do 
   {
      std::cout<<"\nPlease choose from the following options\n";
      std::cout<<"1. Add a new game\n";
      std::cout<<"2. Load game information from a file\n"; 
      std::cout<<"3. Remove a game \n";
      std::cout<<"4. Remove all instances of a game\n";
      std::cout<<"5. Display all games within a certain range\n";
      std::cout<<"6. Display all games\n";
      std::cout<<"7. Display number of 5 star rated games\n";
      std::cout<<"8. Quit\n";
      std::cout<<" $: ";
      std::cin>>input;
      cin.ignore();
      cout<<endl;
   }  

    while(input != 1 && input !=2 && input !=3 && input != 4 && input !=5 && input!=6 && input!= 7 && input != 8);

    //call the correct function
    switch(input)
    {
      case 1:
            add_game(my_table);
            break;
      case 2:
           load_game(my_table);
           break;
      case 3:
            remove_game(my_table);
            break;
     case 4:
            remove_all_games(my_table);
            break;
     case 5:
            display_all_games_range(my_table);
            break;
     case 6:
          disply_all_games(my_table);
           break;
    case 7:
	   display_count(my_table);
	   break;
      default:
           break;
   }

}

/*************************************************************
 Name: add_game()
 Input: the hash table
 Desc: adds a game to the hash map
**************************************************************/
void add_game(table& my_table)
{
  char name [100];
  char desc [100];
  char type [100];
  char platform [100];
  char stars [100];
  char rec [100]; 

  //get the name of the video game
  std::cout<<"\nEnter the name of the video Game\n";
  cout<<": ";
  cin.get(name,100,'\n');
  cin.ignore(100,'\n');

  //get the description of the video game
  std::cout<<"\nEnter short description of the video Game\n";
  cout<<": ";
  cin.get(desc,100,'\n');
  cin.ignore(100,'\n');

  //get the type of video game
  std::cout<<"\nEnter type (e.g FPS,Driving,puzzle, adventure)\n";
  cout<<": ";
  cin.get(type,100,'\n');
  cin.ignore(100,'\n');


  //get the platform of video game
  std::cout<<"\nEnter platform (e.g PC,Xbox 360,Playstartion 3,)\n";
  cout<<": ";
  cin.get(platform,100,'\n');
  cin.ignore(100,'\n');


  //get the star rating  of video game
  std::cout<<"\nEnter star rating  (e.g 0-not so good , 5 - a great and fun game )\n";
  cout<<": ";
  cin.get(stars,100,'\n');
  cin.ignore(100,'\n');
  
  //get game recommendations
  std::cout<<"\nEnter recommendations about the game or comment\n";
  cout<<": ";
  cin.get(rec,100,'\n');
  cin.ignore(100,'\n');

  //create new game object 
  Game new_game(name,desc,type,platform,stars,rec);

  //insert into the hash table
  my_table.insert(name,new_game);

  //return to main menu
  main_menu(my_table);

}



/*************************************************************
 Name: load_game()
 Input: the hash table
 Desc: loads game information from external data file 
**************************************************************/
void load_game(table& my_table)
{

  char file_name[100];  

  //get the name of the file
  std::cout<<"\nEnter the name of the file (case sensitive)\n";
  cout<<": ";
  cin.get(file_name,100,'\n');
  cin.ignore(100,'\n');

  //load the file 
  my_table.load_from_file(file_name);

  //return to main menu
   main_menu(my_table);
}


/*************************************************************
 Name: remove_game()
 Input: the hash table
 Desc: removes game from the hash table
**************************************************************/
void remove_game(table& my_table)
{
  
  char name[100]; 
  char platform[100];

  //get the name of the game
  std::cout<<"\nEnter the name of video game to remove (case sensitive) \n";
  cout<<": ";
  cin.get(name,100,'\n');
  cin.ignore(100,'\n');

  //get the platform
  std::cout<<"\nEnter the platform  (case sensitive) \n";
  cout<<": ";
  cin.get(platform,100,'\n');
  cin.ignore(100,'\n');

  //remove from hash map
  my_table.remove(name,platform);

  //return to main menu
   main_menu(my_table);
}



/*************************************************************
 Name: remove_all_games()
 Input: the  table
 Desc: removes all instances of a video game 
**************************************************************/
void remove_all_games(table& my_table)
{
 char name[100];
   
  //get the name of the video
  std::cout<<"\nEnter the name of video game (case sensitive) \n";
  cout<<": ";
  cin.get(name,100,'\n');
  cin.ignore(100,'\n');

  //remove all instances
  my_table.remove(name);

  //return to main menu 
  main_menu(my_table);

}



/*************************************************************
 Name: display_all_games_range()
 Input: table
 Desc: displays all games in within a given range
**************************************************************/
void display_all_games_range(table& my_table)
{
  
  //int display_all_platform(char* platform);
  char first_letter;
  char second_letter;

  //get the first letter
  std::cout<<"\nEnter first letter (case sensitive, Enter in CAPS) \n";
  cout<<": ";
  cin>>first_letter;

  //get the second letter
  std::cout<<"\nEnter second letter (case sensitive, Enter in CAPS) \n";
  cout<<": ";
  cin>>second_letter;

  //display all games for current platform
  std::cout<<"\n";

  //display items in range 
  my_table.display_range(first_letter,second_letter);

 //return to main menu
  main_menu(my_table);
}



/*************************************************************
 Name: display_all_games()
 Input: the hash table
 Desc: displays all the games in the hash table
**************************************************************/
void disply_all_games(table& my_table)
{
   //display all the games
   my_table.display_all();
  
   //return to main menu
   main_menu(my_table);
}


/*************************************************************
 Name: display_count()
 Input: table
 Desc: displayst the number of games that have 5 star rating 
**************************************************************/
void display_count(table& my_table)
{
	//get the count
	int x = my_table.count();

	//display the count 
	std::cout<<"\nThe number of 5 star rated games is "<<x<<"\n";
	
	//return to main menu
	main_menu(my_table);
}
