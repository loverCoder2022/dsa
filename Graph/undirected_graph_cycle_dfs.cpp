#include <bits/stdc++.h>
using namespace std;
#include "add_edges.h"

bool checkCycle(int node, int parent, vector<bool> & visit, vector<int> adj[])
{

	visit[node] = true;
	for (auto &x : adj[node])
	{
		if (visit[x] == false)
		{
			if (checkCycle(x, node, visit, adj))
				return true;

		}
		else if (parent != x)
			return true;
	}
	return false;
}
bool isCycle(int v , vector<int> adj[])
{
	vector<bool> visit(v, false);
	for (int i = 0; i < v; ++i)
	{
		if (visit[i] == false)
		{
			if (!checkCycle(i, -1, visit, adj))
				return false;
			else
				return true;
		}
	}
}
int main(int argc, char const *argv[])
{
	int edge, vertex;
	cin >> vertex >> edge;
	vector<int> adj[vertex];
	add_edge(edge, adj);


	if (!isCycle(vertex, adj))
		cout << "NO";
	else
		cout << "YES";
	return 0;
}