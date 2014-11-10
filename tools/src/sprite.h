#ifndef SPRITE_H
#define SPRITE_H

namespace Camus
{

class Sprite
{
  public:
    virtual void keyboard(unsigned char key, int x, int y);
    virtual void mouse(int key, int state, int x, int y){}
    virtual void motion(int x, int y){}
    virtual ~Sprite(){}
};


};

#endif /* SPRITE_H */
