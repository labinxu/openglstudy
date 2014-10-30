#ifndef GE_POINT_H_
#define GE_POINT_H_
#include "Types.h"
using namespace KaMi;
enum PtIndex
{
	X = 0 ,
	Y = 1,
	Z = 2
};

struct Color
{
    Color():R(0.0), G(0.0),B(0.0){}
    Color(GEfloat r,GEfloat g,GEfloat b):R(r), G(g), B(b){}

	GEfloat R;
	GEfloat G;
	GEfloat B;
};

struct GePoint2D
{
    GePoint2D():x(0.0), y(0.0){}
    GePoint2D(GEfloat xx,GEfloat yy):x(xx),y(yy){}
    GePoint2D(const GePoint2D& srcPt):x(srcPt.x), y(srcPt.y){}
    GePoint2D operator+(const GePoint2D& lfpoint)
    {
        return GePoint2D(x + lfpoint.x,y + lfpoint.y);
    }

    GePoint2D operator / (GEfloat n)
    {
        return GePoint2D(x/n, y/n);
    }


    GEfloat x;
    GEfloat y;
};


struct GePoint3D : public GePoint2D
{
	GePoint3D():GePoint2D(),z(0.0){}
	GePoint3D(GEfloat xx,GEfloat yy,GEfloat zz):GePoint2D(xx,yy),z(zz){}
	GePoint3D(const GePoint3D &srcPt):GePoint2D(srcPt.x,srcPt.y),z(srcPt.z){}

	GePoint3D operator+(const GePoint3D &lfpoint ) const
	{
		return GePoint3D(x + lfpoint.x ,y + lfpoint.y, z + lfpoint.z);
	}
	
	GePoint3D operator / (GEfloat n) const
	{
		return GePoint3D(x/n, y/n, z/n);
	}


	GePoint3D& operator = (const GePoint3D &lfpoint)
	{
		x = lfpoint.x;
		y = lfpoint.y;
		z = lfpoint.z;

		return *this;
	}
	GEfloat& operator[](PtIndex index)
	{
		switch(index)
		{
		case X: return x;
		case Y: return y;
		case Z: return z;
		}
	}

	GEfloat z;
};

#endif