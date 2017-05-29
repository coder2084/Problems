#pragma once
#include "Solution.h"
/*
Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once. 
A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian Path such that there is an edge (in graph) 
from the last vertex to the first vertex of the Hamiltonian Path. Determine whether a given graph contains Hamiltonian Cycle or not.
If it contains, then print the path. Following are the input and output of the required function.
*/

class Hamiltonian : public Solution
{
private:
	vector<int> solve(vector<vector<int>>& g)
	{
		vector<int> path(g.size()+1,0);

		if (!back(g, path, 1))
			cout << "No solution found";

		return path;
	}

	bool back(vector<vector<int>>& g, vector<int>& path, int pos)
	{
		if (pos == g.size())
		{
			if (g[path[pos - 1]][path[0]] == 1) // there is and edge from last included vertex to the first one
				return true;
			return false;
		}

		for (int v = 1; v < g.size();++v)
		{
			if (isSafe(g, v, path,pos))
			{
				path[pos] = v;
				if (back(g, path, pos + 1)) return true;

				path[pos] = -1;
			}
		}
		return false;
	}

	bool isSafe(vector < vector<int>>& g, int v, vector<int>& path, int pos)
	{
		if (g[path[pos - 1]][v] == 0) return false;

		if (count(path.begin(), path.end(), v) > 0) return false;

		return true;

	}

public:
	void Test()
	{
		vector<vector<int>> g = {
								 { 0, 1, 0, 1, 0 },
								 { 1, 0, 1, 1, 1 },
								 { 0, 1, 0, 0, 1 },
								 { 1, 1, 0, 0, 1 },
								 { 0, 1, 1, 1, 0 },
								};
		
		cout << "Hamiltonian path is : " << solve(g) << endl;

	}


};