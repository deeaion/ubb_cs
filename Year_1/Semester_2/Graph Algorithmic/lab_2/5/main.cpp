#include <fstream>
#include <queue>
#include <iostream>
using namespace std;

void citire_muchii(vector<int> muchii[], int &nr_noduri) {
    ifstream file("../graf.txt");
    file>>nr_noduri;
    int nod, nod_vecin;// pentru salvarea muchiilor
    while (file >> nod >> nod_vecin) {
        muchii[nod].push_back(nod_vecin);

    }
}
vector<vector<int>> matrice_de_adiacenta(int noduri,vector<int>l_adj[])
{
    vector<vector<int>> matrice_adiacenta(noduri+1,vector<int>(noduri+1,0));

    int i;
    for (i=1;i<=noduri;i++)
    {
        for(int j:l_adj[i])
        {
            matrice_adiacenta[i][j]=1;
        }
    }
    return matrice_adiacenta;
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
void printare_matrice(const vector<vector<int>>& matrix,int nr_noduri)
{
    for(int i=1;i<=nr_noduri;i++)
    {for(int j=1;j<=nr_noduri;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;}
}

void DFS(vector<bool>& visited, const vector<vector<int>>& matrix,int nr_noduri,int nod)
{
    visited[nod]=true;
    for(int i=1;i<=nr_noduri;i++)
    {
        if(!visited[i] && matrix[nod][i] == 1)
        {
            cout<<i<<" ";
            visited[i]=true;
            DFS(visited,matrix,nr_noduri,i);
        }
    }
}

int main() {
    vector<int> l_adj[100];
    int nr_noduri, nod;
    citire_muchii(l_adj, nr_noduri);
    cout<<"Adjaency Matrix: \n";
    const vector<vector<int>> matrix=matrice_de_adiacenta(nr_noduri,l_adj);
    printare_matrice(matrix,nr_noduri);
    cout<<"Your node: ";
    cin>>nod;
    cout<<endl;
    cout<<endl<<endl<<"Nodes descovered in the recursive call of DFS:\n";
    vector<bool> visited(nr_noduri,false);
    DFS(visited,matrix,nr_noduri,nod);
    return 0;
}
