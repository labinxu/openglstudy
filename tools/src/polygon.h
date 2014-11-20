#ifndef POLYGON_H
#define POLYGON_H

#include <list>
#include "primitive.h"

namespace Camus
{
class Polygon : public Primitive
{
  public:
    Polygon(){}
    void add(Point &&pt);
    void add(Point &pt);
    void insert(size_t pos, Point &pt);
    void insert(size_t pos, Point &&pt);
  private:
    void draw();
    std::list<Point> _pts;
};
};



#endif /* POLYGON_H */
