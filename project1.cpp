#include <iostream>

#include <string>

#include <ctime>

using namespace std;

int main ()

{
	// XENG VANG 
	srand((unsigned)time(0)); // Initialize random number generator (ONCE);
	int Firstcard = rand()%10 + 1; 
	int Secondcard = rand()%10 + 1;
	int Firsttwocards = Firstcard + Secondcard;
	int Dealerhand = rand()% 7 + 17;
	int Userhand = Firsttwocards;

	string Restart;
	string Hitorstay;
	string readyOrnot;


	cout << "Welcome to Xeng's Casino!" << endl
		 << endl
		 << endl;

	cout << "This game is called Blackjack." << endl
		 << endl
		 << endl;

	cout << "The object is to get as close to 21 as possible without going over." << endl
		 << endl
		 << endl;

	cout << "Would you like to start?  (yes/no)" << endl
		 << endl
		 << endl;

	cin >> readyOrnot;
	cout << endl
		 << endl;

	while ( readyOrnot != "no" && readyOrnot != "No" && readyOrnot != "n" && readyOrnot != "N" && readyOrnot != "yes" && readyOrnot != "Yes" && readyOrnot != "y" && readyOrnot != "Y")
	{
	cout << "Invalid answer. " << endl
		 << endl
		 << endl
		 << "Would you like to start? (yes/no): ";
	cin >> readyOrnot;
	cout << endl
		 << endl;
	
	}
	if (readyOrnot == "no" || readyOrnot == "No" || readyOrnot == "n" || readyOrnot == "N") // user does not want to play.
	{
		cout << "Okay. You can always play later." << endl;
		cout << endl;
		cout << endl;

		system ("pause");

		return 0;
	}
	
	do // if user wants to play again, this loops the whole thing. I added this "do" loop at the very end. 
	   //"readyOrnot" will always equal "yes" even though this "do" loop doesn't ask for an input for "readyOrnot".
	{

	if (readyOrnot == "yes" || readyOrnot == "Yes" || readyOrnot == "y" || readyOrnot == "Y") // User wishes to start.
	{
	int Firstcard = rand()%10 + 1; // every loop generates different values for these ints.
	int Secondcard = rand()%10 + 1;
	int Firsttwocards = Firstcard + Secondcard;
	int Dealerhand = rand()% 7 + 17;
	int Userhand = Firsttwocards;
	
		cout << endl
			 << endl
			 << "Great! Lets get started!" << endl
			 << endl
			 << endl;

		cout << "Your first two cards are:   " << Firstcard;
		cout << " and: " << Secondcard << endl;
		cout << endl;
		cout << endl;

		cout << "Your hand is now:  ";
		cout << Firsttwocards << endl;
		cout << endl;
		cout << endl;
	}

	
	do
	{
	
	cout << "Would you like to hit or stay?  "; // first hit or stay option
	cin >> Hitorstay;
	cout << endl;
	cout << endl;
	
	while (Hitorstay != "hit" && Hitorstay != "h" && Hitorstay != "stay" && Hitorstay != "s")
	{
	cout << "That is not an option." << endl
		 << endl
		 << endl
		 << "Hit or stay? ";
	cin >> Hitorstay;
	cout << endl
		 << endl;
	}

	if (Hitorstay == "hit" || Hitorstay == "h") // user elects to hit after first two cards
	{
		
		int Dealerdeals = rand()%10 + 1; // random number will change each time this loop is executed.
		cout << "You have been dealt a:  " << Dealerdeals << endl; 
		cout << endl;
		cout << endl;

		cout << "Your hand is now: ";
		Userhand = Userhand + Dealerdeals;
		cout << Userhand << endl;
		cout << endl;
		cout << endl;

	} 
	
	if (Hitorstay == "stay" || Hitorstay == "s") // user chooses to stay

	{
	cout << "Very well." << endl
		 << endl
		 << endl;
	}
	
	} while (Hitorstay == "hit" || Hitorstay == "h" && Userhand <= 21); // this loops allows user to hit as many time as desired until user's hand is over 21.
	

	system ("pause");
	
	if (Userhand > 21) // user went over 21 and loses automatically.
	{
	cout << "Sorry, you went over." << endl
		 << endl
		 << endl
		 << "Dealer wins." << endl;

	system ("pause");
	cout << endl
		 << endl;
	}


	if (Userhand <= 21) // user is under 21 or has 21. This "if" reaches all the way down to right before "would you like to play again? (yes/no)?".
	{
	cout << "Dealer has: " << Dealerhand << endl
		 << endl
		 << endl;

	if (Dealerhand > 21) // dealer goes over.
	{
	cout << "Congratulations! You win!" << endl
		 << endl
		 << endl;

	system ("pause");
	cout << endl
		 << endl;


	}

	else if ( Dealerhand == Userhand ) // neither has gone over and they are equal.
	{
	cout << "Nobody wins." << endl
		 << endl
		 << endl;

	system("pause");
	cout << endl
		 << endl;

	}

	else if (Userhand > Dealerhand ) // user has better hand.
	{
	cout << "Congratulations! You win!" << endl
		 << endl
		 << endl;

	system ("pause");
	cout << endl
		 << endl;

	}

	else if (Dealerhand > Userhand) // dealer has better hand.
	{
	cout << "Dealer has better hands" << endl
		 << endl
		 << endl
		 << "Dealer wins!" << endl;
	system("pause");
	cout << endl
		 << endl;

	}
	}

	cout << "Would you like to play again? (yes/no): "; 
	cin >> Restart;
	cout << endl
		 << endl;
	while (Restart != "yes" && Restart != "Yes" && Restart != "y" && Restart != "Y" && Restart != "no" && Restart != "n")
	{
	
	cout << "Invalid answer." << endl
		 << endl
		 << endl
		 << "Would you like to play again? (yes/no): ";
	cin >> Restart;
	}
	

	} while (Restart == "yes" || Restart == "Yes" || Restart == "y" || Restart == "Y"); // this allows user to play again.

	cout << "Thanks for playing! " << endl; // 

	system ("pause");

	return 0;

	}