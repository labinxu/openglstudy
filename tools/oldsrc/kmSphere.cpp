#include "kmSphere.h"
namespace KaMi
{

    kmSphere::kmSphere(void)
    {

    }

    kmSphere::~kmSphere(void)
    {
    }

    void KaMi::kmSphere::draw()
    {

    }

    kmSphere::kmSphere( const kmVector3 &orgpt,kmfloat radius )
        :m_centerpt(orgpt),
        m_radius(radius),
        m_divideNum(5)
    {
        
    }

}