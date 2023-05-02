#ifndef RECIPE_H
#define RECIPE_H
#include <vector>
#include <string>
#include <iostream>
using std:: cout; 
using std:: string;
using std:: cin; 

//declares the recipe class that is used in the main library


class Recipe {
  public:
//declare public to be used in inheritence 
//variables declared here
    string name;
    string type;
    string country;

    vector<string> ingredients;

  public:
    Recipe(string n, string t, string c) {
      name = n;
      type = t;
      country = c;
    }

    void add_ingredient(string ing) {
      ingredients.push_back(ing);
    }
};

#endif
