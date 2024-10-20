#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Introduceti numarul de elemente: ";
    cin >> n;
    int sum = 0;
    int i = 0;
    while (i < n)
    {
        int x;
        cout << "Introduceti elementul: ";
        cin >> x;
        sum = sum + x;
        i = i + 1;
    }
    cout << "Suma este: ";
    cout << sum;
}