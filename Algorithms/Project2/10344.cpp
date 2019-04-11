#include <bits/stdc++.h> 

using namespace std; 

struct Solver 
{ 
	vector<int> nums; 
	string res; 
	int counter; 
	Solver(vector<int> aNums) 
	: nums(aNums),counter(0) 
	{ 
		res = "Impossible"; 

	} 

void run() 
{ 

	permutation(0); 

} 
void permutation(int beg) 
{ 
	if(beg == nums.size()) 
	{ 

		solve(0,nums[0]);
		return; 

	} 

	for(int i = beg;i < nums.size();i++) 
	{ 

		swap(nums[i],nums[beg]); 
		permutation(beg + 1); 
		swap(nums[i],nums[beg]); 

	} 
} 

void solve(int i,int total) 

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
		case 0: solve(i + 1,total + nums[i + 1]); 
		break; 
		case 1: solve(i + 1,total * nums[i + 1]); 
		break; 
		case 2: solve(i + 1,total - nums[i + 1]); 
		break; 
		} 

	} 


} 

}; 

int main() 
{ 

	while(true)
	{ 


		vector<int> nums; 

		for(int t = 0;t < 5;t++) 
		{ 

			int num; 
			cin » num; 

			nums.push_back(num); 

		} 


		if(equal(nums.begin() + 1, nums.end(), nums.begin()) and nums[0] == 0) { 

			break;

		} 

		Solver solv(nums); 

		solv.run(); 
		cout « solv.res « endl; 
	} 

	return 0; 
}