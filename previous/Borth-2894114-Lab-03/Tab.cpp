/* -----------------------------------------------------------------------------
 *
 * File Name:  Tab.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 3 Program
 * Description:  Tab Class will ...
 * Date: 3/1/19
 *
 ---------------------------------------------------------------------------- */

#include "Tab.h"
using namespace std;

Tab::Tab()
{
  urlHistory;
  tabFocus = 0;
  focusedURL = "";
}

Tab::~Tab()
{
  urlHistory.~LinkedList();
  delete &tabFocus;
  delete &focusedURL;
}

void Tab::navigateTo(string url)
{
  bool urlIncluded = false;
  if (urlHistory.getLength() == 0)
  {
    urlHistory.insert(1, url);
    tabFocus++;
    focusedURL = url;
  }
  else
  {
    for (int i = 1; i <= urlHistory.getLength(); i++)
    {
      if (url == urlHistory.getEntry(i))
      {
        urlIncluded = true;
      }
    }

    if (urlIncluded)
    {
      for (int i = 1; i <= urlHistory.getLength(); i++)
      {
        if (url == urlHistory.getEntry(i))
        {
          tabFocus = i;
          focusedURL = url;
        }
      }
    }
    else
    {
      if (tabFocus == urlHistory.getLength())
      {
        urlHistory.insert(urlHistory.getLength() + 1, url);
        tabFocus++;
        focusedURL = url;
      }
      else if (tabFocus >= 1)
      {
        while (urlHistory.getEntry(urlHistory.getLength()) != focusedURL)
        {
          urlHistory.remove(urlHistory.getLength());
        }

        urlHistory.insert(urlHistory.getLength() + 1, url);
        tabFocus++;
        focusedURL = url;
      }
    }

    delete &url;
  }

  delete &url;
}

void Tab::forward()
{
  if(tabFocus < urlHistory.getLength())
  {
    tabFocus++;
    focusedURL = urlHistory.getEntry(tabFocus);
  }
}

void Tab::back()
{
  if(tabFocus > 1)
  {
    tabFocus--;
    focusedURL = urlHistory.getEntry(tabFocus);
  }
}

string Tab::currentURL() const
{
  return (focusedURL);
}

int Tab::copyCurrentHistory(LinkedList<string>& destination)
{
  for (int i = 1; i <= urlHistory.getLength(); i++)
  {
    destination.insert(i, urlHistory.getEntry(i));
  }
  int currentURLPosition = 0;

  if (urlHistory.getLength() == 0)
  {
    return (urlHistory.getLength());
  }
  else
  {
    return (tabFocus);
  }
  destination.~LinkedList();
}
