
#include <bits/stdc++.h>

using namespace std;

string res = "Impossible";
void solve(const vector<int>& nums, int i,int total)
{
	
	res = "Possible";
		
	
}
int main()
{
	
	
	while(true){
		vector<int> nums;
		for(int t = 0;t < 5;t++)
		{
			int num;
			cin >> num;
			if(num == 0)
			{
				goto end;
			}
			nums.push_back(num);
			
			
			solve(nums,0,nums[0]);
			
			


		}
		cout << res << endl;
	}
	end:
	
	
	return 0;
}


