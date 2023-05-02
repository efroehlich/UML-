#include "Recipe.h"
#include <string>
#include <vector>
#include <iostream>
using std:: cout; 
using std:: string;
using std:: cin; 

//declares and stores variables + methods that will be used in library
class Library {
public:
  vector<Recipe> recipes;

  void add_recipe(string n, string t, string c, vector<string> ings);

  void show_recipes_vec(vector<Recipe> &rvec);

  void show_all();

  void show_by_type(string t);

  void show_by_types(vector<string> &types);

  void show_by_country(string c);

  void menu_quiz(vector<Recipe> &rvec); 
};
