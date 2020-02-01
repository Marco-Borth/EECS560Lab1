/* -----------------------------------------------------------------------------
 *
 * File Name:  LinkedList.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 2 Program
 * Description:  LinkedList methods are defined.
 * Date: 2/22/19
 *
 ---------------------------------------------------------------------------- */

#include "LinkedList.h"
#include <string>
using namespace std;

LinkedList::LinkedList()
{
	m_length = 0;
	m_front = nullptr;
}

LinkedList::LinkedList(const LinkedList& original)
{
	operator=(original);
}

LinkedList::~LinkedList()
{
	clear();
	m_front = nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& original)
{
	int index = 1;

	while (index < original.getLength() + 1)
	{
		insert(index, original.getEntry(index));
	}
}

bool LinkedList::isEmpty() const
{
	if(m_length == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

int LinkedList::getLength() const
{
	return(m_length);
}

void LinkedList::insert(int position, int entry)
{
	if (position == 1)
	{
		Node* temp = m_front;
		m_front = new Node(entry);
		m_front->setNext(temp);
		m_length++;
	}
	else if (position == m_length + 1)
	{
		int index = 1;
		Node* m_back = m_front;
		Node* m_order = m_front;
		Node* temp = nullptr;

		while (index < position)
		{
			m_back = m_back->getNext();
			if (index + 1 != position)
			{
				m_order = m_back;
			}
			index++;
		}

		m_back = new Node(entry);
		m_back->setNext(temp);
		m_order->setNext(m_back);
		m_length++;
	}
	else if ((position > 1) && (position < m_length + 1))
	{
		int index = 1;
		Node* m_back = m_front;
		Node* m_order = m_front;
		Node* temp = nullptr;

		while (index < position)
		{
			m_back = m_back->getNext();
			if (index + 1 != position)
			{
				m_order = m_back;
			}
			index++;
		}

		temp = m_back;
		m_back = new Node(entry);
		m_back->setNext(temp);
		m_order->setNext(m_back);
		m_length++;
	}
	else
	{
		throw(runtime_error("ERROR! Invalid position.\n"));
	}
}

void LinkedList::remove(int position)
{
	if (position == 1)
	{
		Node* m_back = m_front;
		Node* temp = m_front;
		m_back = m_back->getNext();
		temp->~Node();
		m_front = m_back;
		m_length--;
	}
	else if ((position > 0) && position == m_length)
	{
		int index = 1;
		Node* m_back = m_front;

		while (index < position)
		{
			m_back = m_back->getNext();
			index++;
		}

		m_back->~Node();
		m_length--;
	}
	else if ((position > 1) && (position < m_length + 1))
	{
		Node* m_order = m_front;
		Node* temp = nullptr;

		for (int i = 1; i < position - 1; i++)
		{
			m_order = m_order->getNext();
		}

		temp = m_order->getNext();
		m_order->setNext(temp->getNext());
		temp->setNext(nullptr);
		delete temp;
		m_length--;
	}
	else
	{
		throw(runtime_error("ERROR! Invalid position.\n"));
	}
}

void LinkedList::clear()
{
	while(!isEmpty())
	{
		Node* m_back = m_front;
		Node* temp = m_front;
		m_back = m_back->getNext();
		temp->~Node();
		m_front = m_back;
		m_length--;
	}
}

int LinkedList::getEntry(int position) const
{
	Node* temp = m_front;

	if ((position >= 1) && (position <= m_length))
	{
		for (int i = 1; i < position; i++)
		{
			temp = temp->getNext();
		}
		return(temp->getEntry());
	}
	else
	{
		throw(runtime_error("ERROR! Invalid position.\n"));
	}
}

void LinkedList::replace(int position, int newEntry)
{
	LinkedList::remove(position);
	insert(position, newEntry);
}
