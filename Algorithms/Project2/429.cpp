#include <bits/stdc++.h>


using namespace std;
enum class Color{white,red,black};
bool isFit(string& s1,string& s2)
{
	int diff = 0;
	for(int i = 0; i < s1.size();i++)
	{
		if(s1[i] != s2[i])
		{
			diff++;
		}
		if(diff > 1)
			return false;
	}
	return (diff == 0) ? false : true;
}
void solve(const string& init,const string& transf,vector<string>& g)
{
	std::map<string, int> dist;
	std::map<string, Color> state;
	std::map<string, string> pred;

	for(auto& str : g)
	{
		dist[str]  = -1;
		state[str] = Color::white;
		pred[str]  = "";
	}
	queue<string> q;
	q.push(init);
	dist[init] = 0;
	state[init] = Color::red;
	while(!q.empty())
	{
		string v = q.front();
		q.pop();
		state[v] = Color::black;
		if(v == transf)break;
		for(string& u : g)
		{
			if(v.size() == u.size() and  u != pred[v] and isFit(v,u) and state[u] == Color::white)
			{
				q.push(u);
				dist[u] = dist[v] + 1;
				state[u] = Color::red;
				pred[u] = v;
			}
		}
	}

	cout << init << " " << transf << " " << dist[transf] << "\n";
}
int main()
{
	int n;
	cin >> n;
	for(int t = 0; t < n;t++)
	{
		string x;
		vector<string> g;
		while(cin >> x and x != "*")
		{
			g.push_back(x);
		}
		cin.ignore();
		string init,transf;
		string line;
	
		while(getline(cin, line) and not line.empty())
		{
			istringstream sinp(line);
			sinp >> init >> transf;
			solve(init,transf,g);
			
		}
		cout << ((t == n - 1) ? "": "\n");

		
		
	}
}