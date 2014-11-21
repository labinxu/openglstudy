#include "drawer.h"
#include "primitive.h"
#include "../os/openglapi.h"

using namespace Camus;


void Drawer::add(Primitive* p)
{
    _primitives.push_back(p);
}

void Drawer::draw()
{
    begin_draw();
    for (auto it: _primitives) {
        draw(it);
    }
    end_draw();

}
void Drawer::draw(Camus::Primitive *p)
{
    switch(p->type())
    {
        case PRIMITIVE_TYPE::LINE_LOOP:
            draw_polygon(p->begin(), p->end());
    };
};
