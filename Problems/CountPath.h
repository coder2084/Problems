#pragma once
#include "Solution.h"
/*
Count all the paths from left top corner to right bottom corner in two dimensional array.
*/

class CountPath : public Solution
{
private:
	int m, n;
	vector<vector<int>> arr;

	int Solve( int cm, int cn)
	{
		if (m == cm+1)
			return 1;
		if (n == cn+1)
			return 1;

		return Solve(cm + 1, cn + 1) + Solve(cm,cn+1) + Solve(cm+1,cn);
	}

	int SolveDynamic(int m, int n)
	{
		vector<vector<int>> d(m, vector<int>(n, 0));

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (i == 0 || j == 0)
					d[i][j] = 1;
				else
					d[i][j] = d[i - 1][j - 1] + d[i - 1][j] + d[i][j - 1];

		return d[m-1][n-1];
	}

	void printPath(int currentRow, int currentColumn, string path)
	{
		if (currentRow == m - 1)
		{
			for (int i = currentColumn; i < n; i++)
			{
				path.append("-");
				path.append(to_string(arr[currentRow][i]));
			}
			cout << path << endl;
			return;
		}

		if (currentColumn == n - 1)
		{
			for (int i = currentRow; i < m; ++i)
			{
				path.append("-");
				path.append(to_string(arr[i][currentColumn]));
			}
			cout << path << endl;
			return;
		}

		path.append("-"); 
		path.append(to_string(arr[currentRow][currentColumn]));

		printPath(currentRow + 1, currentColumn, path);
		printPath(currentRow, currentColumn + 1, path);
	}

public:
	void Test()
	{
		m = 3, n = 3;
		arr = { {1, 2, 3}, { 4,5,6 }, { 7,8,9 }};

		cout << "CountPath recursive: " << Solve(0,0) << endl;
		
		cout << "CountPath dynamic : " << SolveDynamic(m,n) << endl;

		//string path("");
		//printPath(0, 0, path);
	}
};
