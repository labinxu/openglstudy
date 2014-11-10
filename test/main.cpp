#include <map>
#include <iostream>
#include <string.h>
#include "../tools/src/programer.h"


int main(int argc, char *argv[])
{
    using namespace Camus;
    Programer* pg = Programer::Instance();
    pg->init(argc, argv);

}
