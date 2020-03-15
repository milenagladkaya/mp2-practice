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
    static void CreateVariables(const string&, operand*&);
    static string PostfixForm(const string&);
    static double Calculation(const string&, operand*);
};
