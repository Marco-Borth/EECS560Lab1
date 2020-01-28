/* -----------------------------------------------------------------------------
 *
 * File Name:  Tab.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 3 Program
 * Description:  Tab Class is defined.
 * Date: 3/1/19
 *
 ---------------------------------------------------------------------------- */

#ifndef TAB_H
#define TAB_H

#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

class Tab
{
private:
  LinkedList<string> urlHistory;
  int tabFocus;
  string focusedURL;

public:
  /**
  * @pre none
  * @post the browser navigate to the given url
  * @param url, a string representing a URL
  */
  void navigateTo(string url);

  /**
  * @pre none
  * @post if possible, the browser navigates forward in the history otherwise it keeps focus
  *         on the current URL
  */
  void forward();

  /**
  * @pre none
  * @post if possible, the browser navigates backwards in the history otherwise it keeps focus
  *         on the current URL
  */
  void back();

  /**
  * @return the URL currently open in the tab
  */
  string currentURL() const;

  /**
  * @pre The list being passed in is empty
  * @post The current browser history is copied into the given list
  * @param destination, an empty list of strings
  * @return the position in the list with focus (zero if there is no history)
  */
  int copyCurrentHistory(LinkedList<string>& destination);

  Tab();
};

#endif
