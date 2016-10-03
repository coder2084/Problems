#pragma once
#include "solution.h"

class TwoSum : public Solution
{
	private:
		vector<int> twoSum(vector<int>& nums, int target)
		{
			set<int> s;
			vector<int> sol;
			for (size_t i = 0; i < nums.size(); ++i)
			{
				int r = target - nums[i];
				if (s.find(r) != s.end())
				{

					size_t k = 0;
					for (; k < nums.size(); ++k)
						if (nums[k] == r)
							break;
					sol.push_back(min(k, i));
					sol.push_back(max(i, k));
				}
				else
				{
					s.insert(nums[i]);
				}
			}

			return sol;
		}

	public:
		void Test()
		{
			vector<int> test = { 4,5,11,3,23,12,7,2,123 };
			int testNumber = 9;
			cout << "Two Sum solution for " << testNumber << " :" << twoSum(test, testNumber);
		}
};
