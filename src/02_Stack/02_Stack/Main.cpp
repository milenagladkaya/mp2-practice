#include "Postfix.h"

using namespace std;

int main()
{
    try
    {
        cout << "-------------------------STEP 1--------------------------" << endl;
        cout << "Enter an expression (without spaces): ";
        string str;
        cin >> str;

        cout << endl << "-------------------------STEP 2--------------------------" << endl;
        cout << "Postfix form of your expression: ";
        string postfix = Postfix::PostfixForm(str);
        cout << postfix << endl;

		cout << endl << "-------------------------STEP 3--------------------------" << endl;
		operand *var;
		int n = Postfix::CreateVariables(postfix, var);

        cout << "-------------------------STEP 4--------------------------" << endl;
        double rez = Postfix::Calculation(postfix, var, n);
        cout << "Result = " << rez << endl;

		delete [] var;
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

    system("pause");
}

//A+B
//A-B*(A-B)
//A-(B-A)/(C-A)*D
//A B A - C A - / D * -
