#include <bits/stdc++.h>


using namespace std;

struct Solver
{
    int counter;
    
    int n;
    int row;
    int col;
    vector<int> rows;
    vector<int> cols;
    vector<int> diag1;
    vector<int> diag2;
    
    Solver(int aN,int aRow,int aCol)
    : n(aN),row(aRow),col(aCol), rows(n), cols(n), diag1(2 * n - 1), diag2(2 * n - 1), counter(0)
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
            ++counter;
            printSolution();
        }else if(c == col and !check(row, col)){
            return;
        }else if(c == col and check(row, col)){
            putQueen(row, col);
            solve(col + 1);
            takeQueen(row, col);
        }
        else    
        {
            for (int i = 0; i < n; ++i){
                
              
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

        cout << setw(2) << counter << "     ";
        for (int e: cols)
        {
            cout << " " << e + 1;
        }
        cout << endl;
    }
    
};

int main()
{
    int t; cin >> t;
    cin.ignore();
    string empty;
    getline(cin,empty);

    for(int i = 0;i < t;i++)
    {
        int row, col;
        cin >> row  >> col;
        --row;
        --col;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";


        Solver(8,row,col).run();
        if(i != t-1){
            cout << "\n";
        }
    }
    return 0;

}