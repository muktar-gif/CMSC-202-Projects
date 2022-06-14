/*****************************************
** File:    Class.cpp
** Project: CMSC 202 Project 5, Fall 2019
** Author:  Muhammed Muktar
** Date:    12/5/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Class Class.
**
***********************************************/
#include "Class.h"

//Name: Class
//Desc: Default Constructor
//Precondition: None
//Postcondition: Creates Class object
Class::Class()
{

  m_name = "";
  m_section = 0;
}
//Name: Class
//Desc: Overloaded Constructor
//Precondition: Have name and number
//Postcondition: Creates Class object
Class::Class(string name, int section)
{

  SetName(name);
  SetSection(section);
}
//Name: ~Class
//Desc: Destructor
//Precondition: None
//Postcondition: Deallocates anything dynamically allocated in a Class
Class::~Class()
{

  //deletes pointers in m_roster
  for (int i = 0; i < m_roster.Size(); i++)
  {

    delete m_roster[i];
  }

  m_roster.ClearData();

  //deletes pointers in m_waitlist
  for (int i = 0; i < m_waitlist.Size(); i++)
  {

    delete m_waitlist[i];
  }

  m_waitlist.ClearData();
}
//Name: DisplayStudents
//Desc: Displays all students in Class. Displays students in the m_roster
//      and if there are students in the m_waitlist, displays them
//      Additionally shows count of students in m_roster and count in m_waitlist
//Precondition: Class has students enrolled
//Postcondition: Lists all students for a specific Class
void Class::DisplayStudents()
{

  cout << "Displaying Student" << endl;
  cout << "Course: " << m_name << " Section: " << m_section << endl;

  //display enrolled
  cout << "Enrolled (" << m_roster.Size() << " enrolled)" << endl;

  for (int i = 0; i < m_roster.Size(); i++)
  {

    cout << *m_roster[i];
  }

  //displays waitlist if it's not empty
  if (m_waitlist.Size() != 0)
  {

    cout << "Waitlisted (" << m_waitlist.Size() << " waitlisted)" << endl;

    for (int i = 0; i < m_waitlist.Size(); i++)
    {

      cout << *m_waitlist[i];
    }
  }
}
//Name: AddStudent
//Desc: A student is added to a Class. If there is room in the m_roster, added there.
//      If the m_roster is full, attempts to add student to m_waitlist.
//      Else new section added, waitlist moved to new section and new student added.
//Precondition: Class exists
//Postcondition: Adds a student to a Class; returns true if added else false
bool Class::AddStudent(Student *student)
{

  //roster is not full
  if (!IsRosterFull())
  {

    //add student to roster
    m_roster.Enqueue(student);
    return true;
  }
  //waitlist is not full
  else if (!IsWaitlistFull())
  {

    //add student to waitlist
    m_waitlist.Enqueue(student);
    return true;
  }

  //both waitlist and roster are full
  return false;
}

//Name: Sort
//Desc: Sorts the students alphabetically by last name for both roster and waitlist
//Precondition: None
//Precondition: None
//Postcondition: m_roster and m_waitlist are sorted
void Class::SortStudents()
{

  //sorts roster
  m_roster.Sort();

  //sorts waitlist
  m_waitlist.Sort();
}

//Name: GetName
//Desc: Returns name of Class
//Precondition: None
//Postcondition: Class name is returned
string Class::GetName()
{

  return m_name;
}

//Name: SetName
//Desc: Allows Class name to be set
//Precondition: name is a valid string
//Postcondition: Class name is updated
void Class::SetName(string name)
{

  m_name = name;
}

//Name: GetSection
//Desc: Returns section of Class
//Precondition: None
//Postcondition: Class section is returned
int Class::GetSection()
{

  return m_section;
}

//Name: SetSection
//Desc: Allows Class section to be set
//Precondition: section is a valid integer
//Postcondition: Class section is updated
void Class::SetSection(int section)
{

  m_section = section;
}

//Name: TransferWaitToRoster
//Desc: When an m_roster is full and m_waitlist is full, copies all students in
//      m_waitlist to a destination Class
//Precondition: m_waitlist is full
//Postcondition: m_waitlist is empty and all students were transferred to new Class
void Class::TransferWaitToRoster(Class &destination)
{

  for (int i = 0; i < m_waitlist.Size(); i++)
  {

    //transfers waitlist values to destination
    destination.m_roster.Enqueue(m_waitlist[i]);
  }

  int size = m_waitlist.Size();

  //removes info in waitlist
  for (int i = 0; i < size; i++)
    m_waitlist.Dequeue();
}

//Name: IsRosterFull()
//Desc: Returns bool of if the m_roster is at capacity
//Precondition: None
//Postcondition: Returns bool
bool Class::IsRosterFull()
{

  //if roster is full
  if (m_roster.Size() == ROSTER_MAX)
    return true;
  else
    return false;
}

//Name: IsWaitlistFull()
//Desc: Returns bool of if the m_waitlist is at capacity
//Precondition: None
//Postcondition: Returns bool
bool Class::IsWaitlistFull()
{

  //if waitlist is full
  if (m_waitlist.Size() == WAIT_MAX)
    return true;
  else
    return false;
}

//Name: SearchClass
//Desc: Searches m_roster and m_waitlist for a string.
//      If string exists in m_roster or m_waitlist, Class information printed
//Precondition: None
//Postcondition: Returns bool
bool Class::SearchClass(string item)
{

  //loops though roster
  for (int i = 0; i < m_roster.Size(); i++)
  {

    //if name is found in roster
    if (m_roster[i]->GetFName() == item || m_roster[i]->GetLName() == item)
      return true;
  }

  //loops through waitlist
  for (int i = 0; i < m_waitlist.Size(); i++)
  {

    //if name is found in waitlist
    if (m_waitlist[i]->GetFName() == item || m_waitlist[i]->GetLName() == item)
      return true;
  }

  //name is not found
  return false;
}

// Name: Overloaded <<
// Description: Prints the details of a Class (Class name and section)
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of the Class
ostream &operator<<(ostream &output, Class &printClass)
{

  //output for class detail
  output << "Course: " << printClass.m_name << " Section: " << printClass.m_section << endl;

  return output;
}
