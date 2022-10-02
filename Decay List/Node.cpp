/*****************************************
** File:    Node.cpp
** Project: CMSC 202 Project 3, Fall 2019
** Author:  Muhammed Muktar
** Date:    10/29/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the Node Class.
**
***********************************************/
#include "Node.h"

// Constructor
// Preconditions: None
// Postconditions: None
Node::Node()
{
}

// Destructor
// Preconditions: None
// Postconditions: Frees dynamically allocated memory
Node::~Node()
{
}

// Overloaded Constructor
// Preconditions: None
// Postconditions: Initializes member variable with given argument
Node::Node(bool value)
{

  m_value = value;
}

// ReplaceValue - Replaces m_value with opposite (if true then false or if false then true)
// Preconditions: None
// Postconditions: m_value negated
void Node::ReplaceValue()
{

  //inverted value
  m_value = !m_value;
}

// SetNext() - Sets m_next
// Preconditions: None
// Postconditions: m_next is set
void Node::SetNext(Node *next)
{

  m_next = next;
}

// GetNext() - returns m_next
// Preconditions: None
// Postconditions: returns m_next
Node *Node::GetNext()
{

  return m_next;
}

// GetValue() - returns m_value
// Preconditions: None
// Postconditions: returns m_value
bool Node::GetValue()
{

  return m_value;
}
