#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int u;
	double w;
	Edge(int aU,double aW)
	:u(aU),w(aW)
	{

	}
};
double getDist(double x1,double y1,double x2, double y2)
{
	double dist = 0;
	if(x1 == x2){
		dist = abs(y2 - y1);
	}else if(y1 == y2){
		dist = abs(x2 - x1);
	}else{
		dist = sqrt(abs(x2 - x1) * abs(x2 - x1) + abs(y2 - y1) * abs(y2 - y1));
	}
	
	return dist;
}
int main()
{
	iostream::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n; cin >> n;
		std::vector<std::vector<Edge> > g(n);
		std::vector<pair<double,double>> coords;
		for(int i = 0; i < n;i++)
		{	
			double x, y; cin >> x >> y;
			coords.emplace_back(x,y);
		}
		for(int i = 0;i < n;i++)
		{
			for(int j = i + 1;j < n;j++)
			{
				double dist = getDist(coords[i].first, coords[i].second,coords[j].first, coords[j].second);
				g[i].emplace_back(j,dist);
				g[j].emplace_back(i,dist);

			}
		}
		std::vector<double> d(n,-1);
		std::vector<int> vis(n,false);
		
		std::vector<pair<double,int>> pq;
		auto cmp = greater<pair<double,int>>();
		d[0] = 0;
		
		for(auto& e: g[0])
		{
			d[e.u] = e.w;
			pq.emplace_back(d[e.u], e.u);
			push_heap(begin(pq),end(pq),cmp);
			
		}
		
		double minSum = 0.0;
		while(!pq.empty())
		{
			int v = pq.front().second;
			pop_heap(begin(pq),end(pq),cmp);
			pq.pop_back();
			

			if(vis[v])continue;
		
			minSum += d[v];
			vis[v] = true;
			for(auto& e: g[v])
			{
				if(!vis[e.u] and (d[e.u] == -1 or d[e.u] > e.w))
				{
					d[e.u] = e.w;
					pq.emplace_back(d[e.u], e.u);
					push_heap(begin(pq),end(pq),cmp);
				}
			}

		}
		cout << fixed << setprecision(2) <<minSum << "\n" ;
		cout << ((t != 0) ? "\n" : "");

	}
}