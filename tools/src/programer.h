#ifndef PROGRAMER_H
#define PROGRAMER_H
#include <vector>
#include <functional>


namespace Camus
{

class Sprite;
enum class KEYBD_EVENT;
enum class MOUSE_EVENT;
enum class MOTION_EVENT;


class Programer
{
    friend void keyboard (unsigned char key, int x, int y);
    friend void motion(int x, int y);
    friend void mouse(int bt, int state, int x, int y);
  public:
    template<class T>
    T* create()
    {
        return new T();
    }
    void regist(std::function<void (unsigned char,int ,int)> f)
    {
        this->_keyboardReceivers.push_back(f);
    }
    void regist(std::function<void (int ,int)> f)
    {
        this->_motionReceivers.push_back(f);
    }
    void regist(std::function<void (int, int, int ,int)> f)
    {
        this->_mouseReceivers.push_back(f);
    }
    /////////////////////////////////////////////////////////////////
    void createWindow(const char *wname);
    std::vector<Sprite*>::iterator mouseReceiversBegin()
    {
        return m_mouseReceivers.begin();
    }
    std::vector<Sprite*>::iterator mouseReceiversEnd()
    {
        return m_motionReceivers.end();
    }

    std::vector<Sprite*>::iterator motionReceiversBegin()
    {
        return m_motionReceivers.begin();
    }
    std::vector<Sprite*>::iterator motionReceiversEnd()
    {
        return m_motionReceivers.end();
    }

    void init(int argc, char **argv,
              int *cclr, int displaymodel,
              int w, int h);

    static Programer* Instance();
  private:
    std::vector<std::function<void (unsigned char, int, int )> > _keyboardReceivers;
    std::vector<std::function<void (int, int, int, int )> > _mouseReceivers;
    std::vector<std::function<void (int, int )> > _motionReceivers;

  private:
    Programer(){}
    Programer(const Programer&);
    Programer* operator=(const Programer&);
    void init();
  protected:
    int m_height;
    int m_width;
    int m_argc;
    int m_displayModel;
    char **m_argv;
    int* m_cclr;
    static Programer *m_programer;
    std::vector<Sprite*> m_mouseReceivers;
    std::vector<Sprite*> m_motionReceivers;
    std::vector<Sprite*> m_keyboardReceivers;
};


void keyboard (unsigned char key, int x, int y);

void motion(int x, int y);

void mouse(int bt, int state, int x, int y);


};

#endif
