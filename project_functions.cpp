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

#include "project_functions.h"
#include "inventory.h"
#include "shopper.h"
#include "store.h"

void project_functions::GreetUser()
{
    std::cout << "This program is an amazingly realistic simulation of a shopping\n";
    std::cout << "adventure at a grocery store done by a person who chooses\n";
    std::cout << "what products to buy at random, given the guidance of an all-powerful\n";
    std::cout << "overlord who sets a limit on how many things this totally whacky\n";
    std::cout << "and random shopper can purchase.\n\n";
    std::cout << "As CSCI 2312's final assignment, this program incorpoartes nearly\n";
    std::cout << "every subject covered in the course of this fabulous semester.\n";
    std::cout << "Please pass the properly formatted project_inventory.txt file\n";
    std::cout << "as the second command line argument.\n";
}

void project_functions::PressEnterToContinue()
{
    std::cout << "Press ENTER to continue... ";
    fflush( stdout );
    std::cin.get();
    std::cin.ignore();
}

bool project_functions::KeepShopping( bool first_time )
{
    std::string user_choice;

    if( first_time == true )    {
        std::cout << "\n\nWant to go grocery shopping? Type \"Yes\" to shop, anything else exits: ";
        std::cin >> user_choice;
    }
    else    {
        std::cout << "\n\nType \"Yes\" to continue shopping, anything else exits: ";
        std::cin >> user_choice;
    }

    for( unsigned i = 0; i < user_choice.length(); i++ )     {
        user_choice[i] = toupper( user_choice[i]);
    }

    if( user_choice == "YES")   {
        return true;
    }
    else    {
        std::cout << "\n\nThank you for visiting King Soopers!\n\n";
        return false;
    }
}

void project_functions::GoShopping( const char* store_inv )
{

    store KingSoopers( "King Soopers", store_inv );
    shopper KingShopper;
    int item_count;
    bool is_pos = false;


    std::cout << "\n\nWelcome to King Soopers.\n";
    std::cout << "\nHow many different items do you want to buy (positive integer)? ";

   // while( is_pos != true ) {
   //do {
    while ( !( std::cin >> item_count ) ) {
        std::cerr << "\nBad input. Please enter positive integer: ";
        std::cin.clear();
        std::cin.ignore();
       // if( item_count > 0) {
        //    is_pos = true;
       // }
    }//} while ( item_count < 0 );
    /*
    do {
        std::cin >> item_count_str;
        if( item_count_str )
        }   while ( std::cin.fail() == true );
    */

    if( item_count < 0){
        std::cerr << "\nValue " << item_count << " converted to positive.\n";
        item_count = item_count*-1;

    }

    for( int i = 0; i < item_count; i++ ) {
        KingShopper.Buy( KingSoopers.Sell() );
    }


    KingSoopers.CheckOut( KingShopper.GetCart() );
}
