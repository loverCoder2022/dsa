#include <bits/stdc++.h>
using namespace std;
#include "add_edges.h"

void DFS(int s , vector<int> adj[], int v)
{
	vector<int> distance(v, INT_MAX);
	queue<int> q;
	q.push(s);
	distance[s] = 0;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (auto it = adj[node].begin(); it != adj[node].end(); ++it)
		{
			if (distance[node] + 1 < distance[*it] )
			{
				distance[*it] = distance[node] + 1;
				q.push(*it);
			}

		}
	}

	for (auto x : distance)
	{
		cout << x << " ";
	}
}
int main(int argc, char const *argv[])
{
	int edge, vertex;
	cin >> vertex >> edge;
	vector<int> adj[vertex];
	add_edge(edge, adj);


	DFS(0, adj , vertex);;


	return 0;
}