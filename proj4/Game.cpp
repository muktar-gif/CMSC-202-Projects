/*****************************************
** File:    Game.cpp
** Project: CMSC 202 Project 4, Fall 2019
** Author:  Muhammed Muktar
** Date:    11/13/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Game Class.
**
***********************************************/
#include "Game.h"

const string CLASS_MENU_OPTIONS[] = {"Rogue", "Wizard", "Paladin"
                                    , "No Class"};                    //menu for class

const string MOVE_MENU_OPTIONS[] = {"Look", "Move", "Attack Monster"
                                    , "Rest", "Check Stats", "Quit"}; //menu for actions

const string ATTACK_OPTIONS[] = {"Normal Attack", "Special Attack"};  //menu for attack

const int ROGUE_OPTION = 1, WIZARD_OPTION = 2, PALADIN_OPTION = 3
          , NOCLASS_OPTION = 4;                                       //options for menu class

const int LOOK_OPTION = 1, MOVE_OPTION = 2, ATTACK_OPTION = 3
          , REST_OPTION = 4, STATS_OPTION = 5, QUIT_OPTION = 6;       //options for actions menu

const int NORMAL_OPTION = 1, SPECIAL_OPTION = 2;                      //options for attack menu

const int CHARACTER_HEALTH = 10;                                      //character health

const int randChanceOne = 1, randChanceTwo = 2, randChanceThree = 3
          , randChanceFour = 4;                                       //numbers for random chance

// Preconditions: None
// Postconditions: After asking for a file name, loads map, creates char and starts.
Game::Game()
{
}

// Preconditions: None
// Postconditions: Uses filesname to LoadMap, calls create character,
//                 and sets both numRests and m_numSpecial using constants.
Game::Game(string filename)
{

  //starting default values
  m_curRoom = START_ROOM;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  m_curMonster = NULL;

  //loads map
  LoadMap(filename);

  //creates character
  CharacterCreation();

  StartGame();
}

// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated in Game
Game::~Game()
{

  //deletes map
  for (int i = 0; i < (int)m_myMap.size(); i++)
  {

    delete m_myMap.at(i);
    m_myMap.at(i) = NULL;
  }

  //deletes character
  delete m_myCharacter;
  m_myCharacter = NULL;

  if (m_curMonster != NULL)
  {

    //deletes monster
    delete m_curMonster;
    m_curMonster = NULL;
  }
}

// Precondition: File contains map information
// Postcondition: Map is populated with Room objects.
void Game::LoadMap(string filename)
{

  ifstream loadMap;
  loadMap.open(filename);

  string validateFile;

  //validates if file exisits
  while (!loadMap)
  {

    cout << "Invlide file please re-enter file to continue game" << endl;
    cin >> validateFile;

    filename = validateFile;

    cout << "\nLoading file: " << filename << "\n"
         << endl;

    loadMap.open(filename);
  }

  //temp values to read file
  string getID, north, east, south, west;
  string getName, getDesc;

  Room *newRoom;

  //while there is still something to read
  while (getline(loadMap, getID, '|'))
  {

    getline(loadMap, getName, '|');
    getline(loadMap, getDesc, '|');

    getline(loadMap, north, '|');
    getline(loadMap, east, '|');
    getline(loadMap, south, '|');
    getline(loadMap, west, '|');

    //creates new room with values
    newRoom = new Room(atoi(getID.c_str()), getName, getDesc, atoi(north.c_str()), 
              atoi(east.c_str()), atoi(south.c_str()), atoi(west.c_str()));

    //adds room
    m_myMap.push_back(newRoom);
  }
}

// Preconditions: None
// Postconditions: m_myCharacter is populated
void Game::CharacterCreation()
{

  cout << "Welcome too UMBC Adventure!" << endl;

  string askName = "";

  //asks for character name
  cout << "Character Name: ";
  cin >> askName;

  int askClass = 0;

  //asks for class
  cout << "Select a class" << endl;

  //prints menu
  for (int i = 0; i < NOCLASS_OPTION; i++)
    cout << i + 1 << ". " << CLASS_MENU_OPTIONS[i] << endl;

  cin >> askClass;

  //validates option
  while (askClass < ROGUE_OPTION || askClass > NOCLASS_OPTION)
    cin >> askClass;

  switch (askClass)
  {

  case ROGUE_OPTION:

    //creates rogue
    m_myCharacter = new Rogue(askName, ROGUE_HEALTH);

    break;

  case WIZARD_OPTION:

    //creates wizard
    m_myCharacter = new Wizard(askName, WIZARD_HEALTH);

    break;

  case PALADIN_OPTION:

    //creates paladin
    m_myCharacter = new Paladin(askName, PALADIN_HEALTH);

    break;

  case NOCLASS_OPTION:

    //creates normal character
    m_myCharacter = new Character(askName, CHARACTER_HEALTH);

    break;
  }
}

// Preconditions: LoadMap and CharacterCreation must have been completed
// Postconditions: m_numRests, m_numSpecial and curRoom populated and action called
void Game::StartGame()
{

  //creates starting monster
  m_curMonster = RandomMonster();

  //prints rooms details
  m_myMap[m_curRoom]->PrintRoom();

  if (m_curMonster == NULL)
    cout << "It is peaceful here." << endl;

  else if (m_curMonster->GetName() == "Skeleton")
    cout << "A skeleton lumbers around the room." << endl;

  else if (m_curMonster->GetName() == "Goblin")
    cout << "A goblin is here picking his nose." << endl;

  else if (m_curMonster->GetName() == "Baby Dragon")
    cout << "A baby dragon is lurking around the corner." << endl;

  //starts rest of game
  Action();
}

// Name: Action()
// Description: Menu for game
// Preconditions: Everything in start has been completed
// Postconditions: Game continues until quit or player dies
void Game::Action()
{

  bool playerDead = false, keepPlaying = true;
  int askOption = 0;

  //while player is still alive and has not quit
  while (!playerDead && keepPlaying)
  {

    //asks action menu
    cout << "What would you like to do?" << endl;

    for (int i = 0; i < QUIT_OPTION; i++)
      cout << i + 1 << ". " << MOVE_MENU_OPTIONS[i] << endl;

    cin >> askOption;

    //validates options
    while (askOption < LOOK_OPTION || askOption > QUIT_OPTION)
      cin >> askOption;

    switch (askOption)
    {

    case LOOK_OPTION:

      //prints room information
      m_myMap[m_curRoom]->PrintRoom();

      if (m_curMonster == NULL)
        cout << "It is peaceful here." << endl;

      else if (m_curMonster->GetName() == "Skeleton")
        cout << "A skeleton lumbers around the room." << endl;

      else if (m_curMonster->GetName() == "Goblin")
        cout << "A goblin is here picking his nose." << endl;

      else if (m_curMonster->GetName() == "Baby Dragon")
        cout << "A baby dragon is lurking around the corner." << endl;

      break;

    case MOVE_OPTION:

      //moves character and creates new monster
      if (m_curMonster != NULL)
      {

        delete m_curMonster;
        m_curMonster = NULL;
      }

      m_curMonster = RandomMonster();
      Move();

      break;

    case ATTACK_OPTION:

      //attacks monster
      if (m_curMonster == NULL)
        cout << "There are no monsters to attack" << endl;

      else
        Attack();

      //if player has died
      if (m_myCharacter->GetHealth() <= 0)
      {

        cout << "You have died!" << endl;
        playerDead = true;
      }

      break;

    case REST_OPTION:

      //if there is no monster and has enough rests
      if (m_curMonster == NULL && m_numRests > 0)
      {

        cout << "Enjoy your rest" << endl;

        //increases health
        m_myCharacter->SetHealth(m_myCharacter->GetHealth() + REST_HEAL);
        m_numRests--;
      }
      else
        cout << "You cannot rest" << endl;

      break;

    case STATS_OPTION:

      //prints stats
      Stats();

      break;

    case QUIT_OPTION:

      //player quits
      keepPlaying = false;

      break;
    }
  }
}

// Preconditions: Has an entity pointer to hold monster child
// Postconditions: Returns object of type Baby Dragon, Goblin, or Skeleton
Entity *Game::RandomMonster()
{

  //rand number 1 to 4
  int randChance = rand() % randChanceFour + randChanceOne;
  Entity *getMonster;

  //by random chooses monster
  if (randChance == randChanceOne)
    getMonster = new BabyDragon("Baby Dragon", DRAGON_HEALTH);

  else if (randChance == randChanceTwo)
    getMonster = new Goblin("Goblin", GOBLIN_HEALTH);

  else if (randChance == randChanceThree)
    getMonster = new Skeleton("Skeleton", SKELETON_HEALTH);

  else
    return NULL;

  //returns new monster entity
  return getMonster;
}

// Preconditions: Must be valid move (room must exist)
// Postconditions: Displays room information, checks for new monster (deletes old)
void Game::Move()
{

  char getDirection;
  int getID = -1;

  //whiler player is not hitting a wall
  while (getID == -1)
  {

    //asks for directions
    cout << "Which direction (N E S W)" << endl;
    cin >> getDirection;

    //validates direction option
    while (getDirection != 'N' && getDirection != 'n' && getDirection != 'E' && getDirection != 'e' 
          && getDirection != 'S' && getDirection != 's' && getDirection != 'W' && getDirection != 'w')
    {

      cout << "Please enter N E S W" << endl;
      cin >> getDirection;
    }

    //gets id of new room
    getID = m_myMap[m_curRoom]->CheckDirection(getDirection);
  }

  //makes room the current room
  m_curRoom = getID;

  //prints room information
  m_myMap[m_curRoom]->PrintRoom();

  if (m_curMonster == NULL)
    cout << "It is peaceful here." << endl;

  else if (m_curMonster->GetName() == "Skeleton")
    cout << "A skeleton lumbers around the room." << endl;

  else if (m_curMonster->GetName() == "Goblin")
    cout << "A goblin is here picking his nose." << endl;

  else if (m_curMonster->GetName() == "Baby Dragon")
    cout << "A baby dragon is lurking around the corner." << endl;
}

// Preconditions: Everything in start has been completed
// Postconditions: Indicates who wins and updates health(hp) as battle continues.
//                 May need to deallocate enemy monster to prevent memory leaks.
void Game::Attack()
{

  int askAttack;

  //while player or character is not dead
  while (m_myCharacter->GetHealth() > 0 && m_curMonster->GetHealth() > 0)
  {

    //prints attack menu
    for (int i = 0; i < SPECIAL_OPTION; i++)
      cout << i + 1 << ". " << ATTACK_OPTIONS[i] << endl;

    cin >> askAttack;

    //validates options
    while (askAttack < NORMAL_OPTION || askAttack > SPECIAL_OPTION)
      cin >> askAttack;

    //makes sure player has special attacks
    while (askAttack == SPECIAL_OPTION && m_numSpecial <= 0)
    {

      cout << "You have no more special attacks" << endl;
      cin >> askAttack;
    }

    switch (askAttack)
    {

    case NORMAL_OPTION:

      //normal attack
      m_curMonster->SetHealth(m_curMonster->GetHealth() - m_myCharacter->Attack());

      break;

    case SPECIAL_OPTION:

      //special attack
      m_curMonster->SetHealth(m_curMonster->GetHealth() - m_myCharacter->SpecialAttack());
      m_numSpecial--;

      break;
    }

    //random from 1 to 4
    int monsterChance = rand() % randChanceFour + randChanceOne;

    //a 25% chance
    if (monsterChance == randChanceOne)
    {

      //special attack
      m_myCharacter->SetHealth(m_myCharacter->GetHealth() - m_curMonster->SpecialAttack());
    }
    else
    {

      //normal attack
      m_myCharacter->SetHealth(m_myCharacter->GetHealth() - m_curMonster->Attack());
    }

    //prints player health
    if (m_myCharacter->GetHealth() <= 0)
      cout << m_myCharacter->GetName() << "'s health: 0" << endl;

    else
      cout << m_myCharacter->GetName() << "'s health: "
           << m_myCharacter->GetHealth() << endl;
    ;

    //prints monster health
    if (m_curMonster->GetHealth() <= 0)
      cout << m_curMonster->GetName() << "'s health: 0" << endl;

    else
      cout << m_curMonster->GetName() << "'s health: "
           << m_curMonster->GetHealth() << endl;
    ;
  }

  //if player has defeated monster
  if (m_curMonster->GetHealth() <= 0)
    cout << "You have defeated the " << m_curMonster->GetName() << "." << endl;

  //deletes curMonster
  delete m_curMonster;
  m_curMonster = NULL;
}

// Preconditions: None
// Postconditions: None
void Game::Stats()
{

  //prints stats
  cout << "Name: " << m_myCharacter->GetName() << endl;
  cout << "HP: " << m_myCharacter->GetHealth() << endl;
  cout << "Rests: " << m_numRests << endl;
  cout << "Special: " << m_numSpecial << endl;
}
