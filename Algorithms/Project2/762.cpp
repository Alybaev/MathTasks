#include <bits/stdc++.h>

using namespace std;
enum class Color{white,red,black};
int main()
{
	int t;
	bool first = true;
	while(cin >> t)
	{

		map <string, vector<string>> g;
		cout << ((first) ? "" : "\n");
		first = false;
		for(int k = 0;k < t;k++)
		{
			string v,u;
			cin >> v >> u;
			g[v].push_back(u);
			g[u].push_back(v);	
		}
		string start,dest;
		cin >> start >> dest;
		bool hasPath = true;
		vector<string> path;

		path.push_back(dest);
		if(g.find(start) != g.end() and g.find(dest) != g.end())
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
			if(dist[dest] == -1)
			{
				hasPath = false;
			}
			while(dist[path.back()] > 0)
			{
				
				path.push_back(pred[path.back()]	);
				
			}
			reverse(path.begin(), path.end());
		}else{
			hasPath = false;
		}

		if(hasPath)
		{
			for(int i = 1; i < path.size();i++)
			{
				cout <<path[i - 1] << " " <<  path[i] << "\n";
			}

		}else{
			cout << "No route\n";
		}



	}
}