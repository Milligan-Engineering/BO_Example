//File Name: BO_Example.cpp
//Author: JJ Giesey
//Email Address: jjgiesey@milligan.edu
//Term Project
//Description: This program handles banking duties in the B&O Board Game
// Modified to contain multiple loop problems
//Last Changed: 02/18/2019

#include <iostream>
#include <string>
#include <time.h>

using namespace std;


int main()
{
	int numberOfPlayers;
	int value;
	const int MINPLAYERS = 2;
	const int MAXPLAYERS = 6;
	string playerName[MAXPLAYERS];
	double randomArray[MAXPLAYERS];
	string sTemp;
	double dTemp;

	cout << "Welcome to the B&O Banker Assistant \n";

	// Retrieve and validate number of players
	cout << "How many players will be playing?";
	cin >> numberOfPlayers;
	while ((numberOfPlayers < MINPLAYERS) || (numberOfPlayers > MAXPLAYERS)) // Check to see if numberOfPlayer is in range
	{
		cout << "Number of players must be between " << MINPLAYERS << " and " << MAXPLAYERS << ". Please enter number again.";
		cin >> numberOfPlayers;
	}
	cout << "There will be " << numberOfPlayers << " players.\n";// Echo number of players
	// Read player names

	for (int i = 0; i < numberOfPlayers; i++)
	{
		cout << "Enter name of Player " << i+1 << ": ";
		cin >> playerName[i];
	}

	// Set random turn order of players
	
	//Make random number array
	long int currentTime = static_cast<long int>(time(0)); //Generate random seed
//	srand(currentTime);
	for (int i = 0; i < numberOfPlayers; i++)
	{
		randomArray[i] = rand() % 10000; // assign random number
	}


	//Sort names by their random number
	
	for (int i = 0; i < numberOfPlayers-1; i++)
	{
		for (int j = 0; j < numberOfPlayers - i - 1; j++)
		{
			if (randomArray[j] > randomArray[j + 1])
			{
				// Switch player names
				sTemp = playerName[j];
				playerName[j] = playerName[j + 1];
				playerName[j + 1] = sTemp;
				//Switch random numbers
				dTemp = randomArray[j];
				randomArray[j] = randomArray[j + 1];
				randomArray[j + 1] = dTemp;
			}
		}

	}

	// Write player names in new random order
	for (int i = 1; i <= numberOfPlayers; i++)
	{
		cout << i << ": " << playerName[i-1] << endl;

	}
	
	cout << "Enter character to continue \n";
	cin >> value;

	return(0);
}
