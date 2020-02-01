/* -----------------------------------------------------------------------------
*
* File Name:  Node.cpp
* Author: Marco Borth
* Assignment:   EECS-268 Lab 3 Program
* Description:  Node set and get methods defined here.
* Date: 3/1/19
*
---------------------------------------------------------------------------- */

//#include "Node.h"
#include <string>
using namespace std;

template <typename T>
Node<T>::Node(T entry)
{
  m_entry = entry;
  m_next = nullptr;
}

template <typename T>
Node<T>::~Node<T>()
{
  m_next = nullptr;
  delete &m_entry;
}

template <typename T>
void Node<T>::setEntry(T entry)
{
  m_entry = entry;
}

template <typename T>
T Node<T>::getEntry() const
{
  return(m_entry);
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
  m_next = next;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
  return(m_next);
}
