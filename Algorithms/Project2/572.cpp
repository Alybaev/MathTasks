#include <bits/stdc++.h>


using namespace std;



struct Solver{

	const vector<int> dr = {1, 1, 1, -1, -1, -1, 0, 0};
	const vector<int> dc = {-1, 0, 1, -1,  0,  1,-1, 1};
	

	

	vector<vector<char>> desk;
	vector<vector<int>> visited;
	int nComp;
	int n;
	int m;
	Solver(vector<vector<char>>& aDesk, int& aN, int& aM)
	:desk(aDesk), nComp(0), n(aN),m(aM),visited(aN, vector<int>(aM, 0))
	{

	}

	bool inRange(int i, int j)
	{
		return (i >= 0 and i < n) and (j >= 0 and j < m);
	}

	void dfs(int i, int j)
	{
		visited[i][j] = 1;
		for(int t = 0; t < 8;t++)
		{
			int uI = i + dr[t];
			int uJ = j + dc[t];
			if(inRange(uI,uJ) and desk[uI][uJ] == '@' and not visited[uI][uJ])
			{
				dfs(uI,uJ);
			}
		}
	}

	void run(int i, int j)
	{
		 

		if(desk[i][j] == '@' and not visited[i][j] )
		{
			nComp++;
			dfs(i, j);
			
		}

	}
	

};
int main()
{
	int n,m;
	while(cin >> n >> m and n != 0 and m != 0)
	{
		vector<vector<char>> field(n, vector<char>(m));
		for(int i = 0;i < n;i++)
		{
			for(int j = 0; j < m;j++)
			{
				cin >> field[i][j];
			}
		}

	

		Solver solv(field, n, m);
		for(int i = 0;i < n;i++)
		{
			for(int j = 0; j < m;j++)
			{
				
				solv.run(i,j);
				
			}
		}
		cout << solv.nComp << "\n";
	}

	return 0;
}