#include "primitive.h"
#include <assert.h>
#include <gl/gl.h>
#include <iostream>


using namespace Camus;
Primitive::Primitive(){}
Primitive::~Primitive(){}
Points_Iter Primitive::begin()
{
    return _pts.begin();
}

Points_Iter Primitive::end()
{
    return _pts.end();
}

void Primitive::add(Point &&pt)
{
    _pts.push_back(pt);
}
void Primitive::add(Point &pt)
{
    _pts.push_back(pt);
}
