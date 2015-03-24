//FileName:		game.cpp
//Programmer:	Dan Cliburn
//Date:			1/14/2013
//Purpose:		This file defines the methods for the game class
/************************************************************************

Edited By: Xeng Vang

Project 8

COMP 053

4/23/2013

*************************************************************************/
#include "game.h"
#include "fourt.h"
#include "enemy.h"
#include "item.h"
#include "magicWeapon.h"
#include "magicShield.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <mmsystem.h>//for sound
#pragma comment(lib,"winmm.lib")//for sound

using namespace std;


Game::Game()
{
	srand(time(0));

	world = 0;
	rows = cols = 0;
}

void Game::setUpGame(int level)
{
	int r, c;
	//Initial values of rows and cols.
	rows = 8;
	cols = 12;

	//Redefining rows and cols. At level 1, rows and cols should not change.
	rows = rows + 2*(level - 1);
	cols = cols + 3*(level - 1);

	setmovetolose();//initializes the vector.

	//Now we need to dynamically allocate world to be a 2D array of pointers to Locations
	world = new Location **[rows];
	for (r = 0; r < rows; r++)
	{
		world[r] = new Location *[cols];
	}

	//Next, go and initialize all of the pointers in the array to NULL
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < cols; c++)
		{
			world[r][c] = 0;
		}
	}

	//Now we need to place all of the elements into the world
	//First place the player's fourt
	world[0][0] = new Fourt();

	//Place the Goblin Fourt
	r = rand()%(rows-4) + 2;
	c = rand()%(cols-4) + 2;
	//cout << "Goblin Fourt at row " << r << " column " << c << endl;system ("pause");
	world[0][1] = new Enemy("Goblin Fourt", 10,  6, 6, 'G'); 
	//Place goblins around the base
	world[r+1][c] = new Enemy("Goblin camp", 5,  4, 4, 'g');
	world[r-1][c] = new Enemy("Goblin camp", 5,  4, 4, 'g');
	world[r][c+1] = new Enemy("Goblin camp", 5,  4, 4, 'g');
	world[r][c-1] = new Enemy("Goblin camp", 5,  4, 4, 'g');

	//Find a place for the magic sword
	do
	{
		r = rand()%rows;
		c = rand()%cols;
	} while (world[r][c] != 0);
	world[r][c] = new MagicWeapon("magic weapon", 'w', 12);

	//Find a place for the magic shield
	do
	{
		r = rand()%rows;
		c = rand()%cols;
	} while (world[r][c] != 0);
	world[r][c] = new MagicShield("magic shield", 's', 8);

	for (int x = 0; x <= level*2; x++)//Creates more enemy at random locations
	{
		do
		{
			r = rand()%rows;
			c = rand()%cols;
		} while (world[r][c] != 0);
		world[r][c] = new Enemy("Goblin camp", 5, 3, 3, 'g');
	}
	//now put blank locations everywhere else.
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < cols; c++)
		{
			if (world[r][c] == 0) //nothing at this place yet
			{
				world[r][c] = new Location();
			}
		}
	}

	world[0][0]->setVisited(true); //No action where the player begins
	//playerRow = 0;  //Not in Project 6
	//playerCol = 0;  //Not in Project 6

	if (level == 1)//Should only run at the start of game.
					//Stat boosts carry over to next level, and so should deaths. chooseUnits() would just
					//create 3 new characters.
		p.chooseUnits(); 
}


void Game::drawGame(int level, int unitcount, vector <char> gg)//draws the game.
{//I made it take in level and unitcount. Level is to determine the map color.
 // unitcount is used to determine how many characters to check for to print out.
	
	vector <char>::iterator monkey;
	cout << endl << endl;
	cout << setw(40) << "Level: ";//prints out map level.
	otheraquatext();
	cout << level;
	normaltext();
	cout << endl << endl;
	cout << setw(35) << current->getName() << "'s hearts: ";//prints out current character's health
	redtext();
	cout << current->getHearts() << endl << endl;
	normaltext();
	cout << setw(40) << current->getName() << "'s Level: " << current ->getcharacterlevel() << endl;//prints out character's level.

	for (int r = 0; r < rows; r++)
	{
		cout << setw((80 - cols)/2);
		for (int c = 0; c < cols; c++)
		{
			aquatext();//Default color for characters.

			if (unitcount == 3)//All three characters are still alive. Should check to print out all character's letter {W,S,H}.
			{
				if (r == current->getRow() && c == current->getCol())
				{
					cout << current->getName()[0];
				}

				else if (r == current->getNext() ->getRow() && c == current->getNext() ->getCol())
				{
					cout << current ->getNext() ->getName()[0];
				}
					
					
				else if (r == current->getNext() ->getNext() ->getRow() && c == current->getNext() ->getNext() ->getCol())
				{
					cout << current ->getNext() ->getNext() ->getName()[0];
				}
				else
				{//This is to print out the dots. Every level should have different color dots.
					if (level == 2)
						bluetext();

					else if (level == 3)
						greentext();

					else if (level == 4)
						pinktext();

					else if (level == 5)
						redtext();

					else //This would apply to level 1.
						normaltext();

					world[r][c]->draw();
				}
			}


			if (unitcount == 2)//Two characters are still alive. Same as the above if-loop, except
								// it only checks to print out 2 characters.
			{
				if (r == current->getRow() && c == current->getCol())
				{
					cout << current->getName()[0];
				}
				else if (r == current->getNext() ->getRow() && c == current->getNext() ->getCol())
				{
					cout << current ->getNext() ->getName()[0];
				}	
				else
				{
					if (level == 2)
						bluetext();

					else if (level == 3)
						greentext();

					else if (level == 4)
						pinktext();

					else if (level == 5)
						redtext();

					else 
						normaltext();

					world[r][c]->draw();
				}
			}

			if (unitcount == 1)//Only one character is alive.
			{
				if (r == current->getRow() && c == current->getCol())
				{
					cout << current->getName()[0];
				}	
				else
				{
					if (level == 2)
						bluetext();

					else if (level == 3)
						greentext();

					else if (level == 4)
						pinktext();

					else if (level == 5)
						redtext();

					else 
						normaltext();

					world[r][c]->draw();
				}
			}	
		}
		cout << endl;
	}
	
	space();

	cout << setw(40) << "Overall Moves Left: " << endl;

	purpletext();
	for(monkey = movetolose.begin(); monkey != movetolose.end(); monkey++)
		cout << *monkey;

	cout << endl;
	
	normaltext();//change back to normal text color
}

//Acknowledgment: Thanks goes to the following webpages which provided the
// info needed to read the arrow keys from the keyboard:
//	http://www.daniweb.com/software-development/cpp/threads/47195
//	http://www.codingforums.com/archive/index.php/t-100973.html
char Game::getKeyPress()
{
	char key = 127;
	key = _getch();
	
	if (key == 0 || key == -32)  //get a special key
	{
		key = _getch();

		if (key == 72) //up arrow
		{
			key = 'u';
		}
		else if (key == 75) //left arrow
		{
			key = 'l';
		}
		else if (key == 77) //right
		{
			key = 'r';
		}
		else if (key == 80) //down
		{
			key = 'd';
		}
	}
	return key;
}

void Game::playGame()//plays the game.
{
	int state = 1;
	char move = 'x';
	int moves;
	char mander = 'q';
	int level = 1; // For levels.
	
	instructions();
	setUpGame(level);  //Make sure everything is set up for the first level

	current =  p.getCurrentUnit(); //set the current unit

	while (state > 0 && p.getUnits() > 0 && movetolose.size() > 0) //the game continues as long as state is not zero and movetolose is not empty
	{
		system("cls");

		drawGame(level, p.getUnits(), movetolose);	

		if(level > 1)//As you reach the higher levels and bigger maps, characters should be able to move more.
			moves = current->moves() + level*2; //roll the dice for the number of moves the player gets

		else
			moves = current->moves();
		
		//The healing ability can only be accessed if it is healer's turn. 
		if (current ->getName() == "healer")
			if (healCharacter(p, current, current ->getcharacterlevel())) 
			{
				if ((current -> getcharacterlevel() < 1))//If healer was level 2(or above), then healer's characterlevel would be > 1,  
					moves = 0;						  // and the moves penalty is not applied.


		} 
		while (moves > 0)
		{
			cout << setw(35) << current->getName() << " has " << moves << " move(s)." << endl;
			do
			{
				cout << setw(50) << "Use the arrow keys to move " << current->getName() << endl;
				move = getKeyPress();
				cout << endl;
				if (move == 'u' && current->getRow() > 0)
				{
					current->setRow(current->getRow() - 1);
				}
				else if (move == 'd' && current->getRow() < rows-1)
				{
					current->setRow(current->getRow() + 1);
				}
				else if (move == 'l' && current->getCol() > 0)
				{
					current->setCol(current->getCol() - 1);
				}
				else if (move == 'r' && current->getCol() < cols-1)
				{
					current->setCol(current->getCol() + 1);
				}
				else
				{
					PlaySound(TEXT ("185213__casmarrav__bad-boom-kick.wav"), NULL, SND_FILENAME | SND_SYNC);//for boundary 
					cout << "You can't do that!" << endl;
					move = 'x';
				}
			} while (move == 'x');

			system("cls");
			drawGame(level,p.getUnits(), movetolose);
			//resolve actions involved with that move
			state = world[current->getRow()][current->getCol()]->visit(p);
	
			if (state == 2) //indicates a battle
			{
				int result = battle(current, (Enemy *)(world[current->getRow()][current->getCol()]));
				system("CLS");
				drawGame(level, p.getUnits(), movetolose);
				if (result == 1 && ((Enemy *)(world[current->getRow()][current->getCol()]))->getName() == "Goblin Fourt") //We defeated the enemy fourt
				{
				
					if (level == 5)
					{//Level 5 is the last level, so this should print out, and then the game should end.
						
						system ("CLS");
						space();
						space();
						space();
						cout << setw(50) << "YOU WIN THE GAME" << endl;
					
						state = -1; // To get out of the while-loop and end the game
						moves = 0; // changing more values, just to be sure.
						p.setUnits(0);// ^
						
					}

					else
					{
						//User beat the level, but not the game.
						system("CLS");
						drawGame(level,p.getUnits(), movetolose);
						otheraquatext();
						cout << setw(45) << "YOU BEAT LEVEL " << level << "!" << endl << endl << endl;
						normaltext();
					}

					Sleep(1000);

					if (level < 5) // Level 5 should be the last level.
					{
						if (level == 4)
						{	//message for the last level.
							cout << "Would you like to try the Last level? (y/n): ";
							cin >> mander;
						}

						else
						{
						cout << "Would you like to move on to the next level? (y/n)" << endl;
						cin >> mander;
						}
					
						while (mander != 'y' && mander != 'n')
						{//restriction for mander input.
							cout << "Invalid choice. (y/n): ";
							cin >> mander;
						}
					
						if (mander == 'y')
						{//Resets values. It's just like starting a game again.
						//Except map is bigger, and stat boosts from items and/or leveling up SHOULD be retained. 
						//And if you lose a character you don't get it back.
							state = 1;
							moves = 0;
							level++;//Increases level.
						
							int squirtle = p.getUnits();//A copy of the number of characters is made.

							while (squirtle >0)
							{// To move all the character back to world[0][0].
								current ->setRow(0);
								current ->setCol(0);

								p.moveToNextUnit();
								current = p.getCurrentUnit(); 
								squirtle--;
							}

							if (level <= 5) // Level 5 should be the last level.
							setUpGame(level);
							system("CLS");
							space();

							int willneveruseagain = 3; // Used only for the countdown below.
							
							while (willneveruseagain > 0)
							{
								system ("CLS");
								space();
								space();
								space();
								cout << setw(50) << "Next Level ready in: " << willneveruseagain << "....." << endl;
								Sleep(650);
								willneveruseagain--;
							}
					
							PlaySound(TEXT ("185237__erokia__elementary-synth-16-4.wav"), NULL, SND_FILENAME | SND_SYNC);//5 seconds

							system ("CLS");
							space();
							space();
							space();
							cout << setw(50) << "LEVEL READY" << endl << endl;
							system ("pause");
						}
					}
					space();
					//return;
				}


				else if (result == 0)  //a unit was defeated
				{
					p.removeUnit(current->getName()); //NOTE: This both removes the unit from the list and subtracts one from the total "units" attribute
					current = p.getCurrentUnit(); //Find the "new" current since the old current was just defeated
					moves = 0; //If this was a scout we want to remove the rest of its moves
					system("pause");
				}

				else if (result == 2)//Killed an enemy other than Enemy Fourt.
				{
					current->setkillcounter(current ->getkillcounter() + 1);//This adds 1 to killcounter.
					

					if (current ->getkillcounter() == current ->getlevelupnow())
					{//If enough kills have been achieved, character "levels up", and this if-loop will run.
						
						current ->setcharacterlevel(current->getcharacterlevel() + 1);//Character Level is increased.

						//MAXHEARTS is increased and health is replenished to new MAXHEARTS. Hearts increase is not character specific.
						current ->setMAXHEARTS(current ->getMAXHEARTS() + 3);
						current ->setHearts(current ->getMAXHEARTS());

						current ->setkillcounter(0);//Resets current character's killcounter to zero.

						current ->setlevelupnow(current ->getlevelupnow() + 1);//Increases levelupnow by 1. 
						//To get to level 2, it takes 1 kill. To get to level 3, takes 2 kill, etc.
					}

					//The following are character specific increases.
					if (current ->getName() == "scout")//Scout is current character.
						current ->setscoutshonor(current ->getscoutshonor() + 2);//Scout gets more moves per turn.

					if (current ->getName() == "warrior")//Warrior is current character.
					{//Warrior gets an attack and defense boost.
						current ->setAttackDice(current ->getAttackDice() + 4);// + 4
						current ->setDefenseDice(current ->getDefenseDice() + 4); // + 4
					}

					if(current ->getName() == "healer")
					{//Level 2 healer should disable the moves penalty. Level 3+ should allow greater healing range.
						;
					}
				}

				else //Redraw the gameboard if the game is not over and the unit was not defeated
				{
					system("pause");
					system("cls");
					drawGame(level,p.getUnits(), movetolose);
				}
			}
			else if (state == 3) //found an item
			{
				foundItem(current, (Item *)(world[current->getRow()][current->getCol()]));
				system("cls");
				drawGame(level,p.getUnits(), movetolose);
			}
			moves--;
			if(movetolose.size() != 0)
				movetolose.pop_back();//deletes 1 element from the vector.
		}

		if (p.getUnits() > 0 ) //move to the next player if there are players left
		{
			p.moveToNextUnit();
			current = p.getCurrentUnit(); 
		}
		//Sleep(100); //pause for half a second
	}

	if (movetolose.size() == 0)//exited while-loop because moves ran out.
	{
		system("CLS");
		cout<< "You have no more moves!" << endl << endl << endl
			<< "You lose the game!";
		space();
	}
	
	//I made it an "else if" loop just to make sure only 1 of them will be read.	
	else if (mander != 'n' && level < 5)//Player can exit game after loss or win, so this message should 
								   //only appear if user lost the game, instead of quitting after a level.
		cout << "\nAll of your units were defeated.  You lost the game." << endl;

	system("pause");
}

bool Game::healCharacter(Player &p, PlayerCharacter *healer, int healerlevel)//healer healing.
{
	int square = healerlevel - 1;
	//At level 1, healer can only heal 1 square in adjacent directions. 
	//At level 2, healer should be able to heal 2 squares in adjacent directions, etc.
	//The increased healing range should kick in at level 3.

	if (square < 1)//If healer was level 1, then the above code would make square = 0;
		square = 1;

	//We need to see if any players are adjacent to, or on the same square as, the current player
	//Loop through the players and check the coordinates
	PlayerCharacter *current = p.getCurrentUnit();
	PlayerCharacter *start = p.getCurrentUnit();
	char answer;
	bool returnVal = false;
	if (current != 0) //make sure there are elements in the list
	{	
		do
		{
			if (current != healer && current->getRow() <= healer->getRow() + square && current->getRow() >= healer->getRow() - square && current->getCol() <= healer->getCol() + square && current->getCol() >= healer->getCol() - square)
			{	//Found someone near the healer
				//Now find out if this character needs healing
				if (current->getHearts() < current->getMAXHEARTS()) //This character could use healing
				{
					do
					{
						cout << "Would " << healer->getName() << " like to heal " << current->getName() << "? (y/n): ";
						cin >> answer;
					} while (answer != 'y' && answer != 'n');
					if (answer == 'y')
					{
						healer->heal(current);
						returnVal = true;
					}
				}
			}
			current = current->getNext();
		} while (current != start); //end when we get back to the first person
	}
	return returnVal;
}

void Game::foundItem(Character *u, Item *i)//found an item.
{
	char choice;
	cout << "Would you like to pick it up (y/n)? ";
	cin >> choice;

	if (choice == 'y')
	{
		i->updateCharacter(u);
	}
	cin.get();
}

int Game::battle(Character *u, Enemy *e)
{
	int attackerRole, defenderRole, damage;

	system("pause");
	while (u->getHearts() > 0 && e->getHearts() > 0) //No retreating!
	{
		//system("cls");
		//I tried to make the [->getHearts()] outputs as red
		cout << "Your unit's health: ";
		redtext();
		cout << u->getHearts() << "\t";
		normaltext();
		cout << e->getName() << "'s health: ";
		redtext();
		cout << e->getHearts() << endl;
		normaltext();
		cout << "Press any key to role for your attack" << endl;
		cin.get();
		attackerRole = u->attack();
		defenderRole = e->defend();
		cout << "Your attack role is a " << attackerRole << endl;
		cout << "The " << e->getName() << "'s defense role is a " << defenderRole << endl;
		damage = attackerRole - defenderRole;
		if (damage > 0) 
		{
			e->setHearts(e->getHearts() - damage);
			cout << "The " << e->getName() << " takes " << damage << " damage" << endl;
		}
		else
		{
			cout << "The " << e->getName() << " takes no damage" << endl;
		}

		if (e->getHearts() > 0) //Now the enemy gets a turn
		{
			cout << "\nYour unit's health: ";
			redtext();
			cout << u->getHearts() << "\t";
			normaltext();
			cout << e->getName() << "'s health: ";
			redtext();
			cout << e->getHearts() << endl;
			normaltext();
			cout << "Press any key to role for your defense" << endl;
			cin.get();
			attackerRole = e->attack();
			defenderRole = u->defend();
			cout << "The " << e->getName() << "'s attack role is a " << attackerRole << endl;
			cout << "Your unit's defense role is a " << defenderRole << endl;
			damage = attackerRole - defenderRole;
			if (damage > 0) 
			{
				u->setHearts(u->getHearts() - damage);
				cout << "Your unit takes " << damage << " damage" << endl;
			}
			else
			{
				cout << "Your unit takes no damage" << endl;
			}
		}
		system("pause");
	}
	if (u->getHearts() <= 0) //Character was defeated.
	{
		cout << "Your unit was defeated" << endl;
		return 0; //The player's unit was defeated
	}

	else if (e ->getName() == "Goblin Fourt")//Enemy defeated was Goblin Fourt.
	{
	cout << "Your unit defeated the " << e->getName() << endl;
	return 1;  //The player's unit won against the Goblin fourt
	}

	else //Enemy was defeated and was NOT the Goblin Fourt. This return is used to update "int killcounter".
	{
		int r,c;
		cout << "Your unit defeated the " << e->getName() << endl;

		//respawning an enemy at a random location.
		for (int x = 0; x < 10; x++)
		{//Picks ten random spots on map. If those spots haven't been visited and are empty, an enemy will respawn there.
			//I changed the stats a little bit for these respawning enemies.
			r = rand()%rows;
			c = rand()%cols;
			if (world[r][c] == new Location())
				world[r][c] = new Enemy("Goblin camp", 7, 2, 7, 'g');
		
		}

		return 2;
	}
}

void Game::instructions()
{
	cout << "Welcome to Fourt Wars. You live in a mysterious land filled with dragons, orcs," << endl;
	cout << "and goblins. While these creatures once lived far away from your home, they " << endl;
	cout <<	"have recently established nearby fourts and have begun to raid and pillage " << endl;
	cout << "from those who you once called your friends. Your fellow villagers have decided" << endl;
	cout << "that these creatures must be stopped and have established their own fourt near" << endl;
	cout << "the boundary of your territory.  You must lead a team to explore the area past" << endl;
	cout << "this boundary, find the enemies, and destroy their fourts." << endl << endl;
	cout << "To play the game, you can use the arrow keys to move your characters.  When you" << endl;
	cout << "find goblin camps and the goblin fourt you will battle them by rolling dice." << endl;
	cout << "If you survive the battle and lose hearts (your health), you can return to your" << endl;
	cout << "fourt (indicated by the 'F' on the game board) to be healed. You must destroy " << endl;
	cout << "the Goblin Fourt to beat the level. As you advance through the levels, you will " << endl;
	cout << "gain more mobility, as well as access to new items and enemies. \n\nGood luck!\n" << endl;
	system("pause");
	system("cls");
}


Game::~Game()
{
	int r, c;

	if (world != 0) //delete the world if it has been made to point to something
	{
		//first delete all of the objects
		for (r = 0; r < rows; r++)
		{
			for (c = 0; c < cols; c++)
			{
				delete world[r][c];
			}
		}

		//now delete all of the columns on each row
		for (r = 0; r < rows; r++)
		{
			delete [] world[r];
		}

		//finally, we can delete the array
		delete [] world;
	}
}