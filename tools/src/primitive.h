#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "point.h"
#include <list>
#include <iostream>

namespace Camus
{
class Primitive
{
  public:
    Primitive(){}
    void show(){draw();}

  protected:
    virtual void draw() = 0;
};

extern Drawer *GlobalDrawer;
};

#endif /* PRIMITIVE_H */
