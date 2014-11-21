#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include "primitive.h"

namespace Camus
{
class Polygon : public Primitive
{
  public:
    Polygon();
    void insert(size_t pos, Point &pt);
    void insert(size_t pos, Point &&pt);
  private:
    virtual PRIMITIVE_TYPE _type() const;
};
};

#endif /* POLYGON_H */
