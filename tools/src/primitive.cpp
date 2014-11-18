#include "primitive.h"
#include <assert.h>
#include <gl/gl.h>
#include <iostream>


using namespace Camus;
Drawer *GlobalDrawer=NULL;
void InitDrawer(Drawer*drawer)
{
    GlobalDrawer = drawer;
    std::cout<<"init drawer initialize"<<std::endl;
}

void Drawer::show()
{
    for (auto it:m_primitives) {
        it->show();
    }
    return;

}
void OpenGlDrawer::drawLine(Point &pt1, Point &pt2)
{
    glBegin(GL_LINES);
    glVertex2fv(pt1.data());
    glVertex2fv(pt2.data());
    glEnd();
}

void Line::draw()
{
    assert(GlobalDrawer != NULL);
    GlobalDrawer->drawLine(start_pt, end_pt);
}
