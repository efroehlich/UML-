#include "Library.h"
#include "Recipe.h"
#include <string>
#include <iostream>
using std::vector; 
using std:: cout; 
using std:: string;
using std:: cin; 
using std::endl; 

//adds recipes into the library that were initialized on main code
void Library::add_recipe(string n, string t, string c, vector<string> ings) {
  Recipe new_recipe = Recipe(n, t, c);
  for (int i = 0; i < ings.size(); i++)
    new_recipe.add_ingredient(ings[i]);
  recipes.push_back(new_recipe);
}

//prints out the information entered in the recipes
void Library::show_recipes_vec(vector<Recipe> &rvec) {
  for (int i = 0; i < rvec.size(); i++) {
    Recipe r = rvec[i];
    cout << i+1 << ". " << r.name << " | " << r.type << " | " << r.country << endl;
    cout << "\tIngredients:\n";
    for (int j = 0; j < r.ingredients.size(); j++) {
      cout << "\t\t" << j+1 << ". " << r.ingredients[j] << endl;
    }
    cout << endl;
  }
}

//this method runs through all the recipes listen in the vector
void Library::show_all() {
  cout << "There's " << recipes.size() << " recipe: \n";
  show_recipes_vec(recipes);
}


//this recognizes the type in order to print for user input
void Library::show_by_type(string t) {
  vector<Recipe> recipes_by_type;
  for (int i = 0; i < recipes.size(); i++) {
    if (recipes[i].type == t)
      recipes_by_type.push_back(recipes[i]);
  }
  if (recipes_by_type.size() == 0) {
    cout << "Sorry! there's no recipes of type " << t << endl;
  }
  else {
    cout << "There's " << recipes_by_type.size() << " recipe of type " << t <<":\n";
    show_recipes_vec(recipes_by_type);
  }
}

void Library::show_by_types(vector<string> &types) {
  vector<Recipe> recipes_by_type;
    for (int i = 0; i < recipes.size(); i++) {
      for (int j = 0; j < types.size(); j++)
        if (recipes[i].type == types[j]) {
          recipes_by_type.push_back(recipes[i]);
          break;
        }
  }

  //if not recognized, then fails for the user must re enter
  if (recipes_by_type.size() == 0) {
    cout << "Sorry! there's no recipes of specified types." << endl;
  }
    //else shows the recipe of specified type
  else {
    cout << "There's " << recipes_by_type.size() << " recipe of the specified types.\n";
    show_recipes_vec(recipes_by_type);
  }
}

//allows user to enter in and view recipes by country
void Library::show_by_country(string c) {
  vector<Recipe> recipes_by_country;
  for (int i = 0; i < recipes.size(); i++) {
    if (recipes[i].country == c)
      recipes_by_country.push_back(recipes[i]);
  }
  if (recipes_by_country.size() == 0) {
    cout << "Sorry! there's no recipes from  " << c << endl;
  }
  else {
    cout << "There's " << recipes_by_country.size() << " recipe from " << c <<":\n";
    show_recipes_vec(recipes_by_country);
  }

  
}
