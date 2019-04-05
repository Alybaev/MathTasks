
#include <bits/stdc++.h>

using namespace std;
void solve(string hem,int swap1, int swap2,const int& N)
{
	int i  = swap1;
	int j = swap2;

	while((hem[i] == '0' and hem[j] == '1'))
	{
		
		if(swap2 != N){
			solve(hem,swap1+1,swap2+1, N);
		}
		
		swap(hem[i],hem[j]);
		--i;
		--j;
		cout << hem << endl;
	}

	
}
int main()
{
	int n;
	cin >> n;
	
	for(int t = 0;t < n;t++)
	{
		
		int N, H;
		cin >> N >> H;
		string initial = string(N - H,'0') + string(H,'1');
		
		
		solve(initial,N - H - 1,N - H,N);
		
		


	}
	
	return 0;
}


