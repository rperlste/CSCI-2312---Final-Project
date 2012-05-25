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
//      shopper();
//PRE:  none
//POST: creates shopper object with randomly generated
//
//      shopper( shopper& );
//PRE:  none
//POST: Copy Constructor
//
//      shopper( double m ):money(m)    {}
//PRE:  none
//POST: creates shopper with preset amount of money
//
//      ~shopper();
//PRE:  object exists
//POST: No special actions are taken. Compiler imples the destruction of the darray data member properly
//
//      double GetMoney();
//PRE:  none
//POST: returns double money
//
//      darray<inventory>& GetCart();
//PRE:  darray header included
//POST: returns a the cart by reference
//
//      void GenerateMoney();
//PRE:  none
//POST: Generates a money value in range $30.00 - 70.99
//
//      void SetMoney(  double );
//PRE:  none
//POST: set money data member
//
//      void Buy( inventory& );
//PRE:  none
//POST: Pushes cart back with argument inventory item

#ifndef _shopper
#define _shopper

#include <iostream>
#include <cstdlib>
#include <string>

#include "darray.h"
#include "inventory.h"
#include "store.h"

class shopper
{
public:
    // Construction
    shopper();
    shopper( shopper& );
    shopper( double m ):money(m)    {}

    ~shopper();

    // Accessors
    double const GetMoney() const;
    darray<inventory>& GetCart();

    // Manipulators
    void GenerateMoney();
    void SetMoney(  double );
    void Buy( inventory& );

private:

    darray<inventory> cart;
    double money;
};

#endif
