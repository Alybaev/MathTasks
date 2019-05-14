
#include <bits/stdc++.h>

using namespace std;

struct Solver
{
	vector<string> dict;
	vector<string> rules;
	const vector<char> nums = {'0','1','2','3','4','5','6','7','8','9'};
	Solver(vector<string> aDict,vector<string> aRules)
	
	{

		dict = aDict;
		rules = aRules;

	}

	void run()
	{
		for(int i = 0; i < rules.size();i++)
		{

			solve(rules[i],"",0);
		}
		
	}
	
	void solve(const string& rule,string psw,int index)
	{
		if(index == rule.size())
		{
			cout << psw << "\n";
			return;
		}
		if(rule[index] == '0')
		{
			for(int i = 0;i < nums.size();i++)
			{
				solve(rule,psw + nums[i],index + 1);
			}
		}else{
			for(int i = 0;i < dict.size();i++)
			{
				solve(rule,psw + dict[i],index + 1);
			}
		}
	

		

		
	}

};

int main()
{
	iostream::sync_with_stdio(false);
	
	int n;
	while(cin >> n)
	{
		

		vector<string> dict;
		vector<string> rules;

		cout << "--" << "\n";
		
		for(int i = 0; i < n;i++)
		{
			string word;
			cin >> word;
			dict.push_back(word);
		}

		int m;
		cin >> m;

		for(int i = 0; i < m;i++)
		{
			string word;
			cin >> word;
			rules.push_back(word);
		}
		cin.ignore();

		Solver solv(dict,rules);
		solv.run();
		
	}
	
}