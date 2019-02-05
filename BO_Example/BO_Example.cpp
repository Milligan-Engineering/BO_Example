//File Name: BO_Example.cpp
//Author: JJ Giesey
//Email Address: jjgiesey@milligan.edu
//Term Project
//Description: This program handles banking duties in the B&O Board Game
//Last Changed: 02/04/2019

#include <iostream>
using namespace std;
//A Different Comment

int main()
{
	int numberOfPlayers;
	int turnTimeMinutes;
	int turnTimeSeconds;
	double turnTime;
	int value;
	const int MINPLAYERS = 2;
	const int MAXPLAYERS = 6;
	
	cout << "Welcome to the B&O Banker Assistant \n";

	// Retrieve and validate number of players using do while
	do
	{
		cout << "How many players will be playing? Must be between "<< MINPLAYERS << " and " << MAXPLAYERS << " players." ;
		cin >> numberOfPlayers;
	} 
	while ((numberOfPlayers < MINPLAYERS) || (numberOfPlayers > MAXPLAYERS));
	cout << "There will be " << numberOfPlayers << " players.\n"; // Echo number of players
	
	/* Validating the number of players using a while satement requires more
	lines but it could be clearer to the user of the program. */
	cout << "How many players will be playing?";
	cin >> numberOfPlayers;	
	while ((numberOfPlayers < MINPLAYERS) || (numberOfPlayers > MAXPLAYERS)) 
	{
		cout << "Number of players must be between " << MINPLAYERS << " and " << MAXPLAYERS << ". Please enter number again.";
		cin >> numberOfPlayers;
	}
	cout << "There will be " << numberOfPlayers << " players.\n";// Echo number of players
		
	cout << "Enter the desired minutes of turn time: ";
	cin >> turnTimeMinutes;

	cout << "Enter the desired seconds of turn time: ";
	cin >> turnTimeSeconds;

	turnTime = turnTimeMinutes + turnTimeSeconds/60.;

	cout << "There will be " << numberOfPlayers << " playing with a turn time of " 
		<< turnTimeMinutes << " minutes and " << turnTimeSeconds << " seconds. \n";
	cout << "Enter character to continue \n";
	cin >> value;
	// Another Comment
	return(0);
}