#include <bits/stdc++.h>
using namespace std;
#include "add_edges.h"

void topo_sort(int v, vector<int> &indegree, vector<int> adj[])
{

	queue<int> q;
	for (int i = 0; i < v; ++i)
	{
		for (auto x : adj[i])
			indegree[x]++;

	}

	for (int i = 0; i < v; ++i)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int n = q.front();
		cout << n << " ";
		q.pop();
		for (auto it : adj[n])
		{
			indegree[it]--;
			if (indegree[it] == 0)
			{
				q.push(it);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int edge, vertex;
	cin >> vertex >> edge;
	vector<int> adj[vertex];
	vector<int> indegree(vertex, 0);
	add_edge(edge, adj);
	topo_sort(vertex, indegree, adj);


	return 0;
}