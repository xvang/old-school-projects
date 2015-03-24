#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

int main ()
{
	//XENG VANG
	srand ((unsigned) time(0));// all the variables needed
	int Pile1 = rand()%91 + 10; 
	int Pile2 = rand()%91 + 10; 
	int Pile3 = rand()%91 + 10;
	int Userchoiceofpile;
	int Userremovesmarbles;
	int TempPile;
	int Computerremovesmarbles;
	
	
	string Startthegame;
	

	cout << "Welcome." << endl
		 << endl
		 << "You will be playing the game called Nim." << endl
		 << endl;
	

	do
	{
	cout << "would you like to start? (yes/no) "; // if user would like to start the game

	cin >> Startthegame;
	cout << endl;

	if (Startthegame == "yes" || Startthegame == "Yes" ) // user wishes to start
		{
	
		cout << "Very well. We shall see who is better." << endl
			 << endl;

		}

	else if (Startthegame == "no" || Startthegame == "No") // user wishes not to play

		{
		cout << "You made a wise decision." << endl;
		system ("pause");
		return 0;
	
		}

	else // did not answer 'yes' or 'no' therefore answer is invalid
		{
		cout << "Invalid answer." << endl; 
		}
	} while (Startthegame != "yes" && Startthegame != "Yes" && Startthegame != "No" && Startthegame != "no" );

	cout << "The rules of this game is simple." << endl
		 << endl
		 << "We each take turns picking up marbles from three piles." << endl
		 << endl
		 << "We can pick up to HALF the amount in a pile, but only from ONE pile PER turn.We also have to pick at least one marble per turn." << endl
		 << endl
		 << "Whoever has to pick up the last marble loses." << endl
		 << endl
		 << "Let's start." << endl
		 << endl;

	system ("pause");
	
	do // the main loop for the game. 
	{

	cout << endl;
	cout << endl;
	cout << setw(4) <<  "Pile 1		" << setw(4)<< "Pile 2		" <<setw(4) << "Pile 3" << endl; // displays piles
	cout << "=============================================" << endl
		 << setw(4) << Pile1 << "		" << setw(4) << Pile2 << "		"<< setw(4) << Pile3 << endl;


	cout << endl;
	cout << endl;
	cout << "Which pile would you like to draw from? (1, 2, 3) "; // user chooses to draw from a pile
	cin >> Userchoiceofpile;
	cout << endl;
	cout << endl;


	 // this will run if user did not choose 1,2, or 3
		
		while ( Userchoiceofpile != 1 && Userchoiceofpile != 2 && Userchoiceofpile != 3)
		{
			cout << "Invalid pile. Choose again. " << endl
				 << "Which pile would you like to draw from? (1, 2, 3) ";
			cin >> Userchoiceofpile;
		}
		
		if (Userchoiceofpile == 1 && Pile1 == 0) // this block of code will inly come into play if user chooses a pile that has zero amount of marbles.
		{	
		while (Userchoiceofpile == 1)
		{
		cout << "That pile is empty. " << endl
			 << "Choose another pile: " << endl;
		cin >> Userchoiceofpile;
		}
		}

		if (Userchoiceofpile == 2 && Pile2 == 0) 
		{	
		while (Userchoiceofpile == 2)
		{
		cout << "That pile is empty. " << endl
			 << "Choose another pile: " << endl;
		cin >> Userchoiceofpile;
		}
		}

		if (Userchoiceofpile == 3 && Pile3 == 0) 
		{	
		while (Userchoiceofpile == 3)
		{
		cout << "That pile is empty. " << endl
			 << "Choose another pile: " << endl;
		cin >> Userchoiceofpile;
		}
		}
	
	
	if (Userchoiceofpile == 1) // user chose pile 1
	{
	
		cout << "How many marbles would you like to remove? "; // amount user wishes to remove
		cin >> Userremovesmarbles;

		while (Userremovesmarbles > 4 && Userremovesmarbles > Pile1 / 2) // if user chose pile1 and user wanted to remove more than half
		{
			cout << "The maximum amount you can take from Pile 1 is: " << Pile1 / 2 << endl
				 << endl;
			cout << "Please re-enter the amount you would like to remove: ";
			cin >> Userremovesmarbles;
			cout << endl;
		}

		while (Userremovesmarbles == 0) // if user tries to take zero
		{
			cout << "Cannot take out nothing." << endl
				 << "Please re-enter the amount you would like to remove: ";
			cin >> Userremovesmarbles;
		}

		while ( Userremovesmarbles < 0) // cannot take out negative numbers
		{

			cout << "Cannot take out negative numbers. " << endl
				 << "Re-enter the amount you would like to remove: ";
			cin >> Userremovesmarbles;
		}
		cout << Userremovesmarbles << " marbles has been removed. " << endl\
			 << endl;
		cout << Pile1 - Userremovesmarbles << " is left in Pile 1. " << endl;

		TempPile = Pile1 - Userremovesmarbles;
		Pile1 = TempPile; // updating the value of pile1
	}


	else if (Userchoiceofpile == 2) // user chooses pile2
	{
		
		cout << "How many marbles would you like to remove?"; // amount user wishes to remove
		cin >> Userremovesmarbles;

		while (Userremovesmarbles > 4 && Userremovesmarbles > Pile2 / 2) // user wants to remove more than half
		{
			cout << "The maximum amount you can take from Pile 2 is: " << Pile2 / 2 << endl
				 << endl;
			cout << "Please re-enter the amount you would like to remove: ";
			cin >> Userremovesmarbles;
			cout << endl;
		}

		while (Userremovesmarbles == 0) // user wants to take out zero
		{
			cout << "Cannot take out nothing." << endl
				 << "Please re-enter the amount you would like to remove: ";
			cin >> Userremovesmarbles;
		}

		while ( Userremovesmarbles < 0) // cannot take negative numbers
		{

			cout << "Cannot take out negative numbers. " << endl
				 << "Re-enter the amount you would like to remove: ";
			cin >> Userremovesmarbles;
		}
		cout << Userremovesmarbles << " marbles has been removed. " << endl; 
		cout << Pile2 - Userremovesmarbles << " is left in Pile 2. " << endl;	

		TempPile = Pile2 - Userremovesmarbles;
		Pile2 = TempPile; // updating the value of pile2
	}

	 else if ( Userchoiceofpile == 3) // user wants to take from pile3
	{
		
		cout << "How many marbles would you like to remove?"; // amount user wishes to remove
		cin >> Userremovesmarbles;

		while (Userremovesmarbles > 4 && Userremovesmarbles > Pile3 / 2) // if user wants to take more than half
		{
			cout << "The maximum amount you can take from Pile 3 is: " << Pile3 / 2 << endl
				 << endl;
			cout << "Please re-enter the amount you would like to remove: ";
			cin >> Userremovesmarbles;
			cout << endl;
		}

		while (Userremovesmarbles == 0) // if user wanted to take out zero
		{
			cout << "Cannot take out nothing." << endl
				 << "Please re-enter the amount you would like to remove: ";
			cin >> Userremovesmarbles;
		}

		while ( Userremovesmarbles < 0) // cannot take negative numbers
		{

			cout << "Cannot take out negative numbers. " << endl
				 << "Re-enter the amount you would like to remove: ";
			cin >> Userremovesmarbles;
		}
		cout << Userremovesmarbles << " marbles has been removed. " << endl
			 << endl
			 << endl
			 << Pile3 - Userremovesmarbles << " is left in Pile 3. " << endl;
		TempPile = Pile3 - Userremovesmarbles;
		Pile3 = TempPile;
	}

	if (Userchoiceofpile != 1 && Userchoiceofpile != 2 && Userchoiceofpile != 3) // user didnt choose pile1, pile2, or pile3
	{
		cout << "Invalid answer." << endl 
			 << endl
			 << "Your options are 1,2, or 3 " << endl;

	}

	

	cout << endl;
	cout << endl;
	cout << setw(4) <<  "Pile 1		" << setw(4)<< "Pile 2		" <<setw(4) << "Pile 3" << endl; // displays piles
	cout << "=============================================" << endl
		 << setw(4) << Pile1 << "		" << setw(4) << Pile2 << "		"<< setw(4) << Pile3 << endl;

	cout << endl;
	cout << endl;

	system ("pause");
	cout << endl;
	cout << endl;
	cout << "Now its my turn." << endl; // computer's turn
	cout << endl;
	cout << endl;
	

	if (Pile1 != 0) // if marbles can be taken from pile1, it is the first choice.
	{
	if (Pile1 == 1)
	{
	cout << "I remove 1 marble from Pile1." << endl; // if there is only 1 marble left in pile1.
	cout << endl;
	cout << endl;
	Computerremovesmarbles = 1;
	TempPile = Pile1;
	Pile1 = TempPile - Computerremovesmarbles; 
	}

	else 
	{
		cout << "I remove " << Pile1 / 2 << " marbles from Pile1." << endl; // otherwise, pile1 gets deducted properly.
		TempPile = Pile1;
		Pile1 = TempPile / 2;
	}
	}
	
	else if (Pile2 != 0) // pile1 was empty, so computer moves on to pile2 and does the same steps.
	{
	if (Pile2 == 1)
	{
	cout << "I remove 1 marble from Pile2." << endl;
	cout << endl;
	cout << endl;
	Computerremovesmarbles = 1;
	TempPile = Pile2;
	Pile2 = TempPile - Computerremovesmarbles;
	}

	else 
	{
		cout << "I remove " << Pile2 / 2 << " marbles from Pile2." << endl;
		TempPile = Pile2;
		Pile2 = TempPile / 2;
	}
	}

	else if (Pile3 != 0) // if pile1 and pile2 was empty, computer would arrive at pile3.
	{
	if (Pile3 == 1)
	{
	cout << "I remove 1 marble from Pile3." << endl;
	cout << endl;
	cout << endl;
	Computerremovesmarbles = 1;
	TempPile = Pile3;
	Pile3 = TempPile - Computerremovesmarbles;
	}

	else 
	{
		cout << "I remove " << Pile3 / 2 << " marbles from Pile3." << endl;
		TempPile = Pile3;
		Pile3 = TempPile / 2;
	}
	}

	if (Pile1 < 0) // at the end of a loop, if the piles somehow became negative, this would reset it to zero, before the start of the next loop.
	{
	Pile1 = 0;
	}
	
	if (Pile2 < 0)
	{
	Pile2 = 0;
	}

	if (Pile3 < 0)
	{
	Pile3 = 0;
	}
	} while (Pile1 != 0 || Pile2 != 0 || Pile3 != 0 ); // will loop until all three pile has zero.


	if (Computerremovesmarbles = 1 ) // if computerremovesmarble equals 1, that means the computer took the last marble, therefore user wins.
	{
	
		cout << "Nice! You win!" << endl;
		system ("pause");
		return 0;
	} 

	else // else means the user had to have taken the last marble because the only way user can win is if computer takes the last marble.

		cout << "Aww you lost." << endl
			 << endl
			 << endl
			 << "Better luck next time!" << endl;

	system ("pause");
	return 0;



}
