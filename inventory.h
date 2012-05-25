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
//      inventory();
//PRE:  none
//POST: inventory item created, data memebers initialized to NULL
//
//      inventory( inventory& );
//PRE:  none
//POST: Creates an identical iventory item. New address.
//
//      inventory( std::string, double, int );
//PRE:  none
//POST: Initializes the values of the inventory item to arguments that have been passed.
//
//      std::string GetDescription();
//PRE:  none
//POST: returns string data member description
//
//      double GetPrice();
//PRE:  none
//POST: returns double data member price
//
//      int GetCode();
//PRE:  none
//POST: returns in data member code
//
//      void SetDescription( std::string );
//PRE:  none
//POST: Sets description to argument passes
//
//      void SetPrice( double );
//PRE:  none
//POST: Sets price to argument passed
//
//      void SetCode( int );
//PRE:  none
//POST: Sets code to argument passed
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _inventory
#define _inventory

#include <iostream>
#include <string>

class inventory
{
public:

    inventory();
    inventory( inventory& );
    inventory( std::string, double, int );

    std::string const GetDescription() const;
    double const GetPrice() const;
    int const GetCode() const;

    void SetDescription( std::string );
    void SetPrice( double );
    void SetCode( int );

private:

    std::string description;
    double price;
    int code;
};

#endif
