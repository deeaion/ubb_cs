#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;
bitset< 500000> elim;
vector<pair<int,int>> M;
vector<int> L;
void add_edge(vector<int > adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Euler(int k,vector<int> G[])
{
    stack<int> S;
    S.push(k);
    while(! S.empty())
    {
        k = S.top();
        if(G[k].size())
        {
            int x = G[k].back();
            G[k].pop_back();
            if(! elim[x])
            {
                elim[x] = 1;
                int p = M[x]. second;
                if(p == k) p = M[x].first;
                S.push(p);
            }
        }
        else
        {
            L.push_back(k);
            S.pop();
        }
    }
}
int main(int argc,char **argv) {
    if(argc!=3)
    {
        cout<<"Not enough args";
        exit(0);
    }
    char *input=argv[1];
    char *output=argv[2];
    //reading from file
    int V,E;
    ifstream fin(input);
    fin>>V>>E;
    vector<int> adj[V];

    int u,v;
    while(fin>>u>>v)
    {

        M.push_back(pair(u,v));
        int sz=M.size()-1;
        adj[u].push_back(sz);
        adj[v].push_back(sz);

    }
    for(int i=0;i<V;i++)
    {   cout<<i<<": ";
        for(auto t:adj[i])
        {
            cout<<t<<" ";
        }
        cout<<endl;
    }
    ofstream fout(output);
    Euler(0,adj);
    for(auto k:L)
    {
        fout<<k<<" ";
    }

    return 0;
}
