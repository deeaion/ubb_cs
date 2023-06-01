#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
//fac o clasa pt Graph. Graful are edges and vertexes! so i am just gonna have structs for thos
struct Edge{
    int flow,capacity;
    int u,v; //unde u-->v
    Edge(int flow,int capacity,int u,int v)//initializer
    {
        this->flow=flow;
        this->capacity=capacity;
        this->u=u;
        this->v=v;
    }
};
struct Vertex{
    int h,e_flow;//h <- inaltime si adancime
    Vertex(int h,int e_flow)
    {
        this->h=h;//primeste inaltime
        this->e_flow=e_flow;
    }
};
//Graful cu functiile lui pt reprezentare
class Graph{
    int V;//nr varfuri
    //vector varfuri
    vector<Vertex> ver;
    vector<Edge> edge;
    //pompare
    bool push(int u);
    //schimbare proprietati unghi
    void relabel(int u);
    //initializare preflux
    void preflow(int s);
    //pompare
    void changereversenode(int i,int flow);
public:
    Graph(int V);
    void addEdge(int u,int v,int w);
    //get flow
    int getMaxFlow(int sursa,int endnode);
};
Graph::Graph(int V) {
    this->V=V;
    //initialisam toate varfuriile cu inaltime 0 si exces 0
    for(int i=0;i<V;i++)
    {
        ver.push_back(Vertex(0,0));
    }

}
void Graph::addEdge(int u, int v, int w) {
    edge.push_back(Edge(0,w,u,v));//flux initial 0
}
void Graph::preflow(int s)
{
   //sursa e la inaltimea maxima care e chiar inaltimea nr noduri
    ver[s].h = ver.size();

    //
    for (int i = 0; i < edge.size(); i++)
    {
       //verificam nodurile care pornesc din nodul sursa si ele o sa aiba flow ul chiar capacitatea lor
        if (edge[i].u == s)
        {
            // Flow is equal to capacity
            edge[i].flow = edge[i].capacity;

            //exces flow pentru noduriile adiacente
            ver[edge[i].v].e_flow += edge[i].flow;

            // Add an edge from v to s in residual graph with
            // capacity equal to 0
            edge.push_back(Edge(-edge[i].flow, 0, edge[i].v, s));
        }
    }
}

//cel care are excess
int overFlowVertex(vector<Vertex> & ver)
{
    for(int i=1;i<ver.size()-1;i++)
    {
        if(ver[i].e_flow>0)
            return i;
    }
    //daca nu exist return -1
    return -1;
}
//schimbare flow la muchia in sens invers

void Graph::changereversenode(int i, int flow)
{
    int u = edge[i].v, v = edge[i].u;

    for (int j = 0; j < edge.size(); j++)
    {
        if (edge[j].v == v && edge[j].u == u)
        {
            edge[j].flow -= flow;
            return;
        }
    }

    // adding reverse Edge in residual graph
    Edge e = Edge(0, flow, u, v);
    edge.push_back(e);
}

bool Graph::push(int u) {
    //incerc sa trimit excesul la celelalte vb adiacente
    for(int i=0;i<edge.size();i++)
    {
        //verific daca nodul curent e u
        if(edge[i].u==u)
        {
            ///verific daca pot sa trimit ceva! decat daca flow<capacity
            if(edge[i].flow==edge[i].capacity)
                continue;
            //pot sa pompez decat daca inaltimea nodului este mai mare ca a vf adiancet
            if(ver[u].h>ver[edge[i].v].h)
            {
                int flow=min(edge[i].capacity-edge[i].flow,ver[u].e_flow);
                ver[u].e_flow-=flow;
                ver[edge[i].v].e_flow+=flow;
                edge[i].flow+=flow;
                changereversenode(i,flow);
                return true;
            }
        }
    }
    return false;
}

void Graph::relabel(int u) {
    int mh=INT_MAX;
    //vf adj cu cea mai mica inaltime
    for(int i=0;i<edge.size();i++)
    {
        if(edge[i].u==u)
        {
            //daca flow==capacity nope
            if(edge[i].flow==edge[i].capacity)
                continue;
            if(ver[edge[i].v].h<mh)
            {
                mh=ver[edge[i].v].h;
                ver[u].h=mh+1;
            }
        }
    }
}

int Graph::getMaxFlow(int sursa, int endnode) {
    preflow(sursa);
    while(overFlowVertex(ver)!=-1)
    {
        int u= overFlowVertex(ver);
        if(!push(u))
            relabel(u);
    }
    return ver.back().e_flow;
}
int main(int argc,char* argv[]) {
//citire fisier
    int V,E;
    int x,y,c;
    int sursa=0;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    fin>>V>>E;
    //cout<<V<<E;
    Graph G(V);
    while(fin>>x>>y>>c)
    {
       G.addEdge(x,y,c);
    }

    fout<<G.getMaxFlow(0,V-1);
    fout.close();
    fin.close();
    return 0;
}
