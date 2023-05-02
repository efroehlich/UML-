// Emma Froehlich, project main menu 
#include <iostream>
#include <string>
#include "Recipe.h"
#include "Library.h"

using std:: vector;
using std:: cout; 
using std:: string;
using std:: cin; 

//call library function which holds most of information for main menu
Library library;

//declare main menu function
void main_menu();

//display menu used to print out the main menu
void display_menu() {
  cout << "\033[2J\033[1;1H";
  cout<< R"(

  ______                           _       ______              _   _      _ _                          
 |  ____|                         ( )     |  ____|            | | | |    (_) |                         
 | |__   _ __ ___  _ __ ___   __ _|/ ___  | |__ ___   ___   __| | | |     _| |__  _ __ __ _ _ __ _   _ 
 |  __| | '_ ` _ \| '_ ` _ \ / _` | / __| |  __/ _ \ / _ \ / _` | | |    | | '_ \| '__/ _` | '__| | | |
 | |____| | | | | | | | | | | (_| | \__ \ | | | (_) | (_) | (_| | | |____| | |_) | | | (_| | |  | |_| |
 |______|_| |_| |_|_| |_| |_|\__,_| |___/ |_|  \___/ \___/ \__,_| |______|_|_.__/|_|  \__,_|_|   \__, |
                                                                                                  __/ |
                                                                                                 |___/ 
        
)" << '\n';
  cout<< "\t 1. Access all breakfast foods. \n";
  cout<< "\t 2. Access all lunch/dinner foods. \n";
  cout<< "\t 3. Access every food item. \n";
  cout<< "\t 4. Recipes by country.\n";
  cout<< "\t 5. Search recipes by type.\n";
  cout<< "\t 0. exit to main menu \n";

  cout<<"\nPlease enter your choice: ";
}

//main return gives user option to continue exploring options or exit
void menu_return(){
  int menu_key; 
  cout<<" \t Would you like to return to the main menu? Press 1 to return, press 0 to leave \n";
  cin>>menu_key; 
  if (menu_key == 1)
  {
    main_menu();
  }
  else if (menu_key ==0)
  {
    cout<< "\nThanks for visiting!";
    exit(0);
  }
  else {
    cout<<"invalid, returning to main menu";
      main_menu();
  }
  
}
//main menu option for user selection
void main_menu()
{
  vector<string> lunch_dinner {"Lunch", "Dinner"};
  

  //gives int for user choices + display main menu
  int choice;
  string str_in;
  display_menu();
  cin>> choice; 
  //choice returns different functions of the library
  switch(choice)
    {
      case 0: cout<< "Thanks for visiting, hope you come back soon! Goodbye";  
      //shows user all breakfast options
      case 1:
        library.show_by_type("Breakfast");
        menu_return();
        break;

      //shows user all lunch/ dinner options
      case 2:
        library.show_by_types(lunch_dinner);
        menu_return();
        break;

      //shows users all options
      case 3:
        library.show_all();
        menu_return();
        break;
      //shows user options through searching countries
      case 4:
        cout << "Please enter the country: ";
        cin >> str_in;
        library.show_by_country(str_in);
        menu_return();
        break;
      // allows user to search by type of recipe 
      case 5:
        cout << "Please enter the type of recipes: ";
        cin >> str_in;
        library.show_by_type(str_in);
        menu_return();
        break;
      default:
        break;
    }
    

  
}

//this function initializes all of the food menu options presented
 void init()
{
  vector<std::string> ings1 {"Light and fluffly pancakes", "similar to soufle"};
  vector<std::string> ings2 {"Traditionally served as raw fish over sticky rice", "Can be served cooked, or with veggies"};
  vector<std::string> ings3 {"Noodles in salty broth", "Can contain a variety of veggies, meat and egg"};
  
  vector<std::string> ings4 {"Fried eggs served on tortilla", "Typically topped with salsa, cheese and veggies"};
  vector<std::string> ings5 {"Fried tortilla chips", "Usually topped with meat, cheese, salsa, sour cream and veggies"};
  vector<std::string> ings6 {"Corn tortila rolled in a savory sauce", "Filled with meats and cheese"};
  
  vector<std::string> ings7 {"Italian almond biscuits", "Cooked twice, meaning they are very crunchy and often dipped in tea or coffee"};
  vector<std::string> ings8 {"Traditional Italian Soup", "Made with veggies, pasta and beans"};
  vector<std::string> ings9 {"Type of pasta made from potatoes and flour", "Usually served in tomato sauce, pesto or butter+herbs"};

  /* adds each recipe into library class vectors, in order to reuse throughout code */
  library.add_recipe("Japanese Pancake", "Breakfast", "Japan", ings1);
  library.add_recipe("Sushi", "Lunch", "Japan", ings2);
  library.add_recipe("Ramen", "Dinner", "Japan", ings3);
  
 
  library.add_recipe("Huevos Ranchos", "Breakfast", "Mexico", ings4);
  library.add_recipe("Nachos", "Lunch", "Mexico", ings5);
  library.add_recipe("Enchiladas", "Dinner", "Mexico", ings6);

  library.add_recipe("Biscotti", "Breakfast", "Italy", ings7);
  library.add_recipe("Minestrone Soup", "Lunch", "Italy", ings8);
  library.add_recipe("Gnocchi", "Dinner", "Italy", ings9);

  
    

}





//main function calling the main menu +init
int main() 
{
  init();
  
 main_menu(); 
}
