/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.cpp
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 1 - Implementation of Singly Linked List
 * Description:  Executive Class creates and runs the Operator class.
 * Date: 1/28/20
 *
 ---------------------------------------------------------------------------- */
#include "Executive.h"
#include "Operator.h"
#include <string>
using namespace std;

// Create Executive Object.
Executive::Executive(string filename)
{
	file = filename;
}
void Executive::run() {
	Operator List(file);
	List.run();
}
