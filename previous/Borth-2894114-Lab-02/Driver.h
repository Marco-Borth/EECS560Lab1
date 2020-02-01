/* -----------------------------------------------------------------------------
 *
 * File Name:  Driver.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 2 Program
 * Description:  Driver Class is defined.
 * Date: 2/22/19
 *
 ---------------------------------------------------------------------------- */

#ifndef DRIVER_H
#define DRIVER_H

#include "LinkedList.h"
#include <string>
#include <stdexcept>
using namespace std;

class Driver
{
private:
  string driverMode;
  int option;
  LinkedList myList;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

/*
* @pre Executive.cpp must construct Driver object.
* @param mode must be a valid string.
* @post Driver object is constructed.
*/
  Driver(string mode);

/*
* @pre none.
* @post interactiveMenu is initiated if driverMode == "-i".
*/
  void interactiveMenu();

/*
* @pre none.
* @post runTests runs all private test functions if driverMode == "-t".
*/
  void runTests();

private:
  /**
  * @brief Creates an empty list and verifies isEmpty() returns true
  **/
  void sizeTest01();

  /**
  * @brief Creates an empty list adds 1 value, verifies isEmpty() returns false
  **/
  void sizeTest02();

  /**
  * @brief Creates an empty list and verifies getLength() returns 2
  **/
  void sizeTest03();

  /**
  * @brief Creates an empty list and verifies getLength() returns 3
  **/
  void sizeTest04();

  /**
  * @brief Creates an empty list and verifies getLength() returns 3 after front insertion and removal
  **/
  void sizeTest05();

  /**
  * @brief Creates an empty list and verifies getLength() returns 3 after back insertion and removal
  **/
  void sizeTest06();

  /**
  * @brief Creates an empty list and verifies getLength() returns 3 after middle insertion and removal
  **/
  void sizeTest07();

  /**
  * @brief Creates an empty list and returns invalid position runtime_error.
  **/
  void insertTest01();

  /**
  * @brief Creates an empty list and returns invalid position runtime_error.
  **/
  void removeTest01();

  /**
  * @brief Creates an empty list and returns invalid position runtime_error.
  **/
  void replaceTest01();

  /**
  * @brief Creates an empty list and returns invalid position runtime_error.
  **/
  void getEntryTest01();

  /**
  * @brief Creates an empty list adds 1 value, verifies getEntry() returns correct after value inserting at front of list.
  **/
  void getEntryTest02();

  /**
  * @brief Creates an empty list and verifies getEntry() returns correct value after inserting at back of list.
  **/
  void getEntryTest03();

  /**
  * @brief Creates an empty list and verifies getEntry() returns correct value after inserting in middle of list.
  **/
  void getEntryTest04();

  /**
  * @brief Creates an empty list and verifies getEntry() returns correct value after front insertion and removal.
  **/
  void getEntryTest05();

  /**
  * @brief Creates an empty list and verifies getEntry() returns correct value back front insertion and removal.
  **/
  void getEntryTest06();

  /**
  * @brief Creates an empty list and verifies getEntry() returns correct value back middle insertion and removal.
  **/
  void getEntryTest07();

  /**
  * @brief Creates an empty list and verifies isEmpty() returns true
  **/
  void isEmptyTest();
};
#endif
