#pragma once
#include "solution.h"

class LowerBound : public Solution
{
private:
	int Solve(vector<int> v, int low , int high, int x) 
	{
		if (low > high)
			return -1;
		int mid = (low + high) / 2;
		if (v[mid] == x)
		{
			if (mid > 0 && v[mid - 1] == x)
				return Solve(v, low, mid - 1, x);
			return mid;
		}
		else if (v[mid] > x)
			return Solve(v, low, mid - 1, x);

		return Solve(v, mid + 1, high, x);
	}


public:
	void Test()
	{
		vector<int> test = { 1,2,3,4,4,4,4,5,6,7,8 };
		cout << "Lower Bound: " << Solve(test,0, test.size(),4) << endl;
	}
};
