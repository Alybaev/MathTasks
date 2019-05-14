#include <bits/stdc++.h>

using namespace std;
struct Edge
{
	
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
	int n,m;
	while(cin >> n >> m and (n != 0 or m != 0))
	{
		int total = 0;
		std::vector<std::vector<Edge>> g(n);
		for(int k = 0; k < m;k++)
		{
			int v,u,w;cin >> v >> u >> w;

			total += w;

			g[v].emplace_back(u,w);
			g[u].emplace_back(v,w);
		}
		std::vector<int> d(n,-1);
		std::vector<int> vis(n, false);

		int minSum = 0;
		std::vector<pair<int,int>> pq;

		
		vis[0] = true;
		d[0] = 0;
		auto cmp = greater<pair<int,int>>();
		for (auto& e: g[0])
		{
			d[e.u] = e.w;
			pq.emplace_back(d[e.u], e.u);
			push_heap(begin(pq),end(pq), cmp);
		}
		
		while(!pq.empty())
		{
			int v = pq.front().second;
			pq.pop_back();
			pop_heap(begin(pq),end(pq), cmp);
			
			

			if(vis[v])continue;

			vis[v] = true;
			minSum += d[v];
           
			for(auto& e: g[v])
			{
				if(!vis[e.u] and (d[e.u] == -1 or e.w < d[e.u]))
				{
					d[e.u] = e.w;
					pq.emplace_back(d[e.u], e.u);
					push_heap(begin(pq),end(pq), cmp);
				}
			}

		}
		
		cout << total - minSum << "\n";


	}
	

}