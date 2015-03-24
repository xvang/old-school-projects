#include <iostream>

#include <string>

#include <Windows.h>

#include <fstream>

#include <cmath>

#include <ctime>

using namespace std;




int main()
{
	srand((unsigned)time(0));
	
	/*int common;							//When I tested the big do-loop below, I noticed the chosenword did not change.
	for ( int x = 0; x < 1000;x++)			//I wrote the code as "string chosenword = wordbank[rand()%3817];"
	{										// when I tested the rand() on the left, the value of rand() did change.
	common = rand()%2002;					// I can't figure out chosenword didn't change.
	cout << common << endl;
	}*/

	char playornot;

	do // if user wishes to play again. this will loop.
	{
	
	system ("CLS");
	string word;
	ifstream wordlist;
	wordlist.open("sixLetters.txt");
	int x = 0;

	while (!wordlist.eof()) //this counts the number of words in the list. 3817
	{
		getline (wordlist, word);
		x = x++; // x would equal the amount.
	}
	wordlist.close();

	const int sixlettercount = x;

	string wordbank[3817]; /* I tried to write this as "string Wordbank[NumberofWords]", where NumberofWOrds
						  is a const int, "const int NumberofWords = x;" but it didnt work so I had to manually type in 3817. */

	wordlist.open("sixLetters.txt");

	

	while (wordlist.fail()) // if the text did not open
	{
		cout << "File did not open. Try again." << endl;
		system ("pause");
		wordlist.open("sixLetters.txt");
	}
	
	int copy2array = 0; // counter
	while(!wordlist.eof()) // copies the words into the array "wordbank".
	{
		wordlist >> wordbank[copy2array];
		copy2array++;

	}

	wordlist.close();

	ifstream dictionary;

	dictionary.open("dictionary.txt");

	if (dictionary.fail()) // if dictionary.txt cannot open.
	{
		cout << "cant find it." << endl;
	}



	int y = 0; // same function as int x.  this is used to count the number of words in dictionary.txt
	string dictionarybank;
	while (!dictionary.eof())
	{
	getline ( dictionary, dictionarybank);
	y = y++; // y would be the number of words
	}

	const int dictionarycount = y; // stores the number of words in dictionary.txt into a const int.

	string dictionarylist[9314];// I couldn't store the number of words into an int so I had to manually write the number of words.

	dictionary.close();	// I couldn't figure out how to re-read a text file. So I would close it and re-open it.		

	dictionary.open("dictionary.txt");

	int Copydictionarywords = 0; // helps to copy the word onto the array dictionarylist.
	while (!dictionary.eof())
	{
		dictionary >> dictionarylist[Copydictionarywords];

		Copydictionarywords++;
	}
	dictionary.close();

	srand((unsigned)time(0));
	int notimportant = rand()%3817;
	string chosenword = wordbank[notimportant];// randomly chooses a word from the list and stores it in "chosenword" so it
										  // can be used in the game.


	string chosenwordcopy;
	string tempword;
	int wsize;
	int charintempword = 0;
	int wctally = 0;



	for (int x = 0; x < dictionarycount; x++)	// This runs the chosen word against the dictionary.txt to see what words can be made from it.
	{

	chosenwordcopy = chosenword;		// the 'chosenword' variable will be changed in this for-loop, so this line here resets the chosenword to its original value.
	
	tempword = dictionarylist[x];		// stores a word from the dictionary.txt
	wsize = dictionarylist[x].size();	// stores how many spaces a dictionary.txt word takes up.
	charintempword = 0; // counter variable.
	int inbothwords = 0;


	while (charintempword < wsize) // tests all the characters in tempword to see if they match any characters in the chosenword.	 
	{

	if ( tempword[charintempword] == chosenword[0] ||tempword[charintempword] == chosenword[1] ||tempword[charintempword] == chosenword[2] ||tempword[charintempword] == chosenword[3] ||tempword[charintempword] == chosenword[4] ||tempword[charintempword] == chosenword[5] )
	{	
	inbothwords = inbothwords++; // this counts the number of letters in both words.
	}

	charintempword = charintempword++;
	}

	
	if (inbothwords == wsize) // all the characters in tempword is found in chosenword. I could not account for repeating letters in 'tempword'.
	{
		wctally = wctally++; // number of words that are added to wordcount[30]. it starts out at 0.
	}
	
	
	chosenword = chosenwordcopy;
	}

	int wctallyconst = wctally; // to keep a copy of the original wctally value
	string Answer = chosenword; // in case the chosen word gets jumbled and becomes messy. Answer will always contain the chosenword.
	for (int x = 0; x < 100; x++)// switches the letters around 100 times.
	{
		swap (chosenword[rand()%6], chosenword[rand()%6]);
	}
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand()%15+1); // starts the couts.
	cout << "Welcome to the game of Textwist!" << endl << endl
		 << "Your goal is to guess all the word that can be made from the letters given. " << endl << endl
		 << "If you cannot think of anymore words, enter in 'qqq' " << endl << endl
		 << "Good luck and have fun!" << endl << endl << endl;
	system ("pause");

	cout << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand()%15+1);

	cout << "Your letters are: ";
	
	for (int x = 0; x < 6; x++) // couts the scrambled letters.
	{
	cout << chosenword[x]
		 << ", ";
	}
	cout << endl << endl
		 << "Let's start!" << endl << "The word is: " << Answer << endl;

	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand()%15+1);
	system ("pause");

	string guess;

	while (wctally != 0 && guess != "qqq") // loops until wctally reaches zero or user quits
	{

	cout << "Your letters are: ";
	
	for (int x = 0; x < 6; x++) // couts the scrambled letters.
	{
	cout << chosenword[x]
		 << ", ";
	}
	cout << endl;
	cout << "Number of words left: " << wctally << endl << endl;

	cin >> guess;

	cout << endl << endl; // just for spacing.

	if (guess == "qqq") // user wants to quit
	{
		if (wctally < wctally / 2) // user quits, but found more than half of the words.
		{
		cout << "You win!" << endl << "You are a master of Textwist!" << endl;
	system ("pause");

	cout << "Would you like to play again? (y/n): ";
	
	cin >> playornot;

	if (playornot == 'n')
		{ 
			cout << "Good-bye!" << endl;
			system("pause");
			return (0);
		}

		
		}
	cout << "Thanks for playing!. " <<endl;
	system ("pause");
	return 0;
	}
	 // I use Answer instead of chosenword because I think chosen word became permanently jumbled. 
	 // I think the safe thing would be to use Answer. Answer is a const string that I set equal to chosenword
	 // before it became jumbled.
	else if (guess == Answer) // user guesses the word. wins game.
	{
	cout << "You win!" << endl << "You are a master of Textwist!" << endl;
	system ("pause");

	cout << "Would you like to play again? (y/n): ";
	
	cin >> playornot;

	if (playornot == 'n')
		{ 
			cout << "Good-bye!" << endl;
			system("pause");
			return (0);
		}

	}

	else  // did not quit nor win.
	{
		if ( guess != Answer) //
		{
	for (int x = 0; x < dictionarycount; x++) // runs the guess against the dictionarywords
	{	
		int count3 = 0;
		int guesslength = guess.size(); // size of guess length.
		if (guess == dictionarylist[x]) // if guess is in dictionary.
		{
			for ( int y = 0; y < guesslength; y++) // tests to see if guess is also in chosenword.
			{
				if (guess[y] == chosenword[0] ||guess[y] == chosenword[1] || guess[y] == chosenword[2] || guess[y] == chosenword[3] || guess[y] == chosenword[4] || guess[y] == chosenword[5])
					// I dont think it matter if I use chosenword or Answer for this part. They will both contain the same characters.
				{
				count3 = count3++; // goes up by one if the 2 above conditions are met.
				}
			}
		}

		if (count3 == guesslength) // if it is a valid word.
		{
		wctally = wctally--; // "numbers of words left" goes down by one.
		}

	}
	}
		else
		{
		cout << "Invalid input. Try again" << endl;
		}

	}


	}

	if (wctally == 0)
	{
	cout << "You win!" << endl << "You are a master of Textwist!" << endl;
	system ("pause");

	cout << "Would you like to play again? (y/n): ";
	
	cin >> playornot;

	if (playornot == 'n')
		{ 
			cout << "Good-bye!" << endl;
			system("pause");
			return (0);
		}

	
	}
	
	} while (playornot == 'y');
system ("pause");

}


