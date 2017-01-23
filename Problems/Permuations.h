#pragma once
/*Given a collection of distinct numbers, return all possible permutations.

[1,2,3] have the following permutations:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/

class Permutations : public Solution
{
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> r;

		permute(nums, 0, r); 

		return r;
	}
private:
	void permute(vector<int>& nums, int k, vector<vector<int>>& r)
	{
		if ((size_t)k >= nums.size())
		{
			r.push_back(nums);
		}

		for (size_t i = k; i < nums.size(); i++)
		{
			swap(nums[i], nums[k]);
			permute(nums, k+1, r);
			swap(nums[i], nums[k]);
		}
	}

public:
	void Test()
	{
		vector<int> test = { 1,2,3 };
		cout << "Solution for permutations for " << test << ": " << permute(test) << endl;
	}
};