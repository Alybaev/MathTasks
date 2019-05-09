#include <bits/stdc++.h>
using namespace std;
enum class Color {white,red,black};
int main()
{
	
	int n;
	int testcase = 0;
	while(cin >> n and n != 0)
	{
		map<int, vector<int>> g;
		for(int t = 0;t < n;t++)
		{
			int u,v;
			cin >> v >> u;
			g[v].push_back(u);
			g[u].push_back(v);

		}
		int start, ttl;
		while(cin >> start >> ttl and (start != 0 or ttl != 0))
		{
			testcase++;
			map<int,int> dist;
			set<int> visited;
			map<int, Color> state;
			for(auto& p: g)
			{
				dist[p.first] = -1;
				
				state[p.first] = Color::white;
			}
			dist[start] = 0;
			state[start] = Color::red;
			queue<int> q;
			q.push(start);
			while(!q.empty())
			{
				int v = q.front();
				if(g.find(v) != g.end() and dist[v] <= ttl)
				{
					visited.insert(v);
				}else{
					break;
				}
				q.pop();
				state[v] = Color::black;
				for(int& u: g[v] )
				{
					if(state[u] == Color::white)
					{
						q.push(u);
						state[u] = Color::red;
						dist[u] = dist[v] + 1;

						
					}
					

				}
			}
			
			cout  << "Case " << testcase << ": " << g.size() - visited.size() <<" nodes not reachable from node " << start <<" with TTL = " << ttl <<".\n";



		}
		

	}
	return 0;

}