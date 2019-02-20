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

int randomArrayGenerator(double arrayValues[], int arraySize, int maxValue);
//Precondition: arrayValues is an empty array of size arraySize. maxValue contains the upper limit of values
//Postcondition: arrayValues will contain random values between 0 and maxValue. Returns size of array.

int Sorter(double Values[], int Order[], int Size);
//Preconditions: An array with maginitudes stored in Values and the order is stored in Order (0 first, 1 second, ...)
//				The size of the arrays are stored in Size
//Postcondition: The array Order index of the smallest value in 0 the index of the second smallest in 1 ...


int main()
{
	int numberOfPlayers;
	int value;
	const int MINPLAYERS = 2;
	const int MAXPLAYERS = 6;
	string playerName[MAXPLAYERS];
	double randomArray[MAXPLAYERS];
	int playerTurnOrder[MAXPLAYERS];

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
		playerTurnOrder[i] = i; //initialize playerTurnOrder array
	}

	// Set random turn order of players
	randomArrayGenerator(randomArray, MAXPLAYERS, 10000);


	//Sort names by their random number
	
	Sorter(randomArray, playerTurnOrder, numberOfPlayers);
	// Write player names in new random order
	for (int i = 0; i < numberOfPlayers; i++)
	{
		cout << i << ": " << playerName[playerTurnOrder[i]] << "(" << randomArray[playerTurnOrder[i]] << ")" << endl;
	}
	
	cout << "Enter character to continue \n";
	cin >> value;

	return(0);
}

int randomArrayGenerator(double arrayValues[], int arraySize, int maxValue)
{
	//Make random number array
	long int currentTime = static_cast<long int>(time(0)); //Generate random seed
	srand(currentTime);
	for (int i = 0; i < arraySize; i++)
	{
		arrayValues[i] = rand() % maxValue; // assign random number
	}
	return(arraySize);
}


int Sorter(double Values[], int Order[], int Size)
{
	int temp;
	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = 0; j < Size - i - 1; j++)
		{
			if (Values[Order[j]] > Values[Order[j + 1]])
			{
				temp = Order[j];
				Order[j] = Order[j + 1];
				Order[j + 1] = temp;
			}
		}
	}
	return(0);
}
