#include <iostream>
#include "Teste (cu relatie)/TestScurt.h"
#include "Teste (cu relatie)/TestExtins.h"
#include "Colectie/Colectie.h"
#include <assert.h>
#include <cstring>
#include <exception>

using namespace std;
void Test_adaugare()
{
    Colectie c;
    c.adaugaAparitii(5,10);
    assert(c.nrAparitii(10)==5);
    try
    {c.adaugaAparitii(-1,12);
}
    catch(const char* msg)
    {
        assert(strcmp(msg,"\nNumar de aparitii invalid")==0);

    }
    c.adaugaAparitii(1,20);
    assert(c.nrAparitii(20)==1);
    assert(c.dim()==6);
    assert(c.cauta(10)==true);
    assert(c.cauta(12)==false);
    assert(c.cauta(20)==true);
    c.adaugaAparitii(10,10);
    assert(c.nrAparitii(10)==15);
}
using namespace std;
int main() {
    testAll();
    testAllExtins();
    Test_adaugare();
    cout<<"Finished all tests!";
    return 0;
}
