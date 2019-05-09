#include <bits/stdc++.h>


using namespace std;



struct Solver{

	const vector<int> dr = {1, -1,  0, 0};
	const vector<int> dc = {0,  0, -1, 1};
	

	vector<string> desk;
	
	Solver(vector<string>& aDesk)
	:desk(aDesk)
	{

	}
	void printField()
	{
		for(string& line : desk)
		{
			cout << line << "\n";
		}
	}
	
	void dfs(int i, int j)
	{
		desk[i][j] = '#';

		for(int t = 0; t < 4;t++)
		{
			int uI = i + dr[t];
			int uJ = j + dc[t];
			if(desk[uI][uJ] == ' ')
			{
				dfs(uI,uJ);
			}
		}
	}

	
	

};
int main()
{
	int N;cin >> N;
	

	cin.ignore();
	for(int t = 0;t < N;t++)
	{

		vector<string> field;
		int rowStart;
		int colStart;

		int row = 0;
		string line;
		while(getline(cin,line))
		{
			
			field.push_back(line);
			auto it = find(line.begin(), line.end(), '*');
			if(it != line.end())
			{
				rowStart = row;
				colStart = it - line.begin();
			}
			
			row++;
			if(line[0] == '_')
				break;
			
		}

	

		Solver solv(field);
		
				
		solv.dfs(rowStart,colStart);
				
		
		solv.printField();
	}

	return 0;
}