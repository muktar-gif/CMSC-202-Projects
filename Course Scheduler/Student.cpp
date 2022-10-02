/*****************************************
** File:    Student.cpp
** Project: CMSC 202 Project 5, Fall 2019
** Author:  Muhammed Muktar
** Date:    12/5/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Student Class.
**
***********************************************/
#include "Student.h"

// Name: Student
// Description: Default Constructor
// Preconditions: None
// Postconditions: Creates new student object
Student::Student()
{

  m_fName = "";
  m_lName = "";
  m_id = 0;
}

// Name: Student (fName, lName, id)
// Description: Overloaded Constructor
// Preconditions: Data being passed is valid
// Postconditions: Creates new student object
Student::Student(string fName, string lName, int id)
{

  //sets private values
  SetFName(fName);
  SetLName(lName);
  SetID(id);
}

string Student::GetFName()
{

  return m_fName;
}

string Student::GetLName()
{

  return m_lName;
}

int Student::GetID()
{

  return m_id;
}

void Student::SetFName(string fName)
{

  m_fName = fName;
}

void Student::SetLName(string lName)
{

  m_lName = lName;
}

void Student::SetID(int id)
{

  m_id = id;
}

// Name: Overloaded <<
// Description: Prints the details of a student
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of student
ostream &operator<<(ostream &output, Student &student)
{

  //output for student information
  output << student.m_lName << ", " << student.m_fName << endl;

  return output;
}

// Name: Overloaded <
// Description: Overloaded comparison operator (used for sorting)
// Preconditions: Two students being compared
// Postconditions: Returns m_lName first and then m_fName if m_lName same
bool operator<(const Student &s1, const Student &s2)
{

  //lastnames
  string s1L = s1.m_lName;
  string s2L = s2.m_lName;

  //firstnames
  string s1F = s1.m_fName;
  string s2F = s2.m_fName;

  //last name is out of order
  if (s1L > s2L)
  {
    return true;
  }
  //last name is in order
  else if (s1L < s2L)
  {
    return false;
  }
  else
  {

    //first name is out of order
    if (s1F > s2F)
    {
      return true;
    }
    //first name is in order
    else if (s1F < s2F)
    {
      return false;
    }
  }

  //first equals last name
  return false;
}
