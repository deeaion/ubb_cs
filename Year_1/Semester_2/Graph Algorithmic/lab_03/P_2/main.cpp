
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <fstream>
#include <exception>
using namespace std;
using namespace std::string_literals;
typedef pair<int,int> Pereche;
#define INF 5000
void add_edge(int nod,int dest,int w,vector<pair<int,int>> adj[])
{
    adj[nod].push_back(make_pair(dest,w));
}

vector <int> Belman_Ford(vector<pair<int,int>> adj[],int nr_v,int nr_e,int src,vector<int> &distance,vector<vector<int>> edges)
{
   // vector<int> distance(nr_v,INF);
    distance[src]=0;
    for(int i=0;i<nr_v;i++)
    {
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            int w=e[2];
            if(distance[u]!=INF && distance[v]>distance[u]+w)
            {
                distance[v]=distance[u]+w;
            }
        }

    }
    for(int i=0;i<nr_v;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            int u=adj[i][j].first;
            int w=adj[i][j].second;
            if(distance[u]!=INF && distance[u]>distance[i]+w)
            {   //char message[]="-1";
                throw "-1";
            }
        }
    }
    return distance;
}

void RecalculateWeight(vector<pair<int,int>> adj[],int nr_v,int nr_e,vector <int> distance)
{
    for (int i = 0; i < nr_v; i++)
    {
        for(int j = 0 ; j < adj[i].size() ; j++)
        {
            int nod = adj[i][j].first;
            int cost = adj[i][j].second;
            adj[i][j] = { nod,cost + distance[i] - distance[nod] };
        }
    }
}
vector<int> Dijekstra(vector<pair<int,int>> adj[],int nr_v,int nr_e,int src)
{
    priority_queue<Pereche ,vector<Pereche >,greater<>> pq;
    vector<int> distance(nr_v,INF);
    distance[src]=0;
    vector<int> parents(nr_v,-1);
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(auto node:adj[u])
        {
            int v=node.first;
            int w=node.second;
            if(distance[v]>distance[u]+w)
            {
                distance[v]=distance[u]+w;
                pq.push(make_pair(distance[v],v));
                parents[v]=u;
            }
        }
    }
    return distance;

}
int main(int argc,char *argv[])
{   //register int j=0;
    std::ifstream f(argv[1]);
    cout<<argv[1];
    int nod,dest,w;
    int nr_v,nr_e;
    f>>nr_v>>nr_e;
    cout<<nr_v<<nr_e;
    vector <pair <int,int>> adj[nr_v];
    while(f>>nod>>dest>>w)
    {
        add_edge(nod,dest,w,adj);
    }

    for(int i=0;i<nr_v;i++) {
        cout<<endl<<"Node "<<i;
        for (auto j: adj[i])

            cout << " "<<j.first<<"|"<<j.second << " ";
    }
    vector <pair<int,int>> adjp[nr_v+1];
    int nod_n=nr_v;
    vector<vector<int>> edges(nr_v+1,vector<int>(3));
    for(int i=0;i<nr_v;i++) {
        for (int j=0;j<adj[i].size();j++)
            {   dest=adj[i][j].first;
                w=adj[i][j].second;
                add_edge(i,dest,w,adjp);
                edges.push_back({i,dest,w});

        }
        add_edge(nod_n,i,0,adjp);
        edges.push_back({nod_n,i,0});
                            }
//    for(int i=0;i<nr_v;i++) {
//        cout<<endl<<"Node "<<i;
//        for (auto j: adjp[i])
//
//            cout << " "<<j.first<<"|"<<j.second << " ";
//    }
    int nou_e=nr_e+nr_v;
    cout<<endl;
    vector<int> dist(nr_v+1,INF);
    try
    {
        Belman_Ford(adjp,nr_v+1,nou_e,nod_n,dist,edges);
    }
    catch (const char* mes)
    {
        cout<<mes;
        return 0;

    }

    ofstream g(argv[2]);
    RecalculateWeight(adjp,nr_v+1,nr_e,dist);
    cout<<endl;
    for(int i=0;i<nr_v;i++) {
        //cout<<endl;
        for (auto j: adjp[i])

        {g <<i<< " "<<j.first<<" "<<j.second << " ";
            g<<endl;}
    }
    cout<<endl;
    for( auto i:dist)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;
    vector<pair<int,int>> final[nr_v];
    for(int i=0;i<nr_v;i++) {
        for (int j=0;j<adjp[i].size();j++)
        {   dest=adjp[i][j].first;
            w=adjp[i][j].second;
            add_edge(i,dest,w,final);

        }
    }

    for (int src=0;src<nr_v;src++)
    {
        auto distance=Dijekstra(final,nr_v,nr_e,src);
        for(int i=0;i<nr_v;i++)
            if(distance[i]<INF)
            {g<<distance[i]<<" ";}
            else
                g<<"INF ";
        // cout<<endl;
        g<<endl;
    }
    return 0;}
