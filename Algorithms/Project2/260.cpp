#include <bits/stdc++.h>

using namespace std;


struct Solver{


	

	const vector<int> dr = {-1,-1,  0, 0, 1, 1};
	const vector<int> dc = {-1, 0, -1, 1, 0, 1};

	vector<vector<char>> desk;
	vector<vector<int>> visited;
	bool is_white_win;
	int N;

	Solver(vector<vector<char>>& aDesk)
	:desk(aDesk), is_white_win(false), N(aDesk.size()),visited(aDesk.size(), vector<int>(aDesk.size(), 0))
	{

	}

	bool inRange(int i, int j)
	{
		return (i >= 0 and i < N) and (j >= 0 and j < N);
	}
	void run(int i, int j)
	{
		 

		if(desk[i][j] == 'w' and not visited[i][j] )
		{
			
			dfs( i, j);
			
		}
	}
	void dfs( int i,int j)
	{
		visited[i][j] = 1;
		if(j == 0)
			is_white_win = true;

		for(int t = 0; t < 6;t++)
		{
			int uI = i + dr[t];
			int uJ = j + dc[t];
			if(inRange(uI,uJ) and desk[uI][uJ] == 'w' and not visited[uI][uJ])
			{
				dfs( uI, uJ );
			}
		}
	}

};


int main()
{
	
	int N;

	int test = 1; 
	while(cin >> N and N != 0)
	{
		char c;
	
		


		vector<vector<char> > desk(N, std::vector<char>(N));
		for(int i = 0; i < N;i++)
		{
			for(int j = 0; j < N;j++)
			{
				cin >> desk[i][j];
				
				
			}
		}
		Solver solv(desk);
		for(int i = 0; i < N;i++)
		{
			
			for(int j = N - 1; j < N;j++)
			{
				
				solv.run(i,j);
			}
			
		}
		cout << test << ((solv.is_white_win) ? " W": " B") << "\n";
		++test;
	}
	
	

	return 0;
}