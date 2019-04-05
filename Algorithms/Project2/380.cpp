#include <bits/stdc++.h>

using namespace std;
struct ForwardCall
{
	int beg;
	int end;
	int forwExten;
	ForwardCall(int aBeg, int aEnd,int aForwExten)
	:beg(aBeg),end(aBeg + aEnd),forwExten(aForwExten)
	{
		
	}
};
int call(map<int,vector<ForwardCall>>& mp,const int time,int whom,const int& whomFirst,bool wasRedirected)
{
	
	auto p = mp.find(whom);
	if(whom == whomFirst and wasRedirected)
	{
		return 9999;
	}	
			

	if(p != mp.end())
	{
		vector<ForwardCall>& calls = p->second;
		for(int i = 0;i < calls.size();i++)
		{
			if(calls[i].beg <= time && time <= calls[i].end)
			{
				 wasRedirected = true;
				whom = calls[i].forwExten;
				return call(mp,time,whom,whomFirst,wasRedirected);

			}
		}
		
	}
	return whom;
}
int main()
{
	int n;
	cin >> n;
	cout << "CALL FORWARDING OUTPUT\n";
	for(int i = 0; i < n;i++)
	{
		cout << "SYSTEM " << i + 1 << "\n";

		
		map<int,vector<ForwardCall>> mp;
		int exten;
		while(cin >> exten and exten != 0)
		{
			int beg,end,forwExten;
			
			cin >> beg >> end >> forwExten;
			
			ForwardCall call(beg,end,forwExten);
			mp[exten].push_back(call);
			
		}

		int time,whom;
		
		while(cin >> time and time != 9000){
			cin >> whom;
			
			int redirected = call(mp,time,whom,whom,false);
			cout << "AT " <<setfill('0')<<setw(4)<< time << " CALL TO " <<setw(4)<< whom <<" RINGS " <<setw(4)<< redirected << "\n";
		}
		
		
		
	}
	cout << "END OF OUTPUT\n";
	
	return 0;
}


