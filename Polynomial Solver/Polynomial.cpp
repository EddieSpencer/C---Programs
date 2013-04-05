// Name: Eddie Spencer
// Course: CSC 260, Section 1
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Assignment 4 Part 2
// Description: CPP File for Polynomial. This encompasses all of the major operations of the
//				program. It is set up for templates to accept integers, floats, doubles, and complex terms.
// Filename: Polynomial.cpp
// Last modified on: 10/25/12

#include "Polynomial.h"

//constructor for polynomial object
template <class T>
Polynomial<T>::Polynomial()
{//initialize size variable to 0
    size = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {//sets the coefficient and degree of each element in the array to 0
        poly[i].setCoeff(0);
        poly[i].setDeg(0);
    }
}

//overloaded equals operator to set polynomials equal to each other
template <class T>
Polynomial<T> Polynomial<T>::operator=(const Polynomial<T>& polytemp)
{
    //takes the elements of one polynomial and saves into the other
    for (int i = 0; i < polytemp.size; i++)
        poly[i] = polytemp.poly[i];
    
    //accounts for the limit of only 10 terms in an array, removes excess.
    if (size > polytemp.size)
    {
        //resets the coefficients and degree back to original values.
    	for (int i = size; i < polytemp.size; i++)
    	{
    		poly[i].setCoeff(0);
    		poly[i].setDeg(0);
    	}
    }
    
    //sets the size of one poly to another
    size = polytemp.size;
    
    //returns a pointer of the poly array
    return *this;
}

//evaluate method to find the value of a polynomial
template <class T>
T Polynomial<T>::evalPoly(double x)
{
    T result = 0;
    
    //goes through each element of a polynomial
    //raises the input value to the degree and multiplies by the coefficient
    for (int i = 0; i < size; i++)
        result = result + ((pow(x,poly[i].getDeg()))*poly[i].getCoeff());
    //returns evaluated result
    return result;
}

//overloaded multiplication operator for two polynomials
template <class T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T>& polytemp)
{
    //instantiate an array of terms of template T
    Term<T> temp[MAX_SIZE];
    
    //initialize initial variables and results
    int f = 0;
    //checks to see if an element is already present in an array
    bool isInclude = true;
    Polynomial result;
    
    //nested for loops to multiply the elements of one array by another
	//this will multiply the first element of the first array by all the elements of the second array
	//and then continue this process for each element of the first array while simplifying the result

    for (int i = 0; i < size; i++)
        for (int j = 0; j < polytemp.size; j++)
        {//temp variable for one of the polynomials
            Term<T> temp1 = polytemp.poly[j];
            //this will create a new term object that is the multiplication of the coefficients and the
			//addition of the degrees, following basic math rules
            Term<T> temp2 (poly[i].getCoeff() * temp1.getCoeff(), poly[i].getDeg() + temp1.getDeg());
            
            //this exists as a simplification method to determine if the degree of temp2
			//has already been put into the array
            for (int k = 0; k < MAX_SIZE; k++)
            {//searches for matching degrees among the temporary array and the new temporary term
                if (temp[k].getDeg() == temp2.getDeg())
                {
                    if (temp[k].getCoeff() != 0)
                    {//instead of adding duplicate terms of the same degree this will combine their coefficients using additon
                        temp[k].setCoeff(temp[k].getCoeff() + temp2.getCoeff());
                        isInclude = false;
                    }
                }
            }
            //if not already present, it will be added
            if (isInclude)
            {//the variable is set in the temporary array
                temp[f] = temp2;
                f++;
                if (result.size < MAX_SIZE)
                	result.size++;
            }
            else
                isInclude = true;
        }
    
    //After the elements are added into the temorary array they are sorted by degree and coefficient
    result.sort(temp, f);
    //returns the polynomial result
    return result;
}

//polynomial addition of two polynomial arrays of terms
template <class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& polytemp)
{//initialize variables and counting operands
    //twice as large as max size to account for addition
    Term<T> temp[MAX_SIZE*2];
    //checks to determine if the present item is already in the array
    bool isInclude = true;
    //indexing variable
    int f = 0;
    Polynomial result;
    
    //adds the elements in the array into a temporary array
    for (int i = 0; i < size; i++)
        temp[i] = poly[i];
    
    //sets the size equal to the polynomial size
    result.size = size;
    f = size;
    
    //nested for loops to add the elements of one array by another
	//this will add the first element of the first array by all the elements of the second array
	//and then continue this process for each element of the first array while simplifying the result
    for (int i = 0; i < polytemp.size; i++)
    {//temporary polynomial array of terms
        Term<T> temp2 = polytemp.poly[i];
        
        //simple check to see if element's degree is already in the array
        //if so, it will add the coefficients
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (temp[j].getDeg() == temp2.getDeg())
            {
                if (temp[j].getCoeff() != 0)
                {//adds coefficients and resets flag
                    temp[j].setCoeff(temp[j].getCoeff() + temp2.getCoeff());
                    isInclude = false;
                }
            }
        }
        //if the flag is true, adds to the array
        if (isInclude)
        {//checks to make sure the size is less that 10
            if (result.size < MAX_SIZE)
            	result.size++;
            temp[f] = temp2;
            f++;
        }
        else
            isInclude = true;
    }
    
    //After the elements are added into the temorary array they are sorted by degree and coefficient
    //sorts array from highest to lowest term at the given index
    result.sort(temp, f);
    //returns result
    return result;
}

//writes the polynomial output to a file
template <class T>
void Polynomial<T>::writeToFile()
{//creates an outstream object
    int count = 0;
    ofstream fout;
    
    fout.open("output.txt");  
    
    //the number of terms
    fout << size;
    
    //output each term in the polynomial
    while (count < size)
    {
        Term<T> temp = poly[count];
        T temp2 = temp.getCoeff();
        fout << " " << temp2 << " " << temp.getDeg();
        count++;
    }
    //closes the output 
    fout.close();
}

//writes the polynomial complex output to a file
template <class T>
void Polynomial<T>::complexWriteToFile()
{//creates an outstream object
    int count = 0;
    ofstream fout;
    
    fout.open("complexOutput.txt");  
    
    //output number of terms
    fout << size;
    
    //output each term in the polynomial
    while (count < size)
    {//output real, imag, deg
        Term<T> temp = poly[count];
        T temp2 = temp.getCoeff();
        fout << " " << temp2.getReal() << " " << temp2.getImag() << " " << temp.getDeg();
        count++;
    }
    //closes the output
    fout.close();
}

//sorting method to reorganize the array from highest to lowest
//takes a polynomial array of terms to be sorted
template <class T>
void Polynomial<T>::sort(Term<T> toBeSorted[], int f)
{	
	int sortCount = 0;
	    //adds terms to temp to find the highest one and removes them as they are reordered
    while (sortCount < size)
    {
        int coeffMax = 0;
        int degMax = 0;

        for (int i = 0; i < f; i++)
        {   //checks if the degree is greater than the max
            if (toBeSorted[i].getDeg() > degMax)
            {//if it is greater, sets the highest degree to the current term
                degMax = toBeSorted[i].getDeg();
                //sets the max coefficient to the current term
                coeffMax = i;
            }//if the degree is the same, sort by coefficient
            if (toBeSorted[i].getDeg() == degMax)
            {//if the coefficient is non zero
                if (toBeSorted[i].getCoeff() != 0)
                {//sets the max coefficients and degree in the sort
                    degMax = toBeSorted[i].getDeg();
                    coeffMax = i;
                }
            }
        }

        poly[sortCount] = toBeSorted[coeffMax];
        toBeSorted[coeffMax].setCoeff(0);
        toBeSorted[coeffMax].setDeg(0);
        sortCount++;
    }
}

//creates polynomial term from input
template <class S>
istream& operator>>(istream& input, Polynomial<S>& polytemp)
{//size of the polynomial
    int size = 0;
    Term<S> tempoly[MAX_SIZE];
    bool tryAgain = true;
    bool isInclude = true;
    
    //iterates through the polynomial and sets each term to 0
    if (polytemp.size != 0)
    {
    	for (int i = 0; i <polytemp.size; i++)
    	{
    		polytemp.poly[i].setCoeff(0);
    		polytemp.poly[i].setDeg(0);
    	}
    }

   
 //sets the size of the temporary array to the size
    while (tryAgain)
    {
        //input size, number of terms
        input >> size;
        //if the size is a noninteger character, pauses program and displays message
        if (input.fail())
        {   //clears input and pauses process
            cout << "Invalid Input. Must be Integer" << endl;
            input.clear();
            input.ignore(1000, '\n');
        }
        //if the size is greater than the max or less than 1
        else if ((size < 1) || (size > 10))
            cout << "Invalid Input. Must be between 1-10" << endl;
        else
            tryAgain = false;
    }
    //sets the size
    polytemp.size = size;
    
    //for loop to add terms back into the array after size is found
    for (int i = 0; i < size; i++)
    {   //temporary array to fill in
        Term<S> temp1;
        //input the terms
        input >> temp1;

        //checks to see if the terms degree is already included in the array
	    //if so adds the coefficients
            for (int j = 0; j < 10; j++)
            {
                if (tempoly[j].getDeg() == temp1.getDeg())
                {
                    if (tempoly[j].getCoeff() != 0)
                    {//adds coefficients if degree is the same
                        tempoly[j].setCoeff(tempoly[j].getCoeff() + temp1.getCoeff());
                        isInclude = false;
                    }
                }
            }
            //if the degree is not in the array, add it to the array
            if (isInclude)
                tempoly[i] = temp1;
            else
                 isInclude = true;
    }
    //prepares array for next operations
    //sorts it based on the size
    polytemp.sort(tempoly, size);
    
    return input;
}

//output polynomial with its terms in the correct sign
template <class S>
ostream& operator<<(ostream& output, Polynomial<S>& polytemp)
{
    //outputs a negative sign if the coefficient is below 0
    if (polytemp.poly[0].getCoeff() < 0)
        output << "-";
    //checks to see if the term is included and non zero
    bool isInclude = true;
    //iterates through size of polynomial
    for (int i = 0; i < polytemp.size; i++)
    {//sets the terms of polytemp into the temp term
        Term<S> temp = polytemp.poly[i];
        if (temp.getCoeff() != 0)
            //resets flag to false
            isInclude = false;
    }
    //if the element is not included, it will output the correct sign
    if (!isInclude)
    {   //iterate through the polynomial
        for (int i = 0; i < polytemp.size; i++)
        {//checks if the coefficient is not zero
            
            output << polytemp.poly[i];
                //checks the next element of the polynomial
                if ((i+1) < polytemp.size)
                {   //if the coeffcient is greater than 0, outputs a +
                    if (polytemp.poly[i+1].getCoeff() > 0)
                        output << " + ";
                    //if the output is negative, output -
                    else if (polytemp.poly[i+1].getCoeff() < 0)
                        output << " - ";
                    else//output nothing otherwise
                        output <"";
                }
            
        }
    }
    else
        //output 0 if none of the cases match
        output << "0";
    //returns formatted output
    output << endl;
    return output;
}