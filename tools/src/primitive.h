#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "point.h"
#include <list>
#include <vector>
#include <iostream>


namespace Camus
{
typedef std::vector<Point> Points;
typedef std::vector<Point>::iterator Points_Iter;

enum PRIMITIVE_TYPE{
    POINTS=0x0000,
    LINES = 0x0001,
    LINE_LOOP = 0x0002,
    LINE_STRIP = 0x0003,
    TRIANGLES= 0x0004,
    TRIANGLE_STRIP = 0x0005,
    TRIANGLE_FAN = 0x0006
};



class Primitive
{
  public:
    Primitive();
    virtual ~Primitive();
    PRIMITIVE_TYPE type()
    {
        return _type();
    };
    void add(Point &&pt);
    void add(Point &pt);

    virtual Points_Iter begin();
    virtual Points_Iter end();
  protected:
    Points _pts;
  private:
    virtual PRIMITIVE_TYPE _type() const = 0;

};


};

#endif /* PRIMITIVE_H */
