#include <iostream>
#include "Tests.h"

using namespace std;

int main()
{
    cout << "Hello!" << endl;
    cout << "If you want to test operations with matrixes - press 1" << endl;
    cout << "If you want to test operations with vectors - press 2" << endl;

    int n;
    do {
        cout << "Your choice: ";
        cin >> n;
    } while ((n <= 0) || (n > 2));

    switch (n)
    {
    case 1:
    {
        cout << "Choose the number of the test you want to try." << endl << endl;
        cout << "1  - TestEquality" << endl;
        cout << "2  - TestInequality" << endl;
        cout << "3  - TestAssignment" << endl;
        cout << "4  - TestAddition" << endl;
        cout << "5  - TestSubtraction" << endl;
        cout << "6  - TestMultiplication" << endl;
        cout << "7  - TestAdditionConst" << endl;
        cout << "8  - TestSubtractionConst" << endl;
        cout << "9  - TestMultiplicationConst" << endl;
        cout << "10 - TestMultiplicationVec" << endl;
        cout << "11 - TestCopyConstructor" << endl;
        cout << "12 - TestTypeConversionConstructor" << endl;

        do {
            cout << "Number of the test: ";
            cin >> n;
        } while ((n <= 0) || (n > 12));

        switch (n)
        {
        case 1:  { MTestEquality(); break; }
        case 2:  { MTestInequality(); break; }
        case 3:  { MTestAssignment(); break; }
        case 4:  { MTestAddition(); break; }
        case 5:  { MTestSubtraction(); break; }
        case 6:  { MTestMultiplication(); break; }
        case 7:  { MTestAdditionConst(); break; }
        case 8:  { MTestSubtractionConst(); break; }
        case 9:  { MTestMultiplicationConst(); break; }
        case 10: { MTestMultiplicationVec(); break; }
        case 11: { MTestCopyConstructor(); break; }
        case 12: { MTestTypeConversionConstructor(); break; }
        }
        break;
    }
    case 2:
    {
        cout << "Choose the number of the test you want to try." << endl << endl;
        cout << "1  - TestEquality" << endl;
        cout << "2  - TestInequality" << endl;
        cout << "3  - TestAssignment" << endl;
        cout << "4  - TestAddition" << endl;
        cout << "5  - TestSubtraction" << endl;
        cout << "6  - TestMultiplication" << endl;
        cout << "7  - TestAdditionConst" << endl;
        cout << "8  - TestSubtractionConst" << endl;
        cout << "9  - TestMultiplicationConst" << endl;
        cout << "10 - TestIndex" << endl;
        cout << "11 - TestLength" << endl;

        do {
            cout << "Number of the test: ";
            cin >> n;
        } while ((n <= 0) || (n > 11));

        switch (n)
        {
        case 1:  { VTestEquality(); break; }
        case 2:  { VTestInequality(); break; }
        case 3:  { VTestAssignment(); break; }
        case 4:  { VTestAddition(); break; }
        case 5:  { VTestSubtraction(); break; }
        case 6:  { VTestMultiplication(); break; }
        case 7:  { VTestAdditionConst(); break; }
        case 8:  { VTestSubtractionConst(); break; }
        case 9:  { VTestMultiplicationConst(); break; }
        case 10: { VTestIndex(); break; }
        case 11: { VTestLength(); break; }
        }
    }
    break;
    }
    system("pause");
}