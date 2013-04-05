// Name: Eddie Spencer
// Course: CSC 260, Section 1
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Assignment 4 Part 2
// Description: CPP File for Complex. Contains all methods and functions to create complex objects
// Filename: complex.cpp
// Last modified on: 10/25/12

#include "Complex.h"

//compelx object constructor
Complex::Complex (int r, int i)
{
    real = r;
    imag = i;
}

//returns the real value of a complex object
int Complex::getReal()
{
    return real;
}

//returns the imag value of a complex object
int Complex::getImag()
{
    return imag;
}

//creates complex object from addition of components
Complex Complex::operator+(const Complex& rhs)
{
    return (Complex(real + rhs.real, imag + rhs.imag));
}

//creates complex object from multiplication of components
Complex Complex::operator*(const Complex& rhs)
{
    Complex lhs;
    lhs.real = ((real*rhs.real) + (-1)*(imag*rhs.imag));
    lhs.imag = ((real*rhs.imag) + (imag*rhs.real));
    return lhs;
}

//sets complex numbers equal to each other's components
void Complex::operator=(const Complex& rhs)
{
    real = rhs.real;
    imag = rhs.imag;
}

//checks to see if a complex real component equals a number
bool Complex::operator==(int lhs)
{
    if ((real == lhs) && (imag == 0))
        return true;
    else
        return false;
}

//checks to see if a complex real component is not equal a number
bool Complex::operator!=(int lhs)
{
    if ((real == lhs) && (imag == 0))
        return false;
    else
        return true;
}

//will return false
bool Complex::operator<(int comp)
{
    return false;
}

//will return true
bool Complex::operator>(int comp)
{
    return true;
}

//adds integer and complex number
Complex operator+(int lhs, const Complex& rhs)
{
    return (Complex(lhs + rhs.real, rhs.imag));
}

//multiplies integer and complex number
Complex operator*(int lhs, const Complex& rhs)
{
    return (Complex(lhs*rhs.real, lhs*rhs.imag));
}

//intput operator to input the real and imag components
istream& operator>>(istream& input, Complex& rhs)
{
    input >> rhs.real >> rhs.imag;
    return input;
}

//output operator for complex
//handles many situations depending on sign of real and imag
ostream& operator<<(ostream& output, Complex& rhs)
{
    if (abs(rhs.imag) != 1)
    {
        if ((rhs.real != 0) && (rhs.imag > 0))
            output << "(" << rhs.real << " + " << rhs.imag << "i)";
        else if ((rhs.real != 0) && (rhs.imag < 0))
            output << "(" << rhs.real << " - " << abs(rhs.imag) << "i)";
        else if ((rhs.real == 0) && (rhs.imag > 0))
            output << "(" << rhs.imag << "i)";
        else if ((rhs.real == 0) && (rhs.imag < 0))
            output << "(" << rhs.imag << "i)";
        else
            output << rhs.real;
    }
    else
    {
        if ((rhs.real != 0) && (rhs.imag > 0))
            output << "(" << rhs.real << " + " << "i)";
        else if ((rhs.real != 0) && (rhs.imag < 0))
            output << "(" << rhs.real << " - " << "i)";
        else if ((rhs.real == 0) && (rhs.imag > 0))
            output << "(" << "i)";
        else if ((rhs.real == 0) && (rhs.imag < 0))
            output << "(" << "-" << "i)";
        else
            output << rhs.real;
    }
    return output;
}

