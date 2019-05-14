#include <bits/stdc++.h>

using namespace std;
struct Edge
{
	int v;
	int u;
	int w;
	Edge(int aV,int aU,int aW)
	:v(aV),u(aU),w(aW)
	{

	}
};
int main()
{
	iostream::sync_with_stdio(false);
	int t;cin >> t;
	while(t--)
	{
		int n; int m;
		cin >> n >> m;
		std::vector<Edge> edges;
	
		for(int i = 0;i < m;i++)
		{

			int x,y,w;
			cin >> x >> y >> w;
			edges.emplace_back(x,y,w);
		
		

		}
		
	
		std::vector<int> t(n, false);
		std::vector<int> d(n);
		t[0] = true;
		d[0] = 0;
		for(int i = 1;i < n;i++)
		{
			for(auto& e: edges)
			{
				if(t[e.v] and !t[e.u])
				{
					d[e.u] = d[e.v] + e.w;
					t[e.u] = true;
				
				}else if(t[e.v] and t[e.u] and d[e.v] + e.w < d[e.u])
				{
					d[e.u] = d[e.v] + e.w;
					t[e.u] = true;
				}
			}
		}	
		bool inf = false;
		for(auto& e: edges)
		{
			if(t[e.v] and !t[e.u])
			{
				inf = true;
				break;
			
			}else if(t[e.v] and t[e.u] and d[e.v] + e.w < d[e.u])
			{
				inf = true;
				break;
			}
		}
		cout << ((inf) ? "possible" : "not possible") << "\n";
	}
	return 0;
}