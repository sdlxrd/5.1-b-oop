#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exception : exception
{
	string msg;
	public:
		Exception(string) : msg(msg) {}
		string getMessage() { return msg; }
};

