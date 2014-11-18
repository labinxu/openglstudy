#ifndef INPUTERS_H
#define INPUTERS_H

namespace Camus
{

class Keyboard
{
  public:
    virtual void operator()(unsigned char key, int x, int y)=0;
    virtual ~Keyboard(){}
};

class Mouse
{
  public:
    virtual void operator()(int, int, int, int)=0;

    virtual ~Mouse(){}
};

class Motion
{
  public:
    virtual void operator()(int x, int y)=0;

    virtual ~Motion(){}
};


template<class T>
class Register
{

};
template<>
class Register<Keyboard>
{
  public:
    static void Regist(Keyboard* sp)
    {
        Programer* pg = Programer::Instance();
        std::function<void (unsigned char,int ,int)> f;
        f = std::bind(&Keyboard::operator(),
                          sp,
                          std::placeholders::_1,
                          std::placeholders::_2,
                          std::placeholders::_3);
        pg->regist(f);
    }
};

template<>
class Register<Mouse>
{
  public:
    static void Regist(Mouse* sp)
    {
        Programer* pg = Programer::Instance();
        std::function<void (int, int ,int ,int)> f;
        f = std::bind(&Mouse::operator(),
                      sp,
                      std::placeholders::_1,
                      std::placeholders::_2,
                      std::placeholders::_3,
                      std::placeholders::_4);
        pg->regist(f);

    }
};


template<>
class Register<Motion>
{
  public:
    static void Regist(Motion* sp)
    {
        Programer* pg = Programer::Instance();
        std::function<void (int ,int)> f;
        f = std::bind(&Motion::operator(),
                      sp,
                      std::placeholders::_1,
                      std::placeholders::_2);
        pg->regist(f);

    }
};

};

#endif /* INPUTERS_H */
