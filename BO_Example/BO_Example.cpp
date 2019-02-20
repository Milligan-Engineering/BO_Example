//File Name: BO_Example.cpp
//Author: JJ Giesey
//Email Address: jjgiesey@milligan.edu
//Term Project
//Description: This program handles banking duties in the B&O Board Game
// Modified to contain multiple loop problems
//Last Changed: 02/18/2019

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
	while (numberOfPlayers > MINPLAYERS || numberOfPlayers < MAXPLAYERS) // Check to see if numberOfPlayer is in range
	{
		cout << "Number of players must be between " << MINPLAYERS << " and " << MAXPLAYERS << ". Please enter number again.";
		cin >> numberOfPlayers;
	}
	cout << "There will be " << numberOfPlayers << " players.\n";// Echo number of players
	// Read player names

	for (int i = 0; i > numberOfPlayers; i++)
	{
		cout << "Enter name of Player " << i << ": ";
		cin >> playerName[i - 1];
	}

	//Sort names alphabetically (poorly)
	
	for (int i = 0; i <= numberOfPlayers; i++)
	{
		for (int j = 0; j <= numberOfPlayers - i; j++)
		{
			if (playerName[j] > playerName[j - 1])
			{
				temp = playerName[j];
				playerName[j] = playerName[j - 1];
				playerName[j - 1] = temp;
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

	return(0);
}

int setupPlayers(string playerName[], int playerCash[], int playerTurnorder[])
{
	// Set up players names
	int numberPlayers = 0;

	while ((numberPlayers < 3) || (numberPlayers > 6)) // Check for valid input. If not - keep asking
	{
		cout << "Enter number of players between 3 and 6. \n";
		cin >> numberPlayers;
	}
	cout << "There will be " << numberPlayers << " players. \n";


	for (int i = 0; i < numberPlayers; i++) // Get name for each player
	{
		cout << "What is the name of the player " << i << "? \n";
		cin >> playerName[i];
		cout << "Player " << i + 1 << " is " << playerName[i] << endl << endl; // echoing input for validation
	}


	// Set random initial turn order
	long int currentTime = static_cast<long int>(time(0)); //Generate random seed
	srand(currentTime);

	for (int i = 0; i < numberPlayers; i++)
	{
		playerTurnorder[i] = i;	// assign initial turn order
		playerCash[i] = rand() % 10000; // assign randome number
	}


	// list players in turnorder
	cout << "Name \t Cash\t Order\t \n";
	PrintInformation(playerName, playerCash, playerTurnorder, numberPlayers);

	//Sort players by cash
	int test = setPlayerTurnorder(playerCash, playerTurnorder, numberPlayers);

	// Set up initial player cash and net worth
	for (int i = 0; i < numberPlayers; i++)
	{
		playerCash[i] = totalInitialCash / numberPlayers;
	}

	// list players in turnorder
	cout << "Name \t Cash\t Order\t \n";
	PrintInformation(playerName, playerCash, playerTurnorder, numberPlayers);

	return(numberPlayers);

}
