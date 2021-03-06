/////////////////////////////////////////////////////////////////////////////////////
// Names		    			 : Diego Guzman
// Date							 : 12/2/2017
// Project						 : Postfix Calculator
// Course					     : CSS 342
// File Description              : This file represents the console application
//					             entry point which contains the main() method and
//					             all the funtionalitites of the Postfix Calculator.
////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "LLStack.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

////////////Performs the postfix calculations/////////////
template<class Type>
bool calculation(string s, LLStack<Type> & mystack)
{
	int num = 0;
	////variables representing the different types of arithmetic operations 
	string A = "+";
	string S = "-";
	string D = "/";
	string M = "*";
	/////This if statement handles the addition calculation//////
	if (A.compare(s) == 0)  
	{               
		if (mystack.size()>1)
		{
			int operand2 = mystack.top();
			mystack.pop();
			int operand1 = mystack.top();
			mystack.pop();
			int results = operand1 + operand2;
			mystack.push(results);
		}
		else
		{
			cout << endl;
			cout << " Test Fail " << endl;
			mystack.deleteAll();
			return true;
		}
	}
	////This if statement handles the subtraction calculation////
	else if (S.compare(s) == 0)
	{                 
		if (mystack.size()>1)
		{
			int operand2 = mystack.top();
			mystack.pop();
			int operand1 = mystack.top();
			mystack.pop();
			int results = operand1 - operand2;
			mystack.push(results);
		}
		else
		{
			cout << endl;
			cout << " Test Fail " << endl;
			mystack.deleteAll();
			return true;
		}
	}
	////This if statement handles the division calculation////
	else if (D.compare(s) == 0) 
	{                        
		if (mystack.size()>1)
		{
			int operand2 = mystack.top();
			mystack.pop();
			int operand1 = mystack.top();
			mystack.pop();
			int results = operand1 / operand2;
			mystack.push(results);
		}
		else
		{
			cout << endl;
			cout << " Test Fail " << endl;
			mystack.deleteAll();
			return true;
		}
	}
	////This if statement handles the multiplication calculation////
	else if (M.compare(s) == 0)
	{                      
		if (mystack.size()>1)
		{
			int operand2 = mystack.top();
			mystack.pop();
			int operand1 = mystack.top();
			mystack.pop();
			int results = operand1 * operand2;
			mystack.push(results);
		}
		else
		{
			cout << endl;
			cout << " Test Fail " << endl;
			mystack.deleteAll();
			return true;
		}
	}
	else
	{
		// if the number is composed of two digits,
		// traverse over them, and if it contains an
		// invalid character the test fails and the method ends
		if (s.length()>1)
		{
			for (int i = 0; i<s.length(); i++)
			{
				char a = s[i];
				if (a == '+' || a == '-' || a == '*' || a == '/')
				{
					cout << endl;
					cout << " Test Fail " << endl;
					mystack.deleteAll();
					return true;
				}
				//// convert the ascii character to a number////
				num = num * 10 + a - 48;
			}
			////add the number to the stack////
			mystack.push(num);
			num = 0;
		}
		else  
		{
			////convert the ascii character into a digit and/// 
			////push it to the stack /////////////////////////
			char b = s[0];
			num = b - 48;
			mystack.push(num);
			num = 0;
		}
	}
	return false;
}

//////////////////////////////////////////////////////////////////////
////////////////// Main method ///////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[]) {
	//// Initialize a LLStack of ints////
	LLStack<int> mystack; 
	//// When executing the program, if two arguments are passed in, 
	//// then read the file and calculate the result////////////////
	if (argc == 2)
	{   //// This variable contains the data from the file////
		string s;  
		ifstream infile(argv[1]);
		if (infile.fail())
		{
			cout << "problem opening the file" << endl;
		}
		else
		{
			while (infile >> s)
			{
				if (calculation(s, mystack))
				{
					return 0;
				}
			}
			cout << endl;
			cout << "Result: " << endl;
		}          mystack.display();
	}
	else
	{
		//// If no arguments are passed in, ask the user//// 
		//// for input and calculate the result////////////
		string userImput;
		cout << "Enter your input: " << endl;
		getline(cin, userImput);
		istringstream iss(userImput);
		string word;
		while (iss >> word)
		{
			if (calculation(word, mystack))
			{
				return 0;
			}
		}
		cout << endl;
		cout << "Result: " << endl;
		mystack.display();
	}
	system("pause");
	return 0;
}
