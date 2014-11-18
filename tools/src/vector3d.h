#ifndef VECTOR3_H_
#define VECTOR3_H_
#include <math.h>
#include <cstring>
#include <algorithm>


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
        Vector3(void){
        }
        float* data()
        {
            return m_data;
        }
        ~Vector3(void){}
        float m_data[3];

        Vector3(const Vector3 &vec3)
        {
            std::copy(vec3.m_data,vec3.m_data + 3,m_data);
        }
        Vector3(float nx,float ny,float nz=0)
        {
            m_data[X] = nx;
            m_data[Y] = ny;
            m_data[Z] = nz;
        }

        Vector3& operator =(const Vector3& vec3)
        {
           std::copy(vec3.m_data,vec3.m_data + 3,m_data);
            return *this;
        }

        bool operator==(const Vector3& vec3) const
        {
            return (m_data[X]== vec3.m_data[X] 
            && m_data[Y] == vec3.m_data[Y] 
            && m_data[Z] == vec3.m_data[Z]);
        }
    
        bool operator != (const Vector3& vec3) const
        {
            return (m_data[X]!= vec3.m_data[X] 
            || m_data[Y] != vec3.m_data[Y] 
            || m_data[Z] != vec3.m_data[Z]);
        }
        float &operator[] (int index)
        {
            return m_data[index];
        }
        void zero()
        {
             memset(m_data,0,sizeof(m_data));
        }

        Vector3 operator + (const Vector3& vec3) const
        {
            return Vector3(m_data[X] + vec3.m_data[X],m_data[Y] + vec3.m_data[Y], m_data[Z] + vec3.m_data[Z]);
        }

        Vector3 operator - () const
        {
            return Vector3(-m_data[X], -m_data[Y], -m_data[Z]);
        }
    
        Vector3 operator * (float n) const
        {
            return Vector3(m_data[X] * n, m_data[Y] * n, m_data[Z] * n);
        }

        Vector3 operator / (float n) const
        {
            float oneOver = 1.0f / n;
            return Vector3(m_data[X] * oneOver, m_data[Y]* oneOver,m_data[Z]* oneOver);
        }

        Vector3& operator +=(const Vector3&vec)
        {
            m_data[X] += vec.m_data[X];
            m_data[Y] += vec.m_data[Y];
           m_data[Z] += vec.m_data[Z];
            return *this;
        }

        Vector3& operator -= (const Vector3& vec)
        {
            m_data[X] -= vec.m_data[X];
            m_data[Y] -= vec.m_data[Y];
            m_data[Z] -= vec.m_data[Z];
            return *this;
        }

        Vector3& operator *=(float a)
        {
            m_data[X] *= a;
            m_data[Y] *= a;
            m_data[Z] *= a;
            return *this;
        }

        Vector3& operator /=(float a)
        {
            float oneOver = 1.0f /a;
            m_data[X] *= oneOver;
            m_data[Y]*= oneOver;
            m_data[Z] *= oneOver;
        }
       const  float *vertices() const
        {
            return &m_data[X];
        }
        void normalized()
        {
            float magSq =  m_data[X]* m_data[X] + m_data[Y]* m_data[Y] +  m_data[Z]* m_data[Z];
            if (magSq > 0.0f)
            {
                float oneOverMag = 1.0f /sqrt(magSq);
                m_data[X] *= oneOverMag;
                m_data[Y] *= oneOverMag;
                m_data[Z] *= oneOverMag;
            }
        }

        float operator *(const Vector3& a) const
        {
            return m_data[X] * a.m_data[X]+ m_data[Y] * a.m_data[Y] + m_data[Z] * a.m_data[Z];
        }
    };

    //////////////////////////////////////////////////////////////////////////

    inline float VectorMag(const Vector3 &a)
    {
        return sqrt(a.m_data[Vector3::X]*a.m_data[Vector3::X] 
        + a. m_data[Vector3::Y]*a.m_data[Vector3::Y]
        +a.m_data[Vector3::Z]*a.m_data[Vector3::Z]);
    }
    // œÚ¡ø≤Ó≥À
    inline Vector3 CrossProduct(const Vector3 &lv,const Vector3 &rv)
    {
        return Vector3(lv.m_data[Vector3::Y]* rv.m_data[Vector3::Z] - lv.m_data[Vector3::Z] * rv.m_data[Vector3::Y], 
            lv.m_data[Vector3::Z] * rv.m_data[Vector3::X] - lv.m_data[Vector3::X] * rv.m_data[Vector3::Z],
            lv.m_data[Vector3::X] * rv.m_data[Vector3::Y] - lv.m_data[Vector3::Y] * rv.m_data[Vector3::X]);
    }

    inline float Distance(const Vector3 &lv,const Vector3 &rv)
    {
        float dx = lv.m_data[Vector3::X] - rv.m_data[Vector3::X];
        float dy = lv.m_data[Vector3::Y] - rv.m_data[Vector3::Y];
        float dz =  lv.m_data[Vector3::Z] - rv.m_data[Vector3::Z];
        return sqrt(dx * dx + dy * dy + dz * dz);
    }


    extern const Vector3 gcZeroVector;
}
#endif
