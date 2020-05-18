#pragma once

#include "TNode.h"

using namespace std;

template<class TKey, class TData>
class TList
{
private:
    TNode<TKey, TData>* pFirst;
    TNode<TKey, TData>* pPrev;
    TNode<TKey, TData>* pNext;
    TNode<TKey, TData>* pCurr;

public:
    TList();
    TList(const TNode<TKey, TData>*);
    TList(const TList<TKey, TData>&);
    ~TList();
    
    TNode<TKey, TData>* Search(TKey);
    void InsertBeginning(TKey, TData*);
    void InsertEnd(TKey, TData*);
    void InsertBefore(TKey, TData*, TKey);
    void InsertAfter(TKey, TData*, TKey);
    void Remove(TKey);

    void Reset();
    void Next();
    bool IsEnded() const;

    TNode<TKey, TData>* GetpFirst() const;

    friend ostream& operator<<(ostream& out, TList<TKey, TData>& list)
    {
        list.Reset();
        while (!(list.IsEnded()))
        {
            out << *(list.pCurr) << endl;
            list.Next();
        }
        return out;
    }
};

template<class TKey, class TData>
TList<TKey, TData>::TList()
{
    pFirst = nullptr;
    pPrev = nullptr;
    pNext = nullptr;
    pCurr = nullptr;
}

template<class TKey, class TData>
TList<TKey, TData>::TList(const TNode<TKey, TData>* n)
{
    if (n == nullptr)
    {
        pFirst = nullptr;
        pPrev = nullptr;
        pNext = nullptr;
        pCurr = nullptr;
        return;
    }
    pFirst = new TNode<TKey, TData>(*n);
    pCurr = pFirst;
    TNode<TKey, TData>* node = n->pNext;

    while (node)
    {
        pCurr->pNext = new TNode<TKey, TData>(*node);
        pCurr = pCurr->pNext;
        node = node->pNext;
    }
    Reset();
}

template<class TKey, class TData> 
TList<TKey, TData>::TList(const TList<TKey, TData>& list)
{
    if (list.pFirst == nullptr)
    {
        pFirst = nullptr;
        pPrev = nullptr;
        pNext = nullptr;
        pCurr = nullptr;
        return;
    }
    pFirst = new TNode<TKey, TData>(*(list.pFirst));
    pCurr = pFirst;
    TNode<TKey, TData>* node = list.pNext;
    
    
    while (node)
    {
        pCurr->pNext = new TNode<TKey, TData>(*node);
        pCurr = pCurr->pNext;
        node = node->pNext;
    }
    Reset();
}

template<class TKey, class TData>
TList<TKey, TData>::~TList() 
{
    pFirst = nullptr;
    pPrev = nullptr;
    pNext = nullptr;
    pCurr = nullptr;
};

template<class TKey, class TData>
TNode<TKey, TData>* TList<TKey, TData>::Search(TKey k) 
{
    Reset();
    while (!IsEnded())
    {
        if (k == pCurr->key)
            return pCurr;
        Next();
    }
    return nullptr;
}

template<class TKey, class TData>
void TList<TKey, TData>::InsertBeginning(TKey k, TData* d)
{
    if (pFirst == nullptr)
    {
        pFirst = new TNode<TKey, TData>(k, d);
        Reset();
    }
    else
    {
        TNode<TKey, TData>* node = new TNode<TKey, TData>(k, d, pFirst);
        node->pNext = pFirst;
        if (pCurr == pFirst)
        {
            pPrev = node;
        }
        pFirst = node;

    }
}

template<class TKey, class TData>
void TList<TKey, TData>::InsertEnd(TKey k, TData* d)
{
    if (!pFirst)
    {
        pFirst = new TNode<TKey, TData>(k, d);
        pCurr = pFirst;
    }
    else
    {
        while (!IsEnded())
            Next();
        pCurr = new TNode<TKey, TData>(k, d);
        pPrev->pNext = pCurr;
    }
}

template<class TKey, class TData>
void TList<TKey, TData>::InsertBefore(TKey k, TData* d, TKey sk)
{
    if(!pFirst)
        throw Error9();
    if (pFirst->key == sk)
    {
        InsertBeginning(k, d);
        return;
    }

    TNode<TKey, TData>* node = Search(sk);
    if (!node)
        throw Error8();
    Reset();
    while (pCurr != node)
        Next();
    TNode<TKey, TData>* newnode = new TNode<TKey, TData>(k, d, pCurr);
    pPrev->pNext = newnode;
    newnode->pNext = pCurr;
}

template<class TKey, class TData>
void TList<TKey, TData>::InsertAfter(TKey k, TData* d, TKey sk)
{
    if (!pFirst)
        throw Error9();
    TNode<TKey, TData>* node = Search(sk);
    if (!node)
        throw Error8();
    Reset();
    while (pCurr != node)
        Next();
    TNode<TKey, TData>* newnode = new TNode<TKey, TData>(k, d, pNext);
    newnode->pNext = pNext;
    pCurr->pNext = newnode;
    pNext = newnode;
}

template<class TKey, class TData>
void TList<TKey, TData>::Remove(TKey sk)//исправила
{    
    if (!pFirst)
        throw Error9();
    if (!Search(sk))
        throw Error8();

    if (pFirst == pCurr)
    {
        delete pFirst;
        pPrev = nullptr;
        if (pNext)
        {
            pFirst = pNext;
            pCurr = pNext;
            pNext = pNext->pNext;
        }
        else
        {
            pFirst = nullptr;
            pCurr = nullptr;
            pNext = nullptr;
        }
        return;
    }

    delete pCurr;
    if (pNext)
    {
        pPrev->pNext = pNext;
        pCurr = pNext;
        pNext = pNext->pNext;
    }
    else
    {
        pPrev->pNext = nullptr;
        pCurr = nullptr;
        pNext = nullptr;
    }
}


template<class TKey, class TData>
void TList<TKey, TData>::Reset()
{
    pCurr = pFirst;
    pPrev = nullptr;

    if (pFirst == nullptr)
        pNext = nullptr;
    else
        pNext = pCurr->pNext;
}

template<class TKey, class TData>
void TList<TKey, TData>::Next()
{
    pPrev = pCurr;
    pCurr = pNext;
    if (pCurr)
        pNext = pCurr->pNext;
    else
        pNext = nullptr;
}

template<class TKey, class TData>
bool TList<TKey, TData>::IsEnded() const
{
    return (pCurr == nullptr);
}

template<class TKey, class TData>
TNode<TKey, TData>* TList<TKey, TData>::GetpFirst() const 
{
    return pFirst;
}
