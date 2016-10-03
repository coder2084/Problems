#pragma once

#include "headers.h"

class Solution
{
public:
	virtual void Test() = 0;

};

ostream& operator<<(ostream& os, const vector<int>& v)
{
	for (auto&& elem : v)
	{
		os << elem << "  ";
	}

	os << endl;

	return os;
}