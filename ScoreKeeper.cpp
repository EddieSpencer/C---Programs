// Name: Eddie Spencer
// Course: CSC 260, Section 1
// Semester: Fall 2012
// Instructor: Dr. Pulimood
// Assignment 2
// Description: This program is for Assignment 2, which focuses on manipulation of arrays.
// The program itself is a program to keep track of players and scores in a
// bowling alley. There are a maximum of 20 players, and each player can only
// play a maximum of 10 games.
// Filename: ScoreKeeper.cpp
// Last modified on: September 25th, 2012


#include <iostream>
#include <fstream>
#include "ScoreKeeper.h"

using namespace std;

int main(void)
{
	int gameCounter = 0;
	int playerCounter = 0;
	int actionListener = 0;
	int findGame = 0;
	int findPlayer = 0;
	int playerArray[20][10];
    
	cout << "Welcome to the Droll Bowling Alley.\nPress 1 to get started, anything else to exit. ";
	cin >> actionListener;
	//Checks to make sure the user wishes to run the program. 
	if (actionListener==1)
	{
		//This loop is so the program can run multiple times, depending on what the user wishes.
		while(true)
		{
			//Option 1: This means the user wishes to start a new game.
			if (actionListener==1) {
				while(true)
				{
					//Determine the neccessary inputs.
					cout << "How many players will be playing (20 Max)? ";
					cin >> playerCounter;
					//Error handling if the input is invalid.
					if (playerCounter > 20 || playerCounter <= 0)
					{
						cout << "Invalid number of players. Please try again.\n";
					}
					else
					{
						break;
					}
				}
				cout << "There are " << playerCounter << " players. How many games will there be (10 Max)? ";
				cin >> gameCounter;
				//Error handling if the input is invalid
				while(true)
				{
					if (gameCounter > 10 || gameCounter <= 0)
					{
						cout << "Invalid number of games. Please try again.\n";
					}
					else
					{
						break;
					}
					cout << "How many games will there be (10 Max)? ";
					cin >> gameCounter;
				}
				//Resets and removes any information in the array such that
				//new player data may be entered and stored.
				//This avoids any cumulations that may arrise in the program
				cout << "Resetting Data...\n";
				for(int a = 0; a < 20; a++)
				{
					for (int b = 0; b < 10; b++)
					{
						playerArray[a][b]=0;
					}
				}
				cout << "Bowling Started!" << endl;
				//Calls the method that begins the bowling process, gameEngine.
				for (int i = 0; i < gameCounter; i++)
				{
					//Specifies which game the user is playing.
					cout << "Game " << i + 1 << ":" << endl;
					//call to gameEngine
					gameEngine(playerCounter, playerArray, i);
				}
			}
			//Option 2: User wishes to start a new game,
				//but first see scores of previous game.
			else if (actionListener==2) {
				cout << "Scoreboard of all Players: \n" << endl;
				//Nested for loop for access to all game data in the multidimensional array.
				for (int i = 0; i < gameCounter; i++)
				{
					for (int k = 0; k < playerCounter; k++)
					{
						if (playerArray[k][i]>300)
						{
							//Check to make sure it only goes up to the last game played.
						}
						else
						{
							//Displays player data to the user.
							cout << "Player " << k + 1 << "'s score for game " << i + 1 << " is: " << playerArray[k][i] << endl;
						}
					}
				}
				//Same as option 1, begins a new game.
				while(true)
				{
					//Determine the neccessary inputs.
					cout << "How many players will be playing (20 Max)? ";
					cin >> playerCounter;
					//Error handling if the input is invalid.
					if (playerCounter>20 || playerCounter <=0)
					{
						cout << "Invalid number of players. Please try again.\n";
					}
					else
					{
						break;
					}
				}
				cout << "There are " << playerCounter << " players. How many games will there be (10 Max)? ";
				cin >> gameCounter;
				//Error handling if the input is invalid
				while(true)
				{
					if (gameCounter>10 || gameCounter <=0)
					{
						cout << "Invalid number of games. Please try again.\n";
					}
					else
					{
						break;
					}
					cout << "How many games will there be(10 Max)? ";
					cin >> gameCounter;
				}
				//Resets and removes any information in the array such that
				//new player data may be entered and stored.
				//This avoids any cumulations that may arrise in the progra
				cout << "Resetting Data...\n";
				for(int a = 0; a < 20; a++)
				{
					for (int b = 0; b < 10; b++)
					{
						playerArray[a][b]=0;
					}
				}
				cout << "Bowling Started!" << endl;
				//Calls the method that begins the bowling process, gameEngine.
				for (int i=0; i<gameCounter; i++)
				{
					//Specifies which game the user is playing.
					cout << "Game " << i + 1 << ":" << endl;
					//call to gameEngine
					gameEngine(playerCounter, playerArray, i);
				}				
			}
			//Option 3: The user wishes to see a specific score from any player
			else if (actionListener==3)
			{
				cout << "Which player's scores do you want to see? ";
				cin >> findPlayer;
				cout << "Which game do you want to see? ";
				cin >> findGame;
				//checks the requested score. 
				//Error handling if the game does not exist.
				if (findGame > gameCounter || findPlayer > playerCounter)
				{
					cout << "This game does not exist." << endl;
				}
				//prints the score if it is valid.
				else
				{
					cout << "Player " << findPlayer << " scored " << playerArray[findPlayer-1][findGame-1] << " points in game " << findGame<< endl;
				}
			}
			
			//Once the user has finished bowling, the Bowling menu is brought up.
			cout << "\n\nBowling Menu:";
			cout << "\n1-Play a new game. (resets previous game data)";
			cout << "\n2-View all players scores for all games played, and then start a new game (resets previous game data)";
			cout << "\n3-View a specific player's score on a specific game";
			cout << "\n4-View all scores in an output file and exit.\n\n";
			cin >> actionListener;
			//Here is where the program checks to exit.
			if (actionListener!=1 && actionListener!=2 && actionListener!=3)
			{
				//Here it is listing the scores for each player.
                ofstream output;
                output.open("output.txt");
                
                
				output << "The scores for all the players are: " << endl;
				for (int i = 0; i < gameCounter; i++)
				{
					for (int k = 0; k < playerCounter; k++)
					{
						output << "Player " << k+1 << "'s score for game " << i+1 << " is: " << playerArray[k][i] << endl;
					}
				}
                
                output.close();
				//breaking out of the while(true) loop that the entire program is nested in.
				break;
			}
			
		}
	}
	//Exits the program.
	cout << "Exiting..." << endl;
	return 0;
}
void gameEngine(int numPlayers, int playerScores[][10], int gmcntr)
{
	int score[10][4][20];
	//score keeps the frame number in the first dimension,
			//the score for each frame in its second dimension,
			//and which player it's for in its third dimension.
			//The second dimension is of length 4 because index 0 is used to mark whether that
			//frame was normal (integer value 0), a spare (integer value 1), or a strike (integer value 2).
			//Indexes 1-3 are then accordingly used for the values of the throws.
	int pins;
	//pins records a single throw's score.
	
	//This for loop sets all values of score to 0, so no cumulation or accidental crossing
	//of games will occur.
	//A 3 dimensional array requires 3 nested loops.
	for(int j = 0; j < 20; j++)
	{
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < 4; l++) 
			{
				score[k][l][j]=0;
			}
		}
	}
	//this outer for loop keeps track of which frame in the game the user is on.
	for (int i = 0; i < 10; i++)
	{
		//this second for loop determines which player's turn it is.
		//Here the numPlayers is being used so play will alternate between the various
		//players correctly.
		//The variable j is used to differentiate amongst the players, and keep the scores
		//seperate.
		for(int j = 0; j < numPlayers; j++)
		{
			//Because the tenth frame is handled differently from the others, this if statement
			//is neccessary to ensure that only frames 1-9 are calculated this way.
			if (i < 9) {
				//this for loop is for the two throws a player gets in their frame.
				for (int k = 1; k < 3; k++)
				{
					//calling the gettingScore method, which is explained in its method body below.
					pins = gettingScore(i + 1, j + 1);
					//this while loop adds together to scores for the first and second throws (as well as pins)
					//to make sure the player only knocked down a maximum of 10 pins.
					while ((score[i][1][j] + score[i][2][j]) + pins > 10)
					{
						cout << "Error! The number of pins in two throws cannot exceed 10 pins." << endl;
						pins=gettingScore(i + 1, j + 1);
					}
					//After making sure the number of pins knocked down is legal, the score
					//is placed in its spot in the array.
					score[i][k][j]+=pins;
					//if this is the first throw, these if statements check to see if it was a strike.
					if (k == 1)
					{
						//calls the Strike method, which is explained in its method body below.
						if (Strike(score[i][k][j]))
						{
							//if the throw was a strike, mark it as such by giving the
							//second dimension's first index an integer value of 2.
							score[i][0][j]=2;
							//breaks out of the innermost for loop, ending this particular frame
							//for this player.
							break;
						}
					}
					//if this is the second throw, these if statements check to see if it was a spare.
					if(k == 2)
					{
						//calls the Spare method, which is explained in its method body below.
						if (Spare((score[i][k][j]), score[i][k-1][j]))
						{
							//if the throw was a spare, mark it as such by giving the
							//second dimension's first index an integer value of 1.
							score[i][0][j]=1;
							//breaks out of the innermost for loop, ending this particular frame
							//for this player.
							break;
						}
					}
				}
			}
			//Here is where the 10th frame is handled. The reason for this is because unlike
			//other frames, if the player scores a strike or a spare the frame does not end.
			else if(i == 9)
			{
				//this for loop is for the two throws a player gets in their frame.
				for (int k = 1; k < 3; k++)
				{
					//calling the gettingScore method, which is explained in its method body below.
					pins = gettingScore(10, j + 1);
					//this while loop adds together to scores for the first and second throws (as well as pins)
					//to make sure the player only knocked down a maximum of 10 pins.\
					//because the frame is known in this iteration, a variable is not used.
					while ((score[9][1][j] + score[9][2][j]) + pins > 10) {
						cout << "Error! The number of pins in two throws cannot exceed 10 pins." << endl;
						pins = gettingScore(10, j);
					}
					//After making sure the number of pins knocked down is legal, the score
					//is placed in its spot in the array.
					score[9][k][j]+=pins;
					//if this is the first throw, these if statements check to see if it was a strike.
					if (k == 1)
					{
						//calls the Strike method, which is explained in its method body below.
						if (Strike(score[9][k][j]))
						{
							//if the throw was a strike, mark it as such by giving the
							//second dimension's first index an integer value of 2.
							score[9][0][j]=2;
							//breaks out of the innermost for loop, ending this part of the frame.
							break;
						}
					}
					//if this is the second throw, these if statements check to see if it was a spare.
					if(k == 2)
					{
						//calls the Spare method, which is explained in its method body below.
						if (Spare((score[9][k][j]), score[9][k-1][j]))
						{
							//if the throw was a spare, mark it as such by giving the
							//second dimension's first index an integer value of 1.
							score[9][0][j]=1;
							//breaks out of the innermost for loop, ending this part of the frame.
							break;
						}
					}
				}
				//this if statement checks to see if the 10th frame was a spare.
				if (score[9][0][j] == 1)
				{
					//if it was, it gets a third value for the 10th frame from the user.
					score[9][3][j] = gettingScore(10, j + 1);
				}
				//this if statement checks to see if the 10th frame was a strike.
				if (score[9][0][j] == 2)
				{
					//if it was, it gets a second and third value for the 10th frame from the user.
					score[9][2][j] = gettingScore(10, j + 1);
					score[9][3][j] = gettingScore(10, j + 1);
				}
			}
		}
	}
	//calls the specialFrame method, which is explained in its method body below.
	specialFrame(score, numPlayers);
	//these for loops are for adding all the scores in the game together into one score,
	//which is placed in the playerScores array.
	for(int plyrcntr = 0; plyrcntr < numPlayers; plyrcntr++)
	{
		for (int cntr = 0; cntr < 10; cntr++)
		{
			for (int cntr2 = 1; cntr2 < 4; cntr2++)
			{
				//The playerScores array uses the indexes of which player and which game.
				//The game does not change (one of the parameters), and the player only changes with the outmost loop.
				//The score (by frame, throw, then player) is added to the player's game index.
				playerScores[plyrcntr][gmcntr]+=score[cntr][cntr2][plyrcntr];
			}
		}
	}
}
bool Strike(int throw_1)
{
	//This method takes a single parameter and checks it to see if it is a strike.
	//If so, it prints the message "Strike" and returns true. 
	//If not, it returns false and prints nothing.
	if (throw_1==10)
	{
		cout << "Strike!" << endl;
		return true;
	}
	return false;
}
bool Spare(int throw_1, int throw_2)
{
	//This method takes two parameters and check it to see if they are a spare.
	//If so, it prints the message "Spare" and returns true. 
	//If not, it returns false and prints nothing.
	if (throw_1 + throw_2 == 10)
	{
		cout << "Spare!" << endl;
		return true;
	}
	return false;
}
int gettingScore(int frame, int whichPlayer)
{
	//This method takes in frame and whichPlayer as parameters, but they are only
	//for output purposes.
	//It has the user enter in the number of pins knocked down in a single throw and returns
	//that number. It also checks for an invalid input.
	int pins = -1;
	while(true)
	{
		//printing the request for pins knocked down.
		cout << "Enter player " << whichPlayer << "'s throw for frame " << frame << ": ";
		cin >> pins;
		//checking to make sure pins is an acceptable number (between 0 and 10, inclusive).
		if (pins>10 || pins <0)
		{
			cout << "Error! The input score is invalid. Please input a score from 0-10." << endl;
		}
		else
		{
			break;
		}
	}
	return pins;
}
void specialFrame(int scoreArray[][4][20], int lastPlayer)
{
	//This method checks each frame to see if it is a Strike or Spare	
	//This outer for loop ensures that this process is done once for every player.
	for(int h = 0; h < lastPlayer; h++)
	{
		//This for loop begins at the 9th frame (the 10th frame has already been calculated in
		//the gameEngine function) and consistently checks for strikes and spares.
		for(int i = 8; i >= 0; i--)
		{
			//Checks the index 0 in the second dimension for the integer value indicating a
			//spare.
			if(scoreArray[i][0][h] == 1)
			{
				//If this frame was a spare, it takes the first throw from the next frame and
				//records the value as this frame's third throw.
				scoreArray[i][3][h]=scoreArray[i+1][1][h];
			}
			//Checks the index 0 in the second dimension for the integer value indicating a
			//strike.
			else if(scoreArray[i][0][h] == 2)
			{
				//If this frame was a strike, it takes the first throw from the next frame and
				//records the value as this frame's second throw. Then, it takes the second throw
				//from the next frame and records it as this frame's third throw.
				scoreArray[i][2][h]=scoreArray[i+1][1][h];
				scoreArray[i][3][h]=scoreArray[i+1][2][h];
			}
			//if the integer value shows that the frame was neither a strike nor a spare, then it
			//does nothing and the inner for loop moves on to the next iteration.
			else
			{
			}
		}
	}
}