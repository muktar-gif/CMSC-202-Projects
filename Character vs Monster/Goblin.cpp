/*****************************************
** File:    Goblin.cpp
** Project: CMSC 202 Project 4, Fall 2019
** Author:  Muhammed Muktar
** Date:    11/13/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Goblin Class.
**
***********************************************/
#include "Goblin.h"

const int DAMAGE = 2; //attacl value

// Name: Goblin() - Default Constructor
// Description: Creates a new goblin
// Preconditions: None
// Postconditions: Can create a goblin
Goblin::Goblin()
{
}

// Name: Goblin(string name, int hp)
// Description: Creates a new goblin
// Preconditions: None
// Postconditions: Can create a goblin
Goblin::Goblin(string name, int health) : Monster(name, health)
{
}
// Name: SpecialAttack
// Description: Defines the Goblin's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Goblin::SpecialAttack()
{

  cout << GetName() << " knaws at your ankles!" << endl;
  cout << GetName() << " deals " << DAMAGE << " damage!" << endl;

  return DAMAGE;
}
