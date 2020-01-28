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
* @post Driver object is constructed.
*/
  Driver(string mode);

  void interactiveMenu();

  //This will call all your test methods
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
  * @brief Creates an empty list and verifies getLength() returns 3
  **/
  void sizeTest05();

  /**
  * @brief Creates an empty list and verifies getLength() returns 3
  **/
  void sizeTest06();

  /**
  * @brief Creates an empty list and verifies getLength() returns 3
  **/
  void sizeTest07();

  /**
  * @brief Creates an empty list and returns invalid position runtime_error.
  **/
  void insertTest01();
};
#endif
