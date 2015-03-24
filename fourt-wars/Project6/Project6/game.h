//FileName:		game.h
//Programmer:	Dan Cliburn
//Date:			1/14/2013
//Purpose:		This file defines the header for the Game class

#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "character.h"
#include "playerCharacter.h"
#include "enemy.h"
#include "location.h"
#include "item.h"
#include <Windows.h>
#include <vector>
class Game
{
	protected:
		Location ***world;
		Player p;
		PlayerCharacter *current; //New for Project 6

		int rows;
		int cols;
		//int playerRow; //removed for Project 6
		//int playerCol; //removed for Project 6
		vector <char> movetolose;

	public:
		Game();

		//Required Methods
		void instructions();
		void setUpGame(int level);
		void playGame();
		void drawGame(int level, int unitcount, vector <char> lost);

		int battle(Character *u, Enemy *e);
		void foundItem(Character *u, Item *i);
		char getKeyPress();
		bool healCharacter(Player &p, PlayerCharacter *healer, int healerlevel);

		void space(){cout << endl << endl << endl;}//For spacing

		//Set/Get methods for vector.
		void setmovetolose()
		{//This sets the # of moves allowed. I made the move limit to be half of max # of moves.
			for(int x = 0; x < rows*cols/2; x++)
				movetolose.push_back('*');
		}

	

		void redtext(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);}//bright red text
		void pinktext(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);}//pink text
		void aquatext(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);}//light aqua text
		void greentext(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);}//light green text
		void normaltext(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}//normal text
		void bluetext(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);}//blue text.
		void otheraquatext(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);}//agua text. I realize the better name would have been
		                                                                                  //aquatext(), but that name is taken.

		void othergreentext(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);}//normal green text
		void purpletext(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);}//purple text
		void muddyyellowtext(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);}//muddy level text
		~Game();
};

#endif