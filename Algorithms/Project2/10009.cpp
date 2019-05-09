	#include <bits/stdc++.h>

	using namespace std;
	enum class Color{white,red,black};

	void solve(const string& start, const string& dest,map <string, vector<string>>& g)
	{
		std::map<string, int> dist;
		std::map<string, Color> state;
		std::map<string, string> pred;

		for(auto& p : g)
		{
			dist[p.first]  = -1;
			state[p.first] = Color::white;
			pred[p.first]  = "";
		}
		queue<string> q;
		q.push(start);
		dist[start] = 0;
		state[start] = Color::red;
		while(!q.empty())
		{
			string v = q.front();
			q.pop();
			state[v] = Color::black;
			for(string& u : g[v])
			{
				if(state[u] == Color::white)
				{
					q.push(u);
					dist[u] = dist[v] + 1;
					state[u] = Color::red;
					pred[u] = v;
				}
			}
		}

		vector<string> path;
		path.push_back(dest);
		
		while(dist[path.back()] > 0)
		{
			
			path.push_back(pred[path.back()]	);
			
		}
		reverse(path.begin(), path.end());



		for(int i = 0; i < path.size();i++)
		{
			cout << path[i][0];
		}
		cout << "\n";
	}
	int main()
	{
		int t;

		cin >> t;
		for(int k = 0;k < t;k++)
		{

			map <string, vector<string>> g;
			int n, m; cin >> n; cin >> m;
			for(int i = 0;i < n;i++)
			{
				string v,u;
				cin >> v >> u;
				g[v].push_back(u);
				g[u].push_back(v);	
			}
			string start,dest;
			for(int i = 0;i < m;i++)
			{
				
				cin >> start >> dest;
				solve(start,dest,g);
			}	
			cout << ((k != t - 1) ? "\n" : "");

		}
	}