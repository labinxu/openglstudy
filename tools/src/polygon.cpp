#include "polygon.h"

using namespace Camus;

extern Drawer *GlobalDrawer;
void Polygon::add(Point &&pt)
{
    _pts.push_back(pt);
}
void Polygon::add(Point &pt)
{
    _pts.push_back(pt);
}

void Polygon::insert(size_t pos, Point&&pt)
{
    auto itpos = _pts.begin();
    std::advance(itpos, pos);
    _pts.insert(itpos, pt);
}

void Polygon::insert(size_t pos, Point &pt)
{
    auto itpos = _pts.begin();
    std::advance(itpos, pos);
    _pts.insert(itpos, pt);
}

void Polygon::draw()
{
    GlobalDrawer->drawPolygon(_pts.begin(), _pts.end());
}
