/*****************************************
** File:    proj1.cpp
** Project: CMSC 202 Project 1, Fall 2019
** Author:  Muhammed Muktar
** Date:    9/26/19
** Section: 09
** E-mail:  mmuktar1@gl.umbc.edu 
**
** This is project 1, Chase the Rabbit, The program is meant to create  game
** where a farmer chases a rabbit. The farmer is controlled by the player and
** the rabbit moves on its own. The goal is for the farmer to get to the rabbit
**
**
***********************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const string PLAYER_OPTIONS[] = {"Search north.", "Search east.",  //array to display
                                 "Search south.", "Search west."}; //menu options

const char PLAY_YES = 'y', PLAY_NO = 'n'; //player answers

const char FARMER = 'F', RABBIT = 'R';     //pieces to represent farmer and rabbit
const int BOARD_SIZE = 10, BOARD_ZERO = 0; //field size

const int NORTH_OPTION = 1, EAST_OPTION = 2, SOUTH_OPTION = 3, //direction options
    WEST_OPTION = 4, NO_MOVE = 5;

//-------------------------------------------------------
// Name: createBoard
// PreCondition:  none
// PostCondition: Creates 2d array of empty spaces
//-------------------------------------------------------
void createBoard(char board[BOARD_SIZE][BOARD_SIZE]);

//-------------------------------------------------------
// Name: displayBoard
// PreCondition:  game board exists
// PostCondition: displays current game board
//-------------------------------------------------------
void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]);

//-------------------------------------------------------
// Name: updateBoard
// PreCondition: current game board exists, with cordinates
//               X and Y, and board piece to use
// PostCondition: game board should be updated with a the
//                piece in a new position
//-------------------------------------------------------
void updateBoard(char board[BOARD_SIZE][BOARD_SIZE], char boardPiece, int pieceX, int pieceY, int prevX, int prevY);

//-------------------------------------------------------
// Name: askFarmer
// PreCondition: none
// PostCondition: displays direction menu and returns
//                player's choice
//-------------------------------------------------------
int askFarmer();

//-------------------------------------------------------
// Name: getDirectionX
// PreCondition: game piece x cords and player choice exists
//               knows who's cord to change (rabbit or farmer)
// PostCondition: change in x cords respectively
//-------------------------------------------------------
int getDirectionX(int currentPos, int playerChoice, bool);

//-------------------------------------------------------
// Name: getDirectionY
// PreCondition: game piece y cords and player choice exists
//               knows who's cord to change (rabbit or farmer)
// PostCondition: change in y cords respectively
//-------------------------------------------------------
int getDirectionY(int currentPos, int playerChoice, bool);

//-------------------------------------------------------
// Name: randomCord
// PreCondition: none
// PostCondition: generates random number 0 to 9
//-------------------------------------------------------
int randomCord();

//-------------------------------------------------------
// Name: randomDirection
// PreCondition: none
// PostCondition: generates random number 1 to 5
//-------------------------------------------------------
int randomDirection();

//-------------------------------------------------------
// Name: rabbitCompass
// PreCondition: all cords for farmer and rabbit need to
//               exist
// PostCondition: display rabbit position
//-------------------------------------------------------
void rabbitCompass(int farmerX, int farmerY, int rabbitX, int rabbitY);

//-------------------------------------------------------
// Name: checkWon
// PreCondition: allcords for farmer and rabbit need to
//               exist
// PostCondition: return true or false
//-------------------------------------------------------
bool checkWon(int farmerX, int farmerY, int rabbitX, int rabbitY);

int main()
{

  //starts game
  char askPlay = PLAY_YES;

  //while player wants to keep playing
  while (askPlay == PLAY_YES)
  {

    int askChoice, currFarmerX, currFarmerY, currRabbitX, currRabbitY;
    char field[BOARD_SIZE][BOARD_SIZE];

    //empty field
    createBoard(field);

    cout << "Welcome to Chase the Rabbit" << endl;

    //gets starting X
    cout << "Enter the column(x) (0-9)" << endl;
    cin >> currFarmerX;

    //validates X
    while (currFarmerX < BOARD_ZERO || currFarmerX > BOARD_SIZE - 1)
    {
      cout << "Enter the column(x) (0-9)" << endl;
      cin >> currFarmerX;
    }

    //gets starting Y
    cout << "Enter the row(y) (0-9)" << endl;
    cin >> currFarmerY;

    //validates Y
    while (currFarmerY < BOARD_ZERO || currFarmerY > BOARD_SIZE - 1)
    {
      cout << "Enter the row(y) (0-9)" << endl;
      cin >> currFarmerY;
    }

    //random cords for rabbit
    srand(time(NULL));
    currRabbitX = randomCord();
    currRabbitY = randomCord();

    int prevFarmerX, prevFarmerY;

    //while the farmer is not on the rabbit
    while (!checkWon(currFarmerX, currFarmerY, currRabbitX, currRabbitY))
    {

      //ask menu
      askChoice = askFarmer();

      //keeps track of last farmer cords
      prevFarmerX = currFarmerX;
      prevFarmerY = currFarmerY;

      //moves farmer
      switch (askChoice)
      {

      case NORTH_OPTION:
      case SOUTH_OPTION:

        //moves north or south, row wise
        currFarmerY = getDirectionY(currFarmerY, askChoice, true);
        break;

      case WEST_OPTION:
      case EAST_OPTION:

        //moves west or east, column wise
        currFarmerX = getDirectionX(currFarmerX, askChoice, true);
        break;
      }

      //updates farmer
      updateBoard(field, FARMER, currFarmerX, currFarmerY, prevFarmerX, prevFarmerY);

      //keeps track of last rabbit cords
      int prevRabbitX = currRabbitX, prevRabbitY = currRabbitY;

      int rabbitChoice = randomDirection();

      //moves rabbit
      switch (rabbitChoice)
      {

      case NORTH_OPTION:
      case SOUTH_OPTION:

        //moves north or south, row wise
        currRabbitY = getDirectionY(currRabbitY, rabbitChoice, false);
        break;

      case WEST_OPTION:
      case EAST_OPTION:

        //moves west or east, column wise
        currRabbitX = getDirectionX(currRabbitX, rabbitChoice, false);
        break;

      case NO_MOVE:

        cout << "The rabbit nibbles on some food and does not move." << endl;
        break;
      }

      //makes sure rabbit piece does not over lap farmer(when won)
      if (!checkWon(currFarmerX, currFarmerY, currRabbitX, currRabbitY))
        updateBoard(field, RABBIT, currRabbitX, currRabbitY, prevRabbitX, prevRabbitY);
      else
      {

        field[prevRabbitY][prevRabbitX] = ' ';
        field[currRabbitY][currRabbitX] = FARMER;
      }

      //displays rabbit position
      rabbitCompass(currFarmerX, currFarmerY, currRabbitX, currRabbitY);

      displayBoard(field);
    }

    cout << "The farmer has found the rabiit!" << endl;
    cout << "Congrats you've won" << endl;

    //asks player to keep playing
    cout << "Play again? (y/n)" << endl;
    cin >> askPlay;

    //validates play again
    while (askPlay != PLAY_YES && askPlay != PLAY_NO)
    {
      cout << "Play again? (y/n)" << endl;
      cin >> askPlay;
    }
  }

  return 0;
}

int getDirectionX(int currentPos, int pieceDirection, bool farmerTurn)
{

  int newX = 0;

  //checks to move west
  if (pieceDirection == WEST_OPTION)
  {

    //if cord is at the edge (0)
    if (currentPos == BOARD_ZERO)
    {

      if (farmerTurn)
        cout << "The farmer can't leave the field" << endl;
      else
        cout << "The rabbit nibbles on some food and does not move." << endl;

      return currentPos;
    }
    else
    {

      //moves left
      newX = currentPos - 1;

      if (farmerTurn)
        cout << "The farmer moves west" << endl;
    }
  }

  //checks to move east
  else if (pieceDirection == EAST_OPTION)
  {

    //cord is at the edge (9)
    if (currentPos == BOARD_SIZE - 1)
    {

      if (farmerTurn)
        cout << "The farmer can't leave the field" << endl;
      else
        cout << "The rabbit nibbles on some food and does not move." << endl;

      return currentPos;
    }
    else
    {

      //moves right
      newX = currentPos + 1;

      if (farmerTurn)
        cout << "The farmer moves east" << endl;
    }
  }

  //display for when the rabbit is on the move
  if (!farmerTurn)
    cout << "The rabbit moves to another location in search of food" << endl;

  return newX;
}

int getDirectionY(int currentPos, int pieceDirection, bool farmerTurn)
{

  int newY = 0;

  //checks to move north
  if (pieceDirection == NORTH_OPTION)
  {

    //cord is at the edge (0)
    if (currentPos == BOARD_ZERO)
    {

      if (farmerTurn)
        cout << "The farmer can't leave the field" << endl;
      else
        cout << "The rabbit nibbles on some food and does not move." << endl;

      return currentPos;
    }
    else
    {

      //moves up
      newY = currentPos - 1;

      if (farmerTurn)
        cout << "The farmer moves north" << endl;
    }
  }

  //checks to move south
  else if (pieceDirection == SOUTH_OPTION)
  {

    //cord is at the edge (9)
    if (currentPos == BOARD_SIZE - 1)
    {

      if (farmerTurn)
        cout << "The farmer can't leave the field" << endl;
      else
        cout << "The rabbit nibbles on some food and does not move." << endl;

      return currentPos;
    }
    else
    {

      //moves down
      newY = currentPos + 1;

      if (farmerTurn)
        cout << "The farmer moves south" << endl;
    }
  }

  //display for when the rabbit is on the move
  if (!farmerTurn)
    cout << "The rabbit moves to another location in search of food" << endl;

  return newY;
}

void createBoard(char board[BOARD_SIZE][BOARD_SIZE])
{

  //creates empty 2d array
  for (int r = 0; r < BOARD_SIZE; r++)
  {

    for (int c = 0; c < BOARD_SIZE; c++)
    {

      board[r][c] = ' ';
    }
  }
}

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE])
{

  //displays contents of board
  for (int r = 0; r < BOARD_SIZE; r++)
  {

    for (int c = 0; c < BOARD_SIZE; c++)
    {

      cout << '|' << board[r][c];
    }

    cout << '|' << endl;
  }
}

void updateBoard(char board[BOARD_SIZE][BOARD_SIZE], char boardPiece, int pieceX, int pieceY, int prevX, int prevY)
{

  //removes prev piece, makes sure not to remove rabbit or farmer
  if (board[prevY][prevX] == boardPiece)
    board[prevY][prevX] = ' ';

  //adds new piece
  board[pieceY][pieceX] = boardPiece;
}

int askFarmer()
{

  int askPlayer = 0;

  cout << "What would you like to do?" << endl;

  //displays options
  for (int i = 0; i < WEST_OPTION; i++)
    cout << i + 1 << ". " << PLAYER_OPTIONS[i] << endl;

  cin >> askPlayer;

  //validates choice
  while (askPlayer < NORTH_OPTION || askPlayer > WEST_OPTION)
  {

    cout << "Enter another option" << endl;
    cin >> askPlayer;
  }

  return askPlayer;
}

int randomCord()
{

  //random num 0 to 9
  return rand() % (BOARD_SIZE - 1);
}

int randomDirection()
{

  //random num 1 to 5
  int r = (rand() % NO_MOVE) + NORTH_OPTION;
  return r;
}

bool checkWon(int farmerX, int farmerY, int rabbitX, int rabbitY)
{

  //if cords are the same
  if (farmerX == rabbitX && farmerY == rabbitY)
    return true;
  else
    return false;
}

void rabbitCompass(int farmerX, int farmerY, int rabbitX, int rabbitY)
{

  //east of farmer
  if (farmerX < rabbitX)
    cout << "The rabbit is east of the farmer" << endl;

  //west of farmer
  else if (farmerX > rabbitX)
    cout << "The rabbit is west of the farmer" << endl;

  //south of farmer
  else if (farmerY < rabbitY)
    cout << "The rabbit is south of the farmer" << endl;

  //north of farmer
  else if (farmerY > rabbitY)
    cout << "The rabbit is north of the farmer" << endl;
}
