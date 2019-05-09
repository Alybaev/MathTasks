#include <bits/stdc++.h>


using namespace std;
enum class Color{white,red,black};


int main()
{
	
	int t;
	cin >> t;
	for(int k = 0;k < t;k++)
	{
		std::vector<short> start(4);
		std::vector<short> dest(4);

		for(int i = 0;i < 4;i++)
		{
			cin >> start[i];
		}

		for(int i = 0;i < 4;i++)
		{
			cin >> dest[i];

		}
		int forbN; cin >> forbN;
		vector<vector<short>> forb(forbN,vector<short> (4));
		for(int i = 0;i < forbN;i++)
		{
			for(int j = 0;j < 4;j++)
			{
				short dig;
				cin >> dig;
				forb[i][j] = dig;


			}
		}
		map<vector<short>,int> dist;
		map<vector<short>,Color> state;
		dist[start] = 0;
		state[start] = Color::red;
		queue<vector<short>> q;
		q.push(start);

		while(!q.empty())
		{
			auto v = q.front();
			q.pop();
			state[v] = Color::black;

			if(v == dest)
			{
				break;
			}
			for(int i = 0;i < v.size();i++)
			{
				auto copy = v;

				if(copy[i] == 0)
				{
					copy[i] = 1;
					if(state.find(copy) == state.end() and find(forb.begin(),forb.end(),copy) == forb.end())
					{
						q.push(copy);
						dist[copy] = dist[v] + 1;
						state[copy] = Color::red;
					}
					

					copy[i] = 9;
					if(state.find(copy) == state.end() and find(forb.begin(),forb.end(),copy) == forb.end())
					{
						q.push(copy);
						dist[copy] = dist[v] + 1;
						state[copy] = Color::red;
					}
					

					

				}else{
					--copy[i];
					if(state.find(copy) == state.end() and find(forb.begin(),forb.end(),copy) == forb.end())
					{
						q.push(copy);
						dist[copy] = dist[v] + 1;
						state[copy] = Color::red;
					}

					++copy[i];
					++copy[i];
					copy[i] %= 10;

					if(state.find(copy) == state.end() and find(forb.begin(),forb.end(),copy) == forb.end())
					{
						q.push(copy);
						dist[copy] = dist[v] + 1;
						state[copy] = Color::red;
					}
					
				}

			}

		}
		if(dist.find(dest) != dist.end())
		{
			cout << dist[dest] << "\n";
		}else{
			cout << "-1\n";
		}
		

			
		
	



	}
		return 0;
}