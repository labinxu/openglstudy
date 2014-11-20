#include "drawer.h"
#include "primitive.h"

using namespace Camus;

void Drawer::show()
{
    for (auto it:m_primitives) {
        it->show();
    }
    return;

}
