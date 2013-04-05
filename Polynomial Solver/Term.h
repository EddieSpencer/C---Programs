// Name: Eddie Spencer
// Course: CSC 260, Section 1
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Assignment 4 Part 2
// Description: Header file for Term. Holds the public and private variables as well as the
//				member and non member functions and methods of Term
// Filename: Term.h
// Last modified on: 10/25/12

#if!defined _Term_h
#define _Term_h

#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class Term
{
private:
    //stores two integers for coefficient and degree
    T coeff;
    int deg;
public:
    //-------------------------------------------------------------------------
    //  Term()
    //
    //  Precondition: N/A
    //  Postcondition: term object created
    //
    //--------------------------------------
    Term (T = 0, int = 0);
    //-------------------------------------------------------------------------
    //  getCoefficient()
    //
    //  Precondition: N/A
    //  Postcondition: coefficient returned
    //
    //-----------------------------------------------
    T getCoeff();
    //-------------------------------------------------------------------------
    //  setCoef(T)
    //
    //  Precondition: valid parameter
    //  Postcondition: coefficient set
    //
    //----------------------------------------------------------
    void setCoeff(T);
    //-------------------------------------------------------------------------
    //  getDeg()
    //
    //  Precondition: N/A
    //  Postcondition: degree returned
    //
    //-------------------------------------------------------------
    int getDeg();
    //-------------------------------------------------------------------------
    //  setDeg(T)
    //
    //  Precondition: valid parameter
    //  Postcondition: degree set
    //
    //-------------------------------------------
    void setDeg(int);
    //-------------------------------------------------------------------------
    //  operator =(const Term<T>&)
    //
    //  Precondition: used with two term objects
    //  Postcondition: comparison sets equal
    //
    //------------------------------------------------
    void operator=(const Term<T>&);
    //-------------------------------------------------------------------------
    //  operator<<(ostream&, Term<S>&)
    //
    //  Precondition: used with term object
    //  Postcondition: term output
    //
    //--------------------------------------------

	template <class S>    
	friend ostream& operator<<(ostream&, Term<S>&);
    //-------------------------------------------------------------------------
    //  operator>>(istream&, Term<S>&)
    //
    //  Precondition: used with term object
    //  Postcondition: term input
    //
    //--------------------------------------------------
	template <class S>
	friend istream& operator>>(istream&, Term<S>&);
};

#endif
