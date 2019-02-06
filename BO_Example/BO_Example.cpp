//File Name: BO_Example.cpp
//Author: JJ Giesey
//Email Address: jjgiesey@milligan.edu
//Term Project
//Description: This program handles banking duties in the B&O Board Game
//Last Changed: 02/04/2019

#include <iostream>
#include <string>
using namespace std;
//The Original Comment
int main()
{
	int numberOfPlayers;
	int value;
	int playerNumber;
	const int MINPLAYERS = 2;
	const int MAXPLAYERS = 6;
	string playerName[6];

	cout << "Welcome to the B&O Banker Assistant \n";

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
		cin >> playerName[playerNumber];
		playerNumber++;
	}

	cout << "There will be " << numberOfPlayers << " playing. \n";
	playerNumber = 1;
	while (playerNumber <= numberOfPlayers)
	{
		cout <<  playerNumber << ": " << playerName[playerNumber] << endl;
		playerNumber++;
	}

	cout << "Enter character to continue \n";
	cin >> value;

	// Additional comment
	return(0);
}