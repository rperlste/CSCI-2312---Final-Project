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

#include "store.h"

store::store( std::string name_in, const char* file_in )
{
    name = name_in;
    GenerateCashier();
    GenerateStock( file_in );
}

store::~store()
{}

void store::GenerateCashier()
{
    int name_offset;
    std::string names[6] = {"John", "Sarah", "David", "Denice", "Charlie", "Dee"};
    darray< std::string > name_data;
    name_offset = rand() % 6;
    cashier = names[name_offset];
}

void store::PrintStock()
{
    for( unsigned i = 0; i < stock.Size(); i++ ) {
        std::cout << stock[i].GetCode() << "   " << stock[i].GetDescription() << "  " << stock[i].GetPrice() << "\n";
    }
}

void store::GenerateStock( const char* file_in )
{
    std::string temp_string;
//    double temp_price;
//int temp_code, temp_rand;
    inventory temp_inventory;
    darray< inventory > temp_stock;


    try {
        char temp_str[6];
        std::fstream fin( file_in );
        if( !fin ) {
            throw file_error();
        }

        while( !fin.eof() ) {
            std::getline( fin, temp_string, '|' );
            if( temp_string.length() != 4 && temp_string.length() != 0 ) {
                throw input_error();
            }
            for( unsigned i = 0; i < temp_string.length(); i++) {
                temp_str[i] = temp_string[i];
                if( isdigit( temp_string[i] ) == 0 ) {
                    throw input_error();
                }
            }

            temp_inventory.SetCode( atoi(temp_string.c_str()) );
            std::getline( fin, temp_string, '|' );
            temp_inventory.SetDescription( temp_string );
            std::getline( fin, temp_string );
            for( unsigned i = 0; i < temp_string.length(); i++) {
                temp_str[i] = temp_string[i];
                if( isdigit( temp_string[i] ) == 0 && temp_string[i] != '.' ) {
                    throw input_error();
                }
            }
            temp_inventory.SetPrice( atof(temp_string.c_str()) );

            if( temp_inventory.GetCode() != 0 ) {
                stock.PushBack( temp_inventory );
            }
        }

    fin.close();
    }
    catch( file_error f )    {
        f.PrintError();
        std::cout << "\nThere was no project_inventory.txt file found in the source code directory.";
        std::cout << "\n\nIf you would like to continue with the program, please update the directory";
        std::cout << "\nso that it contains a properly formatted project_inventory.txt\n";

        return exit(1);
    }
    catch( input_error i ) {
        i.PrintError();
        std::cout << "There is an error in the file format!\n";
        std::cout << "Make sure the file has a 4 digit code, delimited by the '|' character,\n";
        std::cout << "followed by the description, which is also delimited by '|'. The final\n";
        std::cout << "component is the price, which should be a double in format XX.XX, with\n";
        std::cout << "a newline following it or EOF()\n";
        std::cout << "For example: 2355|Tasty Treats|2.45 \n";

        return exit(1);
    }
}

inventory& store::Sell()
{
//    bool in_stock;
    int sell_offset;

    sell_offset = rand() % stock.Size();

    return stock[sell_offset];
}

void store::CheckOut( darray<inventory>& check_out )
{
    double bill = 0, tax = 0, quantity = 1;
    std::string temp_desc, poundage;
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.setf(std::ios::showpoint);

    if( check_out.Size() == 0 ){
        std::cerr << "\nYou didn't go shopping for anything!\n\n";
        return;
    }

    std::cout << std::setprecision( 2 );
    std::cout << "\n\n\n      888    d8P  8888888 888b    888  .d8888b.       \n";
    std::cout << "      888   d8P     888   8888b   888 d88P  Y88b      \n";
    std::cout << "      888  d8P      888   88888b  888 888    888      \n";
    std::cout << "      888d88K       888   888Y88b 888 888             \n";
    std::cout << "      8888888b      888   888 Y88b888 888  88888      \n";
    std::cout << "      888  Y88b     888   888  Y88888 888    888      \n";
    std::cout << "      888   Y88b    888   888   Y8888 Y88b  d88P      \n";
    std::cout << "      888    Y88b 8888888 888    Y888  \"Y8888P88     \n";
    std::cout << "     _____                                            \n";
    std::cout << "    (        __.    __.   ,___,   ___  .___    ____   \n";
    std::cout << "     `--.  .'   \\ .'   \\ |    \\ .'   ` /   \\  (       \n";
    std::cout << "        |  |    | |    | |    | |----' |   '  `--.    \n";
    std::cout << "   \\___.'   `._.'  `._.' |`---' `.___, /     \\___.'   \n";
    std::cout << "                         \\                             \n";
    std::cout << "                     BRONCOS COUNTRY               \n\n";
    std::cout << "              Welcome to King Soopers #" << (rand()%1000) <<  "\n";
    std::cout << "              12345 West Street Road North                    \n";
    std::cout << "              That City, CO 80999                             \n";
    std::cout << "              (303)-999-5555                                  \n";
    std::cout << "              Your cashier was " << cashier << "\n\n";


    for( unsigned i = 0; i < check_out.Size(); i++ ) {

        poundage = "";
        quantity = 1;
        temp_desc = check_out[i].GetDescription();

        for( int j = 0; j < 4; j++ ) {
            poundage += temp_desc[j];
        }
        if( poundage == "1 lb" ){
            quantity = rand()%3 + 1;
        }



        std::cout << "          " << check_out[i].GetDescription() << std::setw(40 - check_out[i].GetDescription().length() ) << check_out[i].GetPrice()*quantity << " X\n";
        if( quantity > 1 ) {
            std::cout << "       " << quantity <<" @ " << check_out[i].GetPrice() << "\n";
        }
        bill += check_out[i].GetPrice()*quantity;
    }

    tax = bill*0.02;
    std::cout << "\n\n   Valued Customer                   ************9876" << "\n";
    std::cout << "          TAX                                 " << tax << "\n";

    if( bill > 9.99 ) {
        std::cout << "     **** BALANCE                            " << bill << "\n";
    }
    else {
        std::cout << "     **** BALANCE                             " << bill << "\n";
    }

    std::cout << "\n\n   VISA Purchase\n   ************4657";
    std::cout << "\n   TOTAL: " << bill;
    std::cout << "\n   REF#: " << rand() << "\n\n";

}
