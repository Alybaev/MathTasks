#include <bits/stdc++.h>

using namespace std;
struct Edge{
	int u;

	int w;
	Edge(int aU,int aW)
	:u(aU),w(aW)
	{

	}
};

int main()
{
	 iostream::sync_with_stdio(false);
	int t;cin >> t;
	for(int k = 1; k <= t;k++)
	{
		int n, m, start, dest;
		cin >> n >> m >> start >> dest;
		vector<vector<Edge>> g(n);

		for(int i = 0;i < m;i++)
		{

			int v, u, w;
			cin >> v >> u >> w; 
			g[v].emplace_back(u,w);
			g[u].emplace_back(v,w);

		}

		vector<int> d(n, -1);
		vector<int> vis(n, false);

		std::vector<pair<int,int>> pq;
		auto cmp = greater<pair<int,int>>();

		d[start] = 0;
		pq.emplace_back(d[start], start);

		while(!pq.empty())
		{
			int v = pq.front().second;
			pop_heap(begin(pq),end(pq),cmp);
			pq.pop_back();
			if(vis[v])
				continue;
			vis[v] = true;
			for(auto& e : g[v])
			{
				if(!vis[e.u] and (d[e.u] == -1 ||   d[v] + e.w  < d[e.u]))
				{
					d[e.u] = d[v] + e.w;
				 	
				 	pq.emplace_back(d[e.u], e.u);
				 	push_heap(begin(pq),end(pq),cmp);



				}
			}

		}
		cout << "Case #" << k << ": " << ((d[dest] == -1) ? "unreachable" : to_string(d[dest]) ) << "\n";
			




	}

	return 0;
	
}
