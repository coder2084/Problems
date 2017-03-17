#pragma once

#include "headers.h"

#pragma warning(disable:4267)

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

struct Node
{
	Node(int v) : val(v) {}
	int val;
	unique_ptr<Node> left;
	unique_ptr<Node> right;
};

ostream& operator<<(ostream& os, const vector<int>& v)
{
	for (auto&& elem : v)
	{
		os << elem << "  ";
	}
	return os;
}

ostream& operator<<(ostream& os, const vector<const string*>& v)
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

ostream& operator<<(ostream& os, const vector<vector<int>>& v)
{
	cout << std::endl << '[' << std::endl;
	for (auto& sv : v)
	{
		cout << '[';
		for (auto& e : sv)
		{
			cout << e << " ";
		}

		cout << ']' << endl;
	}

	cout <<  ']' << std::endl;

	return os;
}

ostream& operator<<(ostream& os, const vector<string>& v)
{
	
	for (auto& sv : v)
	{
		cout << '[' << sv << "] ";
		
	}

	cout << std::endl;

	return os;
}
