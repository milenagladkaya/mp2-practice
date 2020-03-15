#pragma once
#include "Exception.h"

using namespace std;

template <class ValType>
class Stack
{
private:
    int size;
    ValType* elems;
    int top;

public:
    Stack(int _size);
    Stack(const Stack&);
    ~Stack();
<<<<<<< HEAD
    void Push(ValType);
=======
    void Push(ValType); 
>>>>>>> origin/02_Stack
    void Pop();
    ValType Top() const;
    bool IsEmpty() const;
    bool IsFull() const;
};

template<typename ValType>
Stack<ValType>::Stack(int _size)
{
    if (_size <= 0)
        throw Error3();
    size = _size;
    top = 0;
    elems = new ValType[size];
}

template<typename ValType>
Stack<ValType>::Stack(const Stack& s)
{
    size = s.size;
    top = s.top;
    elems = new ValType[size];
    for (int i = 0; i < size; i++)
        elems[i] = s.elems[i];
}

template<typename ValType>
Stack<ValType>::~Stack()
{
    size = 0;
    top = 0;
    delete[] elems;
}

template<typename ValType>
void Stack<ValType>::Push(ValType el)
{
    if (this->IsFull())
        throw Error4();
    elems[top] = el;
    top++;
}

template <typename ValType>
<<<<<<< HEAD
void Stack<ValType>::Pop()
{
    if (this->IsEmpty())
        throw Error6();
=======
void Stack<ValType>:: Pop() 
{
    if (this->IsEmpty())
        throw Error2();    
>>>>>>> origin/02_Stack
    elems[top--];
}

template <typename ValType>
ValType Stack<ValType>::Top() const
{
    return elems[top - 1];
}

template <typename ValType>
bool Stack<ValType>::IsEmpty() const
{
    return (top == 0);
}

template <typename ValType>
bool Stack<ValType>::IsFull() const
{
    return (top == (size));
}