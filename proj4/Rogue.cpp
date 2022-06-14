/*****************************************
** File:    Rogue.cpp
** Project: CMSC 202 Project 4, Fall 2019
** Author:  Muhammed Muktar
** Date:    11/13/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Rogue Class.
**
***********************************************/
#include "Rogue.h"

// Name: Rogue() - Default Constructor
// Description: Creates a new rogue
// Preconditions: None
// Postconditions: Can create a rogue
Rogue::Rogue()
{
}
// Name: Rogue(string name, int hp)
// Description: Creates a new rogue
// Preconditions: None
// Postconditions: Can create a rogue
Rogue::Rogue(string name, int health) : Character(name, health)
{
}
// Name: ~Rogue - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Rogue::~Rogue()
{
}
// Name: SpecialAttack
// Description: Defines the Rogue's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Rogue::SpecialAttack()
{

  //random number from 12 to 2
  int attack = rand() % 11 + 2;

  cout << GetName() << " performs a sneak attack!" << endl;
  cout << GetName() << " deals " << attack << " damage!" << endl;

  return attack;
}
