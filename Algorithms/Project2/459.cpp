#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

using Graph = vector<vector<char>>;

void dfs(Graph& g,std::vector<bool>& visited, char u) 
{
   visited[u - 'A'] = true;

   for(int i = 0;i < g[u].size();i++)
   {

        if(not visited[g[u][i] - 'A'])
        {

            dfs(g,visited,g[u][i] );
        }
   }
}

int main()
{
    
    string line;
    getline(cin, line);
    
    int n = stoi(line);
    for(int t = 0;t < n;t++)
    {
        
         string line;
        if(t == 0)
        {
            getline(cin, line);
        }
        char largNode;
        cin >> largNode;


       
        g(largNode - 'A' + 1);
      
        cin.ignore();
        while(getline(cin, line) and !line.empty())
        {
            g[line[0] - 'A'].push_back(line[1] - 'A');
             g[line[1] - 'A'].push_back(line[0] - 'A');
        }

        vector<bool> visited(largNode - 'A' + 1);
        int nComp = 0;
        for(auto& p: g)
        {
            if(not visited[p.first - 'A'])
            {
                ++nComp;
                dfs(g,visited, p.first);
                
            }
        }
        cout <<nComp << "\n\n";
        




    }
    

    
    
    
}