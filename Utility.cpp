//
// Created by kregan on 11/15/22.
//

#include "Utility.h"
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
#include <iostream>

using namespace std;


/*
 * Name: PrintMenu
 * Description: prints menu options for user
 * Parameters: none
 * Return: void/none
 */
void PrintMenu() {
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
}

/*
 * Name: ExecuteMenu
 * Description: executes menu option based on user input
 * Parameters:
 *  userOption - character for menu option choice
 *  userCart - shopping cart object passed by reference
 * Return: void/none
 */
void ExecuteMenu(char userOption, ShoppingCart& userCart){
        // allows user to add item to cart
        if (userOption == 'a') {
            string itemNameFromUser;
            string itemDescriptionFromUser;
            float itemPriceFromUser;
            int itemQuantityFromUser;


            // prompts user for information about the new item to be added
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin >> ws, itemNameFromUser);
            cout << "Enter the item description:" << endl;
            getline(cin, itemDescriptionFromUser);
            cout << "Enter the item price:" << endl;
            cin >> itemPriceFromUser;
            cout << "Enter the item quantity:" << endl;
            cin >> itemQuantityFromUser;


            // saves user input to parameter constructor for ItemToPurchase object
            ItemToPurchase itemToAdd = ItemToPurchase(itemNameFromUser, itemDescriptionFromUser, itemPriceFromUser,itemQuantityFromUser);


            //calls add member function for userCart object to add new item to users cart
            userCart.AddItem(itemToAdd);
        }

        //allows user to remove an item from shopping cart
        else if (userOption == 'd') {
            string itemToBeRemoved;

            // prompts user for item to be removed and saves it to a string
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            getline(cin >> ws, itemToBeRemoved);

            // calls member function for user cart to remove item entered by user
            userCart.RemoveItem(itemToBeRemoved);
        }

        // allows user to modify item quantity
        else if (userOption == 'c') {
            string itemToModify;
            int updatedQuantity;
            ItemToPurchase modifiedItem;        // creates a new ItemToPurchase object


            // prompts user for updated quantity
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin >> ws, itemToModify);
            cout << "Enter the new quantity:" << endl;
            cin >> updatedQuantity;

            //saves item name and updated quantity to local ItemToPurchase object
            modifiedItem.SetQuantity(updatedQuantity);
            modifiedItem.SetName(itemToModify);

            //calls member function to modify item quantity
            userCart.ModifyItem(modifiedItem);
        }

        // outputs all items' descriptions by calling member function StringOfDescriptions
        else if (userOption == 'i') {
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            cout << userCart.StringOfDescriptions();
        }

        //outputs all items in shopping cart using member function StringOfTotal
        else if (userOption == 'o') {
            cout << "OUTPUT SHOPPING CART" << endl;
            cout << userCart.StringOfTotal();
        }




}



