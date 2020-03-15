#include <iostream>
#include "TVector.h"

using namespace std;

void VTestEquality()
{
    cout << "A == B ?" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the vector A: ";
        cin >> n;
        cout << "A = " << endl;
        TVector<double> A(n);
        cin >> A;
        cout << A << endl;

        cout << "Enter the dimension of the vector B: ";
        cin >> m;
        cout << "B = " << endl;
        TVector<double> B(m);
        cin >> B;
        cout << B << endl;

        if (A == B)
            cout << "A == B" << endl;
        else
            cout << "A != B" << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void VTestInequality()
{
    cout << "A != B ?" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the vector A: ";
        cin >> n;
        cout << "A = " << endl;
        TVector<double> A(n);
        cin >> A;
        cout << A << endl;

        cout << "Enter the dimension of the vector B: ";
        cin >> m;
        cout << "B = " << endl;
        TVector<double> B(m);
        cin >> B;
        cout << B << endl;
        if (A != B)
            cout << "A != B" << endl;
        else
            cout << "A == B" << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void VTestAssignment()
{
    cout << "A = B" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the vector A: ";
        cin >> n;
        cout << "A = " << endl;
        TVector<double> A(n);
        cin >> A;
        cout << A << endl;

        cout << "Enter the dimension of the vector B: ";
        cin >> m;
        cout << "B = " << endl;
        TVector<double> B(m);
        cin >> B;
        cout << B << endl;

        A = B;
        cout << "A = B" << endl << "A = " << A << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void VTestAddition()
{
    cout << "A + B = C" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the vector A: ";
        cin >> n;
        cout << "A = " << endl;
        TVector<double> A(n);
        cin >> A;
        cout << A << endl;

        cout << "Enter the dimension of the vector B: ";
        cin >> m;
        cout << "B = " << endl;
        TVector<double> B(m);
        cin >> B;
        cout << B << endl;

        TVector<double> C(m);
        C = A + B;
        cout << "C = " << C << endl;
    }
    catch (Error2 e)
    {
        cout << e.what();
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void VTestSubtraction()
{
    cout << "A - B = C" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the vector A: ";
        cin >> n;
        cout << "A = " << endl;
        TVector<double> A(n);
        cin >> A;
        cout << A << endl;

        cout << "Enter the dimension of the vector B: ";
        cin >> m;
        cout << "B = " << endl;
        TVector<double> B(m);
        cin >> B;
        cout << B << endl;

        TVector<double> C(m);
        C = A - B;
        cout << "C = " << C << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
    catch (Error2 e)
    {
        cout << e.what();
    }
}

void VTestMultiplication()
{
    cout << "A * B = c" << endl;
    int n, m;
    double c;

    try {
        cout << "Enter the dimension of the vector A: ";
        cin >> n;
        cout << "A = " << endl;
        TVector<double> A(n);
        cin >> A;
        cout << A << endl;

        cout << "Enter the dimension of the vector B: ";
        cin >> m;
        cout << "B = " << endl;
        TVector<double> B(m);
        cin >> B;
        cout << B << endl;

        c = A * B;
        cout << "c = " << c << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
    catch (Error2 e)
    {
        cout << e.what();
    }
}

void VTestAdditionConst()
{
    cout << "A + const = B" << endl;
    int n, c;

    try {
        cout << "Enter the dimension of the vector A: ";
        cin >> n;
        cout << "A = " << endl;
        TVector<double> A(n);
        cin >> A;
        cout << A << endl;

        cout << "const = ";
        cin >> c;

        TVector<double> B(n);
        B = A + c;
        cout << "B = " << B << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void VTestSubtractionConst()
{
    cout << "A - const = B" << endl;
    int n, c;

    try {
        cout << "Enter the dimension of the vector A: ";
        cin >> n;
        cout << "A = " << endl;
        TVector<double> A(n);
        cin >> A;
        cout << A << endl;

        cout << "const = ";
        cin >> c;

        TVector<double> B(n);
        B = A - c;
        cout << "B = " << B << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void VTestMultiplicationConst()
{
    cout << "A * const = B" << endl;
    int n, c;

    try {
        cout << "Enter the dimension of the vector A: ";
        cin >> n;
        cout << "A = " << endl;
        TVector<double> A(n);
        cin >> A;
        cout << A << endl;

        cout << "const = ";
        cin >> c;

        TVector<double> B(n);
        B = A * c;
        cout << "B = " << B << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}


void VTestIndex()
{
    cout << "A[i] = ?" << endl;
    int n, i;

    try {
        cout << "Enter the dimension of the vector A: ";
        cin >> n;
        cout << "A = " << endl;
        TVector<double> A(n);
        cin >> A;
        cout << A << endl;

        cout << "index = ";
        cin >> i;
        cout << "A[i] = " << A[i] << endl;
    }
    catch (Error3 e)
    {
        cout << e.what();
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void VTestLength()
{
    cout << "|A| = ?" << endl;
    int n;

    try {
        cout << "Enter the dimension of the vector A: ";
        cin >> n;
        cout << "A = " << endl;
        TVector<double> A(n);
        cin >> A;
        cout << A << endl;

        double l = A.Length();
        cout << "|A| = " << l << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}