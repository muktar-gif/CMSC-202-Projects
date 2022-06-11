/*****************************************
** File:    Game.cpp
** Project: CMSC 202 Project 2, Fall 2019
** Author:  Muhammed Muktar
** Date:    10/10/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Game Class.
**
***********************************************/

#include "Game.h"

using namespace std;

// Preconditions: Foundable file must be loaded successfully into m_allFoundables
// Postconditions: Creates new game
Game::Game()
{

  cout << "Welcome to Harry Potter: Wizards Unite" << endl;

  //loads foundables
  cout << LoadFoundables() << " Foundables loaded" << endl;

  //asks name
  GetWizardName();

  int askMenu = 0;
  bool keepPlaying = true;

  //while player as not quit
  while (keepPlaying)
  {

    //asks options
    MainMenu();
    cin >> askMenu;

    //validates input from first and last options(1-5)
    while (askMenu < WIZARD_STAT || askMenu > QUIT)
    {
      cin >> askMenu;
    }

    switch (askMenu)
    {

    case WIZARD_STAT:

      //prints stats
      WizardStat();
      break;

    case PRINT_MY_FOUNDABLES:

      //prints defeated foundables
      PrintMyFoundables();
      break;

    case PRINT_FOUNDABLES:

      //prints all foundables
      PrintFoundables();
      break;

    case ATTACK:

      //attacks foundable
      AttackFoundable();
      break;

    case QUIT:

      //quits game
      cout << "Thanks for Playing" << endl;
      keepPlaying = false;
      break;
    }
  }
}

// asks user for a name
// Preconditions: Requires valid string name
// Postconditions: Returns wizard name
void Game::GetWizardName()
{

  string askName = "";

  //ask user for name
  cout << "What is your wizard's name?" << endl;
  getline(cin, askName);

  //creates new wizard with overloaded constructor
  Wizard newWizard(askName);
  m_wizard = newWizard;
}

// prints out main menu
// Preconditions: Requires valid string name and populated m_allFoundables
// Postconditions: Manages win condition and game
void Game::MainMenu()
{

  cout << "What would you like to do?" << endl;

  //prints menu, loops until QUIT which is the last option
  for (int i = 0; i < QUIT; i++)
  {
    cout << i + 1 << ". " << MENU_OPTIONS[i] << endl;
  }
}

// reads into file and populates m_allFoundables
// Preconditions: Requires valid file name and input file
// Postconditions: Populates m_allFoundables
int Game::LoadFoundables()
{

  ifstream loadFoundablesStream;
  loadFoundablesStream.open(FILE_NAME);

  int index = 0;

  //temperary varible to hold values
  string tempString = "", tempInt = "";

  //reads until all known foundables
  while (index < NUM_FOUNDABLE)
  {

    //gets name
    getline(loadFoundablesStream, tempString, ',');
    m_allFoundables[index].SetName(tempString);

    //gets type
    getline(loadFoundablesStream, tempString, ',');
    m_allFoundables[index].SetType(tempString);

    //gets rarity
    getline(loadFoundablesStream, tempInt, ',');
    m_allFoundables[index].SetRarity(stoi(tempInt));

    //gets toughness
    getline(loadFoundablesStream, tempInt);
    m_allFoundables[index].SetToughness(stoi(tempInt));

    index++;
  }

  loadFoundablesStream.close();

  //size of m_allFoundable
  return index;
}

// Preconditions: Requires populated m_allFoundables
// Postconditions: Displays all Foundables in game
void Game::PrintFoundables()
{

  //prints all foundables
  for (int i = 0; i < NUM_FOUNDABLE; i++)
  {

    cout << i + 1 << ". " << m_allFoundables[i].GetName() << "| "
         << m_allFoundables[i].GetType() << "| "
         << m_allFoundables[i].GetRarity() << "| "
         << m_allFoundables[i].GetToughness() << endl;
  }
}

// prints wizard's stats
// Preconditions: Requires Wizard to be created and populated
// Postconditions: None (display function)
void Game::WizardStat()
{

  //prints wizard's stats
  cout << "***********************************************" << endl;

  //name
  cout << "Information About Wizard " << m_wizard.GetName() << endl;

  //level
  cout << "Level: " << m_wizard.GetLevel() << endl;

  //toughness
  cout << "Toughness: " << m_wizard.GetToughness() << endl;

  //deafeated foundables
  cout << "Foundables Found: " << m_wizard.GetWins() << endl; //add size

  //wins and loses
  cout << "Wins: " << m_wizard.GetWins() << " Losses: "
       << m_wizard.GetLosses() << endl;

  int totalGames = m_wizard.GetWins() + m_wizard.GetLosses();
  double winRate = 0;

  //gets pertentage
  if (totalGames != 0)
    winRate = ((m_wizard.GetWins() + 0.0) / (totalGames + 0.0)) * 100;

  //2 decimal places
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  //win rate
  cout << "Win Rate: " << winRate << "%" << endl;

  cout << noshowpoint;

  cout << "***********************************************" << endl;
}

// prints defeated foundables
// Preconditions: Requires m_foundables in Wizard to be populated
// Postconditions: None (display function)
void Game::PrintMyFoundables()
{

  //wizard has zero foundables
  if (!m_wizard.GetWins())
    cout << "You have not defeated any foundables yet" << endl;
  else
    //prints defeated foundables
    m_wizard.PrintMyFoundables();
}

// functions for attacking foundables
// Preconditions: Requires m_allFoundables to be populated
// Postconditions: Wizard attacks a Foundable of a specific rarity
//                 No duplicate Foundables can be attacked.
void Game::AttackFoundable()
{

  int askRarity = 0;

  //asks for a rarity
  cout << "What rarity of Foundable would you like to challenge (1-5)?" << endl;
  cin >> askRarity;

  //validates rarity
  while (askRarity < MIN_RARE || askRarity > MAX_RARE)
  {
    cin >> askRarity;
  }

  //array of indexes of possible rarities in m_allFoundables
  int indexFoundables[NUM_FOUNDABLE];

  //tracks size of indexFoundables
  int index = 0;

  for (int i = 0; i < NUM_FOUNDABLE; i++)
  {

    //possible found rarity
    if (m_allFoundables[i].GetRarity() == askRarity)
    {

      //if player does not already have that foundable
      if (!(m_wizard.CheckFoundable(m_allFoundables[i])))
      {

        //adds indexes of possible foundable
        indexFoundables[index] = i;
        index++;
      }
    }
  }

  //no possible rarities found (index becomes size as by index++, line 267)
  if (index == 0)
    cout << "You have found all Foundables at the level of rarity" << endl;

  else
  {
    //random index in indexFoundables
    int randFoundable = (rand() % index);

    //player attacks that foundable
    if (m_wizard.AttackFoundable(m_allFoundables[indexFoundables[randFoundable]]))
    {
      m_wizard.InsertFoundable(m_allFoundables[indexFoundables[randFoundable]]);
    }
  }
}
