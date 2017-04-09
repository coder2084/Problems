#pragma once
#include "Solution.h"
class Kruskal :public Solution
{
private:

	struct Graph 
	{ 
		int V; vector<Edge> edges;  
		void createGraph(int v, int e)
		{
			V = v;
			edges.resize(e);
		}

		void SortEdges()
		{
			sort(edges.begin(), edges.end(), [](auto& a, auto& b) { return a.weight < b.weight; });
		}
	};

	struct Subset {	int parent, rank; };

	int find(vector<Subset>& subsets, int i)
	{
		// find root and make root as parent of i (path compression)
		if (subsets[i].parent != i)
			subsets[i].parent = find(subsets, subsets[i].parent);

		return subsets[i].parent;
	}

	void Union(vector<Subset>& subsets, int x, int y)
	{
		int xroot = find(subsets, x);
		int yroot = find(subsets, y);

		// Attach smaller rank tree under root of high rank tree
		// (Union by Rank)
		if (subsets[xroot].rank < subsets[yroot].rank)
			subsets[xroot].parent = yroot;
		else if (subsets[xroot].rank > subsets[yroot].rank)
			subsets[yroot].parent = xroot;

		// If ranks are same, then make one as root and increment
		// its rank by one
		else
		{
			subsets[yroot].parent = xroot;
			subsets[xroot].rank++;
		}
	}

	vector<Edge> KruskalMST(Graph* graph)
	{
		int V = graph->V;
		vector<Edge> result(V-1);
		int e = 0;
		int i = 0;

		graph->SortEdges();
		vector<Subset> subsets(V);
		for (int v = 0; v < V; ++v) { subsets[v].parent = v, subsets[v].rank = 0; }

		while (e < V - 1)
		{
			Edge nextEdge = graph->edges[i++];

			int x = find(subsets, nextEdge.src);
			int y = find(subsets, nextEdge.dest);
			if (x != y)
			{
				result[e++] = nextEdge;
				Union(subsets, x, y);
			}
		}

		return result;
	}

public:
	void Test()
	{
		/*		10
			0--------1
			|  \     |
		   6|  5\    | 15
			|     \  |
			2--------3
		*/
		Graph g;
		g.createGraph(4, 5);
		// add edge 0-1
		g.edges[0].src = 0;
		g.edges[0].dest = 1;
		g.edges[0].weight = 10;
		
			// ad.edge 0-2
		g.edges[1].src = 0;
		g.edges[1].dest = 2;
		g.edges[1].weight = 6;
		
			// ad.edge 0-3
		g.edges[2].src = 0;
		g.edges[2].dest = 3;
		g.edges[2].weight = 5;
	
			// ad.edge 1-3
		g.edges[3].src = 1;
		g.edges[3].dest = 3;
		g.edges[3].weight = 15;
		
			// ad.edge 2-3
		g.edges[4].src = 2;
		g.edges[4].dest = 3;
		g.edges[4].weight = 4;

		cout << "Solution for Kruskal: \n" << KruskalMST(&g)<< endl;
	}

};