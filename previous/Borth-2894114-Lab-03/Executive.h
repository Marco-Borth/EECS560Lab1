/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 3 Program
 * Description:  Executive Class is defined.
 * Date: 3/1/19
 *
 ---------------------------------------------------------------------------- */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <stdexcept>
using namespace std;

class Executive
{
private:
	string file;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

/*
* @pre main.cpp must construct Executive object.
* @post Executive object is constructed.
*/
	Executive(string filename);
};
#endif
