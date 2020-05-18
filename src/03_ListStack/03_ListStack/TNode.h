#pragma once
#include "Exception.h"

using namespace std;

template<class TKey, class TData>
class TNode 
{
public:
	TKey key;
	TData* pData;
	TNode<TKey, TData>* pNext;

	TNode();
	TNode(const TNode<TKey, TData>&);
	TNode(TKey k, TData* d, TNode<TKey, TData>* node = nullptr);
	~TNode();

	friend ostream& operator<<(ostream& out, const TNode<TKey, TData>& node)
	{
		out << "[ " << node.key << " | " << *(node.pData) << " ]";
		return out;
	}
};

template<class TKey, class TData>
TNode<TKey, TData>::TNode()
{
	key = 0;
	pData = nullptr;
	pNext = nullptr;
};

template<class TKey, class TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& node)
{
	key = node.key;
	pData = new TData (*node.pData);
	pNext = nullptr;
}

template<class TKey, class TData>
TNode<TKey, TData>::TNode(TKey k, TData* d, TNode<TKey, TData>* node)
{
	key = k;
	if (d)
		pData = new TData(*d);
	else
		pData = d;
	pNext = node;
	
}

template<class TKey, class TData>
TNode<TKey, TData>::~TNode()
{
	key = 0;
	delete pData;
}