#include <iostream>
using namespace std;
int main()
{
    struct circle
    {
        float r;
    };
    struct circle c;
    float pi = 3.14;
    cout << "Introduceti raza cercului: ";
    cin >> c.r;
    cout << "Perimetrul cercului este: ";
    cout << 2 * pi * c.r;
    cout << "\nAria cercului este: ";
    cout << pi * c.r * c.r;
}