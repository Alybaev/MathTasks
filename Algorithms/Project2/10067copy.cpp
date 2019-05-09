#include <bits/stdc++.h>


using namespace std;
enum class Color{white,red,black};

void update(map<int,int>& dist,map<int,Color>& state,queue<int>& q,vector<int>& forb,const  int& u, const int& v)
{
	if(find(forb.begin(),forb.end(),u) == forb.end() and state.find(u) == state.end())
	{
		q.push(u);
		state[u] = Color::red;
		dist[u] = dist[v] + 1;
	}
	
}
int main()
{
	vector<int> dn = {1000,100,10,1};
	int t;
	cin >> t;
	for(int k = 0;k < t;k++)
	{
		int start = 0;
		int dest = 0;
		int x;
		for(int i = 0;i < 4;i++)
		{
			
			cin >> x;
			start += x * dn[i];
		}

		for(int i = 0;i < 4;i++)
		{
			cin >> x;
			dest += x * dn[i];

		}
		int forbN; cin >> forbN;
		vector<int> forb(forbN, 0);
		for(int i = 0;i < forbN;i++)
		{
			for(int j = 0;j < 4;j++)
			{
				 cin >> x;
				forb[i] += x * dn[j];


			}
		}
		map<int,int> dist;
		map<int,Color> state;
		dist[start] = 0;
		state[start] = Color::red;
		queue<int> q;
		q.push(start);
	
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
			state[v] = Color::black;
			int copy = v;
			if(v == dest)
			{
				break;
			}
			bool isZero = false;
			for(int i = 0;i < 4;i++)
			{

				int dig = ((!isZero) ? copy / dn[i] : 0);
				isZero = false;
				if(dig == 9)
				{
					
					update(dist,state, q, forb,(v + dn[i]) - (dn[i] * 10), v);
					update(dist,state, q,forb, v - dn[i], v);
					
				}else if(dig == 0)
				{
					update(dist,state, q,forb, v + 9 * dn[i], v);
					update(dist,state, q,forb, v + dn[i], v);
				}else{
					update(dist,state, q,forb, v + dn[i], v);
					update(dist,state, q,forb, v - dn[i], v);
					
				}

				copy %= dn[i];
				if(copy * 10 <  dn[i])
				{
					isZero = true;
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