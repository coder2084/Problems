#pragma once
#include "Solution.h"

//Find next greater number with same set of digits
//Given a number n, find the smallest number that has same set of digits as n and is greater than n.
//If x is the greatest possible number with its set of digits, then print “not possible”.
//Input:  n = "218765"
//Output : "251678"

class NextPermuation: public Solution
{
public:
	string findNextPermuation(string nums)
	{
		int k = -1;
		for ( int i = nums.size() - 2; i > 0; i--)
		{
			if (nums[i] < nums[i + 1])
			{
				k = i;
				break;
			}
		}

		if (k == -1)
		{
			reverse(nums.begin(), nums.end());
			return nums;
		}

		int minIndex = -1;
		for (int j = nums.size() - 1; j > k; j--)
			if (nums[j] > nums[k])
				minIndex = j;


		swap(nums[k], nums[minIndex]);
		reverse(nums.begin() + k + 1, nums.end());

		return nums;
	}

public:
	void Test()
	{
		string test = "534976";
		//string test = "123456";

		cout << "Solution for Next greater number with same set of digits for " << test << ": " << findNextPermuation(test) << endl;
	}
};