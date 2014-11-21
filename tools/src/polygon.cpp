#include "polygon.h"

using namespace Camus;

Polygon::Polygon()
{}

PRIMITIVE_TYPE Polygon::_type() const
{
    return PRIMITIVE_TYPE::LINE_LOOP;
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
