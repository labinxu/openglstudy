#ifndef KM_OBJECT_H_
#define KM_OBJECT_H_
#include "includes.h"
namespace KaMi{

class kmObject
{
public:
    kmObject(void);
    virtual ~kmObject(void);
public:
    virtual void draw() = 0;
    virtual void show() = 0 ;
    virtual void onUpdate() = 0 ;
protected:
    kmColor m_color;
};

}
#endif