/*****************************************
** File:    Monster.cpp
** Project: CMSC 202 Project 4, Fall 2019
** Author:  Muhammed Muktar
** Date:    11/13/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Monster Class.
**
***********************************************/
#include "Monster.h"

const int DAMAGE = 1; //attack value

// Name: Monster() - Default Constructor
// Description: Would be used to create a monster but abstracted
// Preconditions: None
// Postconditions: Used to populate child class data
Monster::Monster()
{
}

// Name: Monster(string name, int hp) - Overloaded Constructor
// Description: Would be used to create a monster but abstracted
// Preconditions: None
// Postconditions: Used to populate child class data
Monster::Monster(string name, int health) : Entity(name, health)
{
}

// Name: Attack()
// Description: Describes attack statements for monster
// Preconditions: None
// Postconditions: Returns damage
int Monster::Attack()
{

  cout << GetName() << " deals " << DAMAGE << " point of damage!" << endl;
  return DAMAGE;
}
