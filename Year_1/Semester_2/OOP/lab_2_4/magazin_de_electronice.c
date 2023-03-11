#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#include <stdio.h>
#include "ui/ui.h"

int main() {
    ElectronicsStore* store=create_electronics_store(1);
    runConsole(store);
    _CrtDumpMemoryLeaks();
    return 0;
}
