#ifndef DRAWER_H
#define DRAWER_H
#include <vector>
#include "point.h"
namespace Camus
{
class Primitive;
typedef std::vector<Primitive*> Primitives;
class Drawer
{
  public:
    void show();
    void draw();
    void add(Primitive *p);
  protected:
    void draw(Primitive*p);
    virtual void begin_draw(){}
    virtual void end_draw(){}
  protected:
    Primitives _primitives;
};

}

#endif /* DRAWER_H */
