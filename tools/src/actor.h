#ifndef ACTOR_H
#define ACTOR_H
#include "sprite.h"
#include "inputers.h"
namespace Camus{
        
class Actor :public Keyboard, public Motion, public Mouse
{
  public:
    virtual void operator()(unsigned char key, int x, int y){}
    virtual void operator()(int x, int y){}
    virtual void operator()(int bt,int state, int x, int y){}

    virtual void mouse(int ,int, int, int){}
    virtual void motion(int, int){}
    virtual void keyboard(unsigned char, int, int){}
};
};
#endif /* ACTOR_H */
