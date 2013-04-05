// Name: Eddie Spencer
// Course: CSC 260, Section 1
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Assignment 4 Part 2
// Description: readme file for Polynomial Project
// Filename: readmeES.txt
// Last modified on: 10/25/12

The design of this program was to manipulate and perform desired operations with polynomials with terms of type: integer, float, double or complex.
If the multiplication or addition operation is choosen, it can not multiply terms whose total term product is greater than 10 terms. This is due 
to the resultant array having a size of 10. The max possible multiplication process is 5 x 2 or 10 x 1. 4 x 3 will yield a segmentation fault because it produces
12 terms and be reduced to 10 terms. The user also has the ability to evaluate a polynomial with a given input value.
The user has the option to output a polynomial to the text file "output.txt". For complex polynomials, the output file is called "complexOutput.txt"
The main method calls upon the UserInterface class which acts as an interface between the user and the program, guiding them through the program step by step.
All input is stroked in from the user's keyboard or via input file as specified.