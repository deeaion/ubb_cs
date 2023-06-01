#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
bool bfs(int parent[], int V,int E,vector<int> adj[],vector<vector<int>> &adjMatrix)
{
    //fac un vector de vizitatori
    vector<bool> visited(V,false);
    queue<int> noduri;
    noduri.push(0);
    visited[0]=true;
    while(!noduri.empty())
    {
        int nc=noduri.front();//nodul curent
        noduri.pop();
        for(auto nv:adj[nc])
        {
            if(visited[nv]== false&&adjMatrix[nc][nv]>0)
            {
                noduri.push(nv);
                parent[nv]=nc;
                visited[nv]=true;
            }
        }
    }
    return(visited[V-1]==true);

}
int edmondsKarp(int V,int E,vector<int> adj[],vector<vector<int>> &adjMatrix)
{
    int sursa=0;
    int u,v;
    int destinatie=V-1;
    //int rGraph[V][V];
    int parent[V];
    int max_flow=0;//nu avem flow initial
    //cat timp se poate face bfs de la parinte la sf
    while(bfs(parent,V,E,adj,adjMatrix))
    {
        int pathFlow=INT_MAX;
        for(v=V-1;v!=0;v=parent[v])
        {
            u=parent[v];
            pathFlow=min(pathFlow,adjMatrix[u][v]);
        }
        //schimbam capacitatiile rezitduale
        for(v=V-1;v!=0;v=parent[v])
        {
            u=parent[v];
            adjMatrix[u][v]-=pathFlow;
            adjMatrix[v][u]+=pathFlow;
        }
        max_flow+=pathFlow;
    }
    return max_flow;



}
int main(int argc,char* argv[]) {
//citire fisier
    int V,E;
    int x,y,c;
    int sursa=0;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    fin>>V>>E;
    cout<<V<<E;
    //lista de adj si matrice de adia
    vector<int> adj[V];
    vector<vector<int>> adjMatrix(V,vector<int>(V,0));
    int destinatie=V-1;
    while(fin>>x>>y>>c)
    {
        adjMatrix[x][y]=c;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    fout<<edmondsKarp(V,E,adj,adjMatrix);
}
