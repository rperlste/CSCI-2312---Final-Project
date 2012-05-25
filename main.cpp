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


#include <iostream>
#include <cstdlib>
#include <ctime>

#include "project_functions.h"
#include "inventory.h"
#include "shopper.h"
#include "store.h"

using namespace std;

int main( int argc, const char* argv[] )
{
    bool cont_shop;
    std::srand(std::time(0));

    project_functions::GreetUser();

    cont_shop = project_functions::KeepShopping( true );

    while( cont_shop == true )  {
        project_functions::GoShopping( argv[1] );
        project_functions::PressEnterToContinue();
        cont_shop = project_functions::KeepShopping( false );
    }

}
