#pragma once
#include "Solution.h"
/*
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. 
For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
*/

class LIS : public Solution
{
private:
	int Solve(vector<int> v)
	{
		vector<int> lis;
		SolveRecursive(v, v.size(), lis);

		return lis.size();
	}

	vector<int> SolveRecursive(vector<int>& v, int n, vector<int> &maxSoFar)
	{
		if (n < 2) return vector<int>(1,v[0]);

		vector<int> currentLis(1,v[n-1]);
		for (int i = 0; i < n-1; i++)
		{
			vector<int> subLis = SolveRecursive(v, i, maxSoFar);

			
			if ((v[i] < v[n - 1] && currentLis.size() <= subLis.size()))
			{
				currentLis = subLis, currentLis.push_back(v[n-1]);
			}

			//cout << "LIS[" << n-1 << "]= " << currentLis << endl;
		}
		
		if (maxSoFar.size() < currentLis.size())
			maxSoFar = currentLis;
		return currentLis;
	}

	int SolveDynamic(vector<int>& arr)
	{
		vector<int> dp(arr.size(), 1);
		if (arr.size() < 2) return arr.size();

		int m = 1;
		for (int i = 1; i < arr.size(); ++i)
		{
			for (int j = 0; j < i;j++)
				if (arr[i] > arr[j])
				{
					dp[i] = std::max<int>(dp[i], dp[j] + 1);					
					m = std::max<int>(m, dp[i]);
				}
		}
		return m;
	}
public:
	void Test()
	{
		vector<int> v = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };

		cout << "Longest increasing subsequence : " << Solve(v) << endl;
		cout << "Longest increasing subsequence dynamic: " << SolveDynamic(v) << endl;
	}
};
