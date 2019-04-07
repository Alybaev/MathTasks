
#include <bits/stdc++.h>

using namespace std;

string res = "Impossible";
void solve(const vector<int>& nums, int i,int total)
{
	if( i == 4)
	{
		
		if(total == 23)
		{
			res = "Possible";
		} 
			
		
		return;
		
	}
	for(int o = 0; o < 3;o++)
	{
		switch(o){
			case 0: solve(nums,i + 1,total + nums[i + 1]);
			break;
			case 1: solve(nums,i + 1,total * nums[i + 1]);
			break;
			case 2: solve(nums,i + 1,total - nums[i + 1]);
			break;
		}
		

		
		
		

	}
	
	
}
int main()
{
	
	
	while(true){
		vector<int> nums;
		res = "Impossible";
		for(int t = 0;t < 5;t++)
		{
			int num;
			cin >> num;
			
			nums.push_back(num);
			
			
		}
	
		std::sort(nums.begin(), nums.end());
	    do {
	        solve(nums,0,nums[0]);
	    } while(std::next_permutation(nums.begin(), nums.end()));

		if(equal(nums.begin() + 1, nums.end(), nums.begin()) and nums[0] == 0)
		{
			break;
		}
		cout << res << endl;
	}
	
	
	
	return 0;
}


