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
void huffmanDecode(ofstream &fout,ifstream &fin)
{
    multimap<nod,string> Q;
   string line;cout<<"AAAAAAAAAAAA";
   getline(fin,line);
   cout<<line;
   if(line=="")
       return;
   int letters=stoi(line);
    vector<int> frequency(256,0);
   for(int i=0;i<letters;++i)
   {
       getline(fin,line);
       char chr=line[0];
       frequency[int(chr)]=stoi(line.substr(2));
       Q.insert({nod{chr,frequency[int(chr)]},string(1,chr)});
   }
   string hufman;
   getline(fin,hufman);
   fin.close();
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
    map<string,char> codes;
    for(int i=0;i<256;++i)
    {
        if(code[i]!="\0")
        {
            codes.insert({code[i],i});
        }
    }
    int prev=0,size=0;
    string last,chr;
    string text="";
    while (codes.size() > 1)
    {
        string until = hufman.substr(prev, size);
        size++;
        auto searched = codes.find(until);
        if (searched != codes.end())
        {
            last = until;
            chr = searched->second;
        }
        else if (searched == codes.end() && last != "\0")
        {
            text+=chr;
            frequency[int(chr[0])]--;

            if (frequency[int(chr[0])] == 0)
            {
                codes.erase(last);
            }

            prev += last.size();
            size= 0;
            last = "\0";
            chr = "\0";
        }
    }
    if(codes.size()==1)
    {
        text.append(string(1,codes.begin()->second));

    }
    fout<<text;
}

int main(int argc, char** argv) {
    const char* input = argv[1];
    const char* output = argv[2];
    ifstream fin(input);
    string text;
    ofstream fout(output);
    huffmanDecode(fout,fin);
    fout.close();
    return 0;
}