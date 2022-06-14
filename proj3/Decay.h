/*****************************************
** File:    Decay.h
** Project: CMSC 202 Project 3, Fall 2019
** Author:  Given by professor, Edited by Muhammed Muktar
** Date:    10/29/19
** Section: 30
** This is the .h file for the Decay Class.
**
***********************************************/
#ifndef DECAY_H
#define DECAY_H
#include "Node.h"
#include "DecayList.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib> 
#include <time.h> 
using namespace std;

const string MENU_OPTIONS[] = {"Load File","Simulate Loaded File"
			                        ,"Simulate Random List","Quit"}; //menu option

const int MIN_OPTION = 1, MAX_OPTION = 4, LOAD_OPTION = 1, SIM_LOAD = 2,
  SIM_RAN = 3, QUIT = 4; //option numbers

const int MIN_RAN = 1, MAX_RAN = 10000; //random list values

const int VALUE_RAN = 2; //random value

const char CHAR_ZERO = '0', CHAR_ONE = '1', CHAR_SEMI = ';'; //load list values

class Decay{
 public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Decay();

  // Destructor - Deletes all lists in m_list
  // Preconditions: m_list is populated
  // Postconditions: All lists are deleted and there are no memory leaks
  ~Decay();

  // EmptyLists() - Empties all lists in m_list
  // Preconditions: m_list is populated
  // Postconditions: All lists are deleated and there are no memory leaks
  void EmptyLists();
  
  // LoadFile - Requests a file and loads all linked lists in a file (separated by ;)
  // Preconditions: Valid input file exists (preferably with three lines of data)
  // Postconditions: m_list is initialized
  void LoadFile();

  // ChooseList - After a file is loaded, allows user to choose a list to simulate
  // Preconditions: User has chosen to start simulation
  // Postconditions: Simulation is started on list chosen by user
  void ChooseList();

  // CreateRandomList - Creates list of a specific size (1-10000) times 3 nodes each
  // Preconditions: m_list is empty
  // Postconditions: m_list.at(0) has a list loaded into it
  void CreateRandomList();
  
  // RunSimulation - Simulate one of the loaded lists
  // Preconditions: A DecayList is available
  // Postconditions: Simulation is run
  void RunSimulation(int index);

  // Start - Starts sim. Can load file, choose list, or create random list
  // Preconditions: A DecayList is available
  // Postconditions: Empties all lists after one is simulated.
  void Start();
  
 private:
  vector<DecayList*> m_list; //vector of DecayLists to simulate
  string m_file; //name of the file to load
};

#endif
