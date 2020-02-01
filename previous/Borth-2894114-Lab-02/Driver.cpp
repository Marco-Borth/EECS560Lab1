/* -----------------------------------------------------------------------------
 *
 * File Name:  Driver.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 2 Program
 * Description:  Driver Class will either run the interactiveMenu or the LinkedList tester (runTests).
 * Date: 2/22/19
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
          for (int i = 1; i <= myList.getLength(); i++)
          {
            cout << "Node " << i << ": "<< myList.getEntry(i) << "\n";
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

  myList.~LinkedList();

  cout << "\nHave a nice day!...\n\n";
}

void Driver::runTests()
{
  myList.~LinkedList();
  // Size tests
  for (int i = 1; i <= 7; i++)
  {
    cout << "Size Test #" << i << ": ";
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

  cout <<"\n";

  for(int i = 1; i <= 1; i++)
  {
    cout << "Insert Test #" << i << ": ";
    if (i == 1)
    {
      insertTest01();
    }
  }

  cout <<"\n";

  for(int i = 1; i <= 1; i++)
  {
    cout << "Remove Test #" << i << ": ";
    if (i == 1)
    {
      removeTest01();
    }
  }

  cout <<"\n";

  for(int i = 1; i <= 1; i++)
  {
    cout << "Replace Test #" << i << ": ";
    if (i == 1)
    {
      replaceTest01();
    }
  }

  cout <<"\n";

  // GetEntry tests
  for(int i = 1; i <= 7; i++)
  {
    cout << "GetEntry Test #" << i << ": ";
    if (i == 1)
    {
      getEntryTest01();
    }
    else if (i == 2)
    {
      getEntryTest02();
    }
    else if (i == 3)
    {
      getEntryTest03();
    }
    else if (i == 4)
    {
      getEntryTest04();
    }
    else if (i == 5)
    {
      getEntryTest05();
    }
    else if (i == 6)
    {
      getEntryTest06();
    }
    else if (i == 7)
    {
      getEntryTest07();
    }
  }

  cout << "\nIsEmpty Test: ";
  isEmptyTest();
}

void Driver::sizeTest01()
{
  cout << "size of empty list is zero ";

  LinkedList testList;
  if (testList.isEmpty())
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }
  testList.~LinkedList();
}

void Driver::sizeTest02()
{
  cout << "size returns correct value after inserting at front of list ";

  LinkedList testList;
  testList.insert(1, 23);

  if (testList.getLength() == 1)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::sizeTest03()
{
  cout << "size returns correct value after inserting at back of list ";

  LinkedList testList;
  testList.insert(1, 23);
  testList.insert(testList.getLength() + 1, 45);

  if (testList.getLength() == 2)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::sizeTest04()
{
  cout << "size returns correct value after inserting in middle of list ";

  LinkedList testList;
  testList.insert(1, 23);
  testList.insert(testList.getLength() + 1, 45);
  testList.insert(testList.getLength(), 67);

  if (testList.getLength() == 3)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::sizeTest05()
{
  cout << "size returns correct value after adds and removing from front of list ";

  LinkedList testList;
  testList.insert(1, 23);
  testList.insert(testList.getLength() + 1, 45);
  testList.insert(testList.getLength(), 67);
  testList.insert(1, 89);
  testList.remove(1);

  if (testList.getLength() == 3)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::sizeTest06()
{
  cout << "size returns correct value after adds and removing from back of list ";

  LinkedList testList;
  testList.insert(1, 23);
  testList.insert(testList.getLength() + 1, 45);
  testList.insert(testList.getLength(), 67);
  testList.insert(testList.getLength() + 1, 135);
  testList.remove(testList.getLength());

  if (testList.getLength() == 3)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::sizeTest07()
{
  cout << "size returns correct value after adds and removing from middle of list ";

  LinkedList testList;
  testList.insert(1, 23);
  testList.insert(testList.getLength() + 1, 45);
  testList.insert(testList.getLength(), 67);
  testList.insert(testList.getLength(), 135);
  testList.remove(testList.getLength() - 1);

  if (testList.getLength() == 3)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::insertTest01()
{
  cout << "insert throws exception if given an invalid position ";

  LinkedList testList;

  try
  {
    testList.insert(0, 4602);
    cout << "FAILED\n";
  }
  catch (runtime_error)
  {
    cout << "PASSED\n";
  }

  testList.~LinkedList();
}

void Driver::removeTest01()
{
  cout << "remove throws exception if given an invalid position ";

  LinkedList testList;

  try
  {
    testList.remove(0);
    cout << "FAILED\n";
  }
  catch (runtime_error)
  {
    cout << "PASSED\n";
  }

  testList.~LinkedList();
}

void Driver::replaceTest01()
{
  cout << "replace throws exception if given an invalid position ";

  LinkedList testList;

  try
  {
    testList.replace(0, 24601);
    cout << "FAILED\n";
  }
  catch (runtime_error)
  {
    cout << "PASSED\n";
  }

  testList.~LinkedList();
}

void Driver::getEntryTest01()
{
  cout << "getEntry throws exception if given an invalid position ";

  LinkedList testList;

  try
  {
    testList.getEntry(0);
    cout << "FAILED\n";
  }
  catch (runtime_error)
  {
    cout << "PASSED\n";
  }

  testList.~LinkedList();
}

void Driver::getEntryTest02()
{
  cout << "getEntry returns correct value after inserting at front of list ";

  LinkedList testList;
  testList.insert(1, 23);

  if (testList.getEntry(1) == 23)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::getEntryTest03()
{
  cout << "getEntry returns correct value after inserting at back of list ";

  LinkedList testList;
  testList.insert(1, 23);
  testList.insert(testList.getLength() + 1, 45);

  if (testList.getEntry(testList.getLength()) == 45)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::getEntryTest04()
{
  cout << "getEntry returns correct value after inserting in middle of list ";

  LinkedList testList;
  testList.insert(1, 23);
  testList.insert(testList.getLength() + 1, 45);
  testList.insert(testList.getLength(), 67);

  if (testList.getEntry(2) == 67)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::getEntryTest05()
{
  cout << "getEntry returns correct value after adds and removing from front of list ";

  LinkedList testList;
  testList.insert(1, 23);
  testList.insert(testList.getLength() + 1, 45);
  testList.insert(testList.getLength(), 67);
  testList.insert(1, 89);
  testList.remove(1);

  if (testList.getEntry(1) == 23)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::getEntryTest06()
{
  cout << "getEntry returns correct value after adds and removing from back of list ";

  LinkedList testList;
  testList.insert(1, 23);
  testList.insert(testList.getLength() + 1, 45);
  testList.insert(testList.getLength(), 67);
  testList.insert(testList.getLength() + 1, 135);
  testList.remove(testList.getLength());

  if (testList.getEntry(testList.getLength()) == 45)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::getEntryTest07()
{
  cout << "getEntry returns correct value after adds and removing from middle of list ";

  LinkedList testList;
  testList.insert(1, 23);
  testList.insert(testList.getLength() + 1, 45);
  testList.insert(testList.getLength(), 67);
  testList.insert(testList.getLength(), 135);
  testList.remove(testList.getLength() - 1);

  if (testList.getEntry(2) == 67)
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}

void Driver::isEmptyTest()
{
  cout << "isEmpty returns correct value after list is cleared ";

  LinkedList testList;
  testList.insert(1, 23);
  testList.insert(testList.getLength() + 1, 45);
  testList.insert(testList.getLength(), 67);
  testList.clear();

  if (testList.isEmpty())
  {
    cout << "PASSED\n";
  }
  else
  {
    cout << "FAILED\n";
  }

  testList.~LinkedList();
}
