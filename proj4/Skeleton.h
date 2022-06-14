/*****************************************
** File:    Skeleton.h
** Project: CMSC 202 Project 4, Fall 2019
** Author:  Given by professor
** This is the .h file for the Skeleton class
**
***********************************************/

#ifndef _SKELETON_H_
#define _SKELETON_H_

#include "Monster.h"

class Skeleton: public Monster {
 public:
  // Name: Skeleton() - Default Constructor
  // Description: Creates a new skeleton
  // Preconditions: None
  // Postconditions: Can create a skeleton
  Skeleton();
  // Name: Skeleton(string name, int hp)
  // Description: Creates a new skeleton
  // Preconditions: None
  // Postconditions: Can create a skeleton
  Skeleton(string, int);
  // Name: SpecialAttack
  // Description: Defines the Skeleton's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
