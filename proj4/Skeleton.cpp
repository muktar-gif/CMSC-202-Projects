/*****************************************
** File:    Skeleton.cpp
** Project: CMSC 202 Project 4, Fall 2019
** Author:  Muhammed Muktar
** Date:    11/13/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Skeleton Class.
**
***********************************************/
#include "Skeleton.h"

const int DAMAGE = 1; //attack value

// Name: Skeleton() - Default Constructor
// Description: Creates a new skeleton
// Preconditions: None
// Postconditions: Can create a skeleton
Skeleton::Skeleton()
{
}
// Name: Skeleton(string name, int hp)
// Description: Creates a new skeleton
// Preconditions: None
// Postconditions: Can create a skeleton
Skeleton::Skeleton(string name, int health) : Monster(name, health)
{
}

// Name: SpecialAttack
// Description: Defines the Skeleton's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Skeleton::SpecialAttack()
{

  cout << GetName() << " bashes you with it's own arm!" << endl;
  cout << GetName() << " deals " << DAMAGE << " damage!" << endl;

  return DAMAGE;
}
