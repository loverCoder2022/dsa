#include <bits/stdc++.h>
using namespace std;
#include "add_edges.h"

bool dfs(int s, vector<int> & colors, vector<int> adj[])
{

	if (colors[s] == -1)
		colors[s] = 1;
	for (auto &x : adj[s])
	{
		if (colors[x] == -1)
		{
			colors[s] = 1 - colors[s];
			if (dfs(x, colors, adj))
				return false;

		}
		else if (colors[x] == colors[s])
			return false;
	}
	return true;
}
bool isBipartite(int v , vector<int> adj[])
{
	vector<int> colors(v, -1);
	for (int i = 0; i < v; ++i)
	{
		if (colors[i] == -1)
		{
			if (!dfs(i, colors, adj))
				return false;
		}
	}
	return true;
}
int main(int argc, char const *argv[])
{
	int edge, vertex;
	cin >> vertex >> edge;
	vector<int> adj[vertex];
	add_edge(edge, adj);


	if (!isBipartite(vertex, adj))
		cout << "NO";
	else
		cout << "YES";
	return 0;
}