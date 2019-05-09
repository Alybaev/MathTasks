// Accepted

#include <bits/stdc++.h>

using namespace std;

const int unknown = -1;

struct Edge
{
    int v;
    int w;
    Edge(int aV, int aW)
        : v(aV), w(aW)
    {
    }
};

int main()
{
    iostream::sync_with_stdio(false);
    
    int nCases; cin >> nCases;
    int cCase = 0;
    while (nCases-- > 0)
    {
        int n; cin >> n;
        int m; cin >> m;
        int s; cin >> s;
        int d; cin >> d;
        
        vector<vector<Edge>> graph(n);
        
        for (int i = 0; i < m; ++i)
        {
            int u; cin >> u;
            int v; cin >> v;
            int w; cin >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        
        vector<int> tree(n, false);
        vector<int> dist(n, unknown);
        
        dist[s] = 0;
        vector<pair<int, int>> pq = {{0, s}};
        
        auto cmp = greater<pair<int, int>>();
        while (!pq.empty())
        {
            int u = pq.front().second;
            pop_heap(begin(pq), end(pq), cmp);
            pq.pop_back();
            
            if (tree[u]) continue;
            
            tree[u] = true;
            for (const auto& e: graph[u])
            {
                if (!tree[e.v] && (dist[e.v] == unknown || dist[e.v] > dist[u] + e.w))
                {
                    dist[e.v] = dist[u] + e.w;
                    pq.emplace_back(dist[e.v], e.v);
                    push_heap(begin(pq), end(pq), cmp);
                }
            }
        }
        
        cout << "Case #" << ++cCase << ": ";
        if (dist[d] == unknown)
        {
            cout << "unreachable";
        }
        else
        {
            cout << dist[d];
        }
        cout << "\n";
    }
}