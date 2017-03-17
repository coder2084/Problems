#pragma once
#include "solution.h"

//Given a binary tree, sum all the root to leaf nodes and return the sum.
/*Ex:
		 1
	   /	\
	  2      3
	 / \       \
    4   6       7

here ans : 124 + 126 + 137 = 387
*/
class SumRootToLeaf : public Solution
{
private:
	int Solve(Node* root,int n)
	{
		if (!root)
			return 0;
	
		n = n * 10 + root->val;

		if (!root->left  && !root->right)
			return n;

		return Solve(root->left.get(),n) + Solve(root->right.get(),n);
	}

public:
	void Test()
	{
		unique_ptr<Node> root(new Node(1));
		root->left = make_unique<Node>(2);
		root->right = make_unique<Node>(3);
		root->left->left = make_unique<Node>(4);
		root->left->right = make_unique<Node>(6);

		root->right->right = make_unique<Node>(7);

		cout << "Sum root to leaf nodes is " << Solve(root.get(),0) << endl;
	}
};
