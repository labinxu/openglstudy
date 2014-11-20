#ifndef DRAWER_H
#define DRAWER_H
#include "point.h"
#include <list>

namespace Camus
{
class Primitive;
class Drawer
{
  public:
    void show();
    virtual void drawLine(Point &pt1, Point &pt2){}
    virtual void drawPolygon(std::list<Point>::iterator beg, std::list<Point>::iterator end){}
    void add(Primitive *p)
    {m_primitives.push_back(p);}

  protected:
    std::list<Primitive*> m_primitives;
};

}

#endif /* DRAWER_H */
