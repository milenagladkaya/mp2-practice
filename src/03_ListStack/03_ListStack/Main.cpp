#include <iostream>
#include "Tests.h"
#include "Postfix.h"

using namespace std;

void main()
{
	try {
		int mode;
		Postfix<double>* p; //выделила память

		cout << "Hello! Choose a mode:" << endl;
		cout << "1 - Tests" << endl;
		cout << "2 - Calculator" << endl;
		do {
			cout << "Number of the mode: ";
			cin >> mode;
		} while ((mode != 1) && (mode != 2));
		switch (mode)
		{
		case 1:
		{

			cout << "Choose the number of the test you want to try." << endl << endl;
			cout << "1 - TestSearch" << endl;
			cout << "2 - TestInsertBeginning" << endl;
			cout << "3 - TestInsertBefore" << endl;
			cout << "4 - TestInsertAfter" << endl;
			cout << "5 - TestRemove" << endl;

			int n;
			do {
				cout << "Number of the test: ";
				cin >> n;
			} while ((n < 1) || (n > 5));
			switch (n)
			{
			case 1: { TestSearch(); break; }
			case 2: { TestInsertBeginning(); break; }
			case 3: { TestInsertBefore(); break; }
			case 4: { TestInsertAfter(); break; }
			case 5: { TestRemove(); break; }
			}
			break;
		}

		case 2:
		{
			cout << "Entet the type of stack." << endl;
			cout << "1 - Array stack" << endl;
			cout << "2 - List stack" << endl;
			do {
				cout << "Number of the mode: ";
				cin >> mode;
			} while ((mode != 1) && (mode != 2));

			if (mode == 1)
			{
				p = new Postfix<double>(Array);			
			}
			else
			{
				p = new Postfix<double>(List);
			}
			cout << "---------------------STEP 1----------------------" << endl;
			cout << "Enter an expression (without spaces): ";
			string str;
			cin >> str;

			cout << endl << "---------------------STEP 2----------------------" << endl;
			cout << "Postfix form of your expression: ";
			string postfix = p->PostfixForm(str);
			cout << postfix << endl;

			cout << endl << "---------------------STEP 3----------------------" << endl;
			operand *var;
			int n = p->CreateVariables(postfix, var);

			cout << "---------------------STEP 4----------------------" << endl;
			double rez = p->Calculation(postfix, var, n);
			cout << "Result = " << rez << endl;

			delete[] var;
			delete p;
			break;
		}
		}
	}
	catch (const Error1& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (const Error2& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (const Error3& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (const Error4& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (const Error5& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (const Error6& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (const Error7& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (const Error8& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (const Error9& e)
	{
		cout << endl << e.what() << endl;
	}
	catch (const Error10& e)
	{
		cout << endl << e.what() << endl;
	}
	system ("pause");
}
//A+B
//A-B*(A-B)
//A-(B-A)/(C-A)*D