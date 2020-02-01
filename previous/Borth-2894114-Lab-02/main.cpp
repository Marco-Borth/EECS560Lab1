/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 2 Program
 * Description:  This lab will focus on constructing a Linked List and creating a test class to verify that it works.
 * Date: 2/22/19
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include <iostream>
#include"Executive.h"

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout << "Incorrect number of parameters!\n";
	}
	else
	{
		Executive exec(argv[1]); //sample creation of executive object
		exec.run(); //presumably handles the calling of all other member methods
	}

	return(0);
}
