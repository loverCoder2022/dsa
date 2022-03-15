#include <bits/stdc++.h>
using namespace std;
#include "add_edges.h"

void topo_sort(int node , vector<bool> &visited , vector<int> adj[] , stack<int> &s)
{
	visited[node] = true;

	for (auto it : adj[node])
	{
		if (!visited[it])
			topo_sort(it, visited, adj, s);
	}

	s.push(node);
}
int main(int argc, char const *argv[])
{
	int edge, vertex;
	cin >> vertex >> edge;
	vector<int> adj[vertex];
	vector<bool> visited(vertex, false);
	stack<int> s;
	add_edge(edge, adj);

	for (int i = 0; i < vertex; ++i)
	{
		if (!visited[i])
		{
			topo_sort(i, visited, adj, s);
		}
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}