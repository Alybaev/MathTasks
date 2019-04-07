
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void printS(vector<int> &res)
{
	for(int a : res) cout << a;
	cout << "\n";
}

void solve(vector<int> &res, int cntr, int curr,ll &total,int &sdvig,ll max,int ham)
{
	if(curr == -2 or total == max)
	{
		return;
	}
	else
	{
		if(cntr == ham)
		{
			printS(res);
			total++;			
			res[curr+1]=0;
		  cntr--;
		}
		if(curr >= 0)	res[curr]=1;		
		solve(res,cntr+1,curr-1,total,sdvig,max,ham);
		sdvig++;
		cntr = 0;
		for(int i  = 0 ; i < res.size(); i ++)
		{
			res[i] = 0;
		}
		curr = res.size()-sdvig;
		solve(res,cntr,curr,total,sdvig,max,ham);
	}
}

ll fact(ll n)
{
	ll ans = 1;
	for(ll i = 2; i <= n; i ++)
	{
		ans*=i;
	}
	return ans;
}

int main()
{
	int n; cin >> n;
	ll total = 0;
	int sdvig = 1;

	string temp;
	while(n--){
		getline(cin,temp);
		getline(cin,temp);
		int len,ham; cin >> len >> ham;
		vector<int> res(len,0);
		ll max = fact(len) / fact(len-ham) / fact(ham);
		solve(res,0,res.size()-1,total,sdvig,max,ham);
	}
	return 0;
}