
// Name:		Robert Perlstein
// Date:        11/1/11
// Class:       CSCI 2312
// Assignment:  pa6.cpp - Loan Data Analysis
// Purpose:
// Filename:
///////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _darray
#define _darray

#include <iostream>

//    darray(unsigned);
// PRE:     None
// POST:    Creates darray object with a certain capacity

//    unsigned Capacity() const;
// PRE:     darray exists
// POST:    returns cap

//    unsigned Size() const;
// PRE:     darray exists
// POST:    returns length

//    const T& operator [] (unsigned) const;
// PRE:     darray exists
// POST:    returns indexed data object

//      void Clear();
//PRE:  None
//POST: Clears any free store memory if it exists

//    T& operator [] (unsigned);
// PRE:     darray exists
// POST:    returns indexed data object, can be edited

//    void PushBack(const T&);
// PRE:     darray exists
// POST:    Adds new object to array, increases th lngth. If the array is at capacity, creates new array with larger capacity

//    void PopBack();
// PRE:     darray exists, has length>0
// POST:    darray "loses" one object

//    darray& operator = (const darray&);
// PRE:     darray exists
// POST:    assignes the data, cap, and length of another darray

template< typename T >
class darray
{
public:

    typedef unsigned size_type;

    // Constructors
    darray();
    darray(const darray<T>&);
    darray(unsigned);

    ~darray();

    // Accessors
    unsigned Capacity() const;
    unsigned Size() const;
    const T& operator [] ( unsigned ) const;

    // Modifiers
    T& operator [] ( unsigned );
    void PushBack( const T& );
    void PopBack();
    void Clear();


    // Operators
    darray<T>& operator = ( const darray& );


private:
    T* data;
    unsigned cap, length;
};

// For GCC with windowss use the following:
#include "darray.tem.h"
// For GCC with linux or OSX, use the following:
//#include "darray.tem"

#endif

