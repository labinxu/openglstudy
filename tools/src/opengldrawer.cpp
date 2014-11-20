#include "opengldrawer.h"

using namespace Camus;


void OpenGlDrawer::drawLine(Point &pt1, Point &pt2)
{
    glBegin(GL_LINES);
    glVertex3fv(pt1.data());
    glVertex3fv(pt2.data());
    glEnd();
}

void OpenGlDrawer::drawPolygon(std::list<Point>::iterator beg, std::list<Point>::iterator end)
{
    glBegin(GL_POLYGON);
    for (; beg != end; ++beg) {
        glVertex3fv(beg->data());
    }
    glEnd();
}

