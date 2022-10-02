/*****************************************
** File:    Wizard.cpp
** Project: CMSC 202 Project 2, Fall 2019
** Author:  Muhammed Muktar
** Date:    10/10/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Wizard Class.
**
***********************************************/

#include "Wizard.h"

// Preconditions: None
// Postconditions: Creates new Wizard with valid values
Wizard::Wizard()
{
  m_name = "Mr.Wizard";
  SetToughness(rand() % (MAX_START_TOUGH - MIN_START_TOUGH) + MIN_START_TOUGH);
  m_level = 1;
}

// Preconditions: Requires valid name
// Postconditions: Creates new Wizard with m_Toughness between 150 and 300
//                 and m_Level = 1 with passed name
Wizard::Wizard(string name)
{

  SetName(name);
  SetToughness(rand() % (MAX_START_TOUGH - MIN_START_TOUGH) + MIN_START_TOUGH);
  m_level = 1;
}

// Preconditions: None
// Postconditions: Returns m_name
string Wizard::GetName()
{

  return m_name;
}

// Preconditions: None
// Postconditions: Returns m_toughness
int Wizard::GetToughness()
{

  return m_toughness;
}

// Preconditions: None
// Postconditions: Returns m_level
int Wizard::GetLevel()
{

  return m_level;
}

// Preconditions: None
// Postconditions: Returns m_wins
int Wizard::GetWins()
{

  return m_wins;
}

// Preconditions: None
// Postconditions: Returns m_losses
int Wizard::GetLosses()
{

  return m_losses;
}

// Preconditions: Requires valid string name
// Postconditions: Updates m_name
void Wizard::SetName(string name)
{

  m_name = name;
}

// Preconditions: Requires valid int toughness
// Postconditions: Updates m_toughness
void Wizard::SetToughness(int toughness)
{

  m_toughness = toughness;
}

// Preconditions: Requires a valid Foundable (from m_allFoundables)
// Postconditions: Adds copy Foundable to m_foundables
void Wizard::InsertFoundable(Foundable newFoundable)
{

  //starting index
  int index = GetWins() - 1;

  //if foundable is not already known
  if (!(CheckFoundable(newFoundable)))
  {

    //adds foundable to known foundables
    m_foundables[index].SetName(newFoundable.GetName());
    m_foundables[index].SetType(newFoundable.GetType());
    m_foundables[index].SetRarity(newFoundable.GetRarity());
    m_foundables[index].SetToughness(newFoundable.GetToughness());
  }
}

// Preconditions: Requires valid Foundable
// Postconditions: Returns true if exists in m_foundables else false
bool Wizard::CheckFoundable(Foundable newFoundable)
{

  //wins correlates with size
  int size = GetWins();

  for (int i = 0; i < size; i++)
  {

    //if all varibles are the same
    if (m_foundables[i].GetName() == newFoundable.GetName() &&
        m_foundables[i].GetType() == newFoundable.GetType() &&
        m_foundables[i].GetRarity() == newFoundable.GetRarity() &&
        m_foundables[i].GetToughness() == newFoundable.GetToughness())

      return true;
  }

  return false;
}

// Preconditions: Requires valid enemy (Foundable pointer)
// Postconditions: Compares Wizard toughness to the enemy toughness
//                 (tie goes to enemy) Returns result of comparison
bool Wizard::AttackFoundable(Foundable enemy)
{

  cout << "The Wizard " << GetName() << " attacks " << enemy.GetName() << "!" << endl;

  //if wizard has a larger toughness
  if (GetToughness() > enemy.GetToughness())
  {

    cout << "You defeat the " << enemy.GetName() << "!" << endl;

    m_wins++;
    IncreaseLevel();
    return true;
  }

  //wizard's toughness is lower
  cout << "You loss to the " << enemy.GetName() << "!" << endl;

  m_losses++;
  return false;
}

// Preconditions: None
// Postconditions: Displays a list of all foundables found by Wizard else indicates none
//                 found
void Wizard::PrintMyFoundables()
{

  //wins correlate with size
  int size = GetWins();

  //prints all defeated foundables
  for (int i = 0; i < size; i++)
  {

    cout << i + 1 << ". " << m_foundables[i].GetName() << "| "
         << m_foundables[i].GetName() << "| "
         << m_foundables[i].GetRarity() << "| "
         << m_foundables[i].GetToughness() << endl;
  }
}

// Preconditions: None
// Postconditions: Updates m_level by one and increases toughness from 0 to 100
void Wizard::IncreaseLevel()
{

  //increase level
  m_level++;

  //increase toughness from 0 to 100
  m_toughness += (rand() % (LEVEL_TOUGH_INCREASE + 1));
}
