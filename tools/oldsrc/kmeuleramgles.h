#ifndef KM_EULERANGLES_H_
#define KM_EULERANGLES_H_

#include "Types.h"
namespace Camus{

    class kmQuaternion;
    class kmMatrix4x3;
    class RotationMatrix;

    class kmEulerAngles
    {
    public:
        kmEulerAngles(void);
        ~kmEulerAngles(void);
        kmEulerAngles(kmfloat h,kmfloat p,kmfloat b);
    public:
        // zero
        void identity()
        {
            m_heading = m_pitch = m_bank = 0.0f;
        }
        // transform to restrict set.
        void canonize();

    public:
        kmfloat m_heading;
        kmfloat m_pitch;
        kmfloat m_bank;

    public:
        void fromObjectToInertialQuaternion(const kmQuaternion &q);
        void fromInertialToObjectQuaternion(const kmQuaternion &q);
        void fromObjectToWorldMatrix(const kmMatrix4x3 &m);
    };

}
#endif
