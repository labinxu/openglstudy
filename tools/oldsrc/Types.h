
#ifndef TYPES_H_
#define TYPES_H_

namespace Camus{

typedef float GEfloat; 
typedef int kmInt32;

typedef unsigned int kmObjectId;

typedef float kmfloat;
struct kmColor
{
    kmColor(kmfloat r,kmfloat g,kmfloat b,kmfloat a = 1)
        :R(r),G(g),B(b),A(a){} 
    kmColor()
        :R(0),G(0),B(0),A(0){}
    kmColor(const kmColor&cl):R(cl.R),G(cl.G),B(cl.B),A(cl.A){}
 
    bool operator != (const kmColor&cl)
    {
        return (cl.R != R || cl.G != G || cl.B != B || cl.A != A);
    }
    kmfloat R;
    kmfloat G;
    kmfloat B;
    kmfloat A;
};


}
#endif