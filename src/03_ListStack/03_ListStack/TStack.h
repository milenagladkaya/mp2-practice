#pragma once

template<typename ValType> class TArrayStack;
template<typename ValType> class TListStack;

enum StackType
{
	Array,
	List
};

template<typename ValType>
class TStack
{
public:
	static TStack* Create(StackType);

	virtual void Push(ValType) = 0;
	virtual void Pop() = 0;
	virtual ValType Top() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
};


template<typename ValType>
TStack<ValType>* TStack<ValType>::Create(StackType type)
{
	if (type == Array)
	{
		return new TArrayStack<ValType>(50);
	}
	else if (type == List)
	{
		return new TListStack<ValType>();
	}
};