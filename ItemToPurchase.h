//
// Created by kregan on 11/15/22.
//


#ifndef FINALPROJECTSHOPPINGONLINE_ITEMTOPURCHASE_H
#define FINALPROJECTSHOPPINGONLINE_ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase{
    public:

        //constructors
        ItemToPurchase();
        ItemToPurchase(string name, string description, float price, int quantity);

        //public member functions


        /*
        * Name: SetName
        * Description: sets item name
        * Parameters:
        * string - name input from user
        * Return: void/none
        */
        void SetName(string name);


        /*
        * Name: GetName
        * Description: gets item name
        * Parameters: none
        * Return: string - item's name
        */
        string GetName();


        /*
        * Name: SetPrice
        * Description: sets item price
        * Parameters:
        * float - price input from user
        * Return: void/none
        */
        void SetPrice(float price);


        /*
        * Name: GetPrice
        * Description: gets item price
        * Parameters: none
        * Return: float - item's price
        */
        float GetPrice();


        /*
        * Name: SetQuantity
        * Description: sets item quantity
        * Parameters:
        * int - quantity input from user
        * Return: void/none
        */
        void SetQuantity(int quantity);


        /*
        * Name: GetQuantity
        * Description: gets item quantity
        * Parameters: none
        * Return: int - item's quantity
        */
        int GetQuantity();


        /*
        * Name: SetDescription
        * Description: sets item description
        * Parameters:
        * string - description input from user
        * Return: void/none
         */
        void SetDescription(string description);


        string GetDescription();


        /*
        * Name: StringOfItemCost
        * Description: creates a string with the item's name, description, price and quantity
        * Parameters: none
        * Return: string - with all the item's information
        */
        string StringOfItemCost();


        /*
        * Name: StringOfItemDescription
        * Description: creates a string with the item's name and description
        * Parameters: none
        * Return: string - with all the item's name and description
        */
        string StringOfItemDescription();

    private:

        // private variables for member functions
        string itemDescription;
        string itemName;
        float itemPrice;
        int itemQuantity;
};


#endif //FINALPROJECTSHOPPINGONLINE_ITEMTOPURCHASE_H
