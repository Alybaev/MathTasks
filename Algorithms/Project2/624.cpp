
#include <bits/stdc++.h>

using namespace std;

struct Solver
{
	int N;
	vector<int> tracks;
	int max;
	vector<int> res;
	vector<int> comb;
	Solver(int aN,vector<int> aTracks)
	:N(aN),tracks(aTracks),max(0), res(0),comb(0)
	{

	}

	void run()
	{
		solve(0,0);
	}
	void check(const int& beg,const int& total)
	{
		if(total > max)
		{
			res = comb;
			max = total;
		}

	}
	void solve(int beg,int total)
	{
		
		if(total > N)
		{
			return;
		}

		check(beg,total);
		
		
		for(int i = beg; i < tracks.size();i++)
		{
			comb.push_back(tracks[i]);
			solve(i+1, total + tracks[i]);
			comb.pop_back();
		}
		
		

		
	}

};

int main()
{
	string line;
	while(getline(cin, line))
	{
		istringstream sinp(line);
		int N;
		sinp >> N;

		int trck;
		sinp >> trck;

		vector<int> tracks(trck);

		for(int i = 0;i < trck;i++)
		{
			int dur;
			sinp >> dur;
			tracks[i] = dur;
		}

		Solver solv(N,tracks);
		solv.run();

		for(int& num : solv.res)
		{
			cout << num << " ";
		}
		cout <<  "sum:" << solv.max << endl;

	}
	
	
	
	
	return 0;
}


