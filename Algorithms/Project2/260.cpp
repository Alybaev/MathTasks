#include <bits/stdc++.h>

using namespace std;


struct Solver{


	Solver(vector<vector<char>>& desk,)

	const vector<int> dr = {-1,-1,  0, 0, 1, 1};
	const vector<int> dc = {-1, 0, -1, 1, 0, 1};
	bool inRange(int i, int j, const int N)
	{
		return (i >= 0 and i < N) and (j >= 0 and j < N);
	}
	void dfs(const vector<vector<char>>& desk, bool& is_white_win, vector<vector<int>>& visited, int i,int j)
	{
		visited[i][j] = 1;
		if(j == 0)
			is_white_win = true;

		for(int t = 0; t < 6;t++)
		{
			int uI = i + dr[t];
			int uJ = j + dc[t];
			if(inRange(uI,uJ, desk.size()) and desk[uI][uJ] == 'w' and not visited[uI][uJ])
			{
				dfs(desk,is_white_win,visited, uI, uJ );
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
		bool is_white_win = false;
		for(int i = 0; i < N;i++)
		{
			
			for(int j = 0; j < N;j++)
			{
				vector<vector<int> > visited(N, std::vector<int>(N, 0));
				if(j == N - 1 and desk[i][j] == 'w' and not visited[i][j] )
				{
					

					
					dfs(desk,is_white_win, visited, i, j);
					
					
				}
				
			}
			
		}
		cout << test << ((is_white_win) ? " W": " B") << "\n";
		++test;
	}
	
	

	return 0;
}