#pragma once
#include "Solution.h"

class BinaryTreePaths : public Solution
{
private:
	struct TreeNode
	{
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	}

	vector<string> binaryTreePaths(TreeNode* root)
	{
		vector<string> v;
		string s;
		if (root != nullptr)
			binaryTreePaths(root, v, s);

		return v;
	}

	void binaryTreePaths(TreeNode* root, vector<string>& v, string& s)
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
			binaryTreePaths(root->left, v, s);
			s = tmp;
		}
		if (root->right)
		{
			binaryTreePaths(root->right, v, s);
			s = tmp;
		}
		
public:
	void Test()
	{
		vector<int> test = { 4,5,11,3,23,12,7,2,123 };
		int testNumber = 9;
		cout << "Two Sum solution for [" << test << "] and S=" << testNumber << ": " << twoSum(test, testNumber) << endl;;
	}
};