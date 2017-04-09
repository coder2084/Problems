#pragma once
#include "Solution.h"
/*
Given a binary tree, return all root - to - leaf paths.

For example, given the following binary tree :
1
/   \
2     3
\
5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

class BinaryTreePaths : public Solution
{
private:

	vector<string> binaryTreePaths(Node* root)
	{
		vector<string> v;
		string s;
		if (root != nullptr)
			binaryTreePaths(root, v, s);

		return v;
	}

	void binaryTreePaths(Node* root, vector<string>& v, string& s)
	{
		string tmp = s;
		s += to_string(root->val);

		if (root->left == nullptr && root->right == nullptr)
		{
			v.push_back(s);
			return;
		}
		s.append("->");

		if (root->left)
		{
			binaryTreePaths(root->left.get(), v, s);
			s = tmp;
		}
		if (root->right)
		{
			binaryTreePaths(root->right.get(), v, s);
			s = tmp;
		}
	}

	void AlternativeSol(Node* root, vector<string>& vs, string s)
	{
		if (root == nullptr) return;

		if (root->left == nullptr && root->right == nullptr)
		{
			vs.push_back(s + to_string(root->val));
			return;
		}		

		AlternativeSol(root->left.get(), vs, s + to_string(root->val)+"->");
		AlternativeSol(root->right.get(), vs, s + to_string(root->val)+"->");
	}
		
public:
	void Test()
	{
		unique_ptr<Node> root(new Node(1));
		root->left = make_unique<Node>(2);
		root->right = make_unique<Node>(3);
		root->left->right = make_unique<Node>(5);
		cout << "Binary tree paths: " << binaryTreePaths(root.get()) << endl;;
	}
};
