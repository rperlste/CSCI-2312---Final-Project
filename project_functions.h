// Name:		Robert Perlstein
// Date:		11-21-11
// Class:		CSCI 2312
// Assignment:	Final Project - Grocery Store
// Purpose:     This program is an amazingly realistic simulation of a shopping
//              adventure at a grocery store done by a person who chooses
//              what products to buy at random, given the guidance of an all-powerful
//              overlord who sets a limit on how many things this totslly whacky
//              and random shopper can purchase.
///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
//
//      void GreetUser();
//PRE:  none
//POST: Prints a greeting with a brief decription about the program to the user.
//
//      void PressEnterToContinue();
//PRE:  none
//POST: Prompts the user to press enter, continues with program after return key keystroke
//
//      bool KeepShopping( bool );
//PRE:  none
//POST: Prompts user to continue shopping. Returns bool
//
//      void GoShopping( const char* );
//PRE:  none
//POST: The meat of the whole program. Utilizes all three new classes and the darray, for random access to a shopping cart.
//      Creates a KingSoopers store. Creates a shopper. Shopper is asked how many items they want to buy.
//      It then randomly selects items from the stores inventory. the cart is then passed to CheckOut in store.cpp
//
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _project_functions
#define _project_functions

#include <iostream>
#include <stdio.h>

#include "inventory.h"
#include "project_functions.h"
#include "shopper.h"
#include "store.h"

namespace project_functions
{
    void GreetUser();
    void PressEnterToContinue();
    bool KeepShopping( bool );
    void GoShopping( const char* );
}

#endif
