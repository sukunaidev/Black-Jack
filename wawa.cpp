// wawa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;


int main()
{
	srand(time(0));
	//player hand
	

	//Generating the deck
	int L = 13;
	int R = 4;
	string type;
	string index;

	int cardValue;
	int ar[4][14];
	/**for (int i = 0; i < 4; i++)
	{
		for (int j = 0;j < 13; j++)
		{
			
			switch (i)
			{
			case 0:
				type = "Diamonds";
				break;
			case 1:
				type = "Clubs";
				break;
			case 2:
				type = "Hearts";
				break;
			case 3:
				type = "Spades";
				break;
			

			}

			switch (j)
			{
			case 0:
				index = "Ace";
				break;
			case 1:
				index = "2";
				break;
			case 2:
				index = "3";
				break;
			case 3:
				index = "4";
				break;
			case 4:
				index = "5";
				break;
			case 5:
				index = "6";
				break;
			case 6:
				index = "7";
				break;
			case 7:
				index = "8";
				break;
			case 8:
				index = "9";
				break;
			case 9:
				index = "10";
				break;
			case 10:
				index = "Jack";
				break;
			case 11:
				index = "Queen";
				break;
			case 12:
				index = "King";
				break;

			}


			ar[i][j] = 1 +j;
			if (pHandTotal + 11 > 21 && j ==0)
			{
				ar[i][j] = 1;
			}
			else if (pHandTotal + 11 <21 && j ==0)
			{
				ar[i][j] = 11;
			}

			if (j >= 10)
			{
				ar[i][j] = 10;
			}
			cout << "[" << index << " of " << type << " Value: " << ar[i][j] << "] ";
		}

		cout << endl << "-----------------------" << endl;
	} **/




	int RandomI = 0;
	int RandomJ = 0;

	int value;
	string typee;
	string indexx;
	int turn =0;
	string s;

	int pHandTotal = 0;
	int dealerHandTotal = 0;
	string action;

	bool playerStopped = false;

	cout << "Welcome to BlackJack." << endl;

	while (pHandTotal <= 21 && dealerHandTotal <=21)
	{
		
		if (dealerHandTotal >= 17 && playerStopped)
		{
			break;
		}

		if (pHandTotal == 21)
		{
			cout << "Player Wins";
		}


		if (turn ==0)
		{
			cout << "Press S to start: ";

			cin >> s;
			if (s != "s")
				break;
		}

		if (turn >=5 && !playerStopped)
		{
			cout << "Stand or Hit." << endl;
			cin >> action;
			if (action == "stand")
			{
				
				if (turn % 2 == 0)
				{
					turn+=2;
				}
				else if (turn % 2 != 0)
				{
					turn ++;
				}
				playerStopped = true;
			}
			
			
		}
		
		

		RandomI = (rand() % 4) + 1;
		RandomJ = (rand() % 13) + 1;
		for (int i = 0; i < RandomI; i++)
		{
			for (int j = 0;j < RandomJ; j++)
			{

				switch (i)
				{
				case 0:
					type = "Diamonds";
					break;
				case 1:
					type = "Clubs";
					break;
				case 2:
					type = "Hearts";
					break;
				case 3:
					type = "Spades";
					break;


				}

				switch (j)
				{
				case 0:
					index = "Ace";
					break;
				case 1:
					index = "2";
					break;
				case 2:
					index = "3";
					break;
				case 3:
					index = "4";
					break;
				case 4:
					index = "5";
					break;
				case 5:
					index = "6";
					break;
				case 6:
					index = "7";
					break;
				case 7:
					index = "8";
					break;
				case 8:
					index = "9";
					break;
				case 9:
					index = "10";
					break;
				case 10:
					index = "Jack";
					break;
				case 11:
					index = "Queen";
					break;
				case 12:
					index = "King";
					break;

				}


				ar[i][j] = 1 + j;
				value = 1 + j;
				if (pHandTotal + 11 > 21 && j == 0)
				{
					ar[i][j] = 1;
					value = 1;
				}
				else if (pHandTotal + 11 < 21 && j == 0)
				{
					ar[i][j] = 11;
					value = 11;
				}

				if (j >= 10)
				{
					ar[i][j] = 10;
					value = 10;
				}

				typee = type;
				indexx = index;
				//cout << "[" << index << " of " << type << " Value: " << ar[i][j] << "] ";


			}

			
		}

		
		
		if (turn != 0 && turn !=4)
		{
			cout << indexx << " of " << typee << " Value: " << value << endl;
		}
		else if (turn == 4)
		{
			cout << "Card Unknown" << endl;
		}
		

		if (turn != 0)
		{
			
			if (turn % 2 != 0)
			{
				pHandTotal += value;
				cout <<  "player: " << pHandTotal << endl;
			}
			else if (turn % 2 == 0 && turn !=4)
			{
				dealerHandTotal += value;
				cout << "dealer: " << dealerHandTotal << endl;
			}
		}
		if (!playerStopped)
		{
			turn++;
		}
		else if (playerStopped)
		{
			turn += 2;
		}
		


	}

	if (dealerHandTotal >= 17 && playerStopped)
	{
		//checkwhoscloser
		int dealersub = 21 - dealerHandTotal;
		int playersub = 21 - pHandTotal;

		if (playersub < dealersub)
		{
			cout << "player wins.";
			
		}
		else if (playersub > dealersub)
		{
			cout << "dealer wins";
			
		}
	}

	
}


