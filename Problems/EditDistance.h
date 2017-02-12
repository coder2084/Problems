#pragma once
#include "Solution.h"
/*
Given two strings, s1 and s2 and edit oper­a­tions (given below). 
Write an algorithm to find min­i­mum number oper­a­tions required to convert string s1 into s2.
*/

class EditDistance : public Solution
{
private:
	int Solve(string s1,  string s2, int m, int n)
	{
		if (n == 0) return m;

		if (m == 0) return n;
	
		if (s1[m-1] == s2[n-1]) return Solve(s1, s2, m - 1, n - 1);

		return 1 + std::min<int>(Solve(s1, s2, m - 1, n), 
				                 std::min<int>(Solve(s1, s2, m, n - 1), 
									           Solve(s1, s2, m - 1, n - 1)));
	}

	int SolveDynamic(string s1, string s2, int m, int n)
	{
		vector<vector<int>> d(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < m + 1; i++)
		{
			for (int j = 0; j < n + 1; j++)
			{
				if (i == 0)
					d[i][j] = j;
				else if (j == 0)
					d[i][j] = i;
				else if (s1[i-1] == s2[j-1])
					d[i][j] = d[i - 1][j - 1];
				else
					d[i][j] = 1 + std::min<int>(d[i][j - 1], std::min<int>(d[i - 1][j - 1], d[i - 1][j]));
			}		
		}

		return d[m][n];
	}
public:
	void Test()
	{
		string s1 = "sundaymorning";
		string s2 = "saturdaymarning";

		cout << "Edit distance recursive: " << Solve(s1, s2, s1.length(), s2.length()) << endl; 

		cout << "Edit distance dynamic : " << SolveDynamic(s1,s2, s1.length(), s2.length()) << endl;
	}
};
