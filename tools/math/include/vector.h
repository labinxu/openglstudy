#ifndef VECTOR3_H_
#define VECTOR3_H_
#include <algorithm>
#include <math.h>
#include "Types.h"

namespace Camus
{
    class Vector3
    {
    public:
        enum
        {
            X = 0,
            Y = 1,
            Z = 2
        };
        Vector3(void)
        {
            memset(data,0,sizeof(data));
        }
        ~Vector3(void){}
        float data[3];

        Vector3(const Vector3 &vec3)
        {
            std::copy(vec3.data,vec3.data + 3,data);
        }
        Vector3(float nx,float ny,float nz=0)
        {
            data[X] = nx;
            data[Y] = ny;
            data[Z] = nz;
        }

        Vector3& operator =(const Vector3& vec3)
        {
           std::copy(vec3.data,vec3.data + 3,data);
            return *this;
        }

        bool operator==(const Vector3& vec3) const
        {
            return (data[X]== vec3.data[X] 
            && data[Y] == vec3.data[Y] 
            && data[Z] == vec3.data[Z]);
        }
    
        bool operator != (const Vector3& vec3) const
        {
            return (data[X]!= vec3.data[X] 
            || data[Y] != vec3.data[Y] 
            || data[Z] != vec3.data[Z]);
        }
        float &operator[] (int index)
        {
            return data[index];
        }
        void zero()
        {
             memset(data,0,sizeof(data));
        }

        Vector3 operator + (const Vector3& vec3) const
        {
            return Vector3(data[X] + vec3.data[X],data[Y] + vec3.data[Y], data[Z] + vec3.data[Z]);
        }

        Vector3 operator - () const
        {
            return Vector3(-data[X], -data[Y], -data[Z]);
        }
    
        Vector3 operator * (float n) const
        {
            return Vector3(data[X] * n, data[Y] * n, data[Z] * n);
        }

        Vector3 operator / (float n) const
        {
            float oneOver = 1.0f / n;
            return Vector3(data[X] * oneOver, data[Y]* oneOver,data[Z]* oneOver);
        }

        Vector3& operator +=(const Vector3&vec)
        {
            data[X] += vec.data[X];
            data[Y] += vec.data[Y];
           data[Z] += vec.data[Z];
            return *this;
        }

        Vector3& operator -= (const Vector3& vec)
        {
            data[X] -= vec.data[X];
            data[Y] -= vec.data[Y];
            data[Z] -= vec.data[Z];
            return *this;
        }

        Vector3& operator *=(float a)
        {
            data[X] *= a;
            data[Y] *= a;
            data[Z] *= a;
            return *this;
        }

        Vector3& operator /=(float a)
        {
            float oneOver = 1.0f /a;
            data[X] *= oneOver;
            data[Y]*= oneOver;
            data[Z] *= oneOver;
        }
       const  float *vertices() const
        {
            return &data[X];
        }
        void normalized()
        {
            float magSq =  data[X]* data[X] + data[Y]* data[Y] +  data[Z]* data[Z];
            if (magSq > 0.0f)
            {
                float oneOverMag = 1.0f /sqrt(magSq);
                data[X] *= oneOverMag;
                data[Y] *= oneOverMag;
                data[Z] *= oneOverMag;
            }
        }

        float operator *(const Vector3& a) const
        {
            return data[X] * a.data[X]+ data[Y] * a.data[Y] + data[Z] * a.data[Z];
        }
    };

    //////////////////////////////////////////////////////////////////////////

    inline float VectorMag(const Vector3 &a)
    {
        return sqrt(a.data[Vector3::X]*a.data[Vector3::X] 
        + a. data[Vector3::Y]*a.data[Vector3::Y]
        +a.data[Vector3::Z]*a.data[Vector3::Z]);
    }
    // œÚ¡ø≤Ó≥À
    inline Vector3 CrossProduct(const Vector3 &lv,const Vector3 &rv)
    {
        return Vector3(lv.data[Vector3::Y]* rv.data[Vector3::Z] - lv.data[Vector3::Z] * rv.data[Vector3::Y], 
            lv.data[Vector3::Z] * rv.data[Vector3::X] - lv.data[Vector3::X] * rv.data[Vector3::Z],
            lv.data[Vector3::X] * rv.data[Vector3::Y] - lv.data[Vector3::Y] * rv.data[Vector3::X]);
    }

    inline float Distance(const Vector3 &lv,const Vector3 &rv)
    {
        float dx = lv.data[Vector3::X] - rv.data[Vector3::X];
        float dy = lv.data[Vector3::Y] - rv.data[Vector3::Y];
        float dz =  lv.data[Vector3::Z] - rv.data[Vector3::Z];
        return sqrt(dx * dx + dy * dy + dz * dz);
    }


    extern const Vector3 gcZeroVector;
}
#endif
