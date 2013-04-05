// Name: Eddie Spencer
// Course: CSC 260, Section 1
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Assignment 4 Part 2
// Description: CPP file for Term. This contains the methods and operations
//				for sucessfully creating Term objects of type integer, float, double, and complex
//				to be stored into polynomial arrays.
// Filename: Term.cpp
// Last modified on: 10/25/12

#include "Term.h"

//constructor for Term object
template <class T>
Term<T>::Term (T c, int d)
{
    coeff = c;
    deg = d;
}

//accessor method to get the coeff of a term
template <class T>
T Term<T>::getCoeff()
{
    return coeff;
}

//mutator method to set the coeff of a term
template <class T>
void Term<T>::setCoeff(T a)
{
    coeff = a;
}

//accessor method to get the deg of a term
template <class T>
int Term<T>::getDeg()
{
    return deg;
}

//mutator method to set the deg of a term
template <class T>
void Term<T>::setDeg(int a)
{//checks to make sure the degree is not below zero (negative)
    if (a >= 0)
        deg = a;
}

//overload = operator to set a term equal to another term
template <class T>
void Term<T>::operator=(const Term<T>& temp)
{
    coeff = temp.coeff;
    deg = temp.deg;
}

//overload << operator to output term
template <class S>
ostream& operator<<(ostream& output, Term<S>& obj)
{//normal case if the coefficient and degree are greater than 1
    if(obj.coeff != 0 && obj.coeff != 1 && obj.deg != 0 && obj.deg!= 1)
    {
        cout<<"("<<obj.coeff<<")"<<"x^"<<"("<<obj.deg<<")";
    }
    //case if the coefficient is 1 and the degree is greater than 1
	//this will print the coefficient as an implied 1
    else if(obj.coeff == 1 && obj.deg != 0 && obj.deg != 1)
    {
        cout<<"(1)x^"<<"("<<obj.deg<<")";
    }
    //if the degree of the term is 0, it will return 1. 
	//x^0 = 1
    else if(obj.deg == 0)
    {
        cout<<1;
    }
    //if the degree of the term is one, only the coefficient will be displayed
    else if(obj.deg == 1)
    {
        cout<<"("<<obj.coeff<<")"<<"x";
    }
    //if the coefficient is 0, the entire term is reduced to 0
    else if(obj.coeff == 0)
    {
        cout<<0;
    }
    return output;
}
//input stream overloaded operator for Term input
template <class S>
istream& operator>>(istream& input, Term<S>& temp)
{
    int tempDeg;
	//sets input flag to true, will change for error input
    bool inputError = true;
	//gets the coefficient and temp degree
    input >> temp.coeff>> tempDeg;
	//check to make sure that the degree is valid
	//if it is valid, sets the degree
    if (tempDeg >=0)
        temp.deg = tempDeg;
	//if the degree is less than 0, input new data
    else
    {
        //prompts user for new input
        cout << "Degree must be greater than 0. Input degree: " << endl;
        while (inputError)
        {
            cin >> tempDeg;
            //checks to make sure that the input is a valid int
            //if not an int, pauses the output to display message
            if (cin.fail())
            {
                cout << "Invalid input. Input an integer " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            //if degree is less than 0
            else if (tempDeg < 0)
                cout << "Invalid input. Degree must be greater than 0: " << endl;
            else
                //resets flag
                inputError = false;
        }
     }
    //returns input stream
    return input;
}