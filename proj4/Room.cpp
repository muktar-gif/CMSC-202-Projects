/*****************************************
** File:    Room.cpp
** Project: CMSC 202 Project 4, Fall 2019
** Author:  Muhammed Muktar
** Date:    11/13/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Room Class.
**
***********************************************/

#include "Room.h"

//Name: Room (Overloaded Constructor)
//Precondition: Must have valid input for each part of a room
//Postcondition: Creates a new room
Room::Room(int id, string name, string desc, int north, int east, int south, int west)
{

  m_ID = id;
  m_name = name;
  m_desc = desc;

  m_direction[0] = north;
  m_direction[1] = east;
  m_direction[2] = south;
  m_direction[3] = west;
}

//Name: GetName
//Precondition: Must have valid room
//Postcondition: Returns room name as string
string Room::GetName()
{

  return m_name;
}

//Name: GetID
//Precondition: Must have valid room
//Postcondition: Returns room id as int
int Room::GetID()
{

  return m_ID;
}

//Name: GetDesc
//Precondition: Must have valid room
//Postcondition: Returns room desc as string
string Room::GetDesc()
{

  return m_desc;
}

//Name: CheckDirection
//Precondition: Must have valid room
//You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
//returns the ID of the room in that direction
//Postcondition: Returns id of room in that direction if the exit exists
//If there is no exit in that direction, returns -1
int Room::CheckDirection(char myDirection)
{

  direction getDirection;

  //gets index of directions using enum
  if (myDirection == 'N' || myDirection == 'n')
    getDirection = N;

  else if (myDirection == 'E' || myDirection == 'e')
    getDirection = E;

  else if (myDirection == 'S' || myDirection == 's')
    getDirection = S;

  else if (myDirection == 'W' || myDirection == 'w')
    getDirection = W;

  //if there was no index/ -1
  if (m_direction[getDirection] == -1)
    return -1;

  else
    //return id of room
    return m_direction[getDirection];
}

//Name: PrintRoom
//Precondition: Room must be complete
//Postcondition: Outputs the room name, room desc, then possible exits
void Room::PrintRoom()
{

  //prints room indormation
  cout << m_name << endl;
  cout << m_desc << endl;

  //prints possible exits
  cout << "Possible exits: ";
  for (int i = 0; i < 4; i++)
  {

    if (m_direction[i] != -1)
    {

      if (i == 0)
        cout << "N";
      else if (i == 1)
        cout << "E";
      else if (i == 2)
        cout << "S";
      else if (i == 3)
        cout << "W";

      cout << " ";
    }
  }

  cout << endl;
}
