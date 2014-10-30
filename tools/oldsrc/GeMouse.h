#ifndef GE_MOUSE_H_
#define GE_MOUSE_H_

#include "Types.h"
namespace KaMi{
class IMouseEventMgr
{
public:
    void mouseEvent(kmInt32,kmInt32,kmInt32,kmInt32);
};
}
#endif