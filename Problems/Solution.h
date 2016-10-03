#pragma once

#include "headers.h"

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
	return os;
}

ostream& operator<<(ostream& os, const ListNode* n)
{

	while (n != nullptr)
	{
		os << n->val;
		n = n->next;
		if (n != nullptr)
			os << "->";
	}

	return os;
}
