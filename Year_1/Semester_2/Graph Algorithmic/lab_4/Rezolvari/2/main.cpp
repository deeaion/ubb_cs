#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> cod;
class nod{
public:
    int pred;
    ~nod()=default;
};
int get_min()
{
    vector<bool> fr(cod.size()+1,false);
    for(auto &i:cod)
    {
        fr[i]=true;
    }
 for(int i=0;i<=cod.size();i++)
     if(fr[i]== false)
         return i;
 return -1;

}
void decode(vector<nod>& nodes) {
    for(int i=0;i<nodes.size()-1;i++)
    {
        int min=get_min();
        int x=cod.front();
        nodes[min].pred=x;
        cod.pop_front();
        cod.push_back(min);
    }


    }

int main(int argc, char** argv) {
    const char* input = argv[1];
    const char* output = argv[2];
    ifstream fin(input);

    int l;
    fin >> l;
    cout << l << endl;

    int n=l+1;
    int i=0;
    int rad=-1;
    vector<int> prufer_c;
    vector<nod> nodes(n,nod(-1));
    for(int i=0;i<l;i++)
    {
        int nr;
        fin>>nr;
        cod.push_back(nr);
    }


    fin.close();
    //fin.close();
    decode(nodes);
    ofstream fout(argv[2]);
    fout << nodes.size() << endl;
    for (auto i : nodes) {
        fout << i.pred << " ";
    }
    fout << endl;
     fout.close();

    return 0;
}