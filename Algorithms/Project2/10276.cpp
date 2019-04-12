#include <bits/stdc++.h> 

using namespace std; 

struct Solver 
{ 
	
	vector<int> top;

	int ballNum;

	Solver(int aN) 
	: top(aN,0),ballNum(1)
	{ 
		

	} 

void run() 
{ 

	solve(1);	
	
} 

bool isSquareNum(const int& a, const int& b)
{
	return (sqrt(a + b) == (int)( sqrt(a + b))) ? true : false;
}
void solve(const int& peg) 

{ 
	if(peg == top.size() + 1)
	{
		return;
	}
	
	
	while(true)
	{

		bool failToIns = false;

		for(int i = 0; i < peg;i++)
		{
			if(top[i] == 0 or isSquareNum(ballNum, top[i]))
			{

				top[i] = ballNum;
				failToIns = true;
				++ballNum;

			}	
			
		}

		if(!failToIns)break;
	}

	solve(peg + 1);
} 
 

}; 

int main() 
{ 

	int t;
	cin >> t;
	for(int i = 0;i < t;i++)
	{
		int n;
		cin >> n;

		Solver solv(n);
		solv.run();

		cout << solv.ballNum - 1 << "\n";

	}
	return 0; 
}