//FileName:		main.cpp
//Programmer:	Dan Cliburn
//Date:			1/14/2013
//Purpose:		This file defines the main function for Fourt Wars

/************************************************************************

Edited By: Xeng Vang

Project 8

COMP 053

4/23/2013


- I did very little significant changes outside of game.cpp, 
so I'm only posting this message in here and in game.cpp().
*************************************************************************/
#include "game.h"

int main()
{
	Game g;
	
	g.playGame();

	return 0;
}

/**********************************************************************************
NEW STUFF FOR PROJECT 8

- Levels. I made and setUpGame() take "int level" as an input. Once a level is won, 
user has option to move on or quit. Each level should increase map by +3 rows and +3 cols.
The limit is 5 levels.

- Colors. Added a bunch of functions into game.h to change colors.

- Leveling up. Characters level up with more enemies killed. 
To attempt to implement it, I added "int killcounter" and "int levelupnow"
to the private section of the PlayerCharacter class. And then in playGame(), 
when battle() returns the value that represents the character
winning the battle against an enemy( value is DIFFERENT from win against Goblin Fourt), 
killcounter goes up by one. Once killcounter reaches levelupnow, 
the character "levels up" and gets increased and replenished health, and other more specific boosts.
Then killcounter is reset, and levelupnow is increased. So the next "level up" requires more kills.

-More enemies. Added a bunch of enemies. And enemy has a chance to respawn in random unvisited location once it is defeated.
The loop to respawn them is located towards the end of battle().


-Sound Effects. Here and there.

There's a few more small changes I didn't write down.


-Moves limit. After a certain number of moves, if user has not beaten Enemy Fourt, user loses.  A vector
will be outputted in drawGame(), and lose 1 element each move. When vector is empty, game is over.



************************************************************************************/

