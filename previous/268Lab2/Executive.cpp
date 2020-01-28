/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 2 Program
 * Description:  Executive Class creates and runs driver class: Driver.
 * Date: 2/22/19
 *
 ---------------------------------------------------------------------------- */
#include "Executive.h"
#include "Driver.h"
#include <string>
using namespace std;

// Create Executive and Course Objects.
Executive::Executive(string mode)
{
	LinkedListMode = mode;
}

void Executive::run()
{
	Driver ToDoList(LinkedListMode);
	ToDoList.run();
}
