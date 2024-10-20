#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Introduceti 2 numere naturale: ";
    cin >> a;
    cin >> b;
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    cout << "Cmmdc este: ";
    cout << a;
}