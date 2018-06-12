///////////////////////////////////////////////////////////////////////
// Names		     : Diego Guzman
// Date				 : 12/2/2017
// Project			 : Postfix Calculator
// Course			 : CSS 342
// File Description  : This is the header file for the Linked list stack object 
///////////////////////////////////////////////////////////////////////
#pragma once

#ifndef LLSTACK_
#define LLSTACK_

#include <stdexcept>
#include <iostream>

template<class Type>
class LLStack {

public:
	///////////////////Destructor////////////////////////
	virtual ~LLStack(); 
	///////////Default Constructor///////////////////////
	LLStack(); 
	///////////////////Copy Constructor//////////////////
	LLStack(const LLStack &); 
	////////Assignment operator overload/////////////////
	LLStack<Type> & operator = (const LLStack<Type> &);
	////////////////Adds items to the stack//////////////
	void push(const Type & newItem); 
	///////////////Removes items from the stack//////////
	void pop();
	//////////Returns what is on the top of stack////////
	Type & top() const throw (std::logic_error);
	////////Returns true if the stack is empty///////////
	bool empty() const;
	//////////Returns the size of the stack//////////////
	int size() const; 
	//////////Displays the items on the stack////////////
	void display(); 
	////Deletes all of the items in the stack//////////
	void deleteAll(); 

private:
	////Struct to create node objects/////////////////
	struct LlNode {  
		LlNode * _pnext;
		Type data;
	};

	LlNode * head;
	int counter;
};

#endif
