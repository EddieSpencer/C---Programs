// Name: Eddie Spencer
// Course: CSC 260, Section 1
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Assignment 4 Part 2
// Description: Header file for Polynomial. Contains the class's private
//				and public variables, member and non member functions
// Filename: Polynomial.h
// Last modified on: 10/23/12

#if!defined _Polynomial_h
#define _Polynomial_h

#include <iostream>
#include <cmath>
#include <fstream>
#include "Term.cpp"
using namespace std;

const int MAX_SIZE = 10;

template <class T>
class Polynomial
{
private:
    //array of polynomials 
    Term<T> poly[MAX_SIZE];
    //size
    int size;
public:
    //-------------------------------------------------------------------------
    //  Polynomial()
    //
    //  Precondition: N/A
    //  Postcondition: polynomial object created
    //
    //------------------------------------------------
    Polynomial();
    //  operator=(Polynomial<T>
    //
    //  Precondition: N/A
    //  Postcondition:const polynomial set equal to another polynomial
    //
    //------------------------------------------------
    Polynomial<T> operator=(const Polynomial<T>&);
     //-------------------------------------------------------------------------
    //  operator+(Polynomial<T>&)
    //
    //  Precondition: used with two polynomial objects
    //  Postcondition: polynomial object created
    //
    //----------------------------------------------------
    Polynomial<T> operator+(const Polynomial<T>&);
    //-------------------------------------------------------------------------
    //  operator*(Polynomial<T>&)
    //
    //  Precondition: used with two polynomial objects
    //  Postcondition: polynomial object created
    //
    //------------------------------------------------
    Polynomial<T> operator*(const Polynomial<T>&);
    //-------------------------------------------------------------------------
    //  writeToFile()
    //
    //  Precondition: valid polynomial
    //  Postcondition: polynomial output to file
    //
    //-----------------------------------------------------
    void writeToFile();
    //-------------------------------------------------------------------------
    //  complexwriteToFile()
    //
    //  Precondition: valid polynomial
    //  Postcondition: polynomial output to file
    //
    //-----------------------------------------------------
    void complexWriteToFile();
    
    //-------------------------------------------------------------------------
    //  evalPoly(double)
    //
    //  Precondition: valid parameter
    //  Postcondition: polynomial evaluated
    //
    //-------------------------------------------------
    T evalPoly(double);
    //-------------------------------------------------------------------------
    //  sort(Term T [], int)
    //
    //  Precondition: N/A
    //  Postcondition: polynomial sorted based on index
    //
    //--------------------------------------------------
    void sort(Term<T>[], int);
    //-------------------------------------------------------------------------
    //  operator>>(ifstream&, Polynomial<S>&)
    //
    //  Precondition: used with polynomial object
    //  Postcondition: polynomial input
    //
    //--------------------------------------------------------
	template <class S>
	friend istream& operator>>(istream&, Polynomial<S>&);
    //-------------------------------------------------------------------------
    //  operator<<(ostream&, Polynomial<S>&)
    //
    //  Precondition: used with polynomial object
    //  Postcondition: polynomial output
    //
    //-------------------------------------------------------
    template <class S>
	friend ostream& operator<<(ostream&, Polynomial<S>&);
};

#endif
