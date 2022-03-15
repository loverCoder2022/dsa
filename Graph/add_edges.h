void add_edge(int e, vector<int> ad[])
{
	while (e--)
	{
		int u, v;
		cin >> u >> v;
		ad[u].push_back(v);

		//ad[v].push_back(u);

	}
}