/* -----------------------------------------------------------------------------
*
* File Name:  Node.cpp
* Author: Marco Borth
* Assignment:   EECS-268 Lab 2 Program
* Description:  Node set and get methods defined here.
* Date: 2/22/19
*
---------------------------------------------------------------------------- */

#include "Node.h"
#include <string>
using namespace std;

Node::Node(int entry)
{
  m_entry = entry;
  m_next = nullptr;
}

Node::~Node()
{
  m_next = nullptr;
  delete &m_entry;
}

void Node::setEntry(int entry)
{
  m_entry = entry;
}

int Node::getEntry() const
{
  return(m_entry);
}

void Node::setNext(Node* next)
{
  m_next = next;
}

Node* Node::getNext() const
{
  return(m_next);
}
