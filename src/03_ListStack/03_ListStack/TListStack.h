#pragma once

#include "TList.h"
#include "TStack.h"

using namespace std;

template <typename ValType>
class TListStack: public TStack<ValType>
{
private:
	TList<ValType, ValType>* elems;

public:
	TListStack();
	TListStack(const TListStack&);
	~TListStack();
	void Push(ValType);
	void Pop();
	ValType Top() const;
	bool IsEmpty() const;
	bool IsFull() const;
};

template<typename ValType>
TListStack<ValType>::TListStack()
{
	elems = new TList<ValType, ValType>;
}

template<typename ValType>
TListStack<ValType>::TListStack(const TListStack& ls)
{
elems = new TList<ValType, ValType>(ls.elems);
}

template<typename ValType>
TListStack<ValType>::~TListStack()
{
	delete elems;
}

template<typename ValType>
void TListStack<ValType>::Push(ValType el)
{
	if (this->IsFull())
		throw Error4();
	elems->InsertBeginning(el, nullptr);
	elems->Reset();
}

template <typename ValType>
void TListStack<ValType>::Pop()
{
	if (this->IsEmpty())
		throw Error6();
	elems->Remove(elems->GetpFirst()->key);
}

template <typename ValType>
ValType TListStack<ValType>::Top() const
{
	if (this->IsEmpty())
		throw Error6();
	return elems->GetpFirst()->key;
}

template <typename ValType>
bool TListStack<ValType>::IsEmpty() const
{
	return (elems->GetpFirst() == nullptr);
}

template <typename ValType>
bool TListStack<ValType>::IsFull() const //исправила
{	
	TNode<ValType, ValType>* tmp = new TNode<ValType, ValType>();
	if (tmp == nullptr)
		return true;
	delete tmp;
	return false; 
}

