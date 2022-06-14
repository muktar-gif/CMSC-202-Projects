/*****************************************
** File:    BabyDragon.cpp
** Project: CMSC 202 Project 4, Fall 2019
** Author:  Muhammed Muktar
** Date:    11/13/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the BabyDragon Class.
**
***********************************************/
#include "BabyDragon.h"

const int DAMAGE = 4; //attack value

// Name: BabyDragon() - Default Constructor
// Description: Creates a new baby dragon
// Preconditions: None
// Postconditions: Can create a baby dragon
BabyDragon::BabyDragon()
{
}
// Name: Baby Dragon(string name, int hp)
// Description: Creates a new baby dragon
// Preconditions: None
// Postconditions: Can create a baby dragon
BabyDragon::BabyDragon(string name, int health) : Monster(name, health)
{
}
// Name: SpecialAttack
// Description: Defines the Baby Dragon's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int BabyDragon::SpecialAttack()
{

  cout << GetName() << " breaths a cone of fire at you!" << endl;
  cout << GetName() << " deals " << DAMAGE << " damage!" << endl;

  return DAMAGE;
}
