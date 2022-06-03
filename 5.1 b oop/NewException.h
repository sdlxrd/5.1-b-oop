#pragma once
#include <iostream>
#include <string>
using namespace std;
class NewException
{
	string message;
	public:
		NewException(string message): message(message) {}
		string What() { return message; }
};