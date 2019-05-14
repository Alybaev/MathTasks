#include <bits/stdc++.h>

using namespace std;


bool inRange(int row, int col,int n, int m)
{
	return row < n and row >= 0 and col < m and col >= 0;
}
int main()
{
	iostream::sync_with_stdio(false);
	int t;
	cin >> t;
	const std::vector<int> dr = {1, 0, -1, 0};
	const std::vector<int> dc = {0, 1, 0, -1};

	while(t--)
	{
		int n,m;cin >> n >> m;
		std::vector<std::vector<int> > g(n,std::vector<int>(m));
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < m;j++)
			{
				cin >> g[i][j];
			}
		}
		std::vector<int> d(n * m, -1);
		std::vector<int> vis(n * m, false);

		std::vector<pair<int,int>> pq;
		pq.emplace_back(g[0][0],0);
		d[0] = g[0][0];
		auto cmp = greater<pair<int,int>>();

		while(!pq.empty())
		{
			int v = pq.front().second;
			pop_heap(begin(pq),end(pq),cmp);
			pq.pop_back();
			

			if(vis[v])continue;
			vis[v] = true;
			int row = v / m;
			int col = v % m;

			for(int i = 0;i < 4;i++)
			{
				int rowU = row + dr[i]; 
				int colU = col + dc[i]; 
				int u = rowU * m + colU;
				if(inRange(rowU, colU,n,m) and (!vis[u] and ( d[u] == -1 or g[rowU][colU] + d[v] < d[u])))
				{
					d[u] = g[rowU][colU] + d[v];
					pq.emplace_back(d[u], u );
					push_heap(begin(pq),end(pq),cmp);
				}
			}

		}
		cout << d[d.size() - 1] << "\n";




	}
}