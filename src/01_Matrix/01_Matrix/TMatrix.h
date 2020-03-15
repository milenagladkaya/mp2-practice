#pragma once
#include <iostream>
#include "TVector.h"

using namespace std;

template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
    TMatrix(int size = 10);
    TMatrix(const TMatrix&);
    TMatrix(const TVector<TVector<ValType>>&);
    ~TMatrix();

    bool operator== (const TMatrix&) const;
    bool operator!= (const TMatrix&) const;

    TMatrix& operator=(const TMatrix&);
    TMatrix operator+(const TMatrix&);
    TMatrix operator-(const TMatrix&);
    TMatrix operator*(const TMatrix&);

    TMatrix operator+(const ValType);
    TMatrix operator-(const ValType);
    TMatrix operator*(const ValType);

    TVector<ValType> operator*(const TVector<ValType>&);

    friend ostream& operator<< (ostream& out, const TMatrix& m)
    {
        if (m.size <= 0)
            throw Error1();
        for (int i = 0; i < m.size; i++)
            out << m.elems[i] << endl;
        return out;
    }

    friend istream& operator>> (istream& in, TMatrix& m)
    {
        if (m.size <= 0)
            throw Error1();
        for (int i = 0; i < m.size; i++)
            in >> m.elems[i];
        return in;
    }
};

template<typename ValType>
TMatrix<ValType>::TMatrix(int _size) : TVector<TVector<ValType> >(_size)
{
    for (int i = 0; i < _size; i++)
        this->elems[i] = TVector<ValType>(_size - i, i);
}

template<typename ValType>
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& m) : TVector<TVector<ValType> >(m) {}

template<typename ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& m) : TVector<TVector<ValType> >(m) {}

template<typename ValType>
TMatrix<ValType>::~TMatrix() {}

template<typename ValType>
bool TMatrix<ValType>::operator== (const TMatrix& m) const
{
    if (this->size != m.size)
        return false;
    for (int i = 0; i < m.size; i++)
        if (this->elems[i] != m.elems[i])
            return false;
    return true;
}

template<typename ValType>
bool TMatrix<ValType>::operator!= (const TMatrix& m) const
{
    return !(*this == m);
}

template<typename ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix& m)
{
    if (*this == m)
        return *this;
    if (this->size != m.size)
    {
        this->size = m.size;
        delete[] this->elems;
        this->elems = new TVector<ValType>[m.size];
    }
    for (int i = 0; i < m.size; i++)
        this->elems[i] = m.elems[i];
    return *this;
}

template<typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix& m)
{
    if (this->size != m.size)
        throw Error2();
    TMatrix<ValType> res(*this);
    for (int i = 0; i < res.size; i++)
        res.elems[i] = this->elems[i] + m.elems[i];
    return res;
}

template<typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix& m)
{
    if (this->size != m.size)
        throw Error2();
    TMatrix<ValType> res(*this);
    for (int i = 0; i < res.size; i++)
        res.elems[i] = this->elems[i] - m.elems[i];
    return res;
}

template<typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix& m)
{
    if (this->size != m.size)
        throw Error2();
    TMatrix<ValType> res(*this);
    for (int i = 0; i < this->size; i++)
        for (int j = this->elems[i].GetSI(); j < this->size; j++)
        {
            res.elems[i][j - i] = 0.0;
            for (int k = i; k <= j; k++)
                res.elems[i][j - i] += this->elems[i][k - i] * m.elems[k][j - k];
        }
    return res;
}

template <typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const ValType el)
{
    TMatrix<ValType> res(*this);
    for (int i = 0; i < res.size; i++)
        res.elems[i] = this->elems[i] + el;
    return res;
}

template <typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const ValType el)
{
    TMatrix<ValType> res(*this);
    for (int i = 0; i < res.size; i++)
        res.elems[i] = this->elems[i] - el;
    return res;
}

template <typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const ValType el)
{
    TMatrix<ValType> res(*this);
    for (int i = 0; i < res.size; i++)
        res.elems[i] = this->elems[i] * el;
    return res;
}

template <typename ValType>
TVector<ValType> TMatrix<ValType>::operator*(const TVector<ValType>& v)
{
    if (this->size != v.GetSize()) {
        throw Error2();
    }
    TVector<ValType> res(this->size);
    for (int i = 0; i < this->size; i++)//line index (index of the element(vector) in the vector of vectors)
    {
        res[i] = 0;
        for (int j = 0; j < this->elems[i].GetSize(); j++) //column index (element index in the selected vector)
            res[i] += this->elems[i][j] * v[j + i];
    }
    return res;
}