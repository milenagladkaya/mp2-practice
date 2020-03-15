#pragma once
#include "Stack.h"

struct operand
{
    char name;
<<<<<<< HEAD
    double value; 
=======
    double value; // double
>>>>>>> origin/02_Stack
};

class Postfix
{
private:
    static int Priority(const char);
<<<<<<< HEAD
    static int MainStackCounter(const string&); 
=======
    static int MainStackCounter(const string); // &
>>>>>>> origin/02_Stack
    static bool Operand(const char);
    static bool Digit(const char);

public:
<<<<<<< HEAD
    static void CreateVariables(const string&, operand*&);
    static string PostfixForm(const string&);
    static double Calculation(const string&, operand*);
=======
    //static int InputNumberOfVariables();
	static void CreateVariables(const string&, operand*&);//, int&
    //static operand* CreateVariables(operand*&, int);
	static string PostfixForm(const string&);
	// static double Calculation(const string&, operand*, const int);
    static double Calculation(const string, operand*, const int);
>>>>>>> origin/02_Stack
};