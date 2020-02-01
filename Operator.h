/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.h
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 1 - Implementation of Singly Linked List
 * Description:  Operator Class is defined.
 * Date: 1/28/20
 *
 ---------------------------------------------------------------------------- */

#ifndef OPERATOR_H
#define OPERATOR_H

#include "LinkedList.h"
#include <string>
#include <stdexcept>
using namespace std;

class Operator
{
private:
  int option;
  LinkedList<int> myList;
  string file;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

  void printCommands();

/*
* @pre filename is a string.
* @post Operator object is constructed, file == filename.
*/
  Operator(string filename);
};
#endif
