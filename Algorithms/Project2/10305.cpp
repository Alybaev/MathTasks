#include <bits/stdc++.h>

using namespace std;
void dfs(vector<vector<int>>& g, std::vector<int>& visited,int u,vector<int>& res)
{
	visited[u] = 1;
	

	for(int i = 0; i < g[u].size();i++)
	{

		if(not visited[g[u][i]])
		{
			dfs(g,visited,g[u][i],res);
		}
	}
	res.push_back(u);
}
int main()
{
	int n,m;
	while(cin >> n >> m and (n != 0 or m != 0))
	{	

		int before;
		int task;
		vector<vector<int> > g(n);
		for(int i = 0;i < m;i++)
		{
			cin >> before >> task;
			g[before - 1].push_back(task - 1);

		}

		vector<int> visited(n, 0);
		vector<int> res;
		for(int i = 0;i < n;i++)
		{

			if(not visited[i])
			{
				dfs(g,visited, i,res);
			}
			
		}
		reverse(res.begin(),res.end());

		for(int i = 0;i < res.size();i++)
		{
			cout <<  res[i] + 1<< ((i !=  res.size() - 1) ?  " " : "");
		}
		cout << "\n";
	}
}