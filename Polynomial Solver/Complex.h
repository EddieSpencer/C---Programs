// Name: Eddie Spencer
// Course: CSC 260, Section 1
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Assignment 4 Part 2
// Description: header file for complex
// Filename: complex.h
// Last modified on: 10/23/12

#if!defined _Complex_h
#define _Complex_h

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

//-------------------------------------------------------------------------
//  Class: Complex
//
//  The Complex class is created to maintain and store the data
//  that makes up a complex number used in mathematical applications
//
//---------------------------------------------------------------------

class Complex
{
private:
    //refers to the value that makes up the real part of the complex number
    int real;
    //refers to the value that makes up the imaginary part of the whole number
    int imag;
public:
    //-----------------------------------------------------------------
    //  complex(int = 0, int = 0)
    //
    //  Precondition: int parameter
    //  Postcondition: complex object created
    //
    //-------------------------------------------------------------
    Complex (int = 0, int = 0);
    //-----------------------------------------------------------------
    // int getReal()
    //
    //  Precondition: N/A
    //  Postcondition: real part returned
    //
    //-------------------------------------------------------------
    int getReal();
    //-----------------------------------------------------------------
    // int getReal()
    //
    //  Precondition: N/A
    //  Postcondition: real part returned
    //
    //-------------------------------------------------------------
    int getImag();
    //-----------------------------------------------------------------
    //  operator +(complex&)
    //
    //  Precondition: used with two complex objects
    //  Postcondition: complex object created
    //
    //-------------------------------------------------------------
    Complex operator+(const Complex&);
    //-----------------------------------------------------------------
    //  operator *(complex&)
    //
    //  Precondition: used with two complex objects
    //  Postcondition: complex object created
    //
    //-------------------------------------------------------------
    Complex operator*(const Complex&);
    //-----------------------------------------------------------------
    //  void operator =(const complex&)
    //
    //  Precondition: used with two integers
    //  Postcondition: complex object created
    //
    //--------------------------------------------------------
    void operator=(const Complex&);
    //----------------------------------------------------------------
    //  operator ==(int&)
    //
    //  Precondition: used with two int
    //  Postcondition: comparison generated
    //
    //-------------------------------------------------------------
    bool operator==(int);
    //-----------------------------------------------------------------
    //  operator !=(int)
    //
    //  Precondition: used with two int
    //  Postcondition: comparison generates a bool
    //
    //-------------------------------------------------------------
    bool operator!=(int);
    //-----------------------------------------------------------------
    //  operator <(int)
    //
    //  Precondition: used with two ints
    //  Postcondition: comparison generates a bool
    //
    //--------------------------------------------------------
    bool operator<(int);
    
    //-------------------------------------------------------------------------
    //  operator >(int)
    //
    //  Precondition: used with two ints
    //  Postcondition: comparison generates a bool
    //
    //--------------------------------------
    bool operator>(int);

    //-----------------------------------------------------------------
    //  operator +(int, complex&)
    //
    //  Precondition: used with complex and int
    //  Postcondition: complex object created
    //
    //-------------------------------------------------------------
friend Complex operator+(int, const Complex&);
    //-----------------------------------------------------------------
    //  operator *(int,complex&)
    //
    //  Precondition: used with complex and int
    //  Postcondition: complex object created
    //
    //-------------------------------------------------------------
friend Complex operator*(int, const Complex&);
    //-------------------------------------------------------------------------
    //  operator<<(ostream&, complex&)
    //
    //  Precondition: used with complex object
    //  Postcondition: complex output
    //
    //-------------------------------------
friend ostream& operator<<(ostream&, Complex&);
    //-------------------------------------------------------------------------
    //  operator>>(ostream&, complex&)
    //
    //  Precondition: used with complex object
    //  Postcondition: complex input
    //
    //-----------------------------------
friend istream& operator>>(istream&, Complex&);
};


#endif
