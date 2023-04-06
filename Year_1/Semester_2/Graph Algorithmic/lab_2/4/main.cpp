#include <iostream>
#include <fstream>
#include <queue>

#define INF 1000
using namespace std;

void citire_muchii(vector<int> muchii[], int &nr_noduri) {
    ifstream file("../graf.txt");
    file>>nr_noduri;
    int nod_min=1;
    int nod, nod_vecin;// pentru salvarea muchiilor
    while (file >> nod >> nod_vecin) {
        muchii[nod].push_back(nod_vecin);

    }
}

void printare_muchii(int nr_noduri, vector<int> muchii[]) {
    cout << "Muchiile introduse" << endl;
    for (int i = 1; i <= nr_noduri; i++) {
        cout << "Nodul: " << i << ". Vecini: ";
        for (int j: muchii[i])
            cout << j << ", ";
        cout << endl;
    }
    cout << endl;
}

void BFS(const vector<int> adj_list[100], int nr_noduri, int source) {
    //o fac cu o lista de adiacenta

//avem un start
// printez toate drumuriile
//avem un vector de vizitati booleana
    int len=nr_noduri+2;
    vector<bool> visited(len, false);
    vector<int> order;
    queue<int> q;
    vector<int> distance(len, INF);
    q.push(source);
//avem ordinea
//in coada pun varfurile vizitate
//initializez cu sursa
//extrag din coada
    visited[source] = true;
    distance[source] = 0;
    while (!q.empty()) {//caut vizitatorii
        int x = q.front();
        q.pop();
        order.push_back(x);

        for (int v: adj_list[x]) {
            if (!visited[v]) {
                visited[v] = true;
                distance[v]=distance[x]+1;
                q.push(v);
            }
        }
    }
    cout<<"Noduri descoperite : ";
    for(int i=0;i<order.size();i++)
    {
        cout<<order[i]<<" ";
    }
    cout<<endl;
    int n=1;
    for (int i=1;i<=nr_noduri;i++) {
        if(distance[i]<INF)
        {cout << "d( " <<source<<", "<< n <<")= "<<distance[i]<< endl;}
        else
        cout << "d( " <<source<<", "<< n <<")=INF"<< endl;
        n++;

    }
}

int main() {
    vector<int> l_adj[100];
    int nr_noduri, nod;
    citire_muchii(l_adj, nr_noduri);
    printare_muchii(nr_noduri, l_adj);
    cout << "Dati nodul: ";
    cin >> nod;
    cout << "\n";
    cout << "Nodul " << nod << "are urmatoarele drumuri: \n";
    BFS(l_adj,nr_noduri,nod);
    return 0;
}
