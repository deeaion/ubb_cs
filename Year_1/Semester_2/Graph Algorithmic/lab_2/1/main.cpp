#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define INF 1000
using namespace std;
void citire_muchii(vector<int>muchii[], int &nr_noduri) {
    ifstream file("../graf.txt");
    file >> nr_noduri;
    int i = 0;
    int nod, nod_vecin;// pentru salvarea muchiilor
    while (file >> nod >> nod_vecin) {
        muchii[nod].push_back(nod_vecin);
    }
}
void printare_muchii(int nr_noduri, vector<int>muchii[]) {
    cout << "Muchiile introduse" << endl;
    for (int i= 1; i<=nr_noduri; i++) {
        cout << "Nodul: " << i <<". Vecini: ";
        for(int j : muchii[i])
            cout<<j<<", ";
        cout<<endl;
    }
    cout << endl;
}
void menu(int &opt)
{
    cout<<"\n\t1->Introduce node.\n\t0->Exit\n";
    cin>>opt;
}
void Moore_Algorithm_path(int node,int end_node,vector<int>muchii[],int nr_nodes)
{
    vector<int> l_vec(nr_nodes,INF);
    vector<int> parent(nr_nodes,-1);
    queue<int> Q;
    l_vec[node-1]=0;
    parent[node-1]=0;
    Q.push(node);
    int x;
    while(!Q.empty())
    {
        x=Q.front();
        //now u can ge it out of the queue
        Q.pop();
        for(int j: muchii[x])
        {
            if(l_vec[j-1]==INF)
            {
                parent[j-1]=x;
                l_vec[j-1]=l_vec[x-1]+1;
                Q.push(j);
            }
        }
    }
    int k=l_vec[end_node-1];
    if(k<INF) {
        cout << "Lungime end node:" << k << endl;

        vector<int> path(k);
        k--;
        path[k] = end_node;
        while (k > 0) {
            path[k - 1] = parent[path[k] - 1];
            k--;
        }
        cout << "Shortest path\n";
        cout << node << " ,";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << ", ";
        }
    }
    else
        cout<<"There is no road"<<endl;


}
int main() {
   int nr_noduri,nr_muchii;
   vector<int> muchii[105];
   int opt=-1;
   citire_muchii(muchii,nr_noduri);
   printare_muchii(nr_noduri,muchii);
   while(true)
   {
       opt=-1;
       menu(opt);
       if(opt==1)
       {
           int node,end_node;
           cout<<"Introduce beginning node: ";
           cin>>node;
           cout<<endl;
           cout<<"Introduce end node: ";
           cin>>end_node;
           cout<<endl;
           Moore_Algorithm_path(node,end_node,muchii,nr_noduri);

       }
   }

    return 0;
}
