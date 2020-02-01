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
  LinkedList<string> tabURLHistoryList;
  Tab* newTab;
  Tab* tempTab;

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
      // cout << "new tab\n";
      tempTab = new Tab();
      newTab = tempTab;

      total_num_tabs = tabList.getLength();
      tabNumber = tabList.getLength() + 1;
      tabList.insert(tabNumber, newTab);

      newTab = nullptr;
      delete tempTab;
    }
    else if (command == "FOCUS")
    {
      int index = 0;
      inFile >> index;
      //cout << "focus " << index << "\n";

      tabNumber = index;
    }
    else if (command == "MOVE_LEFT")
    {
      int distance = 0;
      inFile >> distance;
      //cout << "move left " << distance << "\n";

      tabURLHistoryList.clear();
      int currentURLPosition = tabList.getEntry(tabNumber)->copyCurrentHistory(tabURLHistoryList);
      tempTab = new Tab();
      newTab = tempTab;

      for (int i = 1; i <= tabURLHistoryList.getLength(); i++)
      {
        newTab->navigateTo(tabURLHistoryList.getEntry(i));
      }

      tabList.remove(tabNumber);

      if (tabNumber - distance <= 0)
      {
        tabNumber = 1;
      }
      else
      {
        tabNumber = tabNumber - distance;
      }
      tabList.insert(tabNumber, newTab);

      newTab = nullptr;
      delete tempTab;
    }
    else if (command == "MOVE_RIGHT")
    {
      int distance = 0;
      inFile >> distance;
      //cout << "move right " << distance << "\n";

      tabURLHistoryList.clear();
      int currentURLPosition = tabList.getEntry(tabNumber)->copyCurrentHistory(tabURLHistoryList);
      tempTab = new Tab();
      newTab = tempTab;

      for (int i = 1; i <= tabURLHistoryList.getLength(); i++)
      {
        newTab->navigateTo(tabURLHistoryList.getEntry(i));
      }

      tabList.remove(tabNumber);

      if (tabNumber + distance > tabList.getLength() + 1)
      {
        tabNumber = tabList.getLength();
      }
      else
      {
        tabNumber = tabNumber + distance;
      }

      tabList.insert(tabNumber, newTab);

      newTab = nullptr;
      delete tempTab;
    }
    else if (command == "HISTORY")
    {
      //cout << "history\n";
      tabURLHistoryList.clear();
      int currentURLPosition = tabList.getEntry(tabNumber)->copyCurrentHistory(tabURLHistoryList);

      cout << "Tab " << tabNumber << "\n===========\n";
      //cout << "length: " << tabURLHistoryList.getLength() << "\n";
      for (int i = 1; i <= tabURLHistoryList.getLength(); i++)
      {
        cout << tabURLHistoryList.getEntry(i);

        if (tabURLHistoryList.getEntry(i) == tabList.getEntry(tabNumber)->currentURL())
        {
          cout << " <==current";
        }
        cout << "\n";
      }
      cout << "===========\nNewest\n\n";
    }
    else if (command == "CLOSE")
    {
      tabList.remove(tabNumber);
      total_num_tabs = tabList.getLength();

      if (tabNumber > total_num_tabs)
      {
        tabNumber = total_num_tabs;
      }
    }
    else if (command == "EXIT")
    {
      cout << "Exiting Web Browser....\n";
    }
    else if (command == "NAVIGATE") // Tab commands
    {
      // cout << "navigate\n";
      string urlLink;
      inFile >> urlLink;

      tabList.getEntry(tabNumber)->navigateTo(urlLink);
      delete &urlLink;
    }
    else if (command == "BACK")
    {
      tabList.getEntry(tabNumber)->back();
    }
    else if (command == "FORWARD")
    {
      tabList.getEntry(tabNumber)->forward();
    }
  } while (command != "EXIT");

  // Close File.
  inFile.close();

  cout << "\nHave a nice day!...\n\n";

  tabURLHistoryList.~LinkedList();

  for (int i = 1; i < tabList.getLength(); i++)
  {
    tabList.getEntry(i)->~Tab();
  }
  tabList.~LinkedList();
}
