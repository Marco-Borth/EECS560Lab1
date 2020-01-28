/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.cpp
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 1 - Implementation of Singly Linked List
 * Description:  Operator Class will either run the Interactive program for a Singly Linked List
 * Date: 1/28/20
 *
 ---------------------------------------------------------------------------- */

#include "Operator.h"
#include <iostream>
#include <string>
using namespace std;

Operator::Operator(){}

void Operator::printCommands() {
  cout << "Please choose one of the following commands:\n\n";
  cout << "1. Is Empty\n";
  cout << "2. Length\n";
  cout << "3. Insert\n";
  cout << "4. Delete\n";
  cout << "5. Delete Duplicates\n";
  cout << "6. Find\n";
  cout << "7. Find Next\n";
  cout << "8. Print\n";
  cout << "9. ReverseList\n";
  cout << "10. Print At\n";
  cout << "11. Exit\n\n> ";
}

void Operator::run() {
  cout << "\nWelcome to the Interactive Singly Linked List Program!\n\n";

  do {
    printCommands();
    cin >> option;

    while(1) {
      // Error Handling for an non-number entry.
      if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nERROR! Invalid Option!\n\n"; //if not an int, must try again.
        printCommands();
        cin >> option;
      }
      // Operation Number has been selected.
      else {
        // 1. Is Empty - Complete!
        if (option == 1) {
          cout << "\nIs List Empty?...\n";
          if(myList.isEmpty()) {
            cout << "\nThe List is INDEED Empty!\n\n";
          } else {
            cout << "\nThe List is NOT Empty!\n\n";
          }
        }
        // 2. Length - Complete!
        else if (option == 2) {
          cout << "\nMeasuring List Length...\n";

          cout << "The length of the lsit is: " << myList.getLength() << "\n\n";
        }
        // 3. Insert - Complete!
        else if (option == 3) {
          cout << "\nPreparing to Insert a New Element...\n";

          int value;
          cout << "\nChoose a number to be inserted:\n\n> ";
          cin >> value;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nChoose a number to be inserted:\n\n> ";
              cin >> value;
            } else {
              try {
                cout << "\nInserting " << value << " at the front of the list...\n";
                myList.insert(1, value);
                cout << value << " is inserted.\n\n";
              } catch (runtime_error) {
                cout << "\nERROR! Invalid Position!\n\n";
              }

              break;
            }
          }
        }
        // 4. Delete - Work in Progress, develop a Find number algorithm!
        else if (option == 4) {
          cout << "\nPreparing to Delete a Listed Element...\n";

          int value;
          cout << "\nChoose a number to be deleted from the list:\n\n> ";
          cin >> value;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nChoose a number to be deleted from the list:\n\n> ";
              cin >> value;
            } else {
              try {
                cout << "\nDeleting " << value << " from this list...\n";
                //myList.remove(1, value);
                cout << value << " is deleted.\n\n";
              } catch (runtime_error) {
                cout << "\nERROR! Invalid Position!\n\n";
              }

              break;
            }
          }

          cout << "\nTBD\n";
        }
        // 5. Delete Duplicates - Work in Progress, Delete Operation still needs to be developed!
        else if (option == 5) {
          cout << "\nPreparing to Delete All Given Duplicate Elements...\n";
          cout << "\nTBD\n";
        }
        // 6. Find - Complete!
        else if (option == 6) {
          cout << "\nLets find an Element!\n";

          if (myList.getLength() > 0) {
            int value;
            cout << "\nEnter the number to find:\n\n> ";
            cin >> value;

            while(1) {
              if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "\n\nERROR! Invalid entry!\n\n";
                cout << "\nEnter the number to find:\n\n> ";
                cin >> value;
              } else {
                try {
                  cout << "\nLooking for " << value << " within the list...\n\n";
                  int position = 1;

                  bool isFound = false;
                   while (position <= myList.getLength()) {
                    if (myList.getEntry(position) == value) {
                      cout << value << " has been found within the list.\n\n";
                      isFound = true;
                      break;
                    }
                    position++;
                  }

                  if(!isFound)
                    cout << value << " is NOT found in the list.\n\n";
                } catch (runtime_error) {
                  cout << "\nERROR! Invalid Position!\n\n";
                }

                break;
              }
            }
          } else {
            cout << "\nERROR! List is Empty.\n\n";
          }
        }
        // 7. Find Next - Work in Progress!
        else if (option == 7) {
          cout << "\nLets find the next Element!\n";

          if (myList.getLength() > 0) {
            int value;
            cout << "\nEnter the number to find its next element:\n\n> ";
            cin >> value;

            while(1) {
              if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "\n\nERROR! Invalid entry!\n\n";
                cout << "\nEnter the number to find its next element:\n\n> ";
                cin >> value;
              } else {
                try {
                  cout << "\nLooking for the next element after " << value << " within the list...\n\n";
                  int position = 1;

                  bool isFound = false;
                   while (position <= myList.getLength()) {
                    if (myList.getEntry(position) == value) {
                      isFound = true;
                      if (position == myList.getLength())
                        cout << value << " is the last element within the list.\n\n";
                      else
                        cout << myList.getEntry(position + 1) << " is next after " << value << ".\n\n";
                      break;
                    }
                    position++;
                  }

                  if(!isFound)
                    cout << value << " is NOT found in the list.\n\n";
                } catch (runtime_error) {
                  cout << "\nERROR! Invalid Position!\n\n";
                }

                break;
              }
            }
          } else {
            cout << "\nERROR! List is Empty.\n\n";
          }

          cout << "\nTBD\n";
        }
        // 8. Print - Complete!
        else if (option == 8) {
          cout << "\nPrinting List of Elements...\n\n";

          try {
            if (myList.getLength() > 0) {
              cout << "List: ";
              for (int i = 1; i <= myList.getLength(); i++) {
                cout << myList.getEntry(i) << " ";
              }
              cout << "\n\n";
            } else {
              cout << "\nCannot print list.\nList is Empty.\n\n";
            }
          } catch (runtime_error) {
            cout << "\nERROR! Invalid Position!\n\n";
          }
        }
        // 9. Reverse List - Complete!
        else if (option == 9) {
          cout << "\nPrinting the Reverse List of Elements...\n";

          try {
            if (myList.getLength() > 0) {
              cout << "Reversed List: ";
              for (int i = myList.getLength(); i >= 1; i--) {
                cout << myList.getEntry(i) << " ";
              }
              cout << "\n\n";
            } else {
              cout << "\nCannot print list.\nList is Empty.\n\n";
            }
          } catch (runtime_error) {
            cout << "\nERROR! Invalid Position!\n\n";
          }
        }
        // 10. Print At - Work in Progress!
        else if (option == 10) {
          cout << "\nPrinting an Element at Postion:\n";
          cout << "\nTBD\n";
        }
        // 11. Exit - Complete!
        else if (option == 11) {
          cout << "\nClosing Program...\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while(option != 11);
  myList.clear();

  cout << "\nProgram execution completed!\n";
  cout << "\nHave a nice day!...\n\n";
}
