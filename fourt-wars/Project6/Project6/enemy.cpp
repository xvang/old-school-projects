//FileName:		enemy.cpp
//Programmer:	Dan Cliburn
//Date:			1/14/2013
//Purpose:		This file defines the methods for the rat class//.....rat??

#include "enemy.h"
#include "character.h"
#include "location.h"
#include <Windows.h>
Enemy::Enemy(string n, int h, int a, int d, char s) : Character(n,h,a,d), Location(s)
{
	;
}

void Enemy::draw()
{
	if (visited == false) 
		cout << ".";
	else if (visited == true && hearts <= 0)
		cout << " ";
	else
		cout << symbol;
}

int Enemy::visit(Player &p)
{
	if (hearts > 0) //There will be an enemy here as long as it has hearts
	{
		PlaySound(TEXT ("185095__nicolasdrweski__la-mer-csound.wav"), NULL, SND_FILENAME | SND_SYNC);//3 seconds
		cout << "You found a " << name << endl;
		visited = true;
		return 2;  //2 indicates that a battle should be fought
	}
	else
		return 1; //nothing happens
}