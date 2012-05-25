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

#include "shopper.h"

shopper::shopper()
{
    GenerateMoney();
}

shopper::~shopper()
{}

double const shopper::GetMoney() const
{
    return money;
}

darray<inventory>& shopper::GetCart()
{
    return cart;
}


void shopper::SetMoney( double m )
{
    money = m;
}



void shopper::GenerateMoney()
{
    money = (rand()%20 + 50) + ((rand()%99)*.01);
}

void shopper::Buy( inventory& item )
{
    try {
        if( item.GetPrice() > money ) {
            throw money_error();
        }

        cart.PushBack( item );
        money = (money - item.GetPrice());
    }
    catch( money_error m )   {
        std::cout << "\nYou ran out of money, you unfrugal mess of a person!\n";
    }

}
