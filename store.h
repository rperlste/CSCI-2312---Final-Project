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
//
//      store();
//PRE:  none
//POST: creates unitialized store object
//
//      store( store& );
//PRE:  none
//POST: Copy constructor
//
//      store( std::string, const char* );
//PRE:  none
//POST: Creates a store with name initialized to first argument. Second argument is argv[1],
//      the file path for the project_inventory file. It is required to properly populate
//      the store's inventory.
//
//      ~store();
//PRE:  none
//POST: Destructor
//
//      void PrintStock();
//PRE:  none
//POST: prints the stock contents
//
//      void GenerateCashier();
//PRE:  none
//POST: Randomly selects and sets the cashier's name
//
//      void GenerateStock( const char* );
//PRE:  none
//POST: Creates darray of stock. If the argv[1] does not exist, or contains bad data
//      and exception is thrown the program will exit.
//
//      inventory& Sell();
//PRE:  stock exists
//POST: returns a random piece of stock
//
//      void CheckOut( darray<inventory>& );
//PRE:  accepts cart inventory
//POST: Prints receipt based on the cart passed to it



#ifndef _store
#define _store

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cctype>

#include "inventory.h"
#include "project_error.h"
#include "darray.h"

class store
{
public:

    store();
    store( store& );
    store( std::string, const char* );

    ~store();

    void PrintStock();

    void GenerateCashier();
    void GenerateStock( const char* );
    inventory& Sell();
    void CheckOut( darray<inventory>& );

private:

    std::string name, cashier;
    darray<inventory> stock;


};

#endif
