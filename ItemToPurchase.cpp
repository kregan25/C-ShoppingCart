//
// Created by kregan on 11/15/22.
//
#include <string>
#include <iostream>
#include <iomanip>
#include "ItemToPurchase.h"
using namespace std;

// default constructor
ItemToPurchase::ItemToPurchase(){
    itemName = "0";
    itemDescription = "0";
    itemPrice = 0;
    itemQuantity = 0;
}

// parameterized constructor
ItemToPurchase::ItemToPurchase(string name, string description, float price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}


/*
 * Name: SetName
 * Description: sets item name
 * Parameters:
 * string - name input from user
 * Return: void/none
 */
void ItemToPurchase::SetName(string name){
    itemName = name;
}


/*
* Name: GetName
* Description: gets item name
* Parameters: none
* Return: string - item's name
*/
string ItemToPurchase::GetName(){
    return itemName;
}


/*
 * Name: SetPrice
 * Description: sets item price
 * Parameters:
 * float - price input from user
 * Return: void/none
 */
void ItemToPurchase::SetPrice(float price) {
    itemPrice = price;
}


/*
* Name: GetPrice
* Description: gets item price
* Parameters: none
* Return: float - item's price
*/
float ItemToPurchase::GetPrice() {
    return itemPrice;
}


/*
 * Name: SetQuantity
 * Description: sets item quantity
 * Parameters:
 * int - quantity input from user
 * Return: void/none
 */
void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}


/*
* Name: GetQuantity
* Description: gets item quantity
* Parameters: none
* Return: int - item's quantity
*/
int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}


/*
 * Name: SetDescription
 * Description: sets item description
 * Parameters:
 * string - description input from user
 * Return: void/none
 */
void ItemToPurchase::SetDescription(string description){
    itemDescription = description;
}


/*
* Name: GetDescription
* Description: gets item description
* Parameters: none
* Return: string - item's description
*/
string ItemToPurchase::GetDescription(){
    return itemDescription;
}


/*
* Name: StringOfItemCost
* Description: creates a string with the item's name, description, price and quantity
* Parameters: none
* Return: string - with all the item's information
*/
string ItemToPurchase::StringOfItemCost(){
    ostringstream itemCostOSS;
    string ItemCost;
    float totalprice = GetPrice() * GetQuantity();

    itemCostOSS << fixed << setprecision(2);
    itemCostOSS << GetName() << " " << GetQuantity() << " @ $" << GetPrice() << " = $" << totalprice;
    ItemCost = itemCostOSS.str();
    return ItemCost;
}


/*
* Name: StringOfItemDescription
* Description: creates a string with the item's name and description
* Parameters: none
* Return: string - with all the item's name and description
*/
string ItemToPurchase::StringOfItemDescription(){
    ostringstream completeItemDescriptionOSS;
    string CompleteItemDescription;


    completeItemDescriptionOSS << GetName() << ": " << GetDescription();
    CompleteItemDescription = completeItemDescriptionOSS.str();
    return CompleteItemDescription;
}