///////////////////////////////////////////////////////////////////////
// Names		     : Diego Guzman
// Date				 : 12/2/2017
// Project			 : Postfix Calculator
// Course			 : CSS 342
// File Description  : This file represents the linked list stack object 
///////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "LLStack.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <class Type>
///////////////////Destructor////////////////////////
LLStack<Type>::~LLStack()  
{
	this->deleteAll();
}
///////////Default Constructor///////////////////////
template<class Type>
LLStack<Type>::LLStack() 
{
	this->head = NULL;
	this->counter = 0;
}
///////////////////Copy Constructor//////////////////
template<class Type>
LLStack<Type> ::LLStack(const LLStack & rhs)  
{
	*this = rhs;
}
////////Assignment operator overload/////////////////
template<class Type>       
LLStack<Type>& LLStack<Type>:: operator =(const LLStack<Type> & rhs)
{
	if (this != &rhs)
	{
		LlNode * originalPtr = rhs.head;
		counter = rhs.counter;
		////Create a new node////
		head = new LlNode; 
		////Set the new node to rhs data////
		head->data = originalPtr->data;
		originalPtr = originalPtr->_pnext;
		////Set a pointer to point to the new node ////
		LlNode * copyPtr = head;
		while (originalPtr != NULL)
		{
			LlNode * CNode = new LlNode;
			CNode->data = originalPtr->data;
			copyPtr->_pnext = CNode;
			copyPtr = copyPtr->_pnext;
			originalPtr = originalPtr->_pnext;
		}
		copyPtr->_pnext = NULL;
	}
	return *this;
}
////////It adds new items into the stack////////////
template<class Type>   
void LLStack<Type>::push(const Type & newItem)
{
	LlNode * temp = head;
	if (temp == NULL)
	{
		LlNode * temp = new LlNode;
		temp->data = newItem;
		head = temp;
		temp->_pnext = NULL;
		counter++;
	}
	else
	{
		LlNode * A = new LlNode;
		A->data = newItem;
		A->_pnext = head;
		head = A;
		counter++;
	}
}
////Removes nodes(items) from the stack////////////
template<class Type> 
void LLStack<Type>::pop()
{
	LlNode * temp2 = head;

	if (temp2 == NULL)
	{
		cout << "empty stack" << endl;
		return;
	}
	else
	{
		LlNode * temp3 = head->_pnext;
		delete (head);
		head = temp3;
		counter--;
	}
}
////Return what's on the top of the stack////
////or throw an error if its empty//////////
template<class Type> 
Type & LLStack<Type>::top() const throw(std::logic_error)
{
	if (counter == 0)
	{
		throw std::logic_error("empty stack");
	}
	return head->data;
}
////////Returns true if the stack is empty///////////
template<class Type> 
bool LLStack<Type>::empty() const
{
	LlNode * temp = head;
	if (temp != NULL)
	{
		return false;
	}
	return true;
}
//////////Returns the size of the stack//////////////
template <class Type>
int LLStack<Type>::size() const
{
	return counter;
}
//////////Displays the items on the stack////////////
template <class Type>
void LLStack<Type>::display()
{
	LlNode * temp = head;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->_pnext;
	}
}
////Deletes all of the items in the stack//////////
template <class Type>
void LLStack<Type>::deleteAll() 
{
	LlNode * pnode = head;
	while (pnode)
	{
		LlNode * pdead = pnode;
		pnode = pdead->_pnext;
		delete(pdead);
	}
	head = NULL;
}


