// Guess by number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int secretNumber = rand() % 64 + 1;
	int tries = 0;
	int guess;

	cout << "\tWelcome to guess my number\n\n";

	do 
	{
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;
		if (guess>secretNumber)




	}

	







    return 0;
}

