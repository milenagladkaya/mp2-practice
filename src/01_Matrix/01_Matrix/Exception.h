#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Error1 : exception
{
private:
    const string what_str = "Error1: incorrect size";

public:
    const char* what() const { return what_str.c_str(); }
};

class Error2 : exception
{
private:
    const string what_str = "Error2: different dimensions";

public:
    const char* what() const { return what_str.c_str(); }
};

class Error3 : exception
{
private:
    const string what_str = "Error3: no element with such index";

public:
    const char* what() const { return what_str.c_str(); }
};