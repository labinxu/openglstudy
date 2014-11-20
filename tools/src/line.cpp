#include "line.h"
using namespace Camus;

void Line::draw()
{
    assert(GlobalDrawer != NULL);
    GlobalDrawer->drawLine(start_pt, end_pt);
}
