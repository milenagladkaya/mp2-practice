#include <iostream>
#include "TList.h"
#include "Tests.h"

using namespace std;

void TestSearch()
{
	cout << "TEST 1 search by key" << endl;
	int size;
	cout << "size = ";
	if(!(cin >> size))
		throw Error10();

	double key, sk;
	char *data = new char(1);
	TList<double, char> list;
	for (int i = 0; i < size; i++)
	{
		cout << "key = ";
		if(!(cin >> key))
			throw Error10();
		cout << "data = ";
		cin >> *data;
		list.InsertEnd(key, data);
	};
	cout << "search key = ";
	if(!(cin >> sk))
		throw Error10();
	TNode<double, char>* node = list.Search(sk);
	cout << *node;
}

void TestInsertBeginning()
{
	cout << "TEST 2 insert at the beginning" << endl;
	int size;
	cout << "size = ";
	if (!(cin >> size))
		throw Error10();

	double key;
	char *data = new char(1);
	TList<double, char> list;
	for (int i = 0; i < size; i++)
	{
		cout << "key = ";
		if (!(cin >> key))
			throw Error10();
		cout << "data = ";
		cin >> *data;
		list.InsertEnd(key, data);
	}
	cout << endl << "Create a new node:" << endl;
	cout << "key = ";
	if (!(cin >> key))
		throw Error10();
	cout << "data = ";
	cin >> *data;
	list.InsertBeginning(key, data);
	cout << list;

}

void TestInsertBefore()
{
	cout << "TEST 3 insert before" << endl;
	int size;
	cout << "size = ";
	if (!(cin >> size))
		throw Error10();

	double key, bk;
	char *data = new char(1);
	TList<double, char> list;
	for (int i = 0; i < size; i++)
	{
		cout << "key = ";
		if (!(cin >> key))
			throw Error10();
		cout << "data = ";
		cin >> *data;
		list.InsertEnd(key, data);
	}
	cout << endl << "Create a new node:" << endl;
	cout << "key = ";
	if (!(cin >> key))
		throw Error10();
	cout << "data = ";
	cin >> *data;

	cout << "Input the key to insert before the node: ";
	if (!(cin >> bk))
		throw Error10();
	list.InsertBefore(key, data, bk);
	cout << list;
}

void TestInsertAfter()
{
	cout << "TEST 4 insert after" << endl;
	int size;
	cout << "size = ";
	if (!(cin >> size))
		throw Error10();

	double key, ak;
	char *data = new char(1);
	TList<double, char> list;
	for (int i = 0; i < size; i++)
	{
		cout << "key = ";
		if (!(cin >> key))
			throw Error10();
		cout << "data = ";
		cin >> *data;
		list.InsertEnd(key, data);
	}
	cout << endl << "Create a new node:" << endl;
	cout << "key = ";
	if (!(cin >> key))
		throw Error10();
	cout << "data = ";
	cin >> *data;

	cout << "Input the key to insert after the node: ";
	if (!(cin >> ak))
		throw Error10();
	list.InsertAfter(key, data, ak);
	cout << list;
}

void TestRemove()
{
	cout << "TEST 5 remove node" << endl;
	int size;
	cout << "size = ";
	if (!(cin >> size))
		throw Error10();

	double key, rk;
	char *data = new char(1);
	TList<double, char> list;
	for (int i = 0; i < size; i++)
	{
		cout << "key = ";
		if (!(cin >> key))
			throw Error10();
		cout << "data = ";
		cin >> *data;
		list.InsertEnd(key, data);
	}
	
	cout << "Input the key to remove the node: ";
	if (!(cin >> rk))
		throw Error10();
	list.Remove(rk);
	cout << list;
}