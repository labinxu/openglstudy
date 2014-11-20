#ifndef OPENGLDRAWER_H
#define OPENGLDRAWER_H
#include "drawer.h"

namespace Camus
{
class OpenGlDrawer: public Drawer
{
  public:
    virtual void drawLine(Point &pt1, Point &pt2);
    virtual void drawPolygon(std::list<Point>::iterator beg, std::list<Point>::iterator end);
    }

};
};


#endif /* OPENGLDRAWER_H */
