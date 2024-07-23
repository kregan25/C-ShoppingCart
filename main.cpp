/*
 * CIS 2361 Section 27803
 * Assignment No. 35.17 Final Project: Shopping Online
 *
 * Author: Kellie Regan
 * SID: 8887
 *
 * Description: This program models an online shopping cart using a class for shopping cart and a class for items to purchase.
 * User can modify items to purchase by setting the item name, description, price and quantity. User can modify the shopping
 * cart by adding items, removing items and updating quantity of items. User can view the total items in cart, descriptions
 * of items in cart, and all items included in their current cart.
 *
*/
#include <iostream>
#include <string>
#include "ShoppingCart.h"
#include "Utility.h"

using namespace std;


int main() {
    //declare variables to hold user input
    string userInputName;
    string userInputDate;
    char userSelection;

    // create shopping cart object
    ShoppingCart userCart;


    //get user inputs for name and date
    cout << "Enter customer's name:" << endl;
    getline(cin, userInputName);
    cout << "Enter today's date:" << endl;
    getline(cin, userInputDate);

    cout << "Customer name: " << userInputName << endl;
    cout << "Today's date: " << userInputDate << endl;
    userCart = ShoppingCart(userInputName, userInputDate);


    // display menu and prompt for user choice
    PrintMenu();
    cout << "Choose an option:" << endl;
    cin >> userSelection;


    // check to make sure user doesn't want to quit (types in q)
    while(userSelection != 'q') {

        // checks for valid user input
        if (userSelection == 'a'|| userSelection == 'd' || userSelection == 'c'|| userSelection == 'i' || userSelection == 'o') {
            ExecuteMenu(userSelection, userCart);
            PrintMenu();
        }

        // prompts for user for new input until valid input is entered
        cout << "Choose an option:" << endl;
        cin >> userSelection;
    }


    return 0;




}
