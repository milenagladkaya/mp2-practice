#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Error1 : exception
{
private:
	const string what_str = "Error1: no ')' in the expression";

public:
	const char* what() const { return what_str.c_str(); }

};

class Error2 : exception
{
private:
	const string what_str = "Error2: no '(' in the expression";

public:
	const char* what() const { return what_str.c_str(); }
};

class Error3 : exception
{
private:
	const string what_str = "Error3: incorrect size";

public:
	const char* what() const { return what_str.c_str(); }
};

class Error4 : exception
{
private:
	const string what_str = "Error4: full stack";

public:
	const char* what() const { return what_str.c_str(); }
};

class Error5 : exception
{
private:
	const string what_str = "Error5: incorrect variable input";

public:
	const char* what() const { return what_str.c_str(); }
};

class Error6 : exception
{
private:
	const string what_str = "Error6: empty stack";

public:
	const char* what() const { return what_str.c_str(); }
};

class Error7 : exception
{
private:
	const string what_str = "Error7: division by zero";

public:
	const char* what() const { return what_str.c_str(); }
};


class Error8 : exception 
{
private:
	const string what_str = "Error8: there is no such key";

public:
	const char* what() const { return what_str.c_str(); }
};

class Error9 : exception
{
private:
	const string what_str = "Error9: empty list";

public:
	const char* what() const { return what_str.c_str(); }
};

class Error10 : exception 
{
private:
	const string what_str = "Error10: incorrect input";

public:
	const char* what() const { return what_str.c_str(); }
};