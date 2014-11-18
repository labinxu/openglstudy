#ifndef PRIMITIVE_H
#define PRIMITIVE_H
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
    void add(Primitive *p)
    {m_primitives.push_back(p);}


  protected:
    std::list<Primitive*> m_primitives;
};

class OpenGlDrawer: public Drawer
{
  public:
    virtual void drawLine(Point &pt1, Point &pt2);

};
class Primitive
{
  public:
    Primitive(){}
    void show(){draw();}

  protected:
    virtual void draw() = 0;
};

class Line: public Primitive
{
  public:
    Line(Point &pt1, Point &pt2)
            :start_pt(pt1), end_pt(pt2){}

  private:
    virtual void draw();
    Point start_pt;
    Point end_pt;
};
};

#endif /* PRIMITIVE_H */
