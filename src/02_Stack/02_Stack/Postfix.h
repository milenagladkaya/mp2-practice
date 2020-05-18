#pragma once
#include "Stack.h"

struct operand
{
	char name;
	double value;
};

class Postfix
{
private:
	static int Priority(const char);
	static int MainStackCounter(const string&);
	static bool Operand(const char);
	static bool Digit(const char);

public:
	static int CreateVariables(const string&, operand*&);//возвращать массив переменных и количество
	static string PostfixForm(const string&);
	static double Calculation(const string&, operand*, int);//принимать массив переменных и количество
};
