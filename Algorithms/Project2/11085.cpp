#include <bits/stdc++.h>

using namespace std;

struct Solver
{
    int n;

    int steps;
    int min;
    std::vector<int> initCols;

    std::vector<int> rows;
    std::vector<int> cols;
    std::vector<int> diag1;
    std::vector<int> diag2;

    Solver(int aN,std::vector<int> aInitCols)
    : steps(0),min(8),n(aN),rows(n),cols(n),diag1(n * 2 - 1),diag2(n * 2 - 1),initCols(aInitCols)
    {
        
    }
    
    void run()
    {
        solve(0);
    }
    bool check(int row, int col)
    {
        return rows[row] == 0 and diag1[row + col] == 0 and diag2[n - 1 - row + col] == 0;
    }

    void putQueen(int row, int col)
    {
        rows[row] = diag1[row + col] = diag2[n - 1 - row + col] = 1;
        cols[col] = row;
    }

    void takeQueen(int row, int col)
    {
        rows[row] = diag1[row + col] = diag2[n - 1 - row + col] = 0;
   
    }
    void getMin()
    {
        for(int i = 0; i < cols.size();i++)
        {
            if(cols[i] != initCols[i])
            {
                ++steps;
            }
        }
        if(steps < min)
        {
            min = steps;
        }

        steps = 0;
    }
    void solve(int c)
    {
        if(c == n)
        {
            getMin();
            return;
        }

        for(int i = 0; i < 8;i++)
        {
            if(check(i,c))
            {
                putQueen(i,c);
                solve(c + 1);
                takeQueen(i,c);
            }
        }
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