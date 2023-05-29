#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;
class nod{
public:
    int freq=0;
    char chr=0;
    bool frunza=true;
    nod *left,*right;
    bool operator<(const nod&oth) const
    {
        return freq<oth.freq||(freq==oth.freq && chr<oth.chr);
    }
    nod(char ch,int fr)
    {
        left=right= nullptr;
        chr=ch;
        freq=fr;
    }
    ~nod()=default;
};
void huffman(ofstream &fout,string line)
{
    if(line=="")
        return;
    vector<int> frequency(256,0);
    int letters=0;
    for(auto c:line)
    {
        frequency[int(c)]++;
        if(frequency[int(c)]==1)
            letters++;
    }
    fout<<letters<<endl;
    multimap<nod,string> Q;
    for(int i=0;i<256;i++)
    {
        if(frequency[i]) {
            fout << char(i) << " " << frequency[i] << "\n";
            Q.insert({nod{char(i), frequency[i]}, string(1, i)});
        }
    }
    string code[256];
    while(letters!=1)
    {
        letters--;
        auto x=*Q.begin();
        for(auto c:x.second)
        {
            code[int(c)]="0"+code[int(c)];
        }
        Q.erase(Q.begin());

        auto y=*Q.begin();
        for(char c:y.second)
        {
            code[int(c)]="1"+code[int(c)];

        }
        Q.erase(Q.begin());
        Q.insert({nod {min(x.first.chr,y.first.chr),x.first.freq+y.first.freq},
                 x.second+y.second});
    }
    for(char chr:line)
    {
        fout<<code[int(chr)];
    }
}

int main(int argc, char** argv) {
    const char* input = argv[1];
    const char* output = argv[2];
    ifstream fin(input);
    string text;
    getline(fin,text);
    fin.close();
    ofstream fout(output);

    huffman(fout,text);
    fout.close();
    return 0;
}