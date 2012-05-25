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

#include "inventory.h"

inventory::inventory()
{
    description = "";
    price = 0;
    code = 0;
}

inventory::inventory( inventory& i )
{
    description = i.GetDescription();
    price = i.GetPrice();
    code = i.GetCode();
}

inventory::inventory( std::string s, double p, int c )
{
    description = s;
    price = p;
    code =c;
}

std::string const inventory::GetDescription() const
{
    return description;
}

double const inventory::GetPrice() const
{
    return price;
}

int const inventory::GetCode() const
{
    return code;
}

void inventory::SetDescription( std::string d_in )
{
    description = d_in;
}

void inventory::SetPrice( double p_in )
{
    price = p_in;
}

void inventory::SetCode( int c_in )
{
    code = c_in;
}



