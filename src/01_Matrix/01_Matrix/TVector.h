#pragma once
#include <iostream>
#include "Exception.h"

using namespace std;

template <typename ValType>
class TVector
{
protected:
    int size;
    ValType* elems;
    int startIndex;

public:
    TVector(int size = 10, int startIndex = 0);
    TVector(const TVector&);
    virtual ~TVector();

    bool operator== (const TVector&) const;
    bool operator!= (const TVector&) const;

    TVector& operator= (const TVector&);
    TVector operator+ (const TVector&);
    TVector operator- (const TVector&);

    TVector operator+(const ValType);
    TVector operator-(const ValType);
    TVector operator*(const ValType);

    ValType operator*(const TVector&);
    ValType Length() const;
    int GetSize() const;
    int GetSI()const;

    ValType& operator[] (int index);
    const ValType& operator[](int index) const;

    friend ostream& operator<< (ostream& out, const TVector& v)
    {
        if (v.size <= 0)
            throw Error1();
        for (int i = 0; i < v.startIndex; i++)
            out << "\t";
        for (int i = 0; i < v.size; i++)
            out << v.elems[i] << "\t";
        return out;
    }

    friend istream& operator>> (istream& in, TVector& v)
    {
        if (v.size <= 0)
            throw Error1();
        for (int i = 0; i < v.size; i++)
            in >> v.elems[i];
        return in;
    }

};

template<typename ValType>
TVector<ValType>::TVector(int _size, int _startIndex)
{
    if (_size <= 0)
        throw Error1();
    this->size = _size;
    this->startIndex = _startIndex;
    this->elems = new ValType[this->size];
}

template<typename ValType>
TVector<ValType>::TVector(const TVector& v)
{
    this->size = v.size;
    this->startIndex = v.startIndex;
    this->elems = new ValType[this->size];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];
}

template<typename ValType>
TVector<ValType>::~TVector()
{
    this->size = 0;
    delete[] this->elems;
}

template<typename ValType>
bool TVector<ValType>::operator==(const TVector& v) const
{
    if ((this->size != v.size) || (this->startIndex != v.startIndex))
        return false;
    for (int i = 0; i < this->size; i++)
        if (this->elems[i] != v.elems[i])
            return false;
    return true;
}

template<typename ValType>
bool TVector<ValType>::operator!=(const TVector& v) const
{
    return !(*this == v);
}

template<typename ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
    if (*this == v)
        return *this;
    if (this->size != v.size)
    {
        delete this->elems;
        this->size = v.size;
        this->elems = new ValType[this->size];
    }
    this->startIndex = v.startIndex;
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];
    return *this;
}

template <typename ValType>
TVector<ValType> TVector<ValType>:: operator+ (const TVector& v)
{
    if (this->size != v.size || this->startIndex != v.startIndex)
        throw Error2();
    TVector res(*this);
    for (int i = 0; i < this->size; i++)
        res.elems[i] = this->elems[i] + v.elems[i];
    return res;
}

template <typename ValType>
TVector<ValType> TVector<ValType>:: operator- (const TVector& v)
{
    if (this->size != v.size || this->startIndex != v.startIndex)
        throw Error2();
    TVector res(*this);
    for (int i = 0; i < this->size; i++)
        res.elems[i] = this->elems[i] - v.elems[i];
    return res;
}

template <typename ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType el)
{
    TVector res(*this);
    for (int i = 0; i < this->size; i++)
        res.elems[i] = this->elems[i] + el;
    return res;
}

template <typename ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType el)
{
    TVector res(*this);
    for (int i = 0; i < this->size; i++)
        res.elems[i] = this->elems[i] - el;
    return res;
}

template <typename ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType el)
{
    TVector res(*this);
    for (int i = 0; i < this->size; i++)
        res.elems[i] = this->elems[i] * el;
    return res;
}

template <typename ValType>
ValType TVector<ValType>:: operator*(const TVector& v)
{
    if (this->size != v.size || this->startIndex != v.startIndex)
        throw Error2();
    ValType s = 0;
    for (int i = 0; i < this->size; i++)
        s += this->elems[i] * v.elems[i];
    return s;
}

template <typename ValType>
ValType TVector<ValType>::Length() const
{
    ValType l = 0;
    for (int i = 0; i < this->size; i++)
        l += this->elems[i] * this->elems[i];
    return sqrt(l);
}

template <typename ValType>
int TVector<ValType>::GetSize() const
{
    return this->size;
}

template <typename ValType>
int TVector<ValType>::GetSI() const
{
    return this->startIndex;
}

template <typename ValType>
ValType& TVector<ValType>::operator[] (int index)
{
    if ((index < 0) || (index >= this->size))
        throw Error3();
    return this->elems[index];
}

template <typename ValType>
const ValType& TVector<ValType>::operator[](int index) const
{
    if ((index < 0) || (index >= this->size))
        throw Error3();
    return this->elems[index];
}