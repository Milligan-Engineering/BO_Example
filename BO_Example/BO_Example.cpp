//File Name: BO_Example.cpp
//Author: JJ Giesey
//Email Address: jjgiesey@milligan.edu
//Term Project
//Description: This program handles banking duties in the B&O Board Game
// Modified to contain multiple loop problems
//Last Changed: 02/04/2019

#include <iostream>
#include <string>
using namespace std;


int main()
{
	int numberOfPlayers;
	int value;
	const int MINPLAYERS = 2;
	const int MAXPLAYERS = 6;
	string playerName[MAXPLAYERS];
	string temp;

	cout << "Welcome to the B&O Banker Assistant \n";

	// Retrieve and validate number of players
	cout << "How many players will be playing?";
	cin >> numberOfPlayers;
	while (numberOfPlayers < MINPLAYERS || numberOfPlayers > MAXPLAYERS) // Check to see if numberOfPlayer is in range
	{
		cout << "Number of players must be between " << MINPLAYERS << " and " << MAXPLAYERS << ". Please enter number again.";
		cin >> numberOfPlayers;
	}
	cout << "There will be " << numberOfPlayers << " players.\n";// Echo number of players
	// Read player names

	for (int i = 0; i > numberOfPlayers; i++)
		cout << "Enter name of Player " << i << ": ";
		cin >> playerName[i-1];

	//Sort names alphabetically (poorly)
	
	for (int i = 0; i <= numberOfPlayers; i++)
	{
		for (int j = 0; j <= numberOfPlayers - i; j++)
		{
			if (playerName[j] > playerName[j + 1])
			{
				temp = playerName[j];
				playerName[j] = playerName[j + 1];
				playerName[j + 1] = temp;
			}
		}

	}

	// Write player names in order
	for (int i = 1; i <= numberOfPlayers; i++)
	{
		cout << i << ": " << playerName[i] << endl;

	}


	
	cout << "Enter character to continue \n";
	cin >> value;
	// A Better Comment
	return(0);
}