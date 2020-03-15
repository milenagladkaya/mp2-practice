#include "Postfix.h"

using namespace std;

int main()
{
    try
    {
<<<<<<< HEAD
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
        Postfix::CreateVariables(postfix, var);

        cout << endl << "-------------------------STEP 4--------------------------" << endl;
        double rez = Postfix::Calculation(postfix, var);
        cout << "Result = " << rez << endl;
    }

    catch (const Error1& e)
=======
   /* cout << "-------------------------STEP 1--------------------------" << endl;
    cout << "Enter the NUMBER of variables (min = 2, max = 6): ";
    int numvar = Postfix::InputNumberOfVariables();
    operand* var = new operand[numvar];

    cout << endl << "-------------------------STEP 2--------------------------" << endl;
    Postfix::CreateVariables(var, numvar);*/

    cout << "-------------------------STEP 3--------------------------" << endl;
    cout << "Enter an expression (without spaces): ";
    string str;
    cin >> str;
    
    cout << endl << "-------------------------STEP 4--------------------------" << endl;
    cout << "Postfix form of your expression: ";
    string postfix = Postfix::PostfixForm(str);
    cout << postfix << endl;

	//int numvar;
	operand *var = new operand;//numvar = new operand
	Postfix::CreateVariables(postfix, var);//numvar

   /* cout << endl << "-------------------------STEP 5--------------------------" << endl;
    int rez = Postfix::Calculation(str, var, numvar);
    cout << "Result = " << rez << endl;*/
    }

    catch (const Error1 e)//&
>>>>>>> origin/02_Stack
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

    system("pause");
}

//(7+6)*(4-1)-8/2 = 35
//(a+b)*(c-d)-e/f
//a+b*c-(a*b+c/b)
//a+(b*(c-a)+b/(a+b-c))
//a+b*c