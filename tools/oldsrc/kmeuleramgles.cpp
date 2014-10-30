#include "kmEulerAmgles.h"
#include "kmMathUtil.h"

namespace Camus{
kmEulerAngles::kmEulerAngles(void)
{
}

kmEulerAngles::~kmEulerAngles(void)
{
}

void kmEulerAngles::fromObjectToInertialQuaternion( const kmQuaternion &q )
{
    
}

void kmEulerAngles::canonize()
{
    // transform pitch into [-pi pi]
    m_pitch = WrapPi(m_pitch);
    // transform pitch into [-pi/2 pi/2]
    if (m_pitch < - kmPiOver2)
    {
        m_pitch = -kmPi - m_pitch;
        m_heading += kmPi;
        m_bank += kmPi;

    }
    else if(m_pitch > kmPiOver2)
    {
        m_pitch = kmPi - m_pitch;
        m_heading += kmPi;
        m_bank += kmPi;

    }

    if (fabs(m_pitch) > kmPiOver2)
    {
        m_heading += m_bank;
        m_bank = 0.0f;
    }
    else
    {
        m_bank = WrapPi(m_bank);
    }

    m_heading = WrapPi(m_heading);
}

}
