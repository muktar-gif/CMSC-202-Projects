/*****************************************
** File:    DecayList.cpp
** Project: CMSC 202 Project 3, Fall 2019
** Author:  Muhammed Muktar
** Date:    10/29/19
** Section: 30
** E-mail:  mmuktar1@gl.umbc.edu
**
** This is the .cpp file for the DecayList Class.
**
***********************************************/

#include "DecayList.h"

// Constructor
// Preconditions: None
// Postconditions: New list is created
DecayList::DecayList()
{

  m_head = NULL;
  m_size = 0;
}

// Destructor
// Preconditions: None
// Postconditions: Dynamically allocated memory freed
DecayList::~DecayList()
{

  Node *current = m_head;
  Node *temp;

  //runs until end of list
  while (current != NULL)
  {

    temp = current->GetNext();

    //deletes pointer
    delete current;
    current = temp;
    m_size--;
  }

  current = temp = NULL;
  m_head = NULL;
}

// GetSize - Returns size of list
// Preconditions: None
// Postconditions: Returns size (as integer)
int DecayList::GetSize()
{

  return m_size;
}

// InvertValue - Chooses a node to replace value (with opposite value)
// Preconditions: Node to be changed exists
// Postconditions: Node's value is negated
void DecayList::InvertValue(int index)
{

  Node *current;
  current = m_head;

  for (int i = 0; i < m_size; i++)
  {

    //index if found
    if (i == index)
    {

      //changes value
      current->ReplaceValue();
      i = m_size;
    }
    else
      current = current->GetNext();
  }
}

// PrintDecayList() - Prints the list of nodes and their values
// Preconditions: None
// Postconditions: m_value are printed out in order returns true if successfully prints
bool DecayList::PrintDecayList()
{

  if (CheckEmpty())
    return false;

  Node *current;
  current = m_head;

  //prints layout with list
  for (int i = 0; i < m_size; i++)
  {

    cout << "|" << current->GetValue() << "|->";

    current = current->GetNext();
  }

  cout << "END" << endl;

  return true;
}

// TraverseList - Loops list to see if any sequences of 3 or more nodes with a value of 1
// Preconditions: DecayList has Nodes. Passed value to be checked (true by default)
// Postconditions: Removes all sequences of nodess with 3 or more cards with a value of 1;
//                 returns number of cards removed
int DecayList::TraverseList(bool traverse)
{

  Node *first;
  Node *second;
  Node *third;

  int totalRemoved = 0;

  //gets pointers to 3 nodes
  first = m_head;
  second = first->GetNext();
  third = second->GetNext();

  //runs until 3 nodes before the list

  for (int i = 0; i < m_size - (NUM_CONSECUTIVE - 1); i++)
  {

    //checks if 3 nodes have 1
    if ((first->GetValue() == 1) && (second->GetValue() == 1) && (third->GetValue() == 1))
    {

      //removes nodes
      totalRemoved = RemoveNodes(i, NUM_CONSECUTIVE);
      i = m_size;
    }
    else
    {

      first = first->GetNext();
      second = second->GetNext();
      third = third->GetNext();
    }
  }
  return totalRemoved;
}

// RemoveNodes - Called when 3 or more 1's in a row. Nodes are removed left to right.
// Preconditions: A DecayList has a minimum of 3 nodes
// Postconditions: The nodes are removed, which resizes DecayList; Returns number removed.
int DecayList::RemoveNodes(int index, int numNodes)
{

  Node *current;
  Node *prev;
  Node *temp;
  current = m_head;
  prev = m_head;

  int totalRemoved = 0;

  //if removing at beginning
  if (index == 0)
  {

    //points after 3 nodes
    for (int i = 0; i < numNodes; i++)
      current = current->GetNext();

    //connects list
    m_head = current;
    totalRemoved = numNodes;

    //deletes nodes
    for (int i = 0; i < numNodes; i++)
    {

      temp = prev->GetNext();
      delete (prev);
      prev = temp;
    }

    m_size -= numNodes;
  }
  // if removing is at the end
  else if (index == (m_size - numNodes))
  {

    //3 nodes before the end
    for (int i = 0; i < index; i++)
    {
      prev = current;
      current = current->GetNext();
    }

    //connects the list to NULL
    prev->SetNext(NULL);
    totalRemoved = numNodes;

    //deletes nodes
    for (int i = 0; i < numNodes; i++)
    {

      temp = current->GetNext();
      delete (current);
      current = temp;
    }

    m_size -= numNodes;
  }

  else
  {

    for (int i = 0; i < m_size; i++)
    {

      //if index is at the index
      if (i == index)
      {

        //copies the node to remove
        temp = current;

        //points to the end of the removes node
        for (int j = 0; j < numNodes; j++)
          current = current->GetNext();

        //reconnects list
        prev->SetNext(current);
        totalRemoved = numNodes;

        //deletes nodes
        current = temp;
        for (int j = 0; j < numNodes; j++)
        {

          temp = current->GetNext();
          delete (current);
          current = temp;
        }

        //exits for loop
        i = m_size;
      }

      else
      {

        prev = current;
        current = current->GetNext();
      }
    }

    m_size -= numNodes;
  }

  return totalRemoved;
}

// CheckEmpty - Called to see if the list is empty
// Preconditions: Nodes were removed from list
// Postconditions: If empty, returns true and round ends
bool DecayList::CheckEmpty()
{

  //if m_head was still NULL
  if (m_head == NULL)
    return true;

  return false;
}

// InsertEnd - Inserts new Node into end of DecayList
// Preconditions: DecayList exists - may not create m_tail
// Postconditions: Inserts passed node to end of list
void DecayList::InsertEnd(Node *node)
{

  Node *current;

  //makes sure list isnt empty
  if (CheckEmpty())
  {

    m_head = node;
    node->SetNext(NULL);
  }

  else
  {

    current = m_head;

    //goes to end of list
    while (current->GetNext() != NULL)
    {
      current = current->GetNext();
    }

    //adds node to end
    current->SetNext(node);
    node->SetNext(NULL);
  }

  //increases size
  m_size++;
}
