/* -----------------------------------------------------------------------------
 *
 * File Name:  Driver.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 2 Program
 * Description:  Driver Class will either run the interactiveMenu or the LinkedList tester.
 * Date: 1/25/19
 *
 ---------------------------------------------------------------------------- */

#include "Driver.h"
#include <iostream>
#include <string>
using namespace std;

Driver::Driver(string mode)
{
    myList;
    driverMode = mode;
}

void Driver::run()
{
  if (driverMode == "-i")
  {
    interactiveMenu();
  }
  else if (driverMode == "-t")
  {
    runTests();
  }
  else
  {
    cout << "\nInvalid LinkedList Operation.\n\n";
  }
}

void Driver::interactiveMenu()
{
  cout << "\nWelcome to the Linked List Menu!\n\n";

  do {
    cout << "Make a selection:\n\n";

    cout << "1) Insert value at position.\n";
    cout << "2) Remove at position.\n";
    cout << "3) Replace value at position.\n";
    cout << "4) Print length.\n";
    cout << "5) Print list.\n";
    cout << "6) Exit.\n\n";

    cout << "Choice: ";
    cin >> option;

    if (option == 1)
    {
      int value;
      int position;
      cout << "\nEnter value: ";
      cin >> value;
      cout << "\nEnter position: ";
      cin >> position;

      try
      {
        cout << "\nInserting value of " << value << " at position " << position << "....\n\n";
        myList.insert(position, value);
      }
      catch (runtime_error)
      {
        cout << "Invalid position.\n\n";
      }
    }
    else if (option == 2)
    {
      int position;
      cout << "\nEnter position: ";
      cin >> position;

      try
      {
        if (myList.getLength() > 0)
        {
          cout << "\nRemoving entry at position " << position << "....\n\n";
          myList.remove(position);
        }
        else
        {
          cout << "\nCannot remove value.\nList is Empty.\n";
        }
      }
      catch (runtime_error)
      {
        cout << "Invalid position.\n\n";
      }
    }
    else if (option == 3)
    {
      int value;
      int position;
      cout << "\nEnter value: ";
      cin >> value;
      cout << "\nEnter position: ";
      cin >> position;

      try
      {
        cout << "\nReplacing given value of " << value << " at position " << position << "....\n\n";
        myList.replace(position, value);
      }
      catch (runtime_error)
      {
        cout << "Invalid position.\n\n";
      }
    }
    else if (option == 4)
    {
      cout << "\nPrinting length....\n\n";
      cout << "Length: " << myList.getLength() << "\n\n";
    }
    else if (option == 5)
    {
      try
      {
        if (myList.getLength() > 0)
        {
          cout << "\nPrinting List....\n\nLinkedList Entries:\n";
          for (int i = 0; i < myList.getLength(); i++)
          {
            cout << "Node " << i + 1<< ": "<< myList.getEntry(i) << "\n";
          }
        }
        else
        {
          cout << "\nCannot print list.\nList is Empty.\n";
        }
      }
      catch (runtime_error)
      {
        cout << "\nList is Empty.\n";
      }
      cout << "\n";
    }
    else if (option == 6)
    {
      cout << "\nClosing Program...\n";
    }
    else
    {
      cout << "\nInvalid Option...\n\n";
    }
  } while(option != 6);

  myList.clear();

  cout << "\nHave a nice day!...\n\n";
}

void Driver::runTests()
{
/*
Insert tests

insert throws exception if given an invalid position
*/
  for (int i = 1; i <= 7; i++)
  {
    cout << "Test #" << i << ": ";
    if (i == 1)
    {
      sizeTest01();
    }
    else if (i == 2)
    {
      sizeTest02();
    }
    else if (i == 3)
    {
      sizeTest03();
    }
    else if (i == 4)
    {
      sizeTest04();
    }
    else if (i == 5)
    {
      sizeTest05();
    }
    else if (i == 6)
    {
      sizeTest06();
    }
    else if (i == 7)
    {
      sizeTest07();
    }
  }
}

void Driver::sizeTest01()
{
  cout << "size of empty list is zero ";
  if (myList.isEmpty())
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }
}

void Driver::sizeTest02()
{
  cout << "size returns correct value after inserting at front of list ";
  myList.insert(1, 23);
  if (myList.getLength() == 1)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }
}

void Driver::sizeTest03()
{
  cout << "size returns correct value after inserting at back of list ";
  myList.insert(myList.getLength() + 1, 45);
  if (myList.getLength() == 2)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }
}

void Driver::sizeTest04()
{
  cout << "size returns correct value after inserting in middle of list ";
  myList.insert(myList.getLength(), 67);
  if (myList.getLength() == 3)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }
}

void Driver::sizeTest05()
{
  cout << "size returns correct value after adds and removing from front of list ";
  myList.insert(1, 89);
  myList.remove(1);
  if (myList.getLength() == 3)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }
}

void Driver::sizeTest06()
{
  cout << "size returns correct value after adds and removing from back of list ";
  myList.insert(myList.getLength() + 1, 135);
  myList.remove(myList.getLength());
  if (myList.getLength() == 3)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }
}

void Driver::sizeTest07()
{
  cout << "size returns correct value after adds and removing from middle of list ";
  myList.insert(myList.getLength(), 135);
  myList.remove(myList.getLength() - 1);
  if (myList.getLength() == 3)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }
}
