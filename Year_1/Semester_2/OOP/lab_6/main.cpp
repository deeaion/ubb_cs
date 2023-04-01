#include <iostream>
#include "domain/Subject.h"
#include "repository/SubjectsRepo.h"
#include "service/SubjectsService.h"
#include "ui/SubjectsUi.h"

using std::cout;

int main() {
    cout << "Program is starting\n";
    SubjectsRepo rep;
    ValidatorSubject val;
    SubjectsService ctr{rep, val};
    SubjectsUi ui{ctr};
    ui.start();

    return 0;
}
