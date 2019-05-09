#include <bits/stdc++.h>
using namespace std;
void dfs(const vector<vector<int>>& g, vector<int>& visited, int u)
{
	visited[u] = 1;
	for(int i = 0;i < g[u].size();i++)
	{
		if(not visited[g[u][i]])
		{
			dfs(g,visited,g[u][i]);
		}
		
	}
}

int main()
{
	
	int N;
	cin >> N;
	for(int t = 0;t < N;t++)
	{
		
	
		int n, e, h;
		cin >> n >> e >> h;

		vector<vector<int>> g(n);
		vector<int> visited(n, 0);
		for(int i = 0; i < e;i++)
		{
			int v, u;
			cin >> v >> u;
			g[v - 1].push_back(u - 1);
		}
		for(int i = 0;i < h;i++)
		{
			int u;cin >> u;
			if(not visited[u - 1])
			{
				dfs(g,visited, u - 1);
			}
			
		}
		cout << count(visited.begin(), visited.end(), 1) << "\n";
		
	}
	return 0;


}