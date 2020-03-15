#include <iostream>
#include "TMatrix.h"

using namespace std;

void MTestEquality()
{
    cout << "A == B ?" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the matrix A: ";
        cin >> n;
        cout << "A = " << endl;
        TMatrix<double> A(n);
        cin >> A;
        cout << A;

        cout << "Enter the dimension of the matrix B: ";
        cin >> m;
        cout << "B = " << endl;
        TMatrix<double> B(m);
        cin >> B;
        cout << B;
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

void MTestInequality()
{
    cout << "A != B ?" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the matrix A: ";
        cin >> n;
        cout << "A = " << endl;
        TMatrix<double> A(n);
        cin >> A;
        cout << A;

        cout << "Enter the dimension of the matrix B: ";
        cin >> m;
        cout << "B = " << endl;
        TMatrix<double> B(m);
        cin >> B;
        cout << B;

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

void MTestAssignment()
{
    cout << "A = B" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the matrix A: ";
        cin >> n;
        cout << "A = " << endl;
        TMatrix<double> A(n);
        cin >> A;
        cout << A;

        cout << "Enter the dimension of the matrix B: ";
        cin >> m;
        cout << "B = " << endl;
        TMatrix<double> B(m);
        cin >> B;
        cout << B;

        A = B;
        cout << "A = B" << endl << "A = " << A << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void MTestAddition()
{
    cout << "A + B = C" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the matrix A: ";
        cin >> n;
        cout << "A = " << endl;
        TMatrix<double> A(n);
        cin >> A;
        cout << A;

        cout << "Enter the dimension of the matrix B: ";
        cin >> m;
        cout << "B = " << endl;
        TMatrix<double> B(m);
        cin >> B;
        cout << B;

        TMatrix<double> C(m);
        C = A + B;
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

void MTestSubtraction()
{
    cout << "A - B = C" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the matrix A: ";
        cin >> n;
        cout << "A = " << endl;
        TMatrix<double> A(n);
        cin >> A;
        cout << A;

        cout << "Enter the dimension of the matrix B: ";
        cin >> m;
        cout << "B = " << endl;
        TMatrix<double> B(m);
        cin >> B;
        cout << B;

        TMatrix<double> C(m);
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

void MTestMultiplication()
{
    cout << "A * B = C" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the matrix A: ";
        cin >> n;
        cout << "A = " << endl;
        TMatrix<double> A(n);
        cin >> A;
        cout << A;

        cout << "Enter the dimension of the matrix B: ";
        cin >> m;
        cout << "B = " << endl;
        TMatrix<double> B(m);
        cin >> B;
        cout << B;

        TMatrix<double> C(m);
        C = A * B;
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

void MTestAdditionConst()
{
    cout << "A + const = B" << endl;
    int n, c;

    try {
        cout << "Enter the dimension of the matrix A: ";
        cin >> n;
        cout << "A = " << endl;
        TMatrix<double> A(n);
        cin >> A;
        cout << A;

        cout << "const = ";
        cin >> c;

        TMatrix<double> B(n);
        B = A + c;
        cout << "B = " << B << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void MTestSubtractionConst()
{
    cout << "A - const = B" << endl;
    int n, c;

    try {
        cout << "Enter the dimension of the matrix A: ";
        cin >> n;
        cout << "A = " << endl;
        TMatrix<double> A(n);
        cin >> A;
        cout << A;

        cout << "const = ";
        cin >> c;

        TMatrix<double> B(n);
        B = A - c;
        cout << "B = " << B << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void MTestMultiplicationConst()
{
    cout << "A * const = B" << endl;
    int n, c;

    try {
        cout << "Enter the dimension of the matrix A: ";
        cin >> n;
        cout << "A = " << endl;
        TMatrix<double> A(n);
        cin >> A;
        cout << A;

        cout << "const = ";
        cin >> c;

        TMatrix<double> B(n);
        B = A * c;
        cout << "B = " << B << endl;
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void MTestMultiplicationVec()
{
    cout << "A * v1 = v2" << endl;
    int n, m;

    try {
        cout << "Enter the dimension of the matrix A: ";
        cin >> n;
        cout << "A = " << endl;
        TMatrix<double> A(n);
        cin >> A;
        cout << A;

        cout << "Enter the dimension of the vector v1: ";
        cin >> m;
        cout << "v1 = " << endl;
        TVector<double> v1(m);
        cin >> v1;
        cout << v1 << endl;

        TVector<double> v2(m);
        v2 = A * v1;
        cout << "v2 = " << v2 << endl;
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

void MTestCopyConstructor()
{
    int n;
    cout << "B(A) = ?" << endl;
    
    try {

        cout << "Enter the dimension of the matrix A: ";
        cin >> n;
        cout << "A = " << endl;
        TMatrix<double> A(n);
        cin >> A;
        cout << A << endl;

        TMatrix<double> B(A);
        cout << "B(A) =" << endl << B << endl; 
    }
    catch (Error1 e)
    {
        cout << e.what();
    }
}

void MTestTypeConversionConstructor()
{
    int n;
    cout << "A(v1) = ?" << endl;

    try {

        cout << "Enter the dimension of the vector of vectors v1: ";
        cin >> n;
        cout << "v1 = " << endl;
        TVector<TVector<double> > v1(n);
        for (int i = 0; i < n; i++)
        {
            TVector<double> temp(n - i, i);
            v1[i] = temp;
            cin >> v1[i];
        }

        TMatrix<double> A(v1);
        cout << "A(v1) =" << endl << A << endl;
    } 
    catch (Error1 e)
    {
        cout << e.what();
    }
}