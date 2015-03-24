#include <iostream>
#include <ctime>

using namespace std;





// I do not know how to write the codes to test the functions. I'm sorry.




// here are functions that are called upon
int Jackpotnumber (int&Jackpot) // function for jackpot game
{
	int JackpotNumber = rand()%101;
	return JackpotNumber;
}

int WontheGame ( int&Balance,  int&Wager, int&Payoff) // function to calculate balance after a win
{
Balance = Balance + Wager*Payoff;
return Balance;
}

int Lostthegame (int&Balance, int&Wager) // calculation for losing a game
{
Balance = Balance - Wager;
return Balance;
}

int main ()
{
	
	srand((unsigned)time(0));
	int Balance = rand()%101 + 100; // random number between 100-200
	int GameChoice;// user selection from menu
	int Wager = 0; // amount that user wishes to bet on each game played. this can change in every game
	int UserNumber; // really only used for the jackpot game.
	int Payoff = 0; // can also change in every game
	int Result = 0; // when calling functions, the data recieved is stored in here. this variable is used in all the games.


	cout << "Hello. Welcome to my Casino." << endl
		 << endl
		 << "Let us start." << endl
		 << endl
		 << "All players are given $100 - $200 to start with." << endl
		 << endl
		 << "Your starting amount is: " << "$" << Balance << endl // random amount between 100-200
		 << endl;

	system ("pause");

	do { // from here on, it's one big do-loop with a bunch of if/if else/else statements. as soon as one game is finished, it skips the remaining codes, and
		 //it loops back up here and displays the menu again. the loop stops when Balance <= 0, or if user chooses option 5, which is to leave.
		
		
	cout << "Here are the games you can play: " << endl << endl
		 << "---------------" << endl << endl
		 << "(1) Jackpot" << endl << endl
		 << "(2) Roulette" << endl << endl
		 << "(3) Craps " << endl << endl
		 << "(4) Slots " << endl << endl
		 << "Or if you want to quit, choose option (5)." << endl 
		 << endl
		 << "Which option do you want? ";
	cin >> GameChoice; // user's selection from the menu.
	cout << endl;
		while ( GameChoice > 5 || GameChoice < 0) // if user entered an invalid number, this will loop. the options are 1-5.
		{
		cout << "That is not an option." << endl
			 << "Here are the games you can play: " << endl << endl
			 << "(1) Jackpot " << endl << endl
			 << "(2) Roulette " << endl << endl
			 << "(3) Craps " << endl << endl
			 << "(4) Slots " << endl << endl
			 << "Or if you want to quit, choose option (5)." << endl 
			 << endl
			 << "Which option do you want? "; 
		   	 cin >> GameChoice;
			 cout << endl << endl;
		}
	if (GameChoice == 5) // user chooses to exit.
	{
	cout << "Good-bye. " << endl << endl
		 << "You leave with a total of: $" << Balance << endl << endl;
	system ("pause");
	cout << endl << endl;
	return 0;
	}



	if (GameChoice == 1) // jackpot game
	{
		int Jackpot;
		int Payoff = 99;
		cout << "Your balance is: $" << Balance << endl << endl;
		if (Balance < 20) // informs user that balance is under $20. the rest of the code for this game will not read.
		{
		cout << "It seems you don't have enough money to play this game." << endl << endl
			 << "There is a $20 minimum wager, and your balance is: " << Balance << endl << endl;
		}

		
	if (Balance > 20) // this prevents user from playing this game because the balance is under $20.
	{
	cout << "Let's play Jackpot. " << endl
		 << endl;
	cout << "How much will you wager? $";
	cin >> Wager;
	cout << endl << endl;

	while (Wager > Balance || Wager < 20) // for invalid wagers. Wager cannot be greater than Balance, nor smaller than $20.
	{
	cout << "You cannot wager less than $20 or more than your balance, which is: " << Balance << ". " << endl << endl
		 << "Please enter your wager: $";
	cin >> Wager;
	}

	cout << "Choose a number between 1 and 100 : ";

	cin >> UserNumber;

	while (UserNumber > 100 || UserNumber < 1) // prevents user from entering in numbers not in the range.
		{
			cout << "Invalid number." << endl << endl
			 << "Choose again. (1 to 100) : ";
			cin >> UserNumber;
			system ("pause");
	}

	Jackpot = Jackpotnumber(Jackpot);
	if (UserNumber == Jackpot) // user picks the jackpot number.
		{
		Result = WontheGame(Wager, Balance, Payoff);
		cout << "The Jackpot Number is: " << Jackpot << endl << endl
			 << "Awesome! You won!" << endl << endl
			 << "Your balance is now: " << Result << endl << endl;
		Balance = Result; // everytime the balance is changed, whether due to winning or losing, this line stores the new value of Balance into the old Balance. 
		system ("pause");
		}

	else // user loses this game.
		{
		Result = Lostthegame ( Balance, Wager);
		cout << "The Jackpot Number is: " << Jackpot << endl << endl
			 << "Bummer. Better luck next time." << endl << endl
			 << "Your balance is now: $" << Result << endl << endl;
		Balance = Result;
		system ("pause");
		}

		if (Balance <= 0) // if user loses all of the money, this will run right before the game ends. it will force the overall code to end.
		{
			cout << "It seems you have run out of money." << endl << endl << "Good-bye" << endl << endl; 
			return 0;
		}
		system ("pause");
	}

	}
	if (GameChoice == 2) // roulette game. 
	{
		char RouletteOption;
		cout << "Your balance is: $" << Balance << endl << endl
			 << "Welcome to Roulette." << endl << endl
			 << "Betting on colors will get x1 payout. Betting on numbers will get x35 payout. " << endl << endl
			 << "How much would you like to wager?: $" ;
	cin >> Wager;

	while ( Wager > Balance || Wager < 1) // restrictions on wager.
	{
	cout << "You can only wager up to: " << Balance << endl << endl
		 << "Enter your wager: ";
	cin >> Wager;
	}
	cout << "Would you like to bet on (c)olors or (n)umbers?: "; // option of betting on colors or numbers.
	cin >> RouletteOption;

	while (RouletteOption != 'c' && RouletteOption != 'C' && RouletteOption != 'n' && RouletteOption != 'N') // will loop if user inputs invalid character.
	{
	cout << "Invalid input. Enter 'c' for colors, and 'n' for numbers. ";
	cin >> RouletteOption;
	}
	

	if (RouletteOption == 'c' || RouletteOption == 'C' )// user chooses to be on color
	{
		int RouletteNumber = rand()%3; // this only allows 1 or 2 as possible answers. 1 will be red. 2 will be black.
		char RedorBlack;
		Payoff = 1;
		cout << "Very well. " << endl << endl
			 << "You can choose between (r)ed and (b)lack. " << endl << endl
			 << "Which color will you bet on?: " ;
		cin >> RedorBlack; 

		while (RedorBlack != 'r' && RedorBlack !='R' && RedorBlack != 'b' && RedorBlack != 'B') // restricts invalid answer.
		{
		cout << "That was not an option. (r)ed or (b)lack?: " ;
		cin >> RedorBlack;
		}

		if (RouletteNumber == 1) // 1 means red
		{
			cout << "The ball landed on: RED " << endl << endl; 
		}

		else // 2 means black. 
		{
		cout << "The ball landed on: BLACK " << endl << endl; 
		}

		if (RedorBlack == 'r' || RedorBlack == 'R') // user bets on red
		{
			if (RouletteNumber == 1) // roll was red
			{
				cout << "You won! " << endl << endl;
				Result = WontheGame(Balance, Wager, Payoff);
				cout << "Your balance is now: $" << Result << endl << endl;
				Balance = Result;
				system ("pause");
			}

			if (RouletteNumber != 1) // roll was black
			{
			Result = Lostthegame(Balance, Wager);
			cout << "You lost." << endl << endl
				 << "Your balance is now: $" << Result << endl << endl;
			Balance = Result;
		
			}
			system ("pause");
		}


		if (RedorBlack == 'b' || RedorBlack == 'B') // user bets on black.
		{
			if (RouletteNumber != 1) // roll was not 1, therefore it was black
			{
				cout << "You won! " << endl << endl;
				Result = WontheGame(Balance, Wager, Payoff);
				cout << "Your balance is now: $" << Result << endl << endl;
				Balance = Result;
			}

			if (RouletteNumber == 1) // roll was 1 , therefore it was red.
			{
			Result = Lostthegame(Balance, Wager);
			cout << "You lost." << endl << endl
				 << "Your balance is now: $" << Result << endl << endl;
			Balance = Result;
			}
		}
	}


	if (RouletteOption == 'n' || RouletteOption == 'N') // user wants to bet on numbers
		{
			int Chosenumber = rand()% 37; // will give numbers from 1-36
			int RouletteNum;
			Payoff = 35; // payoff is 35x
			cout << "Choose a number between 1 and 36: ";
			cin >> RouletteNum;

			while ( RouletteNum < 1 || RouletteNum > 36) // restricts invalid inputs
			{
			cout << "It is not possible to win with that number. " << endl << endl
				 << "Choose a number between 1 and 36: ";
			cin >> RouletteNum;
			}

			if (Chosenumber == 0) // if Chosenumber happened to be 0
			{	
				Result = Lostthegame(Balance, Wager);
				cout << "Whoops! the ball landed on a: " << Chosenumber << endl << endl
					 << "You lose." << endl
					 << "Your balance is now: $" << Result << endl << endl;
				Balance = Result;
					
			}

			else if ( Chosenumber == RouletteNum) // the spin landed on the selected number. win
			{
				cout << "The ball landed on: " << Chosenumber << endl << endl
					 << "You won!" << endl << endl;
				Result = WontheGame(Balance, Wager, Payoff);
				cout << "Your balance is now: $" << Result << endl << endl;
				Balance = Result;
			}

			else // ball didnt land on selected number. lose
			{
				cout << "The ball landed on: " << Chosenumber << endl << endl
					 << "You lose." << endl << endl;
				Result = Lostthegame(Balance, Wager);
				cout << "Your balance is now: $" << Result << endl << endl;
				Balance = Result;
			
			}
			system ("pause");
		}

			if (Balance <= 0) // once again, at the end of every game, if the balance became zero, this will force the game to end. 
			{
				cout << "It seems you have run out of money." << endl << endl << "Good-bye" << endl << endl;
				return 0;
			}
			}
	
	
	if (GameChoice == 3) // craps game
	{
	int Dice1 = rand()% 6 + 1; 
	int Dice2 = rand()% 6 + 1;
	int Dice3 = rand()% 6 + 1;
	int Dice4 = rand()% 6 + 1;
	int Roll = Dice1 + Dice2;
	int Roll2 = Dice3 + Dice4;
	char Passnp;
	Payoff = 1;
	cout << "Let's play Craps." << endl
		 << "How much would you like to wager?: $";
	cin >> Wager;

	while (Wager > Balance || Wager < 1) // restricts wager
	{
	cout << "You can only bet up to: " << Balance << endl
		 << "Please enter your wager: $";
	cin >> Wager;
	}

	cout << "Please choose: (p)ass or (n)o-pass: ";
	cin >> Passnp;

	while (Passnp != 'p' && Passnp != 'P' && Passnp != 'n' && Passnp!= 'N') // restricts invalid letter input
		{
			cout << "That is not an option. (p)ass or (n)o-pass: " ;
			cin >> Passnp;
		}

	if (Passnp == 'n' || Passnp == 'N') // this runs if user chose 'no pass'
	{
		if ( Roll == 2 || Roll == 3 || Roll == 12 || Roll == 7 || Roll == 11) // user wins
		{	
			Result = WontheGame(Balance, Wager, Payoff);
			cout << "You rolled a: " << Dice1 << " and a " << Dice2 << " for a total of " << Roll << endl
				 << "You win!" << endl
				 << "Your Balance is now: $" << Result << endl << endl;
			Balance = Result;
			

		}
		
		

		else if ( Roll != 2 && Roll != 3 && Roll != 12 && Roll != 7 && Roll != 11) // user didnt win, dice rolls again.
		{
			cout << "You rolled a: " << Dice1 << " and a " << Dice2 << " for a total of " << Roll << endl
				 << "The dices are rolled again." << endl;

			
			do{ // this counts as the second roll. it loops until either the roll equals 7 or the roll equals the original roll.
			 Dice3 = rand()% 6 + 1;
			 Dice4 = rand()% 6 + 1;
			 Roll2 = Dice3 + Dice4;
			} while ( Roll2 != 7 && Roll2 != Roll);

			if (Roll2 == 7) // roll equals 7. user wins
			{
				Result = WontheGame(Balance, Wager, Payoff);
				cout << "You rolled a: " << Dice3 << " and a " << Dice4 << " for a total of " << Roll << endl
					 << "You win!" << endl
					 << "Your Balance is now: $" << Result << endl << endl;
				Balance = Result;
			}

			else if (Roll2 == Roll) // roll equals original roll. user loses.
			{
				Result = Lostthegame (Balance, Wager);
				cout << "You rolled a: " << Dice3 << " and a " << Dice4 << " for a total of " << Roll << endl
					 << "You lose" << endl
					 << "Your balance is now: $" << Result << endl << endl;
				Balance = Result;
			}
		}
	}

	else if (Passnp == 'p' || Passnp == 'P') // its almost the same piece of code as the one above, except this one the user chooses 'pass'
	{
		if (Roll == 2 || Roll == 3 || Roll == 12) // user loses
		{
			Result = WontheGame(Balance, Wager, Payoff);
			cout << "You rolled a: " << Dice3 << " and a " << Dice4 << " for a total of " << Roll << endl
				 << "You lose." << endl
				 << "Your balance is now: $" << Result << endl << endl;
			Balance = Result;
		}

		else if ( Roll == 7 || Roll == 11) // user wins
		{
			Result = WontheGame(Balance, Wager, Payoff);
			cout << "You rolled a: " << Dice3 << " and a " << Dice4 << " for a total of " << Roll << endl
			 << "You win!" << endl << "Your balance is now: $" << Result << endl << endl;
			Balance = Result;
		}

		else // have to roll dice again.
		{
		cout << "You rolled a: " << Dice1 << " and " << Dice2 << " for a total of: " << Roll << endl
			 << "You roll the dice again. " << endl << endl;
		do{
			 Dice3 = rand()% 6 + 1;
			 Dice4 = rand()% 6 + 1;
			 Roll2 = Dice3 + Dice4;
			} while ( Roll2 != 7 && Roll != Roll2);

		if (Roll2 == 7)
		{
			Result = WontheGame (Balance, Wager, Payoff);
			cout << "You rolled a: " << Dice3 << " and a " << Dice4 << " for a total of " << Roll << endl
				 << "You win!" << endl << "Your balance is now: $" << Result << endl << endl;	
			Balance = Result;
		}

		else if ( Roll == Roll2)
		{
			Result = WontheGame(Balance, Wager, Payoff);
			cout << "You rolled a: " << Dice3 << " and a " << Dice4 << " for a total of " << Roll << endl
				 << "You lose." << endl
				 << "Your balance is now: $" << Result << endl;
			Balance = Result;
		}
		}
	}

			if (Balance <= 0)
		{
			cout << "It seems you have run out of money." << endl << "Good-bye" << endl;
			return 0;
		}
			system ("pause");
	}



	
	if ( GameChoice == 4) // slots game
	{
		
	
	int Slot1 = rand()%10;
	int Slot2 = rand()%10;
	int Slot3 = rand()%10;
	
	cout << "Your balance is: $" << Balance << endl << endl
		<< "Please enter your wager: $";
	cin >> Wager;

	while (1 > Wager || Wager > Balance) //restrictions 
	{
	cout << " You don't have that much money. You wager up to: " << Balance << endl
		 << "Please enter your wager: $";
	cin >> Wager;

	}

	if (Slot1 == Slot2  && Slot1 == Slot3) // if all three slots match. 
	{
		Payoff = 99;
		Result = Lostthegame(Balance, Wager);
		cout << "The slot machine landed on: " << Slot1 << "|" << Slot2 << "|" << Slot3 << endl 
			 << "You won!" << endl 
			 << "Your balance is now: $" << Result << endl;
		Balance = Result;

	}
	
	else if (Slot1 == Slot2 || Slot1 == Slot3 || Slot2 == Slot3)// if 2 of the 3 slots match.
	{
		Payoff = 10;
		Result = WontheGame(Balance, Wager, Payoff);
		cout << "You won!" << endl
			 << "The slot machine landed on: " << Slot1 << "|" << Slot2 << "|" << Slot3 << endl
			 << "Your balance is now: $" << Result << endl;
		Balance = Result;
	}


	else // no matching pairs.
	{
		Result = Lostthegame(Balance, Wager);
		cout << " You didn't win this time. " << endl
			 << "The slot machine landed on: " << Slot1 << "|" << Slot2 << "|" << Slot3 << endl;
		Balance = Result;
	}

			if (Balance <= 0)
		{
			cout << "It seems you have run out of money." << endl << "Good-bye" << endl;
			system ("pause");
			return 0;
		}
	system ("pause");
	}
	
	} while (Balance != 0 && GameChoice != 5); // conditions for the loop.



	system ("pause");

} // int main ends here


