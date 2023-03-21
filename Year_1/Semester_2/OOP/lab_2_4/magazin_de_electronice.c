
#include "ui/ui.h"
#include "tests/test.h"
int main() {
    MyList* store= createList(1);
    test_all();
    runConsole(store);
    return 0;
}
