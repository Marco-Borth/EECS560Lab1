/* -----------------------------------------------------------------------------
 *
 * File Name:  WebBrowser.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 3 Program
 * Description:  WebBrowser Class is defined.
 * Date: 3/1/19
 *
 ---------------------------------------------------------------------------- */

#ifndef WEB_BROWSER_H
#define WEB_BROWSER_H

#include "LinkedList.h"
#include "Tab.h"
#include <string>
#include <stdexcept>
using namespace std;

class WebBrowser
{
private:
  string file;
  string command;
  LinkedList<Tab> tabList;
  int total_num_tabs;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

/*
* @pre Executive.cpp must construct WebBrowser object.
* @post WebBrowser object is constructed.
*/
  WebBrowser(string filename);
};

#endif
