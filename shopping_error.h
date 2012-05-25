// Name:		Robert Perlstein
// Date:		11-21-11
// Class:		CSCI 2312
// Assignment:	Final Project - Grocery Store
// Purpose:     This program is an amazingly realistic simulation of a shopping
//              adventure at a grocery store done by a person who chooses
//              what products to buy at random, given the guidance of an all-powerful
//              overlord who sets a limit on how many things this totslly whacky
//              and random shopper can purchase.
// Filename:
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _shopping_error
#define _shopping_error

#include <iostream>


class shopping_error
{
public:
    shopping_error(){}
    shopping_error( const shopping_error& );

    virtual void PrintError() = 0;
};

class neg_count:public shopping_error
{
public:
    neg_count(){}
    neg_count( const neg_count& );

    void PrintError(){ return std::cout << "Cannot buy negative items."; }
}

class file_error:public shopping_error
{
public:
    file_error(){}
    file_error( const file_error& );

    void PrintError(){ return std::cout << "File could not be opened."; }
}

class money_error:public shopping_error
{
public:
    money_error(){}
    money_error( const money_error& );

    void PrintError() { return std::cout << "You cannot afford to make this purchase."; }
}
