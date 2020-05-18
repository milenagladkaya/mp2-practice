#pragma once

#include "TStack.h"
#include "TListStack.h"
#include "TArrayStack.h"

struct operand
{
	char name;
	double value;
};

template<class ValType>
class Postfix
{
private:
	TStack<char>* St1; 
	TStack<char>* St2; 
	TStack<double>* Sum; 

	int Priority(const char);
	int MainStackCounter(const string&);
	bool Operand(const char);
	bool Digit(const char);

public:
	Postfix(StackType);

	int CreateVariables(const string&, operand*&);//возвращать массив переменных и количество
	string PostfixForm(const string&);
	double Calculation(const string&, operand*, int);//принимать массив переменных и количество
};

template<typename ValType>
Postfix<ValType>::Postfix(StackType type)
{
	St1 = TStack<char>::Create(type);
	St2 = TStack<char>::Create(type);
	Sum = TStack<double>::Create(type);
}

template<typename ValType>
int Postfix<ValType>::Priority(const char c)
{
	if ((c == '*') || (c == '/'))
		return 2;
	if ((c == '+') || (c == '-'))
		return 1;
	if ((c == '(') || (c == ')'))
		return 0;
}

template<typename ValType>
int Postfix<ValType>::MainStackCounter(const string& str)
{
	int n = 0, k = 0;
	for (int i = 0; i < str.length(); i++)
		if ((str[i] != '(') && (str[i] != ')'))
			n++;
	return n;
}

template<typename ValType>
bool Postfix<ValType>::Operand(const char a)
{
	return !((a == '(') || (a == ')') || (a == '*') || (a == '/') || (a == '+') || (a == '-'));
}

template<typename ValType>
bool Postfix<ValType>::Digit(const char d)
{
	return (d == '1' || d == '2' || d == '3' || d == '4' || d == '5' || d == '6' || d == '7' || d == '8' || d == '9' || d == '0');
}

template<typename ValType>
string Postfix<ValType>::PostfixForm(const string& str)
{
	int f = 0;
	int n = MainStackCounter(str);

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			f++;
		else if (str[i] == ')')
			f--;
	}

	if (f < 0)
		throw Error2();
	else if (f > 0)
		throw Error1();

	for (int i = 0; i < str.length(); i++)
	{
		if (Operand(str[i]))
		{
			St1->Push(str[i]);
		}
		else
		{
			if (Priority(str[i]) == 0)
				if (str[i] == '(')
					St2->Push(str[i]);
				else
				{
					while (Priority(St2->Top()) != 0)
					{
						St1->Push(St2->Top());
						St2->Pop();
					}
					St2->Pop();
				}
			else
			{
				while ((St2->IsEmpty() == false) && (Priority(str[i]) <= Priority(St2->Top())))
				{
					St1->Push(St2->Top());
					St2->Pop();
				}
				St2->Push(str[i]);
			}
		}
	}
	while (!St2->IsEmpty())
	{
		St1->Push(St2->Top());
		St2->Pop();
	}

	string postfix = str;
	postfix.resize(n);
	for (int i = n - 1; !St1->IsEmpty(); i--)
	{
		postfix[i] = St1->Top();
		St1->Pop();
	}
	return postfix;
}

template<typename ValType>
int Postfix<ValType>::CreateVariables(const string& str, operand*& var)
{
	int n = 0;
	for (int i = 0; i < str.length(); i++)
		if (Operand(str[i]))
			n++;

	var = new operand[n];

	int k = 0, f = 0;
	for (int i = 0; i < str.length(); i++)
		if (Operand(str[i]))
		{
			for (int j = 0; j < k; j++)
				if (var[j].name == str[i])
					f++;
			if (f == 0) // запоминаем переменные без повторений
			{
				var[k].name = str[i];
				cout << "Enter the value of variable " << var[k].name << ": ";
				if (!(cin >> var[k].value))
					throw Error5();
				cout << endl;
				k++;
			}
			f = 0;
		}
	return k;
}

template<typename ValType>
double Postfix<ValType>::Calculation(const string& str, operand* var, int numvar)
{
	double a, b;

	for (int i = 0; i < str.length(); i++)
	{
		if (Operand(str[i]))
		{
			for (int j = 0; j < numvar; j++)
				if (str[i] == var[j].name)
					Sum->Push(var[j].value);
		}
		else
		{
			a = Sum->Top();
			Sum->Pop();
			b = Sum->Top();
			Sum->Pop();
			if (str[i] == '+')
				Sum->Push(b + a);
			if (str[i] == '-')
				Sum->Push(b - a);
			if (str[i] == '*')
				Sum->Push(b * a);
			if (str[i] == '/')
			{
				if (a != 0)
					Sum->Push(b / a);
				else
					throw Error7();
			}
		}
	}
	return Sum->Top();
}