#include<fstream>
#include <cstring>
#include<string>
#include<deque>
#include <queue>
#include<vector>
#include <iostream>
#include <windows.h>
using namespace std;
ifstream f("../labirint_1.txt");
ofstream g("../out.txt");

int n;
int m;
//fiecare celula are cate o cordonata
struct Cell
{
    int x;
    int y;
};
//declarama nod de coada
struct queueNode
{
    Cell pt;
    int dist;
};
//verificare validitate
bool checkValid(int row,int col)
{
    return ((row>=0))&&(row<n) && (col>=0) && (col<m);
}

//Posibile pozitii!
int rowNum[]={-1,0,0,1};
int colNum[]={0,-1,1,0};
void printare_matrice(const vector<vector<int>>& matrix,int n,int m)
{
    for(int i=0;i<n;i++)
    {for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j];
        }
        cout<<endl;}
}
void print_path(vector<vector<int>>& matrix,int n,int m,Cell start,Cell end)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {

            if(i==start.x&&j==start.y)
            {
                cout<<'S';
            }
            else if(i==end.x&&j==end.y)
            {
                cout<<'F';
            }
            else if(matrix[i][j]==0)
                cout<<'1';
            else if(matrix[i][j]==3)
            {
                SetConsoleTextAttribute(hConsole, 4);
                cout<< 'x';
                SetConsoleTextAttribute(hConsole, 10);
            }
            else if(matrix[i][j]==1)
                cout<<' ';
        }
        cout<<endl;
    }
}
int bfsLee(vector<vector<int>>& matrix, Cell src,Cell dest)
{   ;
    int drum_min;
    if(matrix[src.x][src.y]!=1||matrix[dest.x][dest.y]!=1)
        throw "THERE IS NO WAY TO GET A ROAD!";
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    //Mark nod sursa as visited
    visited[src.x][src.y]=true;
    queue<queueNode> q;
    queueNode s = {src, 0};
    q.push(s); // Enqueue source cell
    //creeam un parent vector ca sa putem afisa calea!
    vector<Cell> parent(n*m,{-1,-1});
    parent[src.x]=src;
    // Performing BFS starting from source cell
    while (!q.empty())
    {
        queueNode curr = q.front();
        Cell pt = curr.pt;

        // daca am ajuns la sf returnam distanta finala
        if (pt.x == dest.x && pt.y == dest.y)
        {
            int dist=curr.dist;
            vector<Cell> path(dist+1);
            Cell p=parent[pt.x*m+pt.y];
            path[dist]=pt;
            while (p.x != -1 && p.y != -1)
            {
                path[--dist] = p;
                p = parent[p.x * m + p.y];
            }
            for (int i = 0; i < path.size(); i++)
            {
//                cout << "(" << path[i].x << ", " << path[i].y << ")";
                int x=path[i].x;
                int y=path[i].y;
                matrix[x][y]=3;
//                if (i != path.size() - 1)
//                    cout << " -> ";
            }
            cout << endl;
            print_path(matrix,n,m,src,dest);
            return curr.dist;
        }

        q.pop();
        // Otherwise enqueue its adjacent cells with value 1
        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            // Enqueue valid adjacent cell that is not visited
            if (checkValid(row, col) && matrix[row][col] &&
                !visited[row][col])
            {

                visited[row][col] = true;
                queueNode Adjcell = { {row, col},curr.dist + 1 };
                q.push(Adjcell);
                parent[row*m+col]=pt;
            }
        }
    }

    // Return -1 if destination cannot be reached
    return -1;
}


int main()
{
    char *str= new char[50000];
    f.getline(str, 50000);
    vector<vector<int>> a(50000,vector<int>(50000,0));
    int xstart,ystart,xfinish,yfinish;
    m = strlen(str)+1;
    n = 0;
    while (!f.eof())
    {
        for (int i = 0; i < m; i++) {
            if (str[i] == 'S')
            {
                xstart = n;
                ystart = i+1;
                a[n][i+1] = 1;
            }
            else if (str[i] == 'F')
            {
                xfinish = n;
                yfinish = i+1;
                a[n][i+1] = 1;
            }
            else if (str[i] == '1')
            {
                a[n][i+1] = 0;
            }
            else {
                a[n][i+1] = 1;
            }
        }
        n++;
        f.getline(str, 1000);
    }
    for (int i = 0; i < m; i++) {
        if (str[i] == 'S')
        {
            xstart = n;
            ystart = i + 1;
            a[n][i + 1] = 1;
        }
        else if (str[i] == 'F')
        {
            xfinish = n;
            yfinish = i + 1;
            a[n][i + 1] = 1;
        }
        else if (str[i] == '1')
        {
            a[n][i + 1] = 0;
        }
        else {
            a[n][i + 1] = 1;
        }
    }
    n++;

    //printare_matrice(a,n,m);
    Cell start={xstart,ystart};
    Cell finish={xfinish,yfinish};
    try
    {bfsLee(a,start,finish);}
    catch (const char* e)
    {
     cout<<e;
    }
    //printare_matrice(a,n,m);
    delete[] str;
    return 0;
}
