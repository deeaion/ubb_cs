#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
class nod{
public:
    int val;
    int pred;
    bool frunza=true;
    bool in_graf=true;
    ~nod()=default;
};
nod get_min_frunza(vector<nod> &nodes)
{
    nod aux;
    aux.val=1000001;
    for(int i=0;i<nodes.size();i++)
    {
        if(nodes[i].frunza&&nodes[i].in_graf&&nodes[i].val<aux.val)
            aux=nodes[i];
    }
    return aux;

}
vector<int> prufer(vector<nod>& nodes) {
    vector<int> prufer_code;
    while(prufer_code.size()<nodes.size()-1)
    {
        nod aux= get_min_frunza(nodes);
        if(aux.val>nodes.size())
            break;
        prufer_code.push_back(aux.pred);
        nodes[aux.pred].frunza=true;
        nodes[aux.val].in_graf=false;
        //vad daca mai am in graf si cu acelasi p
        for(int i=0;i<nodes.size();i++)
            if(nodes[i].in_graf && nodes[i].pred == aux.pred)
            {
                nodes[aux.pred].frunza = false;
                break;
            }
    }

    return prufer_code;
}

int main(int argc, char** argv) {
    const char* input = argv[1];
    const char* output = argv[2];
    ifstream fin(input);

    int V;
    fin >> V;
    cout << V << endl;

    int n;
    int i=0;
    int rad=-1;
    nod n_g{-1,-1,true,true};
    vector<nod> nodes(V,n_g);
    while (fin >> n) {
        nodes[i].pred=n;
        nodes[i].val=i;
        if (n == -1) {
            nodes[n].frunza=false;
        }
        else
            nodes[n].frunza=false;
        i++;
    }
    fin.close();

    vector<int> prufer_code = prufer(nodes);
    ofstream fout(argv[2]);
    fout << prufer_code.size() << endl;
    for (int i : prufer_code) {
        fout << i << ' ';
    }
    fout << endl;
    fout.close();

    return 0;
}