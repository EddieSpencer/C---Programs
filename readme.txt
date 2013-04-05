Written by Eddie Spencer
CSC 260
Fall 2012

This is the readme file for the Droll Bowling ScoreKeeper Program.
This program is for Assignment 2, which focuses on manipulation of arrays.
The program itself is a program to keep track of players and scores in a
bowling alley. There are a maximum of 20 players, and each player can only
play a maximum of 10 games.

The program beings by welcoming the user and making sure that they want to enter the program. 

If a valid input is entered, the program will run prompting the user for the number of players and number of games that will be played. The program checks to make sure that these numbers are valid.

Once all the data is entered correctly the bowling process begins. The user will enter input frame by frame alternating player by player. The program accounts for valid and invalid frame scores as well as correctly calculating the score based on normal throws as well as special throws Strike and Spare. Each frame the score is entered into an array that is attached specifically to a player and a game. Once all data is entered for all players and the games are over, the BowlingMenu will be brought up.
All of the data, frame by frame, game by game, and player by player is stored into a multidimensional array for easy access.

From the Bowling Menu, the user has 4 options. 
The first option is to begin a new game and erase any previous game data. This will essentially restart the program from the beginning.
The second option is to view all players scores from all games, and then start a new game. This option will also remove any previous game data.
The third option is to view a specific player's score on a specific game. This option will allow the user to enter in which player's score they wish to see on a desired game.
The fourth option will output all of the players scores from all games to an output file in the working directory and then exit the game.
The output file will be called "output.txt" and should contain information formatted as follows (this game had 2 players playing 2 games):

The scores for all the players are: 
Player 1's score for game 1 is: 217
Player 2's score for game 1 is: 225
Player 1's score for game 2 is: 105
Player 2's score for game 2 is: 96

After choosing an option from the menu, the program will do the desired operation and if prompted, it will exit.




