#include <iostream>
using namespace std;



int main()
{
	int numberOfPlayers;
	int turnTimeMinutes;
	int turnTimeSeconds;
	int value;

	cout << "Welcome to the B&O Banker Assitant \n";

	cout << "How many players will be playing?";
	cin >> numberOfPlayers;
	
	cout << "Enter the desired minutes of turn time: ";
	cin >> turnTimeMinutes;

	cout << "Enter the desired seconds of turn time: ";
	cin >> turnTimeSeconds;

	cout << "There will be " << numberOfPlayers << " playing with a turn time of " << turnTimeMinutes << " minutes and " << turnTimeSeconds << " seconds. \n";
	cout << "Enter character to continue \n";
	cin >> value;

	return(0);
}