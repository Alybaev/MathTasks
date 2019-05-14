#include <bits/stdc++.h>

using namespace std;
std::vector<int> coin = {1,5,10,25,50};

std::set<vector<int> > allComb;
void solve(int m,vector<int> comb)
{
	if(m == 0)
	{	
		allComb.insert(comb);
	}
	for(int i = 0;i < coin.size();i++)
	{
		if(m >= coin[i])
		{
			
			++comb[i];
			solve(m - coin[i],comb);
			--comb[i];
		}
	}
}
int main()
{
	int m;
	
	while(cin >> m)
	{
		std::vector<int> comb(5, 0);
		solve(m, comb);
		cout << allComb.size() << "\n";
		allComb.clear();
		
	}
	return 0;
}