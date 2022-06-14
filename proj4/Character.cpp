/*****************************************
** File:    Character.cpp
** Project: CMSC 202 Project 4, Fall 2019
** Author:  Muhammed Muktar
** Date:    11/13/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Character Class.
**
***********************************************/
#include "Character.h"

const int MAX_ATTACK = 6, MIN_ATTACK = 1; //attack values

// Name: Character() - Default Constructor
// Description: Creates a new character
// Preconditions: None
// Postconditions: Can create a character
Character::Character()
{
}

// Name: Character(string name, int hp) - Overloaded constructor
// Description: Creates a new character
// Preconditions: None
// Postconditions: Can be used to populate character or child classes
Character::Character(string name, int health) : Entity(name, health)
{
}

// Name: ~Character - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Character::~Character()
{
}

// Name: Attack()
// Description: Describes attack statements for character
// Preconditions: None
// Postconditions: Returns damage
int Character::Attack()
{

  //random from 1 to 6
  int attack = rand() % MAX_ATTACK + MIN_ATTACK;

  cout << GetName() << " attacks dealing " << attack << " damage." << endl;
  return attack;
}

// Name: SpecialAttack()
// Description: Tells player that character does not have special attack
// may be used for child class special attacks
// Preconditions: None
// Postconditions: May be used to call child class SpecialAttack
int Character::SpecialAttack()
{

  cout << "You do not have a special attack" << endl;
  return 0;
}
