#include <bits/stdc++.h>

using namespace std;

struct Solver
{
    int min;
    int steps;
    int n;
    vector<int> rows;
    vector<int> cols;
    vector<int> diag1;
    vector<int> diag2;
    std::vector<int> initCols;
    Solver(int aN,vector<int> aInitCols)
    : n(aN), rows(n), cols(n), diag1(2 * n - 1), diag2(2 * n - 1), steps(0),min(8),initCols(aInitCols)
    {
        
    }
    
    void run()
    {
        solve(0);
    }
    
    void solve(int c)
    {
        if (c == n)
        {
         
            printSolution();
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (check(i, c))
                {
                    putQueen(i, c);
                    solve(c + 1);
                    takeQueen(i, c);
                }
            }
        }
        
    }
    
    bool check(int r, int c)
    {
        return rows[r] == 0 and diag1[r + c] == 0 and diag2[n - 1 - r + c] == 0;
    }
    
    void putQueen(int r, int c)
    {
        cols[c] = r;
        rows[r] = diag1[r + c] = diag2[n - 1 - r + c] = 1;
    }
    
    void takeQueen(int r, int c)
    {
        rows[r] = diag1[r + c] = diag2[n - 1 - r + c] = 0;
    }
    
    void printSolution()
    {
        
        for (int i = 0;i < cols.size();i++)
        {
            if(initCols[i] != cols[i]){
                ++steps;
            }
        }
        if(steps < min)
        {

            min = steps;
        
        }
        steps = 0;
        
    }
    
};

int main()
{
  
   
    string line;
    int t = 1;
  

    while(getline(cin,line) and !line.empty())
    {
       
         vector<int> initCols(8);
          int num;
         istringstream sinp(line);
 
       for(int i = 0; i < 8;i++)
       {
             sinp >> num;
            initCols[i] = num - 1;
       }
    
        Solver solv(8,initCols);
        solv.run();
        cout <<"Case " << t << ": "<< solv.min << endl;
         ++t;
       

    }
    return 0;
    
  
}