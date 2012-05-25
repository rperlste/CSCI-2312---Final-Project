// Name:		Robert Perlstein
// Date:        11/1/11
// Class:       CSCI 2312
// Assignment:  pa6.cpp - Loan Data Analysis
// Purpose:
// Filename:
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "darray.h"

//     Construction and destruction     //////////////////////////////
//////////////////////////////////////////////////////////////////////
template< typename T >
darray<T>::darray()
{
	data = 0;
	cap = 0;
	length = 0;
}

template< typename T >
darray<T>::darray( unsigned cap_value )
{
	data = 0;
	cap = cap_value;
	length = 0;
}

template< typename T >
darray<T>::~darray()
{
	delete [] data;
	data = 0;
	length = cap = 0;
}
//////////////////////////////////////////////////////////////////////


//    Modifiers    ///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
template< typename T >
void darray<T>::PushBack( const T& new_data )
{
	if( length >= cap )
	{
		T* temp = new T[cap+2];

		for( unsigned i = 0; i < length; i++ )
		{
			temp[i] = data[i];
		}

		delete [] data;
		data = temp;
		cap = cap+2;
	}
	data[length] = new_data;
	++length;
}

template< typename T >
void darray<T>::PopBack()
{
	if( length > 0)
	{
	    --length;
	}

}

template< typename T >
void darray<T>::Clear()
{
    if( length > 0)
    {
        delete [] data;
        cap = 0;
        length = 0;
    }
}

template< typename T >
T& darray<T>::operator [] (unsigned index)
{
	if( index > length )
	{
	    std::cout << "The index is too large, returning last value in array.";
	    return data[length];
	}
	return data[index];
}

//////////////////////////////////////////////////////////////////////


//     Accessors     /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
template< typename T >
typename darray<T>::size_type darray<T>::Capacity() const
{
	return cap;
}

template< typename T >
typename darray<T>::size_type darray<T>::Size() const
{
	return length;
}


//////////////////////////////////////////////////////////////////////


//     Operators      ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
template< typename T >
darray<T>& darray<T>::operator = ( const darray& darray1 )
{

	if( this != &darray1 )
	{
		T* temp = new T[darray1.cap];

		for( int i = 0; i < darray1.length; i++ )
		{
			temp[i] = darray1.data[i];
		}

		delete [] data;
		data = temp;
		cap = darray1.cap;
		length = darray1.length;
	}

	return *this;
}


template< typename T >
const T& darray<T>::operator [] ( unsigned index ) const
{
	if( index > length )
	{
	    std::cout << "The index is too large, returning last value in array.";
	    return data[length];
	}
	return data[index];
}




//////////////////////////////////////////////////////////////////////
