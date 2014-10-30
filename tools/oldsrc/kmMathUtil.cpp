#include "kmMathUtil.h"
#include "Vector3.h"

namespace KaMi{

const kmVector3 gcZeroVector(0.0f, 0.0f, 0.0f);

// restrict theta in [-pi,pi]
kmfloat WrapPi(kmfloat theta)
{
    theta += kmPi;
    theta -= floor(theta * km1Over2Pi) * km2Pi;
    theta -= kmPi;

    return theta;
}

//if x' value out-of-range ,the function will return a closer valid value.
// otherwise it will return a value that same as cos.
kmfloat SafeAcos(kmfloat x)
{
    if (x <= - 1.0f)
    {
        return kmPi;
    }

    if (x >= 1.0f)
    {
        return 0.0f;
    }
    return cos(x);
}



}