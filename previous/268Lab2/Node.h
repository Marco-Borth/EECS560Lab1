/* -----------------------------------------------------------------------------
*
* File Name:  Node.h
* Author: Marco Borth
* Assignment:   EECS-268 Lab 2 Program
* Description:  Node Class is defined here;
* Date: 2/22/19
*
---------------------------------------------------------------------------- */

#ifndef NODE_H
#define NODE_H

#include <string>
#include <stdexcept>
using namespace std;

class Node
{
private:
  int m_entry;
  Node* m_next;

public:
/*
* @pre none.
* @param entry must be a int value.
* @post m_entry is set to entry.
*/
  void setEntry(int entry);

/*
* @pre none.
* @post return m_entry value.
*/
  int getEntry() const;

/*
* @pre none.
* @param next must be a Node or Node pointer.
* @post m_next is set to next.
*/
  void setNext(Node* next);

/*
* @pre none.
* @post return m_next.
*/
  Node* getNext() const;

/*
* @pre none.
* @param entry must be a valid int entry
* @post creates node with givin int entry.
*/
  Node(int entry);

/*
* @pre Node object must be constructed.
* @post deletes Node, m_entry, and m_next = nullptr.
*/
  ~Node();
};
#endif
