//
// Created by kregan on 11/15/22.
//

#ifndef FINALPROJECTSHOPPINGONLINE_SHOPPINGCART_H
#define FINALPROJECTSHOPPINGONLINE_SHOPPINGCART_H

#include "ItemToPurchase.h"
#include <string>
#include <vector>

class ShoppingCart{

public:

    //constructors
    ShoppingCart();
    ShoppingCart(string inputName, string inputDate);

    // member functions
    /*
    * Name: GetCustomerName
    * Description: gets customer name
    * Parameters: none
    * Return: string - customer's name
    */
    string GetCustomerName();


    /*
    * Name: GetDate
    * Description: gets date shopping cart was created
    * Parameters: none
    * Return: string - date of shopping cart
    */
    string GetDate();


    /*
    * Name: AddItem
    * Description: adds new item to end of cartItems vector
    * Parameters:
     * ItemToPurchase - object with all the new item's information to add to vector
    * Return: none/void
    */
    void AddItem(ItemToPurchase newItem);


    /*
    * Name: RemoveItem
    * Description: removes item from vector
    * Parameters:
     * string - name of item to be removed
    * Return: none/void
    */
    void RemoveItem(string itemName);


    /*
    * Name: ModifyItem
    * Description: modifies/updates item quantity in vector
    * Parameters:
     * ItemToPurchase - object with name of item and updated quantity
    * Return: none/void
    */
    void ModifyItem(ItemToPurchase itemToModify);


    /*
    * Name: GetNumItemsInCart
    * Description: gets the number of items in cart
    * Parameters: none
    * Return: int - number of items currently in cart
    */
    int GetNumItemsInCart();


    /*
    * Name: GetCostOfCart
    * Description: gets the total cost of items in cart
    * Parameters: none
    * Return: float - returns total purchase cost of all times
    */
    float GetCostOfCart();


    /*
    * Name: StringOfTotal
    * Description: creates a string with all the cart information including customer name, date, total itmes,
     * StringOfItemCost for each item, and total cost of cart
    * Parameters: none
    * Return: string - with all cart information formatted correctly
    */
    string StringOfTotal();


    /*
    * Name: StringOfDescriptions
    * Description: creates a string with all item names and descriptions for the cart
    * Parameters: none
    * Return: string - with all cart items names and descriptions formatted correctly
    */
    string StringOfDescriptions();

private:
    //private data variables for member functions
    string customerName;
    string currentDate;
    vector <ItemToPurchase> cartItems;


};


#endif //FINALPROJECTSHOPPINGONLINE_SHOPPINGCART_H
