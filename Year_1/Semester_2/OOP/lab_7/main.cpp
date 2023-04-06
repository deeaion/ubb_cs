#include <iostream>
#include "domain/Subject.h"
#include "repository/SubjectsRepo.h"
#include "service/SubjectsService.h"
#include "ui/SubjectsUi.h"
#include "tests/Tests.h"
using std::cout;

int main() {
    Tests tests;
    tests.testAll();
    cout << "Program is starting\n";
    DynamicVector<Subject> vector;
    SubjectsRepo rep(vector);
    ValidatorSubject val;
    SubjectsService ctr{rep, val};
    SubjectsUi ui{ctr};

    //ui.start();
    return 0;
}
