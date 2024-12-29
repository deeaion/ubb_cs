#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

int main() {
    ifstream file("reguli.txt");
    if (!file) {
        cerr << "Nu pot deschide fisierul!" << endl;
        return 1;
    }

    set<char> neterminale;
    set<char> terminale;
    string startSymbol;
    set<string> reguli;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        reguli.insert(line); 

        char neterminal = line[0];
        neterminale.insert(neterminal);
        if (startSymbol.empty()) {
            startSymbol = neterminal; 
        }

        size_t arrowPos = line.find("->");
        if (arrowPos != string::npos) {
            string dreapta = line.substr(arrowPos + 2);
            for (char ch : dreapta) {
                if (islower(ch) || ch == 'ε') { 
                    terminale.insert(ch);
                } else if (isupper(ch)) { 
                    neterminale.insert(ch);
                }
            }
        }
    }

    file.close();

    cout << "Simbolul de start: " << startSymbol << endl;
    cout << "Neterminale: ";
    for (char nt : neterminale) cout << nt << " ";
    cout << endl;

    cout << "Terminale: ";
    for (char t : terminale) {
        if (t != 'ε') cout << t << " "; 
    }
    cout << endl;

    cout << "Reguli de productie:" << endl;
    for (const string& regula : reguli) {
        cout << regula << endl;
    }

    return 0;
}
