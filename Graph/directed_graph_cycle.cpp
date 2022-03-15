#include <bits/stdc++.h>
using namespace std;
#include "add_edges.h"

bool checkCycle(int s, vector<bool> & visit, vector<int> adj[])
{
	queue<pair<int, int>> q;
	q.push({s, -1});
	visit[s] = true;

	while (!q.empty())
	{
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		for (auto &x : adj[node])
		{
			if (visit[x] == false)
			{
				visit[x] = true;
				q.push({x, node});

			}
			else if (parent != x)
				return true;
		}
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
			if (!checkCycle(i, visit, adj))
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