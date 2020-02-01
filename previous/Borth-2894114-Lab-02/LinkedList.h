/* -----------------------------------------------------------------------------
 *
 * File Name:  LinkedList.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 2 Program
 * Description:  LinkedList Class is defined.
 * Date: 2/22/19
 *
 ---------------------------------------------------------------------------- */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h" //Gone over in class
#include <string>
#include <stdexcept> //For runtime_error
using namespace std;

class LinkedList
{
private:
  Node* m_front;
  int m_length;

public:
/*
* @pre Executive.cpp must construct driverClass object.
* @post LinkedList object is constructed.
*/
  LinkedList();

/*
* @pre none.
* @post LinkedList copy constructor runs operator= function.
*/
  LinkedList(const LinkedList& original);

/*
* @pre none.
* @post ~LinkedList clears m_front and deletes LinkedList object.
*/
  ~LinkedList();

/*
* @pre none.
* @post operator= inserts original nodes onto the LinkedList.
*/
  LinkedList& operator=(const LinkedList& original);

/*
* @pre none.
* @post isEmpty returns true if m_length == 0, otherwise false.
*/
  bool isEmpty() const;

/*
* @pre none.
* @post getLength returns m_length.
*/
  int getLength() const;

/*
* @pre none.
* @param position: must be between 1 and m_length + 1.
* @param entry: must be a valid int.
* @post insert creates a new node within the LinkedList.
* @throw runtime_error if the postion is invalid.
*/
   void insert(int position, int entry);

/*
* @pre none.
* @param position: must be between 1 and m_length.
* @post remove deletes the node at the postion within the LinkedList.
* @throw runtime_error if the postion is invalid.
*/
   void remove(int position);

/*
* @pre none.
* @post clear deletes all nodes within LinkedList, resets m_length to 0.
*/
   void clear();

/*
* @pre none.
* @param position: must be between 1 and m_length.
* @post getEntry returns Node entry at the given position.
* @throw runtime_error if the postion is invalid.
* @throw runtime_error if LinkedList isEmpty.
*/
   int getEntry(int position) const;

/** Here's an example of a doxygen comment block. Do this for all methods
* @pre The position is between 1 and the list's length
* @post The entry at the given position is replaced with the new entry
* @param position:  1<= position <= length
* @param newEntry: A new entry to put in the list
* @throw std::runtime_error if the position is invalid.
**/
  void replace(int position, int newEntry);
};
#endif
