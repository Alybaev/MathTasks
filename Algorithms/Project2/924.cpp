#include <bits/stdc++.h>


using namespace std;
enum class Color{white,red,black};


int main()
{
	
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for(int t = 0; t < n;t++)
	{
		int nFriend; cin >> nFriend;
		for(int i = 0;i < nFriend;i++)
		{
			int frendo; cin >> frendo;
			g[t].push_back(frendo);
			


		}
	
	}
	int m; cin >> m;
	for(int t = 0; t < m;t++)
	{
		int source;cin >> source;
		std::vector<int> dist(n,-1);
		std::vector<int> pred(n,-1);
		std::vector<Color> state(n, Color::white);


		dist[source] = 0;
		state[source] = Color::red;

			
		if(g[source].size() == 0)
		{
			cout << '0' << "\n";
		}else{
			queue<int> q;
			q.push(source);	
			int maxBoom = g[source].size();
			int maxBoomDay = 1;
			int day = 0;
			int boom = 0;
			int nextDayAfterBooms = q.size();
			int people = 0;

			while(!q.empty())
			{
				if(boom == nextDayAfterBooms)
				{
					nextDayAfterBooms = q.size();
					boom = 0;
					day++;
					if(people > maxBoom)
					{
						maxBoomDay = day;
						maxBoom = people;
					}
					people = 0;
				}
				boom++;
				
				int v = q.front();
				q.pop();
				state[v] = Color::black;

				for(int& u: g[v])
				{
					if(state[u] == Color::white)
					{
						++people;
						q.push(u);
						state[u] = Color::red;
						dist[u] = dist[v] + dist[u];
						pred[u] = v;

					}
				}
			}
			cout << maxBoom << " " <<  maxBoomDay << "\n";
		}
	}
	


	return 0;
}