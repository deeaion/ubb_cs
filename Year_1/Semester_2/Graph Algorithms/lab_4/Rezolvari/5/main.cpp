#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
typedef pair<int,int> edge;
typedef  pair<int,int> Pereche;
typedef pair<int,edge> fedge;
void add_node(vector<Pereche> adj[],int s,int f,int w,vector<fedge> &graph)
{
    adj[s].push_back(make_pair(f,w));
    adj[f].push_back(make_pair(s,w));
    graph.push_back(make_pair(w, make_pair(s,f)));
}
int find_set(int i,const vector<int> &parent)
{   //cautam un nod care sa aiba parintele pe el insusi
    if(i==parent[i])
        return i;
    else
        return find_set(parent[i],parent);
}
vector<edge> Kruskal(vector<fedge> G,int V,int E,int &cost)
{   vector<edge> T;
    vector<int> parent(V);
    for(int j=0;j<V;j++)
        parent[j]=j;
    int i,uRep,vRep;
    //sortam dupa weights
    sort(G.begin(),G.end());
    for(i=0;i<G.size();i++)
    {
        int u=G[i].second.first;
        int v=G[i].second.second;
        //cautam u si v
        uRep=find_set(u,parent);
        vRep=find_set(v,parent);
        //daca nu sunt la fel am gasit muchii din arbore
        if(uRep!=vRep)
        {
            T.push_back(G[i].second);
            //si adaug la cost
            cost+=G[i].first;
            parent[uRep]=parent[vRep];
        }
    }
    return T;
}
void printare(const vector<edge> &muchii,int cost,ofstream &fout)
{   fout<<cost<<endl<<muchii.size()<<endl;
    for(const auto &e:muchii)
    {
        fout<<e.first<<" "<<e.second<<"\n";
    }
}
int main(int argc,char** argv) {
   string inputnameFile;
   string outputnameFile;
   char* inputFile=argv[1];
   char* outputFile=argv[2];
//   cout<<"Give name of input file: ";
//   cin>>inputnameFile;
//    cout<<"Give name of output file: ";
//    cin>>outputnameFile;
//    inputFile="../TESTS/";
//    outputFile="../TESTS/";
//    inputFile+=inputnameFile;
//    outputFile+=outputnameFile;
//    cout<<inputFile;
//    cout<<outputFile;
    ifstream fin(inputFile);
    ofstream fout(outputFile);
    int V,E;
    fin>>V>>E;
    cout<<"NUMBER OF NODES: "<<V<<"NUMBER OF EDGES"<<E;

    vector<Pereche> adj[V];
    vector<fedge> Graph;
    int x,y,w;
   while( fin>>x>>y>>w)
   {
       add_node(adj,x,y,w,Graph);
   }
   for(int i=0;i<V;i++)
   {    cout<<"Node "<<i<<":";
       for(auto edge:adj[i])
       {
           cout<<edge.first<<"|"<<edge.second<<", ";
       }
       cout<<endl;
   }
   int cost=0;
    vector<edge> edges=Kruskal(Graph,V,E,cost);
    cout<<cost<<"\n"<<edges.size()<<endl;
    printare(edges,cost,fout);

    fin.close();
    fout.close();
    return 0;
}
