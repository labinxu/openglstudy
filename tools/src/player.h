#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "actor.h"
#include "sprite.h"

namespace Camus{
class Player :public Sprite, public Actor
{
  public:
    virtual void operator()(unsigned char key, int x, int y)
    {
        std::cout<<"oper key: "<<key<<" x: "<<x<<" y: "<<y<<std::endl;
    }
    virtual void operator()(int bt, int state, int x, int y)
    {
        std::cout<<"button "<<bt<< "state "<< state<<" x "<<x<<std::endl;
    }

    virtual void operator()(int x, int y)
    {
        std::cout<<"motion x: "<<x<<" y "<<y<<std::endl;
    }
};

};


#endif /* PLAYER_H */
