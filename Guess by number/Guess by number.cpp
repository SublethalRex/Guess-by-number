// Guess by number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;

int main()
{
	int play = 1; //sets up the variable that controls if the game keeps playing


	while (play = 1) {	//the while loop that keeps the game going after the initial round is over
		srand(static_cast<unsigned int>(time(0)));
		int secretNumber = rand() % 64 + 1;
		int tries = 0;  //variable that controls both linear searching and keeps track of the amount of turns gone by
		int rguess;  //random number guess
		int pguess;   //player controlled guess
		int binguess;   //binary searcher
		int maxnum;   //max num for binary search
		int minnum;   //min number for binary search
		
		string winner = "0";
		int winnerfd = 0;


		cout << "\tWelcome to guess my number\n\n";
		maxnum = 64;
		minnum = 1;

		do
		{
			cout << "\n|1|2|3|4|5|6|7|8|\n|9|10|11|12|13|14|15|16|\n|17|18|19|20|21|22|23|24|\n|25|26|27|28|29|30|31|32|\n|33|34|35|36|37|38|39|40|\n";
			cout << "|41|42|43|44|45|46|47|48|\n|49|50|51|52|53|54|55|56|\n|57|58|59|60|61|62|63|64|\n";

			rguess = rand() % 64 + 1; //controls random number guesser
			binguess = (maxnum + minnum) / 2;   //binary number guesser
			cout << "Where shall we fire captain?\n";
			cin >> pguess;
			++tries;
			cout << "We fired at space " << pguess << "\n";
			if (pguess > secretNumber) // statements to give feedback to the player
			{
				cout << "\n\nWe missed! We aimed too high\n\n";

			}

			else if (pguess < secretNumber)
			{
				cout << "\n\nWe missed! we aimed too low\n\n";

			}
			else if (pguess == secretNumber)
			{
				cout << "\n\n\nWe got them sir, it only took " << tries << " tries!\n They were hiding on grid square " << secretNumber << "!\n";
				winner = "Player";
				winnerfd = 1;
			}

			if (binguess > secretNumber) { //monitors/controlls the binary guesser
				maxnum = binguess + 1;
			}
			else if (binguess < secretNumber) {
				minnum = binguess - 1;
			}
			else if (binguess == secretNumber) {
				winner = "Binary";
				winnerfd = 1;
			}

			if (rguess == secretNumber) {  //follows the random number guesser
				winner = "Random";
				winnerfd = 1;
			}
			if (tries == secretNumber) {   //keeps track of tries and of the linear guesser
				winner = "Linear";
				winnerfd = 1;
			}
			cout << "\nRandom number fired at " << rguess;
			cout << "\nBinary search fired at " << binguess;
			cout << "\nLinear search fired at " << tries;




		} while (winnerfd != 1);  //winner found


		cout << "\nThe winner is " << winner << " they won in " << tries << " amount of shots!";
		cout << "\n\n\n\n keep playing? type 1 for yes or 2 for no";

		cin >> play; //restarts the game
	}
	return 0;
}

