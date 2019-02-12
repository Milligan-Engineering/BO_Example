//File Name: BO_Example.cpp
//Author: JJ Giesey
//Email Address: jjgiesey@milligan.edu
//Term Project
//Description: This program handles banking duties in the B&O Board Game
//Last Changed: 02/04/2019

#include <iostream>
#include <string>
using namespace std;
//A Different Comment

int main()
{
	int numberOfPlayers;
	int value;
	int playerNumber;
	const int MINPLAYERS = 2;
	const int MAXPLAYERS = 6;
	string playerName[MAXPLAYERS];
	double timePerTurn;
	double timePerPlayer;
	double costPerMinute;

	cout << "Welcome to the B&O Banker Assistant \n";

	// Menu for timer
	cout << "Would you like to use a timer for the game? Y/N \n";
	char option;
	cin >> option;
	if ((option == 'Y') || (option == 'y'))
	{
		cout << "Which type of timer would you like to use? \n";
		cout << "S: Shot Clock\n";
		cout << "C: Cumluative Timer\n";
		cout << "M: Cost Timer\n";
		char option2;
		cin >> option2;
		switch (option2)
		{
		case 'S':
			//Set up shot clock
			cout << "Enter time per turn in minutes: ";
			cin >> timePerTurn;
			break;
		case 'C':
			//Set up cumulative timer
			cout << "Enter time per player in minutes: ";
			cin >> timePerPlayer;
			break;
		case 'M':
			//Set up cost timer
			cout << "Enter cost per minute: ";
			cin >> costPerMinute;
			break;
		default:
			cout << "Invalid entry. Timer not used.\n";
			break;
		}
	}


	// Retrieve and validate number of players using while

	cout << "How many players will be playing?";
	cin >> numberOfPlayers;
	while ((numberOfPlayers < MINPLAYERS) || (numberOfPlayers > MAXPLAYERS))
	{
		cout << "Number of players must be between " << MINPLAYERS << " and " << MAXPLAYERS << ". Please enter number again.";
		cin >> numberOfPlayers;
	}
	cout << "There will be " << numberOfPlayers << " players.\n";// Echo number of players

	playerNumber = 1;
	while (playerNumber <= numberOfPlayers)
	{
		cout << "Enter name of Player " << playerNumber << ": ";
		cin >> playerName[playerNumber-1];
		playerNumber++;
	}

	cout << "There will be " << numberOfPlayers << " playing. \n";
	playerNumber = 1;
	while (playerNumber <= numberOfPlayers)
	{
		cout <<  playerNumber << ": " << playerName[playerNumber-1] << endl;
		playerNumber++;
	}

	cout << "Enter character to continue \n";
	cin >> value;
	// A Better Comment
	return(0);
}