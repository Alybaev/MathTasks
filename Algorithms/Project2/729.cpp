
#include <bits/stdc++.h>

using namespace std;
void solve(int beg,int end,string num,const int& N)
{
	if(beg == N)
	{
		cout << num << "\n";
		return;
	}
	
	for(int i = beg; i > end;--i)
	{
			
		swap(num[i],num[beg]);
		
		solve(beg+1,i,num,N);

		swap(num[i],num[beg]);
		
		
	}

	

	
}
int main()
{
	int n;
	cin >> n;
	
	for(int t = 0;t < n;t++)
	{
		cin.ignore();
		string empty;
		getline(cin,empty);
		int N, H;
		cin >> N >> H;


		string initial = string(N - H,'0') + string(H,'1');
		
		
		solve(N - H,-1,initial,N);
		
		if(t != n-1)
		{
			cout << "\n";
		}


	}
	
	return 0;
}


