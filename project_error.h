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
//      file_error(){}
//PRE:  none
//POST: objext exists
//
//      void PrintError()
//PRE:  none
//POST: prints file exception thrown error message
//
//      money_error() {}
//PRE:  none
//POST: objext exists
//
//      void PrintError()
//PRE:  none
//POST: prints money exception thrown error message
//
//      input_error() {}
//PRE:  none
//POST: creates input_error object for throwing
//
//      void PrintError()
//PRE:  none
//POST: prints input exception thrown error message

#ifndef _project_error
#define _project_error

#include <iostream>
#include <string>

class file_error
{
public:
    file_error(){}
    void PrintError() { std::cout << "\nThere was a file exception thrown.\n"; }
};

class input_error
{
public:
    input_error() {}
    void PrintError() { std::cout << "\nThere was a file input exception thrown.\n"; }
};

class money_error
{
public:
    money_error() {}
    void PrintError() { std::cout << "\nThere was a money exception thrown.\n"; }

};


#endif
