#pragma once
#include "../Solution.h"

class Graph
{
public:
	Graph(int numVertives) { mAdjList.resize(numVertives); }
	~Graph() {}

	void addEdgeU(int src, int dest)
	{
		mAdjList[src].push_back(dest);
		mAdjList[dest].push_back(src);
	}

	void addEdgeD(int src, int dest)
	{
		mAdjList[src].push_back(dest);
	}

	void clear()
	{
		mAdjList.clear();
	}


	void print()
	{
		for (size_t i = 0; i < mAdjList.size(); ++i)
		{
			cout << i;

			auto elem = mAdjList.at(i).begin();
			while (elem != mAdjList.at(i).end())
			{
				cout << " - > " << *elem;
				elem++;
			}
			cout << endl;
		}
	}

	void bfs(int node = -1)
	{
		queue<int> q;
		vector<bool> visited(mAdjList.size());
		for (size_t i = 0; i < visited.size(); ++i)
			visited[i] = false;

		if (node == -1)
			node = 0;

		q.push(node);
		visited[node] = true;
		while (q.empty() == false)
		{
			int node = q.front();
			q.pop();
			cout << node << " ";
			auto connections = mAdjList[node];
			for (auto elem : connections)
			{
				if (visited[elem] == false)
				{
					visited[elem] = true;
					q.push(elem);
				}
			}
		}

		cout << endl;
	}

	void dfsRecursive(int node = -1)
	{
		if (node == -1) node = 0;

		cout << "DFS recursive : " << endl;

		vector<bool> visited(mAdjList.size(),false);

		dfsUtil(node, visited);

		cout << endl;
	}

	void topologicalSort()
	{
		vector<bool> visited(mAdjList.size(),false);

		cout << "Topological sort: " << endl;

		stack<int> s;
		for (size_t i = 0; i < mAdjList.size();++i)
		{
			if (visited[i] == false)
			{
				topologicalSortUtil(i, visited, s);
			}
		}

		while (s.empty() == false)
		{
			cout << s.top() << " ";
			s.pop();
		}

		cout << endl;
	}

	void KhanTopologicalSort()
	{
		cout << "Topological sort using Khan Algorithm. Simulate package loading in parallel: " << endl;
		//compute indegrees
		vector<int> indegree(mAdjList.size(), 0);

		for (auto nodes : mAdjList)
			for (auto dest : nodes)
				indegree[dest]++;

		queue<int> q;
		for (size_t i = 0; i < mAdjList.size(); ++i)
			if (indegree[i] == 0)
				q.push(i);

		int level = 0;
		unordered_map<int, queue<int>> sameOrder;
		sameOrder[level] = q;

		vector<int> v;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			v.push_back(u);

			for (auto elem : mAdjList[u])
				if (--indegree[elem] == 0)
				{
					q.push(elem);
					sameOrder[level+1].push(elem);
				}

			level++;
		}

		if (level != mAdjList.size())
		{
			cout << "We have a cycle in the graph" << endl;
			return;
		}

		for (auto level : sameOrder)
		{			
			while (level.second.empty() == false)
			{
				cout << level.second.front()<< " ";
				level.second.pop();
			}
			cout << endl;
		}
	
	}

private:
	void dfsUtil(int i, vector<bool>& visited)
	{
		visited[i] = true;
		cout << i << " ";
		for (auto elem : mAdjList[i])
			if (!visited[elem])
				dfsUtil(elem, visited);
	}

	void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& s)
	{
		visited[v] = true;

		for (auto elem : mAdjList[v])
			if (!visited[elem])
				topologicalSortUtil(elem, visited, s);

		s.push(v);
	}

private:
	vector<list<int>> mAdjList;

	
};