#ifndef KM_SPHERE_H
#define KM_SPHERE_H
#include "KaMiObject.h"
#include "Vector3.h"
#include "Types.h"

namespace KaMi{
    class kmSphere :public kmObject
    {
    public:
        kmSphere(void);
        kmSphere(const kmVector3 &orgpt,kmfloat radius);
        ~kmSphere(void);
        void draw();
    private:
        kmVector3 m_centerpt;
        kmfloat m_radius;

        kmInt32 m_divideNum;
    };

}

#endif