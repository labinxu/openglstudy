#ifndef KM_MATHUTIL_H_
#define KM_MATHUTIL_H_
#include "Types.h"
#include <math.h>

namespace KaMi{

    const kmfloat kmPi = 3.14159265f;
    const kmfloat km2Pi = kmPi * 2.0f;
    const kmfloat kmPiOver2 = kmPi * 0.5f;
    const kmfloat km1OverPi = 1.0f / kmPi;
    const kmfloat km1Over2Pi = 1.0f / km2Pi;

    extern kmfloat WrapPi(kmfloat theta);
    extern kmfloat SafeAcos(kmfloat x);
    
    // calculate the sin value and cos value of the theta
    inline void SinCos(kmfloat theta,kmfloat &retSinVal,kmfloat &retCosVal)
    {
        retSinVal = sin(theta);
        retCosVal = cos(theta);
    }

}
#endif