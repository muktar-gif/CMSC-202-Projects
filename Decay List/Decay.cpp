/*****************************************
** File:    Decay.cpp
** Project: CMSC 202 Project 3, Fall 2019
** Author:  Muhammed Muktar
** Date:    10/29/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Decay Class.
**
***********************************************/
#include "Decay.h"

// Constructor
// Preconditions: None
// Postconditions: None
Decay::Decay()
{
}

// Destructor - Deletes all lists in m_list
// Preconditions: m_list is populated
// Postconditions: All lists are deleted and there are no memory leaks
Decay::~Decay()
{

  //deletes list
  EmptyLists();
}

// EmptyLists() - Empties all lists in m_list
// Preconditions: m_list is populated
// Postconditions: All lists are deleated and there are no memory leaks
void Decay::EmptyLists()
{

  //deletes lists
  for (int i = 0; i < int(m_list.size()); i++)
  {
    delete m_list[i];
  }

  m_list.clear();
}

// LoadFile - Requests a file and loads all linked lists in a file (separated by ;)
// Preconditions: Valid input file exists (preferably with three lines of data)
// Postconditions: m_list is initialized
void Decay::LoadFile()
{

  //gets file name
  string askFile = "";
  cout << "What is the name of the file" << endl;
  cin >> askFile;

  m_file = askFile;

  ifstream loadList;
  loadList.open(m_file);

  //validates file name
  while (!loadList)
  {

    cout << "Re enter file" << endl;
    cin >> askFile;

    m_file = askFile;

    loadList.open(m_file);
  }

  char readList;
  int value = 0;

  DecayList *newList = new DecayList();
  Node *newNode;

  //while there is still something to read in file
  while (loadList >> readList)
  {

    //while not at the end of list
    if (readList != CHAR_SEMI)
    {

      //changes value
      if (readList == CHAR_ZERO)
        value = 0;
      else if (readList == CHAR_ONE)
        value = 1;

      //creates node
      newNode = new Node(value);
      newList->InsertEnd(newNode);
    }
    //reaches end to list
    else
    {

      //adds list
      m_list.push_back(newList);
      newList = new DecayList();
    }
  }

  //removes last allocated list
  delete newList;

  loadList.close();
}

// ChooseList - After a file is loaded, allows user to choose a list to simulate
// Preconditions: User has chosen to start simulation
// Postconditions: Simulation is started on list chosen by user
void Decay::ChooseList()
{

  int askList = 0;

  //asks to choose list
  cout << "Which scenario do you want to experience?" << endl;

  //prints list options
  for (int i = 0; i < int(m_list.size()); i++)
    cout << i + 1 << ". "
         << "List " << i + 1
         << "(" << m_list[i]->GetSize() << ")" << endl;

  cin >> askList;

  //vaildates askList
  while (askList < 0 || askList > int(m_list.size()))
    cin >> askList;

  cout << "The sequence has been initialized." << endl;
  RunSimulation(askList - 1);
}

// CreateRandomList - Creates list of a specific size (1-10000) times 3 nodes each
// Preconditions: m_list is empty
// Postconditions: m_list.at(0) has a list loaded into it
void Decay::CreateRandomList()
{

  int askList = 0;

  //asks length of list
  cout << "How large a list would you like?" << endl;
  cin >> askList;

  //validates askList
  while (askList < MIN_RAN || askList > MAX_RAN)
    cin >> askList;

  DecayList *newList = new DecayList();
  Node *ranNode;

  int randomNum;

  for (int i = 0; i < askList * 3; i++)
  {

    //random num from 0 to 1
    randomNum = rand() % VALUE_RAN;

    //creates and inserts node
    ranNode = new Node(randomNum);
    newList->InsertEnd(ranNode);
  }

  //adds to vector
  m_list.push_back(newList);

  //run the first list
  RunSimulation(0);
}

// RunSimulation - Simulate one of the loaded lists
// Preconditions: A DecayList is available
// Postconditions: Simulation is run
void Decay::RunSimulation(int index)
{

  int askNode = 0;

  //while there are still nodes
  while (m_list[index]->GetSize() != 0)
  {

    //prints list
    m_list[index]->PrintDecayList();

    cout << "Which node to change" << endl;

    //prints layout
    cout << " 1";
    for (int i = 1; i < m_list[index]->GetSize(); i++)
      cout << "    " << i + 1;
    cout << endl;

    cin >> askNode;

    //validates askNode
    while (askNode < MIN_OPTION || askNode > m_list[index]->GetSize())
      cin >> askNode;

    //changes value at index
    m_list[index]->InvertValue(askNode - 1);

    //removes node
    int nodesRemoved = 0, totalRemoved = 0;

    nodesRemoved = totalRemoved = m_list[index]->TraverseList(true);

    //keeps removing nodes
    while (nodesRemoved != 0 && m_list[index]->GetSize() != 0)
    {
      totalRemoved += nodesRemoved;
      nodesRemoved = m_list[index]->TraverseList(true);
    }

    if (totalRemoved != 0)
      cout << totalRemoved << " nodes removed!" << endl;
  }

  cout << "All nodes from that list have been removed" << endl;

  EmptyLists();
  cout << "All lists have been cleared." << endl;
}

// Start - Starts sim. Can load file, choose list, or create random list
// Preconditions: A DecayList is available
// Postconditions: Empties all lists after one is simulated.
void Decay::Start()
{

  bool keepPlaying = true;

  //while player was to keep playing
  while (keepPlaying)
  {

    cout << "Welcome to Decay, where you code a frustrating "
         << "system instead of doing your physics homework." << endl;

    int askOption = 0;

    //prints menu
    for (int i = 0; i < MAX_OPTION; i++)
    {

      cout << i + 1 << ". " << MENU_OPTIONS[i] << endl;
    }

    cin >> askOption;

    //validates askOption
    while (askOption < MIN_OPTION || askOption > MAX_OPTION)
      cin >> askOption;

    switch (askOption)
    {

    case LOAD_OPTION:
      //load file

      //already loaded a list
      if (m_list.size() != 0)
        cout << "Already loaded a list" << endl;
      else
        LoadFile();

      break;
    case SIM_LOAD:

      //Sim loadlife

      //makes sure no list is loaded
      if (m_list.size() != 0)
        ChooseList();
      else
        cout << "Load a List" << endl;

      break;
    case SIM_RAN:

      //Sim random
      CreateRandomList();

      break;
    case QUIT:

      //quit
      keepPlaying = false;

      break;
    }
  }
}
