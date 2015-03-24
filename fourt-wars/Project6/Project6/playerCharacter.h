//FileName:		playerCharacter.h
//Programmer:	Dan Cliburn
//Date:			1/17/2013
//Purpose:		This file defines the header for the PlayerCharacter class

#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "character.h"
#include <string>
#include <stdlib.h>
using namespace std;

class PlayerCharacter : public Character
{
	protected:
		int food;
		int row;
		int col;
		PlayerCharacter *next;
		int killcounter;//Tallies up killcount
		int levelupnow;//# of kills required until next level
		int scoutshonor;//Increases moves for scout.

		int characterlevel;//Keeps track of level.


	public:
		PlayerCharacter(string n = "", int h = 5, int a = 6, int d = 6) : Character(n,h,a,d) 
		{row = 0; col = 0; food = 10; next = 0; killcounter = 0;levelupnow = 1; scoutshonor = 3; characterlevel = 1;}

		void setFood(int f) {food = f;}
		void setRow(int r) {row = r;}
		void setCol(int c) {col = c;}
		void setNext(PlayerCharacter *n) {next = n;}
		void setkillcounter(int k){killcounter = k;}
		void setlevelupnow(int l){levelupnow = l;}
		void setscoutshonor(int s){scoutshonor = s;}
		void setcharacterlevel(int g){characterlevel = g;}
		
		int getFood() {return food;}
		int getRow() {return row;}
		int getCol() {return col;}
		PlayerCharacter *getNext() {return next;}
		int getkillcounter(){return killcounter;}
		int getlevelupnow(){return levelupnow;}
		int getscoutshonor(){return scoutshonor;}
		int getcharacterlevel(){return characterlevel;}

		virtual int moves() {return 1;}
		virtual void heal(PlayerCharacter *u) {u->setHearts(u->getHearts() + 1);  if (u->getHearts() > u->getMAXHEARTS()) u->setHearts(u->getMAXHEARTS());}
};

#endif