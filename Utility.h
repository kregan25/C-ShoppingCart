//
// Created by kregan on 11/15/22.
//

#include "ShoppingCart.h"


#ifndef FINALPROJECTSHOPPINGONLINE_UTILITY_H
#define FINALPROJECTSHOPPINGONLINE_UTILITY_H

//Prototypes

/*
 * Name: PrintMenu
 * Description: prints menu options for user
 * Parameters: none
 * Return: void/none
 */
void PrintMenu();

/*
 * Name: ExecuteMenu
 * Description: executes menu option based on user input
 * Parameters:
 *  userOption - character for menu option choice
 *  userCart - shopping cart object passed by reference
 * Return: void/none
 */
void ExecuteMenu(char userOption, ShoppingCart& userCart);



#endif //FINALPROJECTSHOPPINGONLINE_UTILITY_H
