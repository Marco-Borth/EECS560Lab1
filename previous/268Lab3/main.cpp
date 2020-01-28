/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 3 Program
 * Description:  In this lab, you will build a mock web browser,
 read commands from a file that let you know what buttons are being pushed
 and what URLs are being navigated to, and you will track a List of Tabs.
 * Date: 3/1/19
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
