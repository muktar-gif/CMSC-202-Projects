/*****************************************
** File:    Paladin.cpp
** Project: CMSC 202 Project 4, Fall 2019
** Author:  Muhammed Muktar
** Date:    11/13/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Paladin Class.
**
***********************************************/
#include "Paladin.h"

const int MAX_ATTACK = 8, MIN_ATTACK = 1; //attack values

// Name: Paladin() - Default Constructor
// Description: Creates a new paladin
// Preconditions: None
// Postconditions: Can create a paladin
Paladin::Paladin()
{
}

// Name: Paladin(string name, int hp)
// Description: Creates a new paladin
// Preconditions: None
// Postconditions: Can create a paladin
Paladin::Paladin(string name, int health) : Character(name, health)
{
}
// Name: ~Paladin - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Paladin::~Paladin()
{
}

// Name: SpecialAttack
// Description: Defines the Paladin's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Paladin::SpecialAttack()
{

  //rand number 1 to 8;
  int attack = rand() % MAX_ATTACK + MIN_ATTACK;

  cout << GetName() << " uses smite evil!" << endl;
  cout << GetName() << " deals " << attack << " damage!" << endl;

  return attack;
}
