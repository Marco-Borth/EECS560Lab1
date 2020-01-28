/* -----------------------------------------------------------------------------
 *
 * File Name:  WebBrowser.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 3 Program
 * Description:  WebBrowser Class will ...
 * Date: 3/1/19
 *
 ---------------------------------------------------------------------------- */

#include "WebBrowser.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

WebBrowser::WebBrowser(string filename)
{
  tabList;
  file = filename;
  total_num_tabs = 0;
}

void WebBrowser::run()
{
  cout << "\nWelcome to your Browser!\n\n";

  Tab TabTester;
  LinkedList<string> tabURLHistoryList;
  //LinkedList<LinkedList<string>> browserList;

  int tabNumber = 0;
  int tabPosition = 0;
  ifstream inFile;

  //Open File.
  inFile.open(file);

  if (!inFile.is_open())
  {
    cout << "File name not valid!\n";
  }

  do{
    inFile >> command;

    // WebBrowser swtich case
    if (command == "NEW_TAB")
    {
      cout << "new tab\n";
      //Tab tempTab;
      //LinkedList<string> tempList;

      total_num_tabs++;
      tabNumber++;
      //tabList.insert(tabNumber, TabTester);
      //browserList.insert(browserList.getLength() + 1, tempList);
    }
    else if (command == "FOCUS")
    {
      int index = 0;
      inFile >> index;
      cout << "focus " << index << "\n";

      tabNumber = index;
    }
    else if (command == "MOVE_LEFT")
    {
      int distance = 0;
      inFile >> distance;
      cout << "move left " << distance << "\n";

      if (tabNumber - distance <= 0)
      {
        tabNumber = 1;
      }
      else
      {
        tabNumber = tabNumber - distance;
      }
    }
    else if (command == "MOVE_RIGHT")
    {
      int distance = 0;
      inFile >> distance;
      cout << "move right " << distance << "\n";

      if (tabNumber + distance > tabList.getLength())
      {
        tabNumber = tabList.getLength();
      }
      else
      {
        tabNumber = tabNumber + distance;
      }
    }
    else if (command == "HISTORY")
    {
      //Tab tempTab = tabList.getEntry(tabNumber);
      cout << "Tab " << tabNumber << "\n===========\n";
      // tabURLHistoryList.getLength()
      // browserList.getEntry(tabNumber).getLength()
      for (int i = 1; i <= tabURLHistoryList.getLength(); i++)
      {
        // tabURLHistoryList.getEntry(i)
        // browserList.getEntry(tabNumber).getEntry(i)
        cout << tabURLHistoryList.getEntry(i);
        // tabURLHistoryList.getLength()
        // browserList.getEntry(tabNumber).getLength()

        if (tabURLHistoryList.getEntry(i) == TabTester.currentURL())
        {
          cout << " <==current";
        }

        if (i != tabURLHistoryList.getLength())
        {
          cout << "\n";
        }
      }
      cout << "\n===========\nNewest\n\n";
    }
    else if (command == "EXIT")
    {
      cout << "Exiting Web Browser....\n";
    }
    else if (command == "NAVIGATE") // Tab commands
    {
      cout << "navigate\n";
      string urlLink;
      inFile >> urlLink;

      //tabList.getEntry(tabNumber).navigateTo(urlLink);
      TabTester.navigateTo(urlLink);
      //tabPosition = TabTester.copyCurrentHistory(tabURLHistoryList)
      tabURLHistoryList.insert(tabURLHistoryList.getLength() + 1, urlLink);
      //browserList.getEntry(tabNumber).insert(browserList.getLength() + 1, urlLink);
      //tabList.getEntry(tabNumber).copyCurrentHistory(tabURLHistoryList);
    }
    else if (command == "BACK")
    {
      TabTester.back();
    }
    else if (command == "FORWARD")
    {
      TabTester.forward();
    }
  } while (command != "EXIT");

  // Close File.
  inFile.close();

  cout << "\nHave a nice day!...\n\n";

  tabList.~LinkedList();
}
