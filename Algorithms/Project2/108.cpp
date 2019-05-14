#include <bits/stdc++.h>


using namespace std;
vector<int> sumTwoVectors(vector<int>& v1,vector<int>& v2)
{
	vector<int> res(v1.size());
	for(int i=0;i < v1.size();i++)
	{
		res[i] = v1[i] + v2[i];

	}
	return res;
}
void getMax(std::vector<int>& v, int& maxSum, bool& isAllNeg)
{
	
	int sum = 0;
  	
    for (int i = 0; i < v.size(); i++) 
    { 
    	
        sum += v[i];  
        if (sum < 0)  
        {  
            sum = 0;  
        }  
        else if (sum > maxSum)  
        {  
            maxSum = sum;  
            isAllNeg = false;
            
        }  
    } 
    if(isAllNeg)
    {
    	int m = *(std::max_element(v.begin(),v.end()));
    	
    	if( m > maxSum)
    	{
    		maxSum = m;
    	}
    }
   
}
int main()
{
	int n;
	while(cin >> n)
	{
		std::vector<std::vector<int> > g(n,vector<int>(n));
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				cin >> g[i][j];
			}
		}

		bool isAllNeg = true;
		int max = -127	;

		for(int i = 0;i < n;i++)
		{
			
			std::vector<int> v;
			for(int j = i;j < n;j++)
			{
				
				if(i == j)
				{
					v = g[i];
					getMax(v,max,isAllNeg);
				}else{
					v = sumTwoVectors(v,g[j]);
					getMax(v, max,isAllNeg);
				}
				

			}
		}
		cout << max << endl;
	}
	





}