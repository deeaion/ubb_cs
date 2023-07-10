#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main(){

    double Ew;
    double Te;
    cin>>Te>>Ew;
    double sum=0.5+0.25+1+0.05*10+0.05*9+0.2*9;
    sum+=0.3*Ew+0.15*10+0.15*Te;
    cout<<floor(sum)<<sum;
    return 0;
}
