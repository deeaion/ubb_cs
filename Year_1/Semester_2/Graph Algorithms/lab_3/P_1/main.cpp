#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define INF 5000
typedef pair<int,int> Pereche;
#include <list>
void addEdge(vector<Pereche> ladj[],int u,int v,int w)
{
    ladj[u].push_back(make_pair(v,w));
    //ladj[v].push_back(make_pair(u,w));
}
vector<int> DjekstraShortestPath(vector<pair<int,int>> adj[],int V,int src)
{
    //Create oriority queue
    //Syntax: priority_queue<el,vector<el>,greater<el> > nume
    priority_queue<Pereche ,vector<Pereche>, greater<Pereche >> pq;
    //trebuie sa memoram si distantele -> la inceput toatele sunt ing
    vector<int> distance(V,INF);
    //sursa e prima bagata in queue. Distanta trebuie setata 0
    pq.push(make_pair(0,src));
    distance[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second; //extragem elementul . Second e de la pereche ca ne trebuie nod
        pq.pop();//il scoate

        //cautam toate cele adiacente
        for(auto i: adj[u])
        {
            int v=i.first;
            int weight=i.second;
            //vedem daca e un path mai scurt
            if(distance[v]>distance[u]+weight)
            {
                distance[v]=distance[u]+weight;
                pq.push(make_pair(distance[v],v));
            }
        }
    }
    return distance;
}

int main(int argc,char * argv[]) {

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int nr_varfuri,nr_edges,source;
    //am citit primul rand
    fin>>nr_varfuri>>nr_edges>>source;
    vector<Pereche> adj[nr_varfuri];
    //vector<vector<pair<int,int>>> lista_adiacenta()
    int i=1;
    for(i=0;i<nr_varfuri;i++)
    {   cout<<i<<": ";
        for( auto j: adj[i])
            cout<< j.first<<" "<<j.second << " ";
        cout<<endl;
    }
    while(i<=nr_edges)
    {   int u,v,w;
        fin>>u>>v>>w;
        addEdge(adj,u,v,w);
        i++;
    }

    const vector<int>& distance= DjekstraShortestPath(adj,nr_varfuri,source);
    for(int i=0;i<nr_varfuri;++i)
    {
        if(distance[i]!=INF)
            fout<<distance[i]<<" ";
        else
            fout<<"INF"<<" ";
    }
    return 0;
}
