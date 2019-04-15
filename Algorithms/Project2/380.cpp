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


struct Solver
{
	map<int,vector<ForwardCall>> mp;
	int time;
	int whom;
	int redirect;

	vector<ForwardCall> calls;

	Solver(map<int,vector<ForwardCall>> aMp)
	:mp(aMp)
	{
		
	}
	void run(int aTime,int aWhom)
	{
		whom = aWhom;
		time = aTime;
		redirect = aWhom;
		call(false);
	}
	void call(bool wasRedirected)
	{
	
		auto p = mp.find(redirect);

		if(redirect == whom and wasRedirected)
		{
			redirect = 9999;
			return;
		}	
				

		if(p != mp.end())
		{
			calls = p->second;

			for(int i = 0;i < calls.size();i++)
			{
				if(calls[i].beg <= time && time <= calls[i].end)
				{
					 wasRedirected = true;
					redirect = calls[i].forwExten;
					call(wasRedirected);

				}
			}
			
		}
		

	}
};



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
		Solver solv(mp);

		while(cin >> time and time != 9000){
			
			cin >> whom;
			
			solv.run(time,whom);
			
			cout << "AT " <<setfill('0')<<setw(4)<< solv.time << " CALL TO " <<setw(4)<< solv.whom <<" RINGS " <<setw(4)<< solv.redirect << "\n";
		}
		
		
		
	}
	cout << "END OF OUTPUT\n";
	
	return 0;
}


