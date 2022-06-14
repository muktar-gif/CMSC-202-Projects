/*****************************************
** File:    Wizard.cpp
** Project: CMSC 202 Project 4, Fall 2019
** Author:  Muhammed Muktar
** Date:    11/13/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Wizard Class.
**
***********************************************/
#include "Wizard.h"

// Name: Wizard() - Default Constructor
// Description: Creates a new wizard
// Preconditions: None
// Postconditions: Can create a wizard
Wizard::Wizard()
{
}

// Name: Wizard(string name, int hp)
// Description: Creates a new wizard
// Preconditions: None
// Postconditions: Can create a wizard
Wizard::Wizard(string name, int health) : Character(name, health)
{
}
// Name: ~Wizard - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Wizard::~Wizard()
{
}
// Name: SpecialAttack
// Description: Defines the Wizard's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Wizard::SpecialAttack()
{

  //rand number from 3 to 12
  int attack = rand() % 10 + 3;

  cout << GetName() << " casts magic missle!" << endl;
  cout << GetName() << " deals " << attack << " damage!" << endl;

  return attack;
}
