/*****************************************
** File:    Foundable.cpp
** Project: CMSC 202 Project 2, Fall 2019
** Author:  Muhammed Muktar
** Date:    10/10/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Foundable Class.
**
***********************************************/

#include "Foundable.h"

// creates foundable
// Preconditions: None
// Postconditions: Creates new Foundable with valid data
Foundable::Foundable()
{
  
}

// creates foundable adding values
// Preconditions: Requires valid input data
// Postconditions: Creates new Foundable with passed data
Foundable::Foundable(string name, string type, int rarity, int toughness)
{
  m_name = name;
  m_type = type;
  m_rarity = rarity;
  m_toughness = toughness;
}

// Preconditions: None
// Postconditions: Returns name
string Foundable::GetName()
{

  return m_name;
}

// Preconditions: None
// Postconditions: Returns type (not currently used)
string Foundable::GetType()
{

  return m_type;
}

// Preconditions: None
// Postconditions: Returns rarity
int Foundable::GetRarity()
{

  return m_rarity;
}

// Preconditions: None
// Postconditions: Returns toughness
int Foundable::GetToughness()
{

  return m_toughness;
}

// Preconditions: Requires valid name
// Postconditions: Updates value of m_name
void Foundable::SetName(string newName)
{

  m_name = newName;
}

// Preconditions: Requires valid type
// Postconditions: Updates value of m_type
void Foundable::SetType(string newType)
{

  m_type = newType;
}

// Preconditions: Requires valid rarity (1-5)
// Postconditions: Updates value of m_rarity
void Foundable::SetRarity(int newRarity)
{

  m_rarity = newRarity;
}

// Preconditions: Requires valid toughness
// Postconditions: Updates value of m_toughness
void Foundable::SetToughness(int newToughness)
{

  m_toughness = newToughness;
}
