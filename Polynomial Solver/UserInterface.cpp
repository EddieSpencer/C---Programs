// Name: Eddie Spencer
// Course: CSC 260, Section 1
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Assignment 4 Part 2
// Description: CPP File for the User Interface.
//				This contains all of the user interaction with the program
//				The user is presented with a menu with select1s to choose from.
// Filename: UserInterface.cpp
// Last modified on: 10/25/12

#include <iostream>
#include "UserInterface.h"
#include "Polynomial.cpp"
#include "Complex.h"


void UserInterface::menu()
{
    //string used for input files
    string inFileName;
	//bool to check if the input was read correctly
    bool isFile = true;
	//input stream object
	ifstream fin;
	//output stream object
    ofstream fout;
	//creation of 12 polynomials of different types that will be manipulated by user
    Polynomial<int> poly1, poly2, poly3;
    Polynomial<float> poly4, poly5, poly6;
    Polynomial<double> poly7, poly8, poly9;
    Polynomial<Complex> poly10, poly11, poly12;
	//input variable for evaluation
    double x;
	//used for special case of complex evaluation
    Complex temp;   
    //user input throughout menu
    int select1, select2, operation;

    
        //presents the user with main menu, deciding which type of data to work with
        
        cout << "Select the data type you wish to work with: " << endl;
        cout << "1: Integer" << endl;
        cout << "2: Float" << endl;
        cout << "3: Double" << endl;
        cout << "4: Complex" << endl;       
		//reads in user's selection
		cin >> select1;
        
        //Switch statement for main menu
        switch (select1)
        {
            //User has selected Integer. Will input 2 polynomials   
            case 1:
                cout << "You have chosen Integer." << endl;
                cout << "Select how you wish to input data:" << endl;
                cout << "1. Keyboard\n2. Input File" << endl;
                cin >> select2;
                while (select2!=1 && select2!=2)
                {
                    cout << "Input error.\nPlease try again:" <<endl;
                    cin >> select2;
                }
                switch (select2)
            {	//Input from keyboard
                case 1:
                    cout << "Input first int term: " << endl;
                    cin >> poly1;
                    
                    cout << "Input second int term: " << endl;
                    cin >> poly2;
                    break;
                    
                case 2:
                    //input from file for two polynomials
                    do
                        {
                        cout << "Input file name to read from:" << endl;
                        cin >> inFileName;
                        fin.open(inFileName.c_str());
                        if (fin.fail())
                        {
                            cout <<"Input error." << endl;
                            cout << "Please try again." << endl;
                            fin.clear();
                            isFile = false;
                            
                        }
                        else
                            isFile = true;
                        
                        }while(!isFile);
                    
                        fin >> poly1;
                        fin.close();
                    do
                    {
                        cout << "Input file name to read from:" << endl;
                        cin >> inFileName;
                        fin.open(inFileName.c_str());
                        if (fin.fail())
                        {
                            cout <<"Input error." << endl;
                            cout << "Please try again." << endl;
                            fin.clear();
                            isFile = false;
                        }
                        else
                            isFile = true;
                        
                    }while(!isFile);
                        fin >> poly2;
                    fin.close();
                        
                    break;
            }
               
                
                //user presented with operations menu
                cout << "Select the operation you wish to perform: " << endl;
                cout << "1:  Addition" << endl;
                cout << "2:  Multiplication" << endl;
                cout << "3:  Evaluation" << endl;
                cout << "4:  Output to file" << endl;
                
                cin >> operation;
                //reads in the users choice and selects the appropriate operation
                switch (operation)
                {
                    case 1:
                        cout << "Addition of polynomials: " << endl;
                        poly3 = poly1 + poly2;
                        cout << poly3 << endl;
                        break;
                    case 2:
                        cout << "Multiplication of polynomials: " << endl;
                        poly3 = poly1 * poly2;
                        cout << poly3 << endl;
                        break;
                    case 3:
                        cout << "Input evaluation value: " << endl;
                        cin >> x;
                        cout << "Evaluating first polynomial with x = " << x << " equals: " << endl;
                        cout << poly1.evalPoly(x) << endl;
                        cout << "Evaluating second polynomial with x = " << x << " equals: " << endl;
                        cout << poly2.evalPoly(x) << endl;
                        break;
                    case 4:
                        cout << "Polynomial 1 written to output text file"<< endl;
                        poly1.writeToFile();
                }
                
                break;
            
            //User has selected Float. Will input 2 polynomials  
            case 2:
                cout << "You have chosen Float." << endl;
                cout << "Select how you wish to input data:" << endl;
                cout << "1. Keyboard\n2. Input File" << endl;
                cin >> select2;
                while (select2!=1 && select2!=2)
                {
                    cout << "Input error.\nPlease try again:" <<endl;
                    cin >> select2;
                }
                switch (select2)
            {
                case 1:
                    cout << "Input first float term: " << endl;
                    cin >> poly4;
                    
                    cout << "Input second float term: " << endl;
                    cin >> poly5;
                    break;
                    
                case 2:
                    
                    do
                    {
                        cout << "Input file name to read from:" << endl;
                        cin >> inFileName;
                        fin.open(inFileName.c_str());
                        if (fin.fail())
                        {
                            cout <<"Input error." << endl;
                            cout << "Please try again." << endl;
                            fin.clear();
                            isFile = false;
                            
                        }
                        else
                            isFile = true;
                        
                    }while(!isFile);
                    
                    fin >> poly4;
                    fin.close();
                    do
                    {
                        cout << "Input file name to read from:" << endl;
                        cin >> inFileName;
                        fin.open(inFileName.c_str());
                        if (fin.fail())
                        {
                            cout <<"Input error." << endl;
                            cout << "Please try again." << endl;
                            fin.clear();
                            isFile = false;
                        }
                        else
                            isFile = true;
                        
                    }while(!isFile);
                    fin >> poly5;
                    fin.close();
                    
                    break;
            }
                                
                //user presented with operations menu
                cout << "Select the operation you wish to perform: " << endl;
                cout << "1:  Addition" << endl;
                cout << "2:  Multiplication" << endl;
                cout << "3:  Evaluation" << endl;
                cout << "4:  Output to file" << endl;
                
               cin >> operation;
                
                 //reads in the users choice and selects the appropriate operation
                switch (operation)
                {
                    case 1:
                        cout << "Addition of polynomials: " << endl;
                        poly6 = poly4 + poly5;
                        cout << poly6 << endl;
                        break;
                    case 2:
                        cout << "Multiplication of polynomials: " << endl;
                        poly6 = poly4 * poly5;
                        cout << poly6 << endl;
                        break;
                    case 3:
                        cout << "Input evaluation value: " << endl;
                        cin >> x;
                        cout << "Evaluating first polynomial with x = " << x << " equals: " << endl;
                        cout << poly4.evalPoly(x) << endl;
                        cout << "Evaluating second polynomial with x = " << x << " equals: " << endl;
                        cout << poly5.evalPoly(x) << endl;

                        break;
                    case 4:
                        cout << "Polynomial 1 written to output text file"<< endl;
                        poly4.writeToFile();
                }
                
                break;
            
            //User has selected Double. Will input 2 polynomials                  
            case 3:
                cout << "You have chosen Double." << endl;
                cout << "Select how you wish to input data:" << endl;
                cout << "1. Keyboard\n2. Input File" << endl;
                cin >> select2;
                while (select2!=1 && select2!=2)
                {
                    cout << "Input error.\nPlease try again:" <<endl;
                    cin >> select2;
                }
                switch (select2)
            {
                case 1:
                    cout << "Input first double term: " << endl;
                    cin >> poly7;
                    
                    cout << "Input second double term: " << endl;
                    cin >> poly8;
                    break;
                    
                case 2:
                    
                    do
                    {
                        cout << "Input file name to read from:" << endl;
                        cin >> inFileName;
                        fin.open(inFileName.c_str());
                        if (fin.fail())
                        {
                            cout <<"Input error." << endl;
                            cout << "Please try again." << endl;
                            fin.clear();
                            isFile = false;
                            
                        }
                        else
                            isFile = true;
                        
                    }while(!isFile);
                    
                    fin >> poly7;
                    fin.close();
                    do
                    {
                        cout << "Input file name to read from:" << endl;
                        cin >> inFileName;
                        fin.open(inFileName.c_str());
                        if (fin.fail())
                        {
                            cout <<"Input error." << endl;
                            cout << "Please try again." << endl;
                            fin.clear();
                            isFile = false;
                        }
                        else
                            isFile = true;
                        
                    }while(!isFile);
                    fin >> poly8;
                    fin.close();
                    
                    break;
            }
                                
                
                //user presented with operations menu
                cout << "Select the operation you wish to perform: " << endl;
                cout << "1:  Addition" << endl;
                cout << "2:  Multiplication" << endl;
                cout << "3:  Evaluation" << endl;
                cout << "4:  Output to file" << endl;
                
                cin >> operation;
                
                 //reads in the users choice and selects the appropriate operation
                switch (operation)
                {   case 1:
                        cout << "Addition of polynomials:" << endl;
                        poly9 = poly7 + poly8;
                        cout << poly9 << endl;
                        break;
                    case 2:
                        cout << "Multiplication of polynomials: " << endl;
                        poly9 = poly7 * poly8;
                        cout << poly9 << endl;
                        break;
                    case 3:
                        cout << "Input evaluation value: " << endl;
                        cin >> x;
                        cout << "Evaluating first polynomial with x = " << x << " equals: " << endl;
                        cout << poly7.evalPoly(x) << endl;
                        cout << "Evaluating second polynomial with x = " << x << " equals: " << endl;
                        cout << poly8.evalPoly(x) << endl;
                        break;
                    case 4:
                        cout << "Polynomial 1 written to output text file"<< endl;
                        poly7.writeToFile();
                }
            
                break;  
            
            //User has selected Complex. Will input 2 polynomials                 
            case 4:
                cout << "You have chosen Complex." << endl;
                cout << "Select how you wish to input data:" << endl;
                cout << "1. Keyboard\n2. Input File" << endl;
                cin >> select2;
                while (select2!=1 && select2!=2)
                {
                    cout << "Input error.\nPlease try again:" <<endl;
                    cin >> select2;
                }
                switch (select2)
            {
                case 1:
                    cout << "Input first complex term: " << endl;
                    cin >> poly10;
                    
                    cout << "Input second complex term: " << endl;
                    cin >> poly11;
                    break;
                    
                case 2:
                    
                    do
                    {
                        cout << "Input file name to read from:" << endl;
                        cin >> inFileName;
                        fin.open(inFileName.c_str());
                        if (fin.fail())
                        {
                            cout <<"Input error." << endl;
                            cout << "Please try again." << endl;
                            fin.clear();
                            isFile = false;
                            
                        }
                        else
                            isFile = true;
                        
                    }while(!isFile);
                    
                    fin >> poly10;
                    fin.close();
                    do
                    {
                        cout << "Input file name to read from:" << endl;
                        cin >> inFileName;
                        fin.open(inFileName.c_str());
                        if (fin.fail())
                        {
                            cout <<"Input error." << endl;
                            cout << "Please try again." << endl;
                            fin.clear();
                            isFile = false;
                        }
                        else
                            isFile = true;
                        
                    }while(!isFile);
                    fin >> poly11;
                    fin.close();
                    
                    break;
            }
                                
                //user presented with operations menu
                cout << "Select the operation you wish to perform: " << endl;
                cout << "1:  Addition" << endl;
                cout << "2:  Multiplication" << endl;
                cout << "3:  Evaluation" << endl;
                cout << "4:  Output to file" << endl;

                
                cin >> operation;
                
                 //reads in the users choice and selects the appropriate operation
                switch (operation)
                {
                    case 1:
                        cout << "Addition of polynomials:" << endl;
                        poly12 = poly10 + poly11;
                        cout << poly12 << endl;
                        break;
                    case 2:
                        cout << "Multiplication of polynomials:  " << endl;
                        poly12 = poly10 * poly11;
                        cout << poly12 << endl;
                        break;
                    case 3:
                        cout << "Input evaluation value: " << endl;
                        cin >> x;
                        cout << "Evaluating first polynomial with x = " << x << " equals: " << endl;
                        temp = poly10.evalPoly(x);
                        cout << temp << endl;
                        cout << "Evaluating second polynomial with x = " << x << " equals: " << endl;
                        temp = poly11.evalPoly(x);
                        cout << temp << endl;

                        break;
                    case 4:
                        cout << "Polynomial 1 written to output text file"<< endl;
                        poly10.complexWriteToFile();
                }
            
                break;
            default: cout << "Invalid input. Rerun." << endl;
            
        }
}
        
