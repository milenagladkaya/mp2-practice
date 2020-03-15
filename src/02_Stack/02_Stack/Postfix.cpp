#include "Postfix.h"

using namespace std;

int Postfix::Priority(const char c)
{
    if ((c == '*') || (c == '/'))
        return 2;
    if ((c == '+') || (c == '-'))
        return 1;
    if ((c == '(') || (c == ')'))
        return 0;
}

int Postfix::MainStackCounter(const string& str)
{
    int n = 0, k = 0;
    for (int i = 0; i < str.length(); i++)
        if ((str[i] != '(') && (str[i] != ')'))
        {
            n++;
            if (Operand(str[i]))
                k++;
        }
    if (k == 0)
        return -1;
    return n;
}

bool Postfix::Operand(const char a)
{
    return !((a == '(') || (a == ')') || (a == '*') || (a == '/') || (a == '+') || (a == '-'));
}

bool Postfix::Digit(const char d)
{
    return (d == '1' || d == '2' || d == '3' || d == '4' || d == '5' || d == '6' || d == '7' || d == '8' || d == '9' || d == '0');
}

string Postfix::PostfixForm(const string& str)
{
    int f = 0;
    int n = Postfix::MainStackCounter(str);
    Stack<char> St1(n);
    Stack<char> St2(n);

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
            St1.Push(str[i]);
        }
        else
        {
            if (Priority(str[i]) == 0)
                if (str[i] == '(')
                    St2.Push(str[i]);
                else
                {
                    while (Priority(St2.Top()) != 0)
                    {
                        St1.Push(St2.Top());
                        St2.Pop();
                    }
                    St2.Pop();
                }
            else if (Priority(str[i]) == 1)
            {
                while (Priority(St2.Top()) == 2)
                {
                    St1.Push(St2.Top());
                    St2.Pop();
                }
                St2.Push(str[i]);
            }
            else
                St2.Push(str[i]);
        }
    }

    while (!St2.IsEmpty())
    {
        St1.Push(St2.Top());
        St2.Pop();
    }

    string postfix = str;
    postfix.resize(n);
    for (int i = n - 1; !St1.IsEmpty(); i--)
    {
        postfix[i] = St1.Top();
        St1.Pop();
    }
    return postfix;
}

void Postfix::CreateVariables(const string& str, operand*& var)
{
    int n = 0;
    for (int i = 0; i < str.length(); i++)
        if (Operand(str[i]))
            n++;

    var = new operand[n];

    int k = 0;
    for (int i = 0; i < str.length(); i++)
        if (Operand(str[i]))
        {
            var[k].name = str[i];
            cout << "   Enter the value of variable " << var[k].name << ": ";
            if (!(cin >> var[k].value))
                throw Error5();
            cout << endl;
            k++;
        }
}

double Postfix::Calculation(const string& str, operand* var)
{
    int a, b;

    int numvar = 0;
    for (int i = 0; i < str.length(); i++)
        if (Operand(str[i]))
            numvar++;

    Stack<double> Sum(str.length());
    for (int i = 0; i < str.length(); i++)
    {
        if (Operand(str[i]))
        {
            for (int j = 0; j < numvar; j++)
                if (str[i] == var[j].name)
                    Sum.Push(var[j].value);
        }
        else
        {
            a = Sum.Top();
            Sum.Pop();
            b = Sum.Top();
            Sum.Pop();
            if (str[i] == '+')
                Sum.Push(b + a);
            if (str[i] == '-')
                Sum.Push(b - a);
            if (str[i] == '*')
                Sum.Push(b * a);
            if (str[i] == '/')
                Sum.Push(b / a);
        }
    }
    return Sum.Top();
}