#include <bits/stdc++.h>
using namespace std;
void add_edge(int e, vector<int> ad[])
{
	while (e--)
	{
		int u, v;
		cin >> u >> v;
		ad[u].push_back(v);
		ad[v].push_back(u);

	}
}
void dfs(int source, vector<int>ad[], vector<bool>& visit)
{
	visit[source] = true;
	cout << "\n" << source;
	for (auto it = ad[source].begin(); it != ad[source].end(); ++it)
	{
		if (visit[*it] == false)
			dfs(*it, ad, visit);
	}
}
void bfs(int source, vector<int> ad[], vector<bool>& visit)
{
	queue<int> q;
	q.push(source);
	visit[source] = true;
	while (!q.empty())
	{
		int e = q.front();
		q.pop();
		cout << e << " ";
		for (auto x = ad[e].begin(); x != ad[e].end(); ++x)
		{
			if (visit[*x] == false)
			{
				q.push(*x);
				visit[*x] = true;
			}
		}
	}

}

int main()
{
	int edge, vertex;
	cin >> vertex >> edge;
	vector<int> ad[vertex];
	vector<bool> visit(vertex, false);
	add_edge(edge, ad);
	int components = 0;
	for (int i = 0; i < vertex; ++i)
	{
		if (visit[i] == false)
		{
			components++;
			bfs(i, ad, visit);
			//dfs(i, ad, visit);
		}

	}

	cout << "\nno of components in the graph : " << components;

	return 0;
}
