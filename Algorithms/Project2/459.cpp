#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

using Graph = vector<vector<int>>;

void dfs(Graph& g,std::vector<bool>& visited, int u) 
{
   visited[u] = true;

   for(int i = 0;i < g[u].size();i++)
   {

        if(not visited[g[u][i]])
        {

            dfs(g,visited, g[u][i]);
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
            getline(cin,line);
        char largNode;
        cin >> largNode;


       
        Graph g(largNode - 'A' + 1);
      
        cin.ignore();
        while(getline(cin, line) and !line.empty())
        {
            g[line[0] - 'A'].push_back(line[1] - 'A');
             g[line[1] - 'A'].push_back(line[0] - 'A');
        }

        vector<bool> visited(largNode - 'A' + 1);
        int nComp = 0;
        for(int i = 0; i < g.size();i++)
        {
            if(not visited[i])
            {
                ++nComp;
                dfs(g,visited, i);
                
            }
        }
        cout << nComp << ((t == n - 1) ? "\n" : "\n\n");
        




    }
    

    
    
    
}