#include <bits/stdc++.h>

using namespace std;


struct Solver
{

	vector<vector<char>> cblPath;

	int startColIndex;
	const string IEHOVA = "IEHOVA#";

	Solver(vector<vector<char>> aCblPath, int aStartColIndex)
	:cblPath(aCblPath), startColIndex(aStartColIndex)
	{

	}

	void run()
	{
		solve(0, cblPath.size() - 1, startColIndex);	
	}
	void solve(int cblStIndex,int i,int j)
	{
		if(cblStIndex == IEHOVA.size())
		{
			cout << endl;
			return;
		}


		if(j + 1 != cblPath.size() and cblPath[i][j + 1] == IEHOVA[cblStIndex])
		{
			cout << ((cblStIndex == 0) ? "right" : " right");
			solve(cblStIndex + 1, i, j + 1);
		}else if(j - 1 != -1 and cblPath[i][j - 1] == IEHOVA[cblStIndex])
		{
			cout << ((cblStIndex == 0) ? "left" : " left");
			solve(cblStIndex + 1, i, j - 1);
		}else {
			cout << ((cblStIndex == 0) ? "forth" : " forth");
			solve(cblStIndex + 1, i - 1, j);
		}
		
	}
};


int main()
{
	
	int test;
	cin >> test;
	for(int t = 0; t < test;t++)
	{
		int n;
		cin >> n;
		int m;
		cin >> m;
		cin.ignore();
		vector<vector<char>> cblPath(n,std::vector<char>(m));

		int startCol = 0;

		for(int i = 0;i < n;i++)
		{

			for(int j = 0; j < m;j++)
			{
				char c;
				cin.get(c);
				if(c == '@')
					startCol = j;
			
				cblPath[i][j] = c;


			}
			cin.ignore();
		}
		Solver solv(cblPath,startCol);
		solv.run();

		


	}

}