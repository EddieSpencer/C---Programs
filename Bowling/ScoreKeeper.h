// Name: Eddie Spencer
// Course: CSC 260, Section 1
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Assignment 2
// Description: Contains the function prototypes for all functions used in ScoreKeeper.cpp
// Filename: ScoreKeeper.h
// Last modified on: September 25th, 2012


//-----------------------------------------------------------------------------------------
//  function:  gameEngine ()
//             This is the main driver of the bowling game logic, keeping track of
//				throws and frame data.
//	Parameters:
//  numPlayers: the amount of players in this game. Used in keeping track of the
					//third dimension in score (mainly in the specialFrame function).
//	playerScores[][10]: The array where the total score is kept. It is an input so it can
							//be used in the main function.
//	gmcntr: short for "gameCounter," it's used mainly for output purposes, but also for
				//the second dimension in playerScores.
//-----------------------------------------------------------------------------------------
void gameEngine(int, int [][10], int);

//-----------------------------------------------------------------------------------------
//  function:  Strike ()
//             This method takes a single parameter and checks it to see if it is a strike.
	//If so, it prints the message "Strike" and returns true. 
	//If not, it returns false and prints nothing.
//	Parameters:
//    throw_1: the integer value of the first throw, if it is 10 it is a strike.

//	Return Value:
//		true if it is a strike
//-----------------------------------------------------------------------------------------
bool Strike(int);

//-----------------------------------------------------------------------------------------
//  function:  Spare ()
//    This method takes two parameters and check it to see if they are a spare.
	//If so, it prints the message "Spare" and returns true. 
	//If not, it returns false and prints nothing.
//	Parameters:
//    throw_1: the integer value of the first throw
//	  throw_2: the integer value of the second throw
//	Return Value:
//		true if it is a spare
//-----------------------------------------------------------------------------------------
bool Spare(int, int);

//-----------------------------------------------------------------------------------------
//  function:  gettingScore ()
	//This method takes in frame and whichPlayer as parameters, but they are only
	//for output purposes.
	//It has the user enter in the number of pins knocked down in a single throw and returns
	//that number. It also checks for an invalid input.
//	Parameters:
//    frame: int value of which frame is being bowled
//	  whichPlayer: int value of which player is bowling
//	Return Value:
//		pins: int value of pins knocked down.
//-----------------------------------------------------------------------------------------
int gettingScore(int, int);

//-----------------------------------------------------------------------------------------
//  function:  specialFrame ()
//    This method checks each frame to see if it is a Strike or Spare and if so, does the 
//		necessary calculation to the score.
//	Parameters:
//    scoreArray: three dimensional array that holds the frame, game, and player data
//	  lastPlayer: int value of the last player to roll
//-----------------------------------------------------------------------------------------

void specialFrame(int [][4][20], int);