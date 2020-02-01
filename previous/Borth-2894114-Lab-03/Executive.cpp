/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 2 Program
 * Description:  Executive Class creates and runs driver class: WebBrowser.
 * Date: 3/1/19
 *
 ---------------------------------------------------------------------------- */
#include "Executive.h"
#include "WebBrowser.h"
#include <string>
using namespace std;

// Create Executive and Course Objects.
Executive::Executive(string filename)
{
	file = filename;
}

void Executive::run()
{
	WebBrowser SearchEngine(file);
	SearchEngine.run();
}
