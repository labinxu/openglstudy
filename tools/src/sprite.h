#ifndef SPRITE_H
#define SPRITE_H
#include <functional>
#include "programer.h"


namespace Camus
{
class Sprite
{
  public:
    Sprite(){}
    virtual void keyboard(unsigned char key, int x, int y);
    virtual void mouse(int key, int state, int x, int y);
    virtual void motion(int x, int y){}
    virtual ~Sprite(){}
};

template<class T>
class Register
{};

template<>
class Register<KEYBD_EVENT>
{
  public:
    template<class T>
    void regist(T* sp)
    {
        Programer* pg = Programer::Instance();
        std::function<void (unsigned char,int ,int)> f;
        f = std::bind(&T::keyboard,
                          sp,
                          std::placeholders::_1,
                          std::placeholders::_2,
                          std::placeholders::_3);
        pg->regist(f);

    }
};

template<>
class Register<MOUSE_EVENT>
{
  public:
    template<class T>
    void regist(T* sp)
    {
        Programer* pg = Programer::Instance();
        std::function<void (int, int ,int ,int)> f;
        f = std::bind(&T::mouse,
                      sp,
                      std::placeholders::_1,
                      std::placeholders::_2,
                      std::placeholders::_3,
                      std::placeholders::_4);
        pg->regist(f);

    }
};


};

#endif /* SPRITE_H */
