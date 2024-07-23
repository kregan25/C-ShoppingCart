//
// Created by kregan on 11/15/22.
//

#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>
using namespace std;


// Default Constructor
ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}


// parameterized constructor
ShoppingCart::ShoppingCart(string inputName, string inputDate) {
    customerName = inputName;
    currentDate = inputDate;
}


/*
* Name: GetCustomerName
* Description: gets customer name
* Parameters: none
* Return: string - customer's name
*/
string ShoppingCart::GetCustomerName() {
    return customerName;
}


/*
* Name: GetDate
* Description: gets date shopping cart was created
* Parameters: none
* Return: string - date of shopping cart
*/
string ShoppingCart::GetDate() {
    return currentDate;
}


/*
* Name: AddItem
* Description: adds new item to end of cartItems vector
* Parameters:
 * ItemToPurchase - object with all the new item's information to add to vector
* Return: none/void
*/
void ShoppingCart::AddItem(ItemToPurchase newItem) {
    cartItems.push_back(newItem);
}


/*
* Name: RemoveItem
* Description: removes item from vector
* Parameters:
 * string - name of item to be removed
* Return: none/void
*/
void ShoppingCart::RemoveItem(string itemName) {
    bool isFound = false;

    // loop to walk through vector to find and delete requested item
    for(unsigned int i = 0; i < cartItems.size(); ++i) {
        if (cartItems[i].GetName() == itemName) {
            cartItems.erase(cartItems.begin() + i);
            isFound = true;
            break;
        }
    }

    //if item is not found, error message is printed
    if( isFound == false){
           cout << "Item not found in cart. Nothing removed." << endl;
    }
}


/*
* Name: ModifyItem
* Description: modifies/updates item quantity in vector
* Parameters:
 * ItemToPurchase - object with name of item and updated quantity
* Return: none/void
*/
void ShoppingCart::ModifyItem(ItemToPurchase itemToModify) {
    bool isFound = false;

    //walks through vector to find item, updates quantity if found
    for(unsigned int i = 0; i < cartItems.size(); ++i) {
        if(cartItems[i].GetName() == itemToModify.GetName()){
            isFound = true;

            //check to make sure that default constructor is not present before updating
            if(!(cartItems[i].GetDescription() == "none" && cartItems[i].GetPrice() == 0.0 && cartItems[i].GetQuantity() == 0)) {
                cartItems[i].SetQuantity(itemToModify.GetQuantity());
                break;
            }
        }
    }


    // prints error message if item is not found in cart
    if(isFound == false){
            cout << "Item not found in cart. Nothing modified." << endl;
    }
}


/*
* Name: GetNumItemsInCart
* Description: gets the number of items in cart
* Parameters: none
* Return: int - number of items currently in cart
*/
int ShoppingCart::GetNumItemsInCart() {
    int totalQuantity = 0;
    ItemToPurchase currentItem;

    //walks through vector to get the quantity for each item, keeps a running total
    for(unsigned int i = 0; i < cartItems.size(); ++i) {
        currentItem = cartItems[i];
        totalQuantity += currentItem.GetQuantity();
    }

    return totalQuantity;
}


/*
* Name: GetCostOfCart
* Description: gets the total cost of items in cart
* Parameters: none
* Return: float - returns total purchase cost of all times
*/
float ShoppingCart::GetCostOfCart() {
    float totalCostOfCart = 0.0;
    ItemToPurchase currentItem;


    //walks through vector to get running total of the cost of all the items
    for(unsigned int i = 0; i < cartItems.size(); ++i){
        currentItem = cartItems[i];
        totalCostOfCart += currentItem.GetPrice() * currentItem.GetQuantity();
    }
    return totalCostOfCart;
}



/*
* Name: StringOfTotal
* Description: creates a string with all the cart information including customer name, date, total items,
 * StringOfItemCost for each item, and total cost of cart
* Parameters: none
* Return: string - with all cart information formatted correctly
*/
string ShoppingCart::StringOfTotal() {
    string stringOfTotal;
    ostringstream stringOfTotalOSS;

    //create header for cart information
    stringOfTotalOSS << fixed << setprecision(2);
    stringOfTotalOSS << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
    stringOfTotalOSS << "Number of Items: " << GetNumItemsInCart() << endl << endl;


    //checks if shopping cart is empty, if true - prints error message
    if (cartItems.size() == 0) {
        stringOfTotalOSS << "SHOPPING CART IS EMPTY" << endl;
    }

    // if cart is not empty - walks through the vector getting string of information for each item
    else {

        for (unsigned int i = 0; i < cartItems.size(); ++i) {
            ItemToPurchase currentItem = cartItems[i];

            stringOfTotalOSS << currentItem.StringOfItemCost() << endl;
        }

    }
    //adds the total cost for the cart to the string
    stringOfTotalOSS << endl << "Total: $" << GetCostOfCart() << endl << endl;

    //saves all the information into one string
    stringOfTotal = stringOfTotalOSS.str();

    return stringOfTotal;
}


/*
* Name: StringOfDescriptions
* Description: creates a string with all item names and descriptions for the cart
* Parameters: none
* Return: string - with all cart items names and descriptions formatted correctly
*/
string ShoppingCart::StringOfDescriptions() {
    string stringOfDescriptions;
    ostringstream  stringOfDescriptionsOSS;


    //creates header for and adds to stream
    stringOfDescriptionsOSS << fixed << setprecision(2);
    stringOfDescriptionsOSS << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl << endl;
    stringOfDescriptionsOSS << "Item Descriptions" << endl;

    // gets item description for each item in vector
    for(unsigned int i = 0; i < cartItems.size(); ++i) {
        ItemToPurchase currentItem = cartItems[i];

        stringOfDescriptionsOSS << currentItem.StringOfItemDescription() << endl;
    }

    // saves everything in the stream into a single string
    stringOfDescriptions = stringOfDescriptionsOSS.str();


    return stringOfDescriptions;
}
