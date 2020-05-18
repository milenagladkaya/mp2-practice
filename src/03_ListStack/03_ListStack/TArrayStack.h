#pragma once
#include "Exception.h"
#include "TStack.h"

using namespace std;

template <typename ValType>
class TArrayStack: public TStack<ValType>
{
private:
	int size;
	ValType* elems;
	int top;

public:
	TArrayStack(int _size);
	TArrayStack(const TArrayStack&);
	~TArrayStack();
	void Push(ValType);
	void Pop();
	ValType Top() const;
	bool IsEmpty() const;
	bool IsFull() const;
};

template<typename ValType>
TArrayStack<ValType>::TArrayStack(int _size)
{
	if (_size <= 0)
		throw Error3();
	size = _size;
	top = 0;
	elems = new ValType[size];
}

template<typename ValType>
TArrayStack<ValType>::TArrayStack(const TArrayStack& s)
{
	size = s.size;
	top = s.top;
	elems = new ValType[size];
	for (int i = 0; i < size; i++)
		elems[i] = s.elems[i];
}

template<typename ValType>
TArrayStack<ValType>::~TArrayStack()
{
	size = 0;
	top = 0;
	delete[] elems;
}

template<typename ValType>
void TArrayStack<ValType>::Push(ValType el)
{
	if (this->IsFull())
		throw Error4();
	elems[top] = el;
	top++;
}

template <typename ValType>
void TArrayStack<ValType>::Pop()
{
	if (this->IsEmpty())
		throw Error6();
	elems[top--];
}

template <typename ValType>
ValType TArrayStack<ValType>::Top() const
{
	return elems[top - 1];
}

template <typename ValType>
bool TArrayStack<ValType>::IsEmpty() const
{
	return (top == 0);
}

template <typename ValType>
bool TArrayStack<ValType>::IsFull() const
{
	return (top == (size));
}
