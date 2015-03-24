#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <ctime>

using namespace std;


void Intro(); // Greets the User and explains the rules
void changecolor(); // changes color of text to a random color
void yellowtext(); // changes text to bright yellow
void bluetext(); // changes text to light blue
void redtext(); // changes text to bright red
void whitetext(); // changes text to bright white
void greentext(); // changes text to light green
void space(); // just for spacing
void title(); // displays the title
void DeclareWinner(int, string, string); // declares a winner
void PlayerOneWon(string); // couts "player 1 won" message
void PlayerTwoWon(string);// couts "player 2 won" message
void Congratulations(); // couts "Is the Winner!" 


class cFour
{
private: char board[6][7] = { { ' ' } };

public: 
		void displayBoard() // Displays the board. 
		{
			for (int row = 0; row < 6; row++) 
			{
				int WillNeverUseAgain = 1; // This is just a counter
				cout << setw((80 - 16) / 2); // To make the board centered.

				for ( int col = 0; col < 7; col++) 
				{
					if (WillNeverUseAgain == 1)
					{
						bluetext(); // I wanted to the first line of every row to be blue. 
						cout << "|";
						WillNeverUseAgain++;/* This makes sure the if-statement is only read once
											   while in the second for-loop*/
					}

					else // This makes the lines that separate the X's and O's yellow.
					{
					yellowtext(); 
					cout << "|";
					}


					if (board[row][col] == 'X') // If the value is 'X', the text color is changed to green.
					{
						greentext();
					}
					
					if (board[row][col] == 'O') // If the value is 'O', the text color is changed to red.
					{
						redtext();
					}
					cout << board[row][col]; // Outputs the value after the color changes. Can be either green 'X', red 'O', or empty space.
				}
			bluetext(); // These last couple of lines are just design.
			cout << "| " << row << endl; 
			}
			cout << setw(46) << "_______________" << endl << setw((80 - 16) / 2)
				 << " " << "0" << " " << "1" << " " << "2" << " " << "3" << " " << "4" << " " << "5" << " " << "6" << endl << endl;
		}

		int checkMove(int&colll) // Checks to see if move is legal. 
		{
			while (colll > 6 || colll < 0) // If user input is not between 0-6
			{
				cout << "That is out of range. " << endl << endl
					 << "Enter a valid column number(0-6): ";
				cin >> colll;
			}
				
				while (board[0][colll] != ' ') /* If the top spot in chosen column is filled,
											   then that means column is full*/
				{
					cout << "That column is full." << endl << endl
						 << "Please choose another: ";
					cin >> colll;

					while (colll > 6 || colll < 0) // Have to restrict input again.
					{
						cout << "That is out of range. " << endl << endl
							 << "Enter a valid column number(0-6): ";
						cin >> colll;
					}
				}
			
		
		return colll;// Updates player's chosen "col" in int main.
		}

		int updateBoard(int&classCol, int&TakeTurns)/*Takes in column user selects and whose turn it is*/
		{
			for (int ROW = 5; ROW >= 0; ROW--)
			{
				
				if (board[ROW][classCol] != 'O' && board[ROW][classCol] != 'X') /* for example, if board[5][classCol] does not have 'X' or 'O', 
																				then 'X' or 'O' is stored in there, depending on whose turn it is.
																				If row 5 is full, then it moves on to row 4, and so on. */
				{
					if (TakeTurns == 1) // Player 1's turn. 'X' will be stored.
					{
					board[ROW][classCol] = 'X';
					TakeTurns++;
					return TakeTurns; // By returning here, it ends the loop so 'X' or 'O' isn't stored in multiple rows for one turn.
					}

					if (TakeTurns == 2)// Player 2's turn. 'O' will be stored.
					{
					board[ROW][classCol] = 'O';
					TakeTurns--; 
					return TakeTurns;
					}
					
				}
			}
		}

		bool isFull() // Checks if board is full.
		{	
			int counter = 0; // counts the empty spaces on the board

			for ( int COL = 0; COL < 7; COL++) // Checks all the column
			{
				if ( board[0][COL] == 'X' || board[0][COL] == 'O')// 0 is the very top slot
				{
					counter++; 
				}
			}

			if (counter == 7) // If counter = 0, that means all spaces are filled. "False" is returned, and it ends the do-loop.
			{
				space();
				whitetext();
				cout << "No more spaces are left. " << endl << endl // I couldn't figure out why this message gets cout multiple times.
					<< "There is no winner this round." << endl << endl;
				return false;
			}

			else 
			{
				return true; // do-loop will keep looping if this is returned.
			}
		}

		int hasWon(int & WWWinner)
		{
			for (int JustOnce = 0; JustOnce < 1; JustOnce++) /* This for-loop goes through all the options for winning once. If an option is met, 
																then the 'return' command is executed, and hasWon() ends. If there is no winner,
																it returns WWWinner = 0 and that continues the game.*/
			{
			for (int RWcol = 0; RWcol < 7; RWcol++) // User wins vertically.
			{
				for (int RWrow = 5; RWrow > 2; RWrow--)
				{
					if ( board[RWrow][RWcol] == 'X' && board[RWrow - 1][RWcol] == 'X' && board[RWrow - 2][RWcol] == 'X' && board[RWrow - 3][RWcol] == 'X')
					{
						return WWWinner = 1;
					}

					else if ( board[RWrow][RWcol] == 'O' && board[RWrow - 1][RWcol] == 'O' && board[RWrow - 2][RWcol] == 'O' && board[RWrow - 3][RWcol] == 'O')
					{
						return WWWinner = 2;
					}
				}
			}
				for ( int DWcol = 0; DWcol <= 3; DWcol++) // User wins diagonally bottom left to top right.
				{
					
					for (int DWrow = 5; DWrow > 2; DWrow--)
					{
						if (board[DWrow][DWcol] == 'X' && board[DWrow - 1][DWcol + 1] == 'X' && board[DWrow - 2][DWcol + 2] == 'X' && board[DWrow - 3][DWcol + 3] == 'X')
						{
							return WWWinner = 1;
						}

						else if (board[DWrow][DWcol] == 'O' && board[DWrow - 1][DWcol + 1] == 'O' && board[DWrow - 2][DWcol + 2] == 'O' && board[DWrow - 3][DWcol + 3] == 'O')
						{
							return WWWinner = 2;
						}
					}
				}

				for ( int CWrow = 5; CWrow >= 0; CWrow--) // User wins horizontally.
				{
					for (int CWcol = 0; CWcol < 4; CWcol++)
					{
						if ( board[CWrow][CWcol] == 'X' && board[CWrow][CWcol + 1] == 'X' && board[CWrow][CWcol + 2] == 'X' && board[CWrow][CWcol + 3] == 'X')
						{
							return WWWinner = 1;
						}

						else if (board[CWrow][CWcol] == 'O' && board[CWrow][CWcol + 1] == 'O' && board[CWrow][CWcol + 2] == 'O' && board[CWrow][CWcol + 3] == 'O')
						{
							return WWWinner = 2;
						}
					}
				}

				for (int CW2row = 5; CW2row >= 0; CW2row--)// User wins diagonally bottom right to top left.
				{
					for (int CW2col = 6; CW2col >= 3; CW2col--)
					{
						if (board[CW2row][CW2col] == 'X' && board[CW2row - 1][CW2col - 1] == 'X' && board[CW2row - 2][CW2col - 2] == 'X' && board[CW2row - 3][CW2col - 3] == 'X')
						{
							return WWWinner = 1;
						}

						else if (board[CW2row][CW2col] == 'O' && board[CW2row - 1][CW2col - 1] == 'O' && board[CW2row - 2][CW2col - 2] == 'O' && board[CW2row - 3][CW2col - 3] == 'O')
						{
							return WWWinner = 2;
						}
					}
				}
			} 
			return WWWinner = 0; // If no one wins, '0' is returned and the game goes on.
		}

		void hostGame()
		{
			string name1;
			string name2;
			string Replay;
		
			space(); // space() just consists of cout << endl << endl << endl;
			space();
			space();
			space();
			cout << setw(50);
			cout << "Enter in Player 1's name: ";
			getline(cin, name1);
			system ("CLS");

			space();
			space();
			space();
			space();
			cout << setw(50);
			cout << "Enter in Player 2's name: ";
			getline(cin, name2);

			do
			{	
			system ("CLS");
			int col;
			int player = 1; /* When player = 1, it is Player 1's turn. 
							   When player = 2, it is player 2's turn. 
							   After Player 1's turn, player++. 
							   After Player 2's turn, player--.*/

			int Winner = 0;/*Same concept here. If Player 1 wins, "Winner = 1" after hasWon(). 
						     If Player 2 wins, "Winner = 2" after hasWon().
						     Otherwise, "Winner = 0" and the game continues.*/

			makeBoard(); // This sets ' ' as all the values of board[6][7]. It is only called one time per game.

			displayBoard();

			do // This is where the users take turns.
			{
				cout << endl << endl;
				whitetext();
				cout << name1 << "'s turn. Column: "; // Player 1's turn. player = 1
				cin >> col;
				space();
				checkMove(col);
				updateBoard(col, player);
				displayBoard();
				hasWon(Winner);
				DeclareWinner(Winner, name1, name2);
				whitetext();
	
			if (hasWon(Winner) == 0)/* If Player 1 wins, then hasWon(Winner) has already returned '1' during player 1's turn. 
									Player 2 should not be allowed to move one last time before the game ends.
									If Player 2 wins, then the do-loop is already done, and the game just ends.
									Otherwise, 0 is returned for Winner, and the game continues.*/								
			{
				cout << name2 << "'s turn. Column: "; // Player 2's turn. player = 2
				cin >> col;
				checkMove(col);
				updateBoard(col, player);
				displayBoard();
				hasWon(Winner);
				DeclareWinner(Winner, name1, name2);
				isFull();
			}

		} while (isFull() == true && hasWon(Winner) == 0); // Will loop until somebody wins or the gameboard is full.

		space();
		greentext();
		cout << "Would you like to play again?(yes/no): ";
		cin >> Replay;

		/*While-loop is for restricting user input*/
		while (Replay != "Y" && Replay != "y" && Replay != "Yes" && Replay != "yes" 
				&& Replay != "n" && Replay != "N" && Replay != "No" && Replay != "no" && Replay != "NO")
		{
			cout << endl << endl;
			cout << "Invalid answer." << endl << endl
				 << "Would you like to play again? ";
			cin >> Replay;
		}

		if (Replay == "n" || Replay == "N" || Replay == "No" || Replay == "no" || Replay == "NO")
		{ /*If users want to quit*/
			system("CLS");
			space();
			space();
			space();
			space();
			string EndMessage = "THANKS FOR PLAYING!";
			int EMlength = EndMessage.length();
			int Number = (80 - EMlength*2) / 2; /* This is to make the EndMessage centered.
												   This equation is used alot.*/

			for (int y = 0; y < Number; y++)
			{
				changecolor();
				cout << "~";
			}

			cout << " ";
			for (int x = 0; x < EMlength - 1; x++) // couts message in EndMessage. The ( - 1) accounts for the (cout << " ";) above
			{
				changecolor();
				cout << EndMessage[x] << " ";
			}

			for (int y = 0; y < Number; y++)
			{
				changecolor();
				cout << "~";
			}			

		}

	}while (Replay == "Y" || Replay == "yes" || Replay == "y" || Replay == "Yes"); // If User wants to replay.

		}
};

int main()/****************************************/
{
	srand((unsigned)time(0));

	cFour game;

	Intro(); // Outputs all the dialogues and general rules.

	game.hostGame(); //Runs the game.

	space();
	space();
	system ("pause");
}/**************************************************/

void Intro()
{
	
	
	title(); // displays the title.
	whitetext();
	cout << "Hello." << endl << endl
		 << "Welcome to Connect Four. " << endl << endl
		 << "This is a two player game. " << endl << endl
		 << "First person to get four chips in a row wins!" << endl << endl;
	system ("pause");
	space();
	cout << "The first player will be: ";
	greentext();
	cout << "X" << endl << endl;
	whitetext();
	cout << "The second player will be: ";
	redtext();
	cout << "O" << endl << endl;
	whitetext();

	cout << "First player goes first. " << endl << endl
		 << "Enter in Column Number (0-6) that you " << endl
		 << "wish to drop your chip into. " << endl << endl;
	
	system ("pause");
	space();
	system("CLS");
}

void changecolor() // These just change the colors
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),rand()%5 + 10);
}

void yellowtext()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}

void bluetext()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
}

void redtext()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
}

void whitetext()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void greentext()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
}

void space()
{
cout << endl << endl << endl;
}

void title()
{
	space();
	string title = "CONNECT FOUR";
	int titlelength = title.length();

	cout << setw(20);

	int tcounter = 1;
	for (int x = 0; x < 42; x++)
	{
		if (tcounter == 1)
		{
		changecolor();
		cout << "/";
		tcounter++;
		}

		else if (tcounter == 2)
		{
			changecolor();
			cout << "\\";
			tcounter--;
		}
	}

	cout << endl << endl;


	cout << setw((80 - 2*titlelength - 1) / 2);

	changecolor();
	cout << " ";
	for (int x = 0; x < titlelength; x++)
	{
		changecolor();
		cout << title[x];
		changecolor();
		cout << " ";
	}

	cout << endl;
	cout << setw(20);
	cout << endl;
	int tcounter2 = 1;
	for (int x = 0; x < 42; x++)
	{
		if (tcounter2 == 1)
		{
		changecolor();
		cout << "\\";
		tcounter2++;
		}

		else if (tcounter2 == 2)
		{
			changecolor();
			cout << "/";
			tcounter2--;
		}
	}

	cout << endl;
	space();
}



void DeclareWinner(int JJJ, string DWname1, string DWname2)/*Takes in the Winner value and the 2 names of the users.*/
{
	
	if (JJJ == 1)
	{
		PlayerOneWon(DWname1); 
	}

	if (JJJ == 2)
	{
		PlayerTwoWon(DWname2); 
	}

}

void PlayerOneWon(string POWname1) // couts the message saying player 1 won
{
	space();
	int lengthOfname = POWname1.length();
	string WinMessage = "Is The Winner!";
	int lengthofWM = WinMessage.length();

	cout << setw(20);
	for (int x = 0; x < 42; x++)
	{
		changecolor();
		cout << "*";
	}
	cout << endl;
	cout << setw((80 - 2*lengthOfname - 1 ) / 2);

	cout << " ";
	for (int count = 0; count < lengthOfname; count++)
	{
		changecolor();
		cout << POWname1[count];
		changecolor();
		cout << " ";
	}
	cout << endl;
	cout << setw(20);
		for (int x = 0; x < 42; x++)
		{
			changecolor();
			cout << "*";
		}

	cout << endl;

	cout << setw((80 - 2*lengthofWM) / 2);

	for (int wmcount = 0; wmcount < lengthofWM; wmcount ++)
	{
		changecolor();
		cout << WinMessage[wmcount];
		cout << " ";
	}
	space();
}

void PlayerTwoWon(string POWname2)// couts the message saying player 2 won
{

	space();
	int lengthOfname2 = POWname2.length();
	string WinMessage = "Is The Winner!";
	int lengthofWM = WinMessage.length();

	cout << setw(20);
	for (int x = 0; x < 42; x++)
	{
		changecolor();
		cout << "*";
	}
	cout << endl;
	cout << setw((80 - 2*lengthOfname2 - 1 ) / 2);

	cout << " ";
	for (int count = 0; count < lengthOfname2; count++)
	{
		changecolor();
		cout << POWname2[count];
		changecolor();
		cout << " ";
	}
	cout << endl;
	cout << setw(20);
		for (int x = 0; x < 42; x++)
		{
			changecolor();
			cout << "*";
		}

	cout << endl;

	cout << setw((80 - 2*lengthofWM) / 2);

	for (int wmcount = 0; wmcount < lengthofWM; wmcount ++)
	{
		changecolor();
		cout << WinMessage[wmcount];
		cout << " ";
	}
	space();
}




 